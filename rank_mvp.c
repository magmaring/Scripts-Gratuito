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
-	script	#mvp_kill	-1,{

OnInit:
	setarray .p_rwd, 607,1;	// Party reward <item>,<amount>
	setarray .s_rwd, 6543,1;	// Solo reward <item>,<amount>
	.chance = 100;	// Drop rate chances %
	.gm = 4;  // Impede que o nível gm e acima acione o evento
	// MVP Map list
	setarray .t_maps$[0],"moc_pryd06","lhz_dun03","gld2_prt","abbey02","ayo_dun02","lhz_dun04","ra_fild02","xmas_fild01","dic_dun02","beach_dun","iz_dun05","tur_dun04","lhz_dun02","jupe_core","moc_fild22","anthell02","odin_tem03","gon_dun03","gef_fild02","thana_boss","gef_fild10","ein_dun02","gef_fild14","moc_pryd04","dew_dun01","in_sphinx5","niflheim","moc_fild17","xmas_dun02","ice_dun03","kh_dun02","treasure02","moc_prydn2","pay_dun04","ra_san05","mosk_dun03","ama_dun03","thor_v03","gef_dun01","mjolnir_04","abyss_03","dic_dun03","prt_sewb4","pay_fild11","gef_dun02","gl_chyard","ra_fild03","ra_fild04","ve_fild01","ve_fild02","lou_dun03","prt_maze03","bra_dun02";
	end;

OnNPCKillEvent:
if (getgmlevel() >= .gm ) end; // If gm = event wont happen
if ( getmonsterinfo( killedrid, MOB_MVPEXP )) {
	for (.@a = 0; .@a < getarraysize(.t_maps$); .@a++) {
	if ( strcharinfo(3) == instance_mapname("06guild_01") ) end; 
	if ( strcharinfo(3) == instance_mapname("force_1-1") ) end;
	if ( strcharinfo(3) == .t_maps$[.@a]) { 
			if ( getcharid(1) ) {
				getpartymember getcharid(1), 1;
				getpartymember getcharid(1), 2;
				for ( .@i = 0; .@i < $@partymembercount; .@i++ ) {
					if ( isloggedin( $@partymemberaid[.@i], $@partymembercid[.@i] ) ) { 
						.@partymemberaid[.@c] = $@partymemberaid[.@i];
						.@c++;
					}
				}
				/*
				if (rand(100) < .chance) getitem .p_rwd[0], .p_rwd[1], .@partymemberaid[ rand( .@c ) ];
				announce "[ System ] : Player ["+ strcharinfo(0) +"] of party ["+ strcharinfo(1) +"] has killed "+ getmonsterinfo( killedrid, MOB_NAME ) +" at "+ strcharinfo(3), bc_all;
				*/
			}
			else {
			/*
				if (rand(100) < .chance) getitem .s_rwd[0], .s_rwd[1];
				announce "[ System ] : Player ["+ strcharinfo(0) +"] has killed "+ getmonsterinfo( killedrid, MOB_NAME ) +" alone at "+ strcharinfo(3), bc_all;
			*/
			}
		MVPKills = MVPKills+1;
		dispbottom "---------------------------------------------------";
		dispbottom "Você matou um total de "+MVPKills+" MVP"+((MVPKills == 1)?"":"s")+".";
		dispbottom "---------------------------------------------------";
		end;
		}
	}
	if ( getcharid(1) ) {
		//announce "[ System ] : Player ["+ strcharinfo(0) +"] of party ["+ strcharinfo(1) +"] has killed "+ getmonsterinfo( killedrid, MOB_NAME ) +" at "+ strcharinfo(3), bc_all;
		} 
		else {
		//announce "[ System ] : Player ["+ strcharinfo(0) +"] has killed "+ getmonsterinfo( killedrid, MOB_NAME ) +" alone at "+ strcharinfo(3), bc_all;
		}
	end;
	}

	
}

prontera,146,176,2	script	Rank MVP#Euphy	4_M_KNIGHT_BLACK,{
	mes "[^FF4500Rank MVP^000000]";
	mes "Olá, ^008aff"+strcharinfo(0)+"^000000.";
	mes "O que você gostaria de fazer?";
	next;
	switch(select("[^228B22¤^000000] Confira a Classificação.","[^228B22¤^000000] Minhas estatisticas.","[^228B22¤^000000] Premiação",( getgmlevel() >= 99 ) ? "[^FF0000¤^000000] REDEFINIR":"","[^FF0000¤^000000] Sair...")) {
		case 1:
			mes "[^FF4500Rank MVP^000000]";
			query_sql("SELECT char_id, CAST(`value` AS SIGNED) FROM `char_reg_num` WHERE `key` = 'MVPKills' ORDER BY CAST(`value` AS SIGNED) DESC LIMIT 20",.@cid,.@value);
			for(set .@i,0; .@i<getarraysize(.@cid); set .@i,.@i+1) {
				query_sql("SELECT `name` FROM `char` WHERE char_id = "+.@cid[.@i]+";",.@j$);
				set .@name$[.@i], .@j$;
			}
			if (!getarraysize(.@cid))
				mes "As classificações estão vazias.";
			else for(set .@i,0; .@i<getarraysize(.@cid); set .@i,.@i+1)
			mes "^FF0000["+(.@i+1)+"]^000000 ^0000FF"+.@name$[.@i]+"^000000 ~ ^008000"+.@value[.@i]+" MVPs mortos^000000";
			close;
			
		case 2:
			mes "[^FF4500Rank MVP^000000]";
			mes "Você matou "+((MVPKills)?"^0055FF"+MVPKills:"no")+"^000000 MVP"+((MVPKills == 1)?".":"s.");
			close;
		case 3:
			mes "[^FF4500Rank MVP^000000]";
			mes "Todo dia primeiro do mês o jogador que estiver em primeiro do rank ganhará Visuais exclusivos de Matador de MVP.";
			close;
		case 4:
			if ( select( "Confirm","Cancel" ) == 1 ) {
				query_sql("UPDATE `char_reg_num` SET `value` = '0' WHERE `key` ='MVPKills'");
				addrid(0);
				MVPKills = 0;
			}
			close;
		default:		
			close;
	}
	
OnInit:
		waitingroom "MVP LÍDER!",0;
		end;
}
