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
prontera.gat,162,182,5	script	Arena Mvp	403,{
 
 
mes "[Arena MVP]";
mes "Você quer ir para a arena MvP?";
menu "Opa,claro que sim",sim,"Ah,agora não to afim",nao;
 
nao:
next;
mes "[Arena MVP]";
mes "OK, volte quando quiser";
close;
 
sim:
next;
mes "[Arena MVP]";
mes "Escolha uma arena";
menu "Arena",arena,Nenhuma,n;
 
n:
next;
mes "[Arena MVP]";
mes "OK, volte quando quiser";
close;
 
arena:
warp "pvp_n_1-3",50,45;
}
 
//
pvp_n_1-3,100,106,5	script	Criadora	94,{
mes "[Criadora]";
mes "Olá¡ "+strcharinfo(0)+", gostaria que eu chamasse um MVP?";
menu "Sim",sim,"Não",-;
close;
 
sim:
next;
mes "[Criadora]";
mes "Qual?";
menu "Abelha-Rainha",mvp1,"Amon-Ra",mvp2,"Atroce",mvp3,"Bafomé",mvp4,"Besouro_ladrão-Dourado",mvp5,"Cavaleiro da Tempestade",mvp6,"Dark Snake Lord",mvp7,"Detale",mvp8,"Drácula",mvp9,"Flor do Luar",mvp11,"Freeoni",mvp12,"Garm",mvp13,"General Tartaruga",mvp14,"Kiel D-01",mvp15,"Maya",mvp16,"Orc Herói",mvp18,"Osí­ris",mvp19,"RSX 0806",mvp20,"Senhor das Trevas",mvp21,"Senhor dos Mortos",mvp22,"Senhor dos Orcs",mvp23,"Tao Gunka",mvp24,"Memória de Thanatos",mvp25,"Egnigem Cenia",mvp26,"Lorde Seyren",mvp27,"Algoz Eremes",mvp28,"Mestre-Ferreiro Howard",mvp29,"Suma-Sacerdotisa Margaretha",mvp30,"Atiradora de Elite Ceci",mvp31,"Arquimaga Kathryne",mvp32,"Vesper",mvp33,"Bacsojin",mvp34,"Lady Tanee",mvp35,"Valquíria Randgris",mvp36,"Pesar Noturno",mvp37,"Ktullanux",mvp38,"Ifrit",mvp39,"Belzebu",mvp40,"Gorynych",mvp41,"Morroc Ferido",mvp42,"Imperador Morroc",mvp43,"Leão de Vinhas",mvp44,"Mamute Rochoso",mvp45,"Nenhum",-;
close;
 
mvp1:
next;
monster "pvp_n_1-3",100,106,"Abelha-Rainha",1059,1;
close;
 
mvp2:
next;
monster "pvp_n_1-3",100,106,"Amon-Ra",1511,1;
close;
 
mvp3:
next;
monster "pvp_n_1-3",100,106,"Atroce",1785,1;
close;
 
mvp4:
monster "pvp_n_1-3",100,106,"BafomÃ©",1039,1;
close;
 
mvp5:
monster "pvp_n_1-3",100,106,"Besouro_ladrÃ£o-Dourado",1086,1;
close;
 
mvp6:
next;
monster "pvp_n_1-3",100,106,"Cavaleiro da Tempestade",1251,1;
close;
 
mvp7:
next;
monster "pvp_n_1-3",100,106,"Dark Snake Lord",1418,1;
close;
 
mvp8:
next;
monster "pvp_n_1-3",100,106,"Detale",1719,1;
close;
 
mvp9:
next;
monster "pvp_n_1-3",100,106,"DrÃ¡cula",1389,1;
close;
 
mvp10:
next;
monster "pvp_n_1-3",100,106,"DragÃ£o Mutante",1262,1;
close;
 
mvp11:
next;
monster "pvp_n_1-3",100,106,"Flor do Luar",1150,1;
close;
 
mvp12:
next;
monster "pvp_n_1-3",100,106,"Freeoni",1159,1;
close;
 
mvp13:
next;
monster "pvp_n_1-3",100,106,"Garm",1889,1;
close;
 
mvp14:
next;
monster "pvp_n_1-3",100,106,"General Tartaruga",1312,1;
close;
 
mvp15:
next;
monster "pvp_n_1-3",100,106,"Kiel D-01",1734,1;
close;
 
mvp16:
next;
monster "pvp_n_1-3",100,106,"Maya",1147,1;
close;
 
mvp17:
next;
monster "pvp_n_1-3",100,106,"Maya",1147,1;
close;
 
mvp18:
next;
monster "pvp_n_1-3",100,106,"Orc HerÃ³i",1087,1;
close;
 
mvp19:
next;
monster "pvp_n_1-3",100,106,"OsÃ­ris",1038,1;
close;
 
mvp20:
next;
monster "pvp_n_1-3",100,106,"RSX 0806",1623,1;
close;
 
mvp21:
next;
monster "pvp_n_1-3",100,106,"Senhor das Trevas",1272,1;
close;
 
mvp22:
next;
monster "pvp_n_1-3",100,106,"Senhor dos Mortos",1373,1;
close;
 
mvp23:
next;
monster "pvp_n_1-3",100,106,"Senhor dos Orcs",1190,1;
close;
 
mvp24:
next;
monster "pvp_n_1-3",100,106,"Tao Gunka",1583,1;
close;
 
mvp25:
next;
monster "pvp_n_1-3",100,106,"Thanatos",1708,1;
close;
 
mvp26:
next;
monster "pvp_n_1-3",100,106,"Egnigem Cenía",1658,1;
close;
 
mvp27:
next;
monster "pvp_n_1-3",100,106,"Lorde Seyren",1646,1;
close;
 
mvp28:
next;
monster "pvp_n_1-3",100,106,"Algoz Eremes",1647,1;
close;
 
mvp29:
next;
monster "pvp_n_1-3",100,106,"Mestre-Ferreiro Howard",1648,1;
close;
 
mvp30:
next;
monster "pvp_n_1-3",100,106,"Suma-Sacerdotisa Margaretha",1649,1;
close;
 
mvp31:
next;
monster "pvp_n_1-3",100,106,"Atiradora de Elite Cecil",1650,1;
close;
 
mvp32:
next;
monster "pvp_n_1-3",100,106,"Arquimaga Kathryne",1651,1;
close;
 
mvp33:
next;
monster "pvp_n_1-3",100,106,"Vesper",1685,1;
close;
 
mvp34:
next;
monster "pvp_n_1-3",100,106,"Bacsojin",1518,1;
close;
 
mvp35:
next;
monster "pvp_n_1-3",100,106,"Lady Tanee",1688,1;
close;
 
mvp36:
next;
monster "pvp_n_1-3",100,106,"Valquíria Randgris",1751,1;
close;
 
mvp37:
next;
monster "pvp_n_1-3",100,106,"Pesar Noturno",1768,1;
close;
 
mvp38:
next;
monster "pvp_n_1-3",100,106,"Ktullanux",1779,1;
close;
 
mvp39:
next;
monster "pvp_n_1-3",100,106,"Ifrit",1832,1;
close;
 
mvp40:
next;
monster "pvp_n_1-3",100,106,"Belzebu",1873,1;
close;
 
mvp41:
next;
monster "pvp_n_1-3",100,106,"Gorynych",1885,1;
close;
 
mvp42:
next;
monster "pvp_n_1-3",100,106,"Morroc Ferido",1917,1;
close;
 
mvp43:
next;
monster "pvp_n_1-3",100,106,"Imperador Morroc",1916,1;
close;
 
mvp44:
next;
monster "pvp_n_1-3",100,106,"Leão de Vinhas",1991,1;
close;
 
mvp45:
next;
monster "pvp_n_1-3",100,106,"Mamute Rochoso",1990,1;
close;
 
}
 
// MapFlag
pvp_n_1-3	mapflag	nowarp
pvp_n_1-3	mapflag	nowarpto
pvp_n_1-3	mapflag	noteleport
pvp_n_1-3	mapflag	nosave	SavePoint
pvp_n_1-3	mapflag	nomemo
pvp_n_1-3	mapflag	nobranch
pvp_n_1-3	mapflag	nopenalty
 
//Portais
pvp_n_1-3.gat,8,49,0	warp	pvp_n_1-3Portal1	1,1,prontera.gat,156,191
pvp_n_1-3.gat,91,50,0	warp	pvp_n_1-3Portal2	1,1,prontera.gat,156,191