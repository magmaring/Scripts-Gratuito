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
prontera,142,184,5	script	Roleta da Sorte	563,{

mes "[^FFA500Roleta da Sorte^000000]";
mes "Olá ^008aff"+strcharinfo(0)+"^000000, como posso te ajudar?";
next;

    switch(select("^008000[»]^000000 Jogar:^008000[»]^000000 Ver Top Jogadores:^FF0000[»]^000000 Sair")) {
		case 1:
		
        if(countitem(30169) < 1 ) goto SemFicha;
        delitem 30169,1;
        
        .@delay = 100;
        for ( .@i = 0; .@i < .roulette_size; .@i++ ) {
            cutin "roleta_"+.roulette$[.@i],2;
            sleep2 .@delay;
            if ( .@i && .@i % 9 == 0 )
                .@delay += 10;
        }
        for ( .@i = .roulette_size - 1; .@i >= 0; .@i-- ) {
            cutin "roleta_"+.roulette$[.@i],2;
            sleep2 .@delay;
            if ( .@i && .@i % 9 == 0 )
                .@delay += 10;
        }
    
        .@found = -1;
        .@target = rand( .roulette_size  );
        
        for ( .@i = 0; .@i < .roulette_size && .@found < 0; .@i++ ) {
            cutin "roleta_"+.roulette$[.@i],2;
            sleep2 .@delay;
            if ( .@i && .@i % 9 == 0 )
                .@delay += 10;
            .@found_pre = .@i;
            if (  .@i == .@target )
                .@found = .@i;
        }
        
        if ( .@target >= .roulette_size ) {
            for ( .@i = .roulette_size - 1; .@i >= 0 && .@found < 0; .@i-- ) {
                cutin "roleta_"+.roulette$[.@i],2;
                sleep2 .@delay;
                if ( .@i && .@i % 9 == 0 )
                    .@delay += 10;
                .@found_pre = .@i;
                if ( ( .roulette_size + .@i ) == .@target )
                    .@found = ( .roulette_size - ( .roulette_size - .@i ) - 1 );
                    
            }
        }
        if ( .@found < 0 || .@found >= .roulette_size ) {
            .@found = .@found_pre;
        }
		.@pontos = 1;
		query_sql "insert into `Rank_Roleta` value ( "+ getcharid(0) +", '"+ escape_sql( strcharinfo(0) ) +"', 1 ) on duplicate key update partidas = partidas + 1";
		#ROLETA += .@pontos;
		Roleta = Roleta+1;
        .saiu = rand(8,16);
		mes "[^FFA500Roleta da Sorte^000000]";
        mes "Parabéns, aqui está o seu prêmio.";
        cutin "roleta_"+.saiu,2;
		switch ( .saiu ) {
			case 0: getitem 501,1; break;
			case 1: getitem 502,1; break;
			case 2: getitem 503,1; break;
			case 3: getitem 504,1; break;
			case 4: getitem 505,1; break;
			case 5: getitem 506,1; break;     
			case 6: getitem 507,1; break;    
			case 7: getitem 508,1; break;    
			case 8: getitem 19972,1; break;  
			case 9: getitem 35065,1; break;
			case 10: getitem 35066,1; break;   
			case 11: getitem 35067,1; break;    
			case 12: getitem 35068,1; break;    
			case 13: getitem 20145,1; break;    
			case 14: getitem 35069,1; break;    
			case 15: getitem 35070,1; break;    
			case 16: getitem 35071,1; break;    

		}
		
		close2;
		cutin "",255;
		end;
		
	case 2:
	mes "[^FFA500Roleta da Sorte^000000]";
			query_sql("SELECT char_id, CAST(`value` AS SIGNED) FROM `char_reg_num` WHERE `key` = 'Roleta' ORDER BY CAST(`value` AS SIGNED) DESC LIMIT 20",.@cid,.@value);
			for(set .@i,0; .@i<getarraysize(.@cid); set .@i,.@i+1) {
				query_sql("SELECT `name` FROM `char` WHERE char_id = "+.@cid[.@i]+";",.@j$);
				set .@name$[.@i], .@j$;
			}
			if (!getarraysize(.@cid))
				mes "As classificações estão vazias.";
			else for(set .@i,0; .@i<getarraysize(.@cid); set .@i,.@i+1)
			mes "^FF0000["+(.@i+1)+"]^000000 ^0000FF"+.@name$[.@i]+"^000000 Jogou ^008000"+.@value[.@i]+" Vezes.^000000";
			close;
	
	case 3:
        mes "[^FFA500Roleta da Sorte^000000]";
        mes "Volte quando quiser jogar.";
    close;
    }
    
    
    OnInit:
        setarray .roulette$,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16;
        .roulette_size = getarraysize( .roulette$ );
		
		waitingroom "ROLETA DA SORTE",0,"",0;
		
        end;
        
SemFicha:
	mes "[^FFA500Roleta da Sorte^000000]";
	mes "Compre uma Ficha na Loja Rops para poder jogar.";
close;
}
