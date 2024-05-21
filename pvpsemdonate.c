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
prontera,148,181,5	script	PvP Sem Donate	450,{

mes "[PvP Sem Donate]";
mes "Olá, deseja entrar na Arena PvP sem Donates?";
next;
menu "Sim",C_DON,"Nao",-;
mes "[PvP Sem Donate]";
mes "Muito bem, volte aqui quando desejar!";
close;

C_DON:
mes "[PvP Sem Donate]";
mes "Hum.. sem donater ^^ irei te levar para a sala PvP ^000000!";
next;

mes "[PvP Sem Donate]";
mes "Vamos nessa";
next;
warp "pvp_n_1-5",87,113;
close;

DON:
mes "[PvP Sem Donate]";
mes "^0000FFSafadinho tentando me enganar^000000? tire seus donates se quiser entrar aqui";
close;
}

//NPC DE SAIR

pvp_n_1-5,87,113,4	script	Sair	801,{

mes "Deseja sair da sala?";
menu "Sim",sim,"Nao",nao;

sim:
warp "prontera",150,175;
close;

nao:
close;
}

pvp_y_2-2	mapflag	nomemo
pvp_y_2-2	mapflag	gvg	off
pvp_y_2-2	mapflag	pvp
pvp_y_2-2	mapflag	nopenalty
pvp_y_2-2	mapflag	nobranch
pvp_y_2-2	mapflag	pvp_noguild
pvp_y_2-2	mapflag	noloot
pvp_y_2-2	mapflag	noexp
pvp_y_2-2	mapflag	noteleport
pvp_y_2-2	mapflag	noreturn
pvp_y_2-2	mapflag	nowarp
pvp_y_2-2	mapflag	nowarpto
pvp_y_2-2	mapflag	nosave	SavePoint