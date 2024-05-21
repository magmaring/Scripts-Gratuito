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
prontera,162,177,3	script	[Plagio de Habilidade]#HB	482,{

set .npcname$[0], "[Plagiador de Habilidades]";
mes .npcname$[0];
mes "Olá ^339966"+strcharinfo(0)+"^000000";
mes "Sou o ^FF0000Plagiador de Habilidades^000000.";
 
next;
mes .npcname$[0];
mes "Deixa eu explicar melhor... Tenho uma lista com varias habilidades e magias que podem ser ^339966copiadas^000000.";
mes "Basta escolher uma habilidade ou magia da lista que eu plagio para você.";
mes "Mas primeiro deixa eu ver se você realmente é um ^339966Arruaceiro/Desordeiro^000000...";
next;

if(Class != 4018) goto nstk;
mes .npcname$[0];
mes "Parabéns ^339966"+strcharinfo(0)+"^000000, você é um legitimo Stalker.";
mes "Agora escolha uma opção da lista abaixo para que eu copie ela para você.";
next;
 
menu"Desperado",de,"Esma",es,"Nevasca",ne,"Impacto de Tyr",ty,"Punho Supremo de Azura",pu,"Combo Esmagador",co,"Bomba Acida",bo,"Combo triplo",ad,"Nada Talvez mais tarde...",na;
close;
 
es:
mes .npcname$[0];
mes"Pronto você já está plagiado.";
mes "Até mais!";  
skill 86,5,0;
skilleffect 86, 86;
emotion 51;
close;
 
fo:
mes .npcname$[0];
mes"pronto você já está plagiado";
mes "Até mais";  
skill 229,5,0;
skilleffect 229, 229;
emotion 51;
close;
 
ne:
mes .npcname$[0];
mes"pronto você já está plagiado";
mes "Até mais";  
skill 539,5,0;
skilleffect 539, 539;
emotion 51;
close;
 
ty:
mes .npcname$[0];
mes"pronto você já está plagiado";
skill 62,10,0;
skilleffect 62, 62;
emotion 51;
close;
 
 
la:
mes .npcname$[0];
mes"pronto você já está com a plagiado";
skill 540,10,0;
emotion 51;
close;
 
co:
mes .npcname$[0];
mes"pronto você já está com a plagiado";  
skill 537,10,0;
emotion 51;
close;
 
pe:
mes .npcname$[0];
mes"pronto você já está com a plagiado";
skill 534,10,0;
emotion 51;
close;
 
ad:
mes .npcname$[0];
mes"pronto você já está com a plagiado";
skill 230,5,0;
emotion 51;
close;
 
na:
mes .npcname$[0];
mes "estarei aqui novamente se precisar";
mes "Até mais";
emotion 20;
close;
 
nstk:
mes .npcname$[0];
mes "Desculpe ^339966"+strcharinfo(0)+"^000000 mas você não e um verdadeiro Stalker !";
close;

} 