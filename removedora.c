//========================================================================================================||
//           000     000 0000000 00000000 000     000 00000000 00000000 00 000      00 00000000           ||
//           0000   0000 00   00 00       0000   0000 00    00 00    00 00 00 00    00 00                 ||
//           00000 00000 00   00 00  0000 00000 00000 00    00 00    00 00 00  00   00 00  0000           ||
//           00000000000 0000000 00    00 00000000000 00000000 000000   00 00   00  00 00    00           ||
//           00       00 00   00 00    00 00       00 00    00 00    00 00 00    00 00 00    00           ||
//           00       00 00   00 00000000 00       00 00    00 00    00 00 00     0000 00000000           ||
//========================================================================================================||
//         VENDAS DE SERVIÇOS SERVIDORES DE RAGNAROK ONLINE/PERFECT WORLD/MU/AION/CABAL/MINECRAFT         ||
//                                CONTATO OU SUPORTE ATRAVÉS DOS CANAIS                                   ||
//                                DISCORD: [ADM] Magmaring#0352                                           ||
//                                FACEBOOK: https://www.facebook.com/sorakamente/                         ||
//                                WHATSAPP: https://wa.me/5585999677074                                   ||
//========================================================================================================||
prontera,147,174,6	script	Velha Sábia	863,{

//===== Configurações: =======================================
set .@falhar, 0;	// A remoção pode falhar? [1=Sim/0=Não]
//============================================================

	mes "["+strnpcinfo(1)+"]";
	mes "Eu tenho o poder místico de remover cartas colocadas em equipamentos. O que acha disso?";
	next;
	switch (select ("Me ajudaria muito!:O que você quer em troca?:Não acho nada interessante...")) {
		mes "[Velha Sábia]";
	
		case 1:
			mes "Então, qual item você quer que eu examine?";
			setarray .@pos$[1], "Cabeça Topo","Armadura","Mão Esquerda","Mão Direita","Capa","Sapatos","Acessório 1","Acessório 2","Cabeça Meio","Cabeça Baixo";
			set .@menu$, "";
			for (set .@i, 1; .@i <= 10; set .@i, .@i + 1) {
				if (getequipisequiped(.@i))
					set .@menu$, .@menu$ + .@pos$[.@i] + " ("+getequipname(.@i)+")";
				set .@menu$, .@menu$ + ":";	
			}
			next;
			set .@menu, select (.@menu$);
			mes "[Velha Sábia]";
			if (!getequipisequiped(.@menu))
				callsub F_MesThenClose, "Não há nada equipado aí.";
			if (!getequipcardcnt(.@menu))
				callsub F_MesThenClose, "Não há nenhuma carta nesse equipamento.";
			if (!checkweight(1202,(getequipcardcnt(.@menu)+1)))
				callsub F_MesThenClose, "Você está com peso de mais. Vá até o armazém e guarde algumas coisas.";
			mes "O item escolhido possui "+getequipcardcnt(.@menu)+" carta(s) equipada(s).";
			mes "Para aprimorar minha magia, serão necessários "+((getequipcardcnt(.@menu)*25000)+2000)+"z,";
			next;
			if (select ("Continuar!:Desistir...") == 2) close;
			mes "[Velha Sábia]";
			if ((Zeny < (2000+(getequipcardcnt(.@menu)*25000))))
				callsub F_MesThenClose, "Você não tem tudo que é necessário para minha mágica; volte quando conseguir.";
			if (.@falhar) {
				mes "Bem, antes de continuarmos, tenho que dizer que o processo pode não ter sucesso...";
				mes "Suas cartas, seu item ou ambos podem ser destruídos. Qual você preza mais?";
				if (select ("O item:As cartas:Mudei de ideia") == 3) close;
				set .@escolhafalhar, @menu;
				next;
				mes "["+strnpcinfo(1)+"]";
			}
			mes "Muito bem, vamos começar!";
			next;
			mes "["+strnpcinfo(1)+"]";
			set Zeny, Zeny - (2000+(getequipcardcnt(.@menu)*25000));
			
			if (.@falhar) {
				set .@chancefalhar, rand(100);
				
				if (.@chancefalhar < 10) {
					failedremovecards .@menu, 0;
					callsub F_MesThenClose, "O processo foi uma falha total. Estou envergonhada, seu item e suas cartas foram destruídos.";
				} else if (.@chancefalhar < 8) {
					failedremovecards .@menu, .@escolhafalhar;
					if (.@escolhafalhar)
						callsub F_MesThenClose, "Eu falhei ao remover as cartas, e elas foram destruídas. O item está em perfeito estado.";
					else
						callsub F_MesThenClose, "Eu consegui remover as cartas, mas o seu item foi destruído.";
				} else if (.@chancefalhar < 10) {
					failedremovecards .@menu, 3;
					callsub F_MesThenClose, "Eu falhei ao remover as cartas, e por sorte sua nada foi danificado.";
				}
			}
			successremovecards .@menu;
			mes "O processo foi um grande sucesso, tudo ocorreu nos conformes.";
			close;	
	
		case 2:
			callsub F_MesThenClose, "Eu vou precisar de 2.000z, mais 25.000z para cada carta em seu equipamento.";
		
		case 3:
			mes "Que pena... T_T";
			close;
	}
	
	F_MesThenClose:
		mes getarg(0);
		close;
	return;
}