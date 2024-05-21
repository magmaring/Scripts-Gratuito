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
prontera,152,179,5	script	Refinador	826,{

// Pe�as refin�veis: Deixe "" para ignorar aquela pe�a.
	setarray .@_ref_able$,"Cabe�a - Topo","Vestimenta","M�o esquerda","M�o direita","Capa","Cal�ados","Acess�rio 1","Acess�rio 2","Cabe�a - Meio","Cabe�a - Baixo";
// Pre�o do Refinador
	set .@_ref_cost,0;
// O Refinador pode refinar itens n�o-refin�veis? 1=Sim / 0=N�o
	set .@_ref_ignore,1;
// At� quanto o Refinador pode refinar os itens?
	set .@_ref_max,50;
// O refinador pode diminuir a taxa de refinamento dos itens? 1=Sim / 0=N�o
	set .@_ref_dec,1;
// N�o altere nada abaixo a n�o ser que saiba o que est� fazendo.
	mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
	mes "Ol�, "+strcharinfo(0)+". Como vai voc�? Veio em busca de meus servi�os especiais?";
	next;
	if(select("- Sim, eu vim.:- Por que seus servi�os s�o especiais?")==2){
		mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
		mes "V�rios fatores...";
		mes "- Eu NUNCA falho.";
		mes "- Eu posso refinar:";
		for (set .@i, 0; .@i < 10; set .@i, .@i + 1)
			mes "   * "+.@_ref_able$[.@i];
		if(.@_ref_ignore)
			mes "- Eu posso refinar itens que os ferreiros normais n�o conseguem.";
		if(.@_ref_max > 50)
			mes "- Eu posso refinar itens at� +"+.@_ref_max+".";
		if(.@_ref_dec)
			mes "- Eu posso diminuir a taxa de refinamento de itens.";
		next;
	}
	mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
	mes "O que deseja de mim?";
	next;
	setarray .@_ref_temp$[0],"","- Desaprimorar equipamento";
	set @mode, select("- Aprimorar equipamento:"+.@_ref_temp$[.@_ref_dec]+":- Cancelar");
	mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
	if(@mode == 3 || (@mode == 2 && !.@_ref_dec)){ //Anti Hacker
		mes "Siga seu caminho.";
		close;
	}
	mes "Selecione a parte onde deseja que eu realize o trabalho?";
	next;
	set .@menu$,"";
	for (set .@i, 0; .@i < 10; set .@i, .@i + 1)
		set .@menu$, .@menu$ + .@_ref_able$[.@i] + " [" + getequipname((.@i+1)) + "]:";
	set .@menu$, .@menu$ + "Cancelar";
	set @part, select(.@menu$);
	mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
	if(@part > 10 || .@_ref_able$[(@part - 1)] == ""){ //Anti Hacker
		mes "Siga seu caminho.";
		close;
	}
	if(!getequipisequiped(@part)){
		mes "Voc� quer que eu queime seu corpo no fogo ardente?";
		close;
	}
	if(!getequipisenableref(@part) && !.@_ref_ignore){
		mes "Desculpe, n�o posso trabalhar nesse item.";
		close;
	}
	setarray .@_ref_temp$[1],"aprimorar","desaprimorar";
	mes "Hmm, e quantas vezes voc� deseja "+ .@_ref_temp$[@mode] +" esse equipamento?";
	next;
	input @count;
	mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
	if(!@count){
		mes "Se voc� n�o quer nada...";
		close;
	}
	if((((@count + getequiprefinerycnt(@part)) > .@_ref_max) && @mode == 1) || (((getequiprefinerycnt(@part) - @count) < 0) && @mode == 2)){
		mes "Nossa, eu sou bom, mas n�o posso fazer isso...";
		close;
	}
	if(.@_ref_cost){
		mes "Para "+.@_ref_temp$[@mode]+" esse item, precisarei de "+ (@count * .@_ref_cost) + "z, voc� deseja continuar?";
		next;
		if(select("- Sim:- N�o, isso � um roubo!")==2){
			mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
			mes "Ent�o volte para o refinador comum.";
			close;
		}
		mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
	}
	if(Zeny < (@count * .@_ref_cost)){
		mes "Voc� precisa de mais dinheiro se deseja ficar forte.";
		close;
	}
	set Zeny, Zeny - (@count * .@_ref_cost);
	switch(@mode){
		case 1:
			for (set .@i, 0; .@i < @count; set .@i, .@i + 1)
				successrefitem @part;
			break;
		case 2:
			setarray @cards,getequipcardid(@part,0),getequipcardid(@part,1),getequipcardid(@part,2),getequipcardid(@part,3);
			set @refine, getequiprefinerycnt(@part);
			set @id, getequipid(@part);
			unequip @part;
			delitem2 @id,1,1,@refine,0,@cards[0],@cards[1],@cards[2],@cards[3];
			getitem2 @id,1,1,(@refine - @count),0,@cards[0],@cards[1],@cards[2],@cards[3];
			equip @id;
			specialeffect2 154;
	}
	mes "Clang !! Clang !! Clang !!";
	next;
	mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
	mes "Aqui est�! Boa sorte!";
	close;
	}