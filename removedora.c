//========================================================================================================||
//           000     000 0000000 00000000 000     000 00000000 00000000 00 000      00 00000000           ||
//           0000   0000 00   00 00       0000   0000 00    00 00    00 00 00 00    00 00                 ||
//           00000 00000 00   00 00  0000 00000 00000 00    00 00    00 00 00  00   00 00  0000           ||
//           00000000000 0000000 00    00 00000000000 00000000 000000   00 00   00  00 00    00           ||
//           00       00 00   00 00    00 00       00 00    00 00    00 00 00    00 00 00    00           ||
//           00       00 00   00 00000000 00       00 00    00 00    00 00 00     0000 00000000           ||
//========================================================================================================||
//         VENDAS DE SERVI�OS SERVIDORES DE RAGNAROK ONLINE/PERFECT WORLD/MU/AION/CABAL/MINECRAFT         ||
//                                CONTATO OU SUPORTE ATRAV�S DOS CANAIS                                   ||
//                                DISCORD: [ADM] Magmaring#0352                                           ||
//                                FACEBOOK: https://www.facebook.com/sorakamente/                         ||
//                                WHATSAPP: https://wa.me/5585999677074                                   ||
//========================================================================================================||
prontera,147,174,6	script	Velha S�bia	863,{

//===== Configura��es: =======================================
set .@falhar, 0;	// A remo��o pode falhar? [1=Sim/0=N�o]
//============================================================

	mes "["+strnpcinfo(1)+"]";
	mes "Eu tenho o poder m�stico de remover cartas colocadas em equipamentos. O que acha disso?";
	next;
	switch (select ("Me ajudaria muito!:O que voc� quer em troca?:N�o acho nada interessante...")) {
		mes "[Velha S�bia]";
	
		case 1:
			mes "Ent�o, qual item voc� quer que eu examine?";
			setarray .@pos$[1], "Cabe�a Topo","Armadura","M�o Esquerda","M�o Direita","Capa","Sapatos","Acess�rio 1","Acess�rio 2","Cabe�a Meio","Cabe�a Baixo";
			set .@menu$, "";
			for (set .@i, 1; .@i <= 10; set .@i, .@i + 1) {
				if (getequipisequiped(.@i))
					set .@menu$, .@menu$ + .@pos$[.@i] + " ("+getequipname(.@i)+")";
				set .@menu$, .@menu$ + ":";	
			}
			next;
			set .@menu, select (.@menu$);
			mes "[Velha S�bia]";
			if (!getequipisequiped(.@menu))
				callsub F_MesThenClose, "N�o h� nada equipado a�.";
			if (!getequipcardcnt(.@menu))
				callsub F_MesThenClose, "N�o h� nenhuma carta nesse equipamento.";
			if (!checkweight(1202,(getequipcardcnt(.@menu)+1)))
				callsub F_MesThenClose, "Voc� est� com peso de mais. V� at� o armaz�m e guarde algumas coisas.";
			mes "O item escolhido possui "+getequipcardcnt(.@menu)+" carta(s) equipada(s).";
			mes "Para aprimorar minha magia, ser�o necess�rios "+((getequipcardcnt(.@menu)*25000)+2000)+"z,";
			next;
			if (select ("Continuar!:Desistir...") == 2) close;
			mes "[Velha S�bia]";
			if ((Zeny < (2000+(getequipcardcnt(.@menu)*25000))))
				callsub F_MesThenClose, "Voc� n�o tem tudo que � necess�rio para minha m�gica; volte quando conseguir.";
			if (.@falhar) {
				mes "Bem, antes de continuarmos, tenho que dizer que o processo pode n�o ter sucesso...";
				mes "Suas cartas, seu item ou ambos podem ser destru�dos. Qual voc� preza mais?";
				if (select ("O item:As cartas:Mudei de ideia") == 3) close;
				set .@escolhafalhar, @menu;
				next;
				mes "["+strnpcinfo(1)+"]";
			}
			mes "Muito bem, vamos come�ar!";
			next;
			mes "["+strnpcinfo(1)+"]";
			set Zeny, Zeny - (2000+(getequipcardcnt(.@menu)*25000));
			
			if (.@falhar) {
				set .@chancefalhar, rand(100);
				
				if (.@chancefalhar < 10) {
					failedremovecards .@menu, 0;
					callsub F_MesThenClose, "O processo foi uma falha total. Estou envergonhada, seu item e suas cartas foram destru�dos.";
				} else if (.@chancefalhar < 8) {
					failedremovecards .@menu, .@escolhafalhar;
					if (.@escolhafalhar)
						callsub F_MesThenClose, "Eu falhei ao remover as cartas, e elas foram destru�das. O item est� em perfeito estado.";
					else
						callsub F_MesThenClose, "Eu consegui remover as cartas, mas o seu item foi destru�do.";
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