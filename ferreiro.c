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
prontera,152,179,5	script	Refinador	826,{

// Peças refináveis: Deixe "" para ignorar aquela peça.
	setarray .@_ref_able$,"Cabeça - Topo","Vestimenta","Mão esquerda","Mão direita","Capa","Calçados","Acessório 1","Acessório 2","Cabeça - Meio","Cabeça - Baixo";
// Preço do Refinador
	set .@_ref_cost,0;
// O Refinador pode refinar itens não-refináveis? 1=Sim / 0=Não
	set .@_ref_ignore,1;
// Até quanto o Refinador pode refinar os itens?
	set .@_ref_max,50;
// O refinador pode diminuir a taxa de refinamento dos itens? 1=Sim / 0=Não
	set .@_ref_dec,1;
// Não altere nada abaixo a não ser que saiba o que está fazendo.
	mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
	mes "Olá, "+strcharinfo(0)+". Como vai você? Veio em busca de meus serviços especiais?";
	next;
	if(select("- Sim, eu vim.:- Por que seus serviços são especiais?")==2){
		mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
		mes "Vários fatores...";
		mes "- Eu NUNCA falho.";
		mes "- Eu posso refinar:";
		for (set .@i, 0; .@i < 10; set .@i, .@i + 1)
			mes "   * "+.@_ref_able$[.@i];
		if(.@_ref_ignore)
			mes "- Eu posso refinar itens que os ferreiros normais não conseguem.";
		if(.@_ref_max > 50)
			mes "- Eu posso refinar itens até +"+.@_ref_max+".";
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
		mes "Você quer que eu queime seu corpo no fogo ardente?";
		close;
	}
	if(!getequipisenableref(@part) && !.@_ref_ignore){
		mes "Desculpe, não posso trabalhar nesse item.";
		close;
	}
	setarray .@_ref_temp$[1],"aprimorar","desaprimorar";
	mes "Hmm, e quantas vezes você deseja "+ .@_ref_temp$[@mode] +" esse equipamento?";
	next;
	input @count;
	mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
	if(!@count){
		mes "Se você não quer nada...";
		close;
	}
	if((((@count + getequiprefinerycnt(@part)) > .@_ref_max) && @mode == 1) || (((getequiprefinerycnt(@part) - @count) < 0) && @mode == 2)){
		mes "Nossa, eu sou bom, mas não posso fazer isso...";
		close;
	}
	if(.@_ref_cost){
		mes "Para "+.@_ref_temp$[@mode]+" esse item, precisarei de "+ (@count * .@_ref_cost) + "z, você deseja continuar?";
		next;
		if(select("- Sim:- Não, isso é um roubo!")==2){
			mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
			mes "Então volte para o refinador comum.";
			close;
		}
		mes "[ ^FF0000"+strnpcinfo(1)+"^000000 ]";
	}
	if(Zeny < (@count * .@_ref_cost)){
		mes "Você precisa de mais dinheiro se deseja ficar forte.";
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
	mes "Aqui está! Boa sorte!";
	close;
	}