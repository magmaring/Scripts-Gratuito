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
new_zone01,124,124,5	script	Ajudante de Iniciantes#n	642,{
	specialeffect2 100;
	mes "^0099FF[ "+strnpcinfo(1)+" ]^000000";
	if( #check == 1 ){ 
		mes "A quest foi realizada!";
		mes "Você já está apto a iniciar sua jornada, siga ao portal em frente ao castelo!";
		close;
	}
	if( #save_quest == 0 ){
		mes "Deseja dar inicio a quest? É necessário derrotar 6 espécies de monstros diferentes sendo 10 de cada uma das espécies.";
		next;
		if( select("^00CC00•^000000 Iniciar Quest.:^00CC00•^000000 Desistir.") ) == 2 close;
			dispbottom "Quest ativa. Derrote os monstros necessários!",0x00FFFF;
			set #save_quest, 1;
			close;
	} else {
		mes "Derrote algum dos monstros da lista para iniciar sua jornada:";
		mes "^777777- "+ getmonsterinfo( 22183,MOB_NAME ) +"^000000: ^2596C2("+ check_kill_a +"/10).^000000";
		mes "^777777- "+ getmonsterinfo( 22184,MOB_NAME ) +"^000000: ^2596C2("+ check_kill_b +"/10).^000000";
		mes "^777777- "+ getmonsterinfo( 22185,MOB_NAME ) +"^000000: ^2596C2("+ check_kill_c +"/10).^000000";
		mes "^777777- "+ getmonsterinfo( 22186,MOB_NAME ) +"^000000: ^2596C2("+ check_kill_d +"/10).^000000";
		mes "^777777- "+ getmonsterinfo( 22187,MOB_NAME ) +"^000000: ^2596C2("+ check_kill_e +"/10).^000000";
		mes "^777777- "+ getmonsterinfo( 22188,MOB_NAME ) +"^000000: ^2596C2("+ check_kill_f +"/10).^000000";
		next;
		mes "^0033FF[ "+ strnpcinfo(1) +" ]^000000";
		if( check_kill_a < 10 ){ mes "Verifique se falta algum monstro para ser morto."; close; }
		if( check_kill_b < 10 ){ mes "Verifique se falta algum monstro para ser morto."; close; }
		if( check_kill_c < 10 ){ mes "Verifique se falta algum monstro para ser morto."; close; }
		if( check_kill_d < 10 ){ mes "Verifique se falta algum monstro para ser morto."; close; }
		if( check_kill_e < 10 ){ mes "Verifique se falta algum monstro para ser morto."; close; }
		if( check_kill_f < 10 ){ mes "Verifique se falta algum monstro para ser morto."; close; }
		mes "Prontinho, você já pode começar sua jornada. Entre no portal abaixo e bom jogo!";
		dispbottom "Você recebeu 1x "+ getitemname(607) +". Dê um clique duplo para abrir.",0x00FFFF;
		getitem 40064, 1;
		viewpoint 1, 39, 32, 1, 0x2596C2;
		set #check, 1;
		announce "[Campo de Iniciantes]: Bem-vindo(a) "+ strcharinfo(0) +", sua jornada só está começando!", bc_all|bc_blue;
		close;
}

OnNPCKillEvent:
	if( #save_quest == 0 ){
		message strcharinfo(0), "Quest Inativa.";
		dispbottom "Fale com o (Ajudante de Iniciantes) e de inicio a quest de iniciantes.", 0x00FFFF;
		end;
	}
	if( #check == 1 ) end;
	if( strcharinfo(3) != "new_zone01" ) end; 
	if( killedrid == 22183 ){
		if( check_kill_a < 10 ){
			set check_kill_a, check_kill_a + 1;
			message strcharinfo(0), getmonsterinfo( 22183,MOB_NAME ) +" ("+ check_kill_a +"/10).";
			end;
		} else {
			message strcharinfo(0), getmonsterinfo( 22183,MOB_NAME ) +" (Completo).";
			dispbottom "Você já matou 10x "+ getmonsterinfo( 22183,MOB_NAME ) +" necessários.",0x00FFFF;
			end;
			}
	}
	if( killedrid == 22184 ){
		if( check_kill_b < 10 ){
			set check_kill_b, check_kill_b + 1;
			message strcharinfo(0), getmonsterinfo( 22184,MOB_NAME ) +" ("+ check_kill_b +"/10).";
			end;
		} else {
			message strcharinfo(0), getmonsterinfo( 22184,MOB_NAME ) +" (Completo).";
			dispbottom "Você já matou 10x "+ getmonsterinfo( 22184,MOB_NAME ) +" necessários.",0x00FFFF;
			end;
			}
	}
	if( killedrid == 22185 ){
		if( check_kill_c < 10 ){
			set check_kill_c, check_kill_c + 1;
			message strcharinfo(0), getmonsterinfo( 22185,MOB_NAME ) +" ("+ check_kill_c +"/10).";
			end;
		} else {
			message strcharinfo(0), getmonsterinfo( 22185,MOB_NAME ) +" (Completo).";
			dispbottom "Você já matou 10x "+ getmonsterinfo( 22185,MOB_NAME ) +" necessários.",0x00FFFF;
			end;
			}
	}
	if( killedrid == 22186 ){
		if( check_kill_d < 10 ){
			set check_kill_d, check_kill_d + 1;
			message strcharinfo(0), getmonsterinfo( 22186,MOB_NAME ) +" ("+ check_kill_d +"/10).";
			end;
		} else {
			message strcharinfo(0), getmonsterinfo( 22186,MOB_NAME ) +" (Completo).";
			dispbottom "Você já matou 10x "+ getmonsterinfo( 22186,MOB_NAME ) +" necessários.",0x00FFFF;
			end;
			}
	}
	if( killedrid == 22187 ){
		if( check_kill_e < 10 ){
			set check_kill_e, check_kill_e + 1;
			message strcharinfo(0), getmonsterinfo( 22187,MOB_NAME ) +" ("+ check_kill_e +"/10).";
			end;
		} else {
			message strcharinfo(0), getmonsterinfo( 22187,MOB_NAME ) +" (Completo).";
			dispbottom "Você já matou 10x "+ getmonsterinfo( 22187,MOB_NAME ) +" necessários.",0x00FFFF;
			end;
			}
	}
	if( killedrid == 22188 ){ 
		if( check_kill_f < 10 ){
			set check_kill_f, check_kill_f + 1;
			message strcharinfo(0), getmonsterinfo( 22188,MOB_NAME ) +" ("+ check_kill_f +"/10).";
			end;
		} else {
			message strcharinfo(0), getmonsterinfo( 22188,MOB_NAME ) +" (Completo).";
			dispbottom "Você já matou 10x "+ getmonsterinfo( 22188,MOB_NAME ) +" necessários.",0x00FFFF;
			end;
		}
		end;
		}
}