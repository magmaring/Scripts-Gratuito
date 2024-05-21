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
prontera.gat,154,182,5	script	Arena PvP	737,{
mes "[PvP Arena]";
mes "Olá, deseja entrar na Arena PvP ??";
next;
menu "Sim",-,"Não",cancel;{

mes "[ArenaPvP]";
mes "Vamos nessa";
next;
warp "guild_vs2",92,49;
close;

cancel:
mes "[ArenaPvP]";
mes "Então saia já daqui!";
close;
}

}

guild_vs2	mapflag	nomemo
guild_vs2	mapflag	nowarp
guild_vs2	mapflag	nowarpto
guild_vs2	mapflag	noreturn
guild_vs2	mapflag	nosave
guild_vs2	mapflag	noteleport
guild_vs2	mapflag	nobranch


