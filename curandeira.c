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
-	script	Buffer	-1,{

npcspeed 170;	//Velocidade de locomoção do npc
	set @ServerName$, "Lost RO"; 	//Nome de Seu Servidor que aparecera quando npc falar
	set .@Price,	0;	// Zeny necessário para curar. 0 = Gratuito
	set .@Buffs,	1;	// Dar buffs básicos ao jogador? (1 = Sim/0 = Não)
	set .@Delay,	0;	// Delay para usar o npc, em segundos. 0 = Desativado

	callfunc "F_ClearGarbage", 0;
	if (@HD > gettimetick(2)) end;
	if (.@Price) {
		message strcharinfo(0),"A cura custa "+.@Price+" Zeny.";
		if (Zeny < .@Price) end;
		if(select("^0055FFCurar^000000:^777777Cancelar^000000")==2) close;
		set Zeny, Zeny-.@Price;
	}
	sc_end SC_STONE;
	sc_end SC_FREEZE;
	sc_end SC_STUN;
	sc_end SC_SLEEP;
	sc_end SC_POISON;
	sc_end SC_CURSE;
	sc_end SC_SILENCE;
	sc_end SC_CONFUSION;
	sc_end SC_BLIND;
	sc_end SC_BLEEDING;
	sc_end SC_HALLUCINATION;
	specialeffect2 313; percentheal 100,100;
	if (.@Buffs) {
	if(getgroupid() < 0)
		specialeffect2 EF_INCAGILITY; sc_start SC_INC_AGI,240000,10; 
		specialeffect2 EF_BLESSING; sc_start SC_BLESSING,240000,10;
		specialeffect2 112; sc_start SC_KYRIE,240000,10;	
		sc_start SC_ASSUMPTIO,240000,5; specialeffect2 375; 
		specialeffect2 84; sc_start SC_IMPOSITIO,240000,5; 
		specialeffect2 76; sc_start SC_MAGNIFICAT,240000,5; 
		specialeffect2 75; sc_start SC_GLORIA,240000,5;	
		specialeffect2 88; sc_start SC_SUFFRAGIUM,240000,3;
			
}

	if (.@Delay) set @HD, gettimetick(2)+.@Delay;
    dispbottom "Obrigado por jogar no "+ @ServerName$ +"!";
    emotion 51;

OnTimer10000:
    npcwalkto 150+rand(8),173+rand(8);
    setnpctimer 0;

doitagain:
        set $lol,rand(5);
    if($lol == 0) goto Lquote0;
    if($lol == 1) goto Lquote1;
    if($lol == 2) goto Lquote2;
    if($lol == 3) goto Lquote3;
    if($lol == 4) goto Lquote4;
    if($lol == 5) goto Lquote5;
        goto doitagain;

Lquote0:
    npctalk "Buff's!";
    setnpctimer 0;
    end;
Lquote1:
    npctalk "Proteção gratuita!";
    setnpctimer 0;
    end;
Lquote2:
    npctalk "Pegue seus buff's!";
    setnpctimer 0;
    end;
Lquote3:
    npctalk "Cliquem em mim e ganhe buff's!";
    setnpctimer 0;
    end;
Lquote4:
    npctalk "Proteção de graça!";
    setnpctimer 0;
    end;
Lquote5:
    npctalk "Pegue sua proteção!";
    setnpctimer 0;
    end;

OnInit:
    initnpctimer;
	.delay = 500;
	.title$ = " BUFFER";
	
	.string_size = getstrlen( .title$ );
	while( 1 ){
		.@title$[ .@i ] = charat( .title$,.@i );
		delwaitingroom;
		waitingroom ""+implode( .@title$," " ),0;
		.@i++;
		if( .@i > .string_size ){
			.@i = 0;
			deletearray .@title$;
		}
		sleep .delay;
    }
    end;
}

prontera,170,170,4	duplicate(Buffer)	Buffer#pront	1998
morocc,159,96,5	duplicate(Buffer)	Buffer#moc	1998
ayothaya,155,111,5	duplicate(Buffer)	Buffer#ayo	1998
geffen,121,61,5	duplicate(Buffer)	Buffer#gef	1998
umbala,94,162,5	duplicate(Buffer)	Buffer#umb	1998
payon,180,105,5	duplicate(Buffer)	Buffer#pay	1998
alberta,185,144,5	duplicate(Buffer)	Buffer#alb	1998
aldebaran,134,123,5	duplicate(Buffer)	Buffer#alde	1998
izlude,125,118,5	duplicate(Buffer)	Buffer#izl	1998
xmas,149,136,5	duplicate(Buffer)	Buffer#xmas	1998
comodo,188,162,5	duplicate(Buffer)	Buffer#com	1998
amatsu,200,80,5	duplicate(Buffer)	Buffer#ama	1998
gonryun,164,130,5	duplicate(Buffer)	Buffer#gon	1998
yuno,152,186,5	duplicate(Buffer)	Buffer#yuno	1998
niflheim,188,180,5	duplicate(Buffer)	Buffer#nif	1998
louyang,225,103,5	duplicate(Buffer)	Buffer#lou	1998
rachel,131,117,5	duplicate(Buffer)	Buffer#rac	1998
veins,212,124,5	duplicate(Buffer)	Buffer#vei	1998
moscovia,221,192,5	duplicate(Buffer)	Buffer#mosc	1998