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
-	script	OnPCLoginEvent	-1,{

    OnPCLoginEvent:
	cutin "kafra_07",2;
    set @npcname$,"^FF1493[ Bem Vindo ao PowkRO ]^000000";
    set @servername$,"^0000FFPowkRO^000000";	
    mes @npcname$;
    mes (gettime(3)>= 6&&gettime(3)<= 12?"Bom-dia":(gettime(3)>=13&&gettime(3)<=18?"Boa-tarde":"Boa-noite"))+", ^008aff"+strcharinfo(0)+"^000000 !";
    mes "Você possui ^FF0000"+#CASHPOINTS+"^000000 Rops";
	if(vip_status(1)) {
	set .@timer, vip_status(2);
	mes "Tempo VIP Restante:"+callfunc("Time2Str",.@timer);
	}
    mes "Não se esqueça de votar!";
	mes "<URL>Votar no PowkRO^000000<INFO>https://powkro.com/site/?module=voteforpoints</INFO></URL>";

    next;
    mes @npcname$;
    mes "Tudo certo, tenha um bom jogo";
cutin "",255;
    close;


}