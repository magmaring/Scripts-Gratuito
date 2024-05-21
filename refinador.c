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
prt_in,58,56,3	script	Mestre Ferreiro	4_M_DWARF,{
	function ShowChanceInfo; function ShowSecureInfo;
	function GetChanceBonus; function GetSecure;
	function ConsumeSecure; function Refine;
	function ConsumeChance;
	
	// Group requirement
	if (getgroupid() < .UseMinLv) {
		mes .npcname$;
		mes "Desculpa, mas nao posso te ajudar.";
		mes "Até logo.";
		close;
	}
	
	mes .npcname$;
	mes "Eu sou o Armsmith.";
	mes "Posso refinar todos os tipos de armas, armaduras e equipamentos sem quebrar, então deixe-me saber o que você quer refinar.";
	next;

	setarray .@position$[1], "Cabeça (Alto)","Vestimenta","Mão esquerda","Mão direita","Capa","Sapatos","Acessório Esquerdo","Acessório Direito","Cabeça (Meio)","Cabeça (Baixo)";
	set .@menu$, "";
	for(.@i = EQI_ACC_L; .@i <= EQI_HAND_R; .@i++) {
		if(getequipisequiped(.@i)) {
			.@menu$ += F_getpositionname(.@i) + " - " + "[" + getequipname(.@i) + "]";
			.@equipped = 1;
		}
		.@menu$ += ":";
	}
	if (.@equipped == 0) {
		mes .npcname$;
		mes "Eu não acho que posso refinar quaisquer itens que você tem ...";
		close;
	}
	// Get part to upgrade
	@part = select(.@menu$) -1;

	if(!getequipisequiped(@part)) {
		mes .npcname$;
		mes "Você não está vestindo nada lá que eu possa refinar.";
		emotion ET_FRET;
		close;
	}
	// Verificar se o item é refinável ...
	else if(!getequipisenableref(@part)) {
		mes .npcname$;
		mes "Esse equipamento não pode ser refinado.";
		close;
	}
	// Verifique se os itens já estão + MAX_REFINE
	else if(getequiprefinerycnt(@part) >= .MaxRefine) {
		mes .npcname$;
		mes "Eu não posso refinar isso mais. Isto é tão refinado como ele fica!";
		close;
	}
	
	// Save some upgrade data
	@refId = getequipid(@part);					// item id
	@refCount = getequiprefinerycnt(@part);		// refine count
	@refLv = getequipweaponlv(@part);			// weapon level
	@price = .RefinePrices[@refLv];				// Refine Price
	@item = .RefineItems[@refLv];				// Refine Item
	@chance = getequippercentrefinery(@part); 	// Refine Chance
	@safe = .SafeLevels[@refLv];				// Safe limit
	.@refTimes = 1;
	
	if (.DisplayRefineInfo) {
		mes .npcname$;
		mes "Aqui estão algumas informações:";
		mes "Limite de segurança: " + @safe;
		
		ShowChanceInfo();
		ShowSecureInfo();
		next;
	}

	// Opção de refinamento múltiplo
	if (getgroupid() >= .MultipleRefineMinLv) {
		mes .npcname$;
		mes "Posso refinar esta vez, ou várias vezes, o que você diz?";
		next;
		switch(select("Refinar uma vez.:Refinar várias vezes.:Eu mudei de idéia.")) {
			case 1:
				.@refTimes = 1;
			break;
			
			case 2:
				if (.BreakWarning == 1)
					.@warningShown = 1;
					
				mes .npcname$;
				mes "Muito bem, quantas vezes você deseja refinar este item?";
				next;
				do {
					input .@refTimes;
					if (.@refTimes <= 0 || (.@refTimes + @refCount) > .MaxRefine) {
						mes .npcname$;
						mes "Ei, eu não posso refinar este item muito!";
						next;
						mes .npcname$;
						mes "Tente novamente.";
						next;
					}
					else {
						break;
					}
				} while(true);
			break;
			
			case 3:
				mes .npcname$;
				mes "Ok, volte quando precisar dos meus serviços.";
				close;
		}
	}
	
	.@totalPrice = @price * .@refTimes;
	
	mes .npcname$;
	mes "Para refinar isso eu preciso de";
	mes .@refTimes + " ^A020F0"+getitemname(@item)+"^000000 e uma taxa de";
	mes "serviço de ^228B22" + .@totalPrice + "^000000 Zeny.";
	mes "Você realmente deseja continuar?";
	next;
	if (select("Sim:Não") == 2) {
		mes .npcname$;
		mes "Yeah...";
		mes "Não há necessidade de correr. Não tenha pressa.";
		close;
	}
	else if((countitem(@item) < .@refTimes) || (Zeny < .@totalPrice)) {
		// Não pode pagar
		mes .npcname$;
		mes "Você não parece ter suficiente Zeny ou ^A020F0"+getitemname(@item)+"^000000...";
		mes "Vá buscar mais. Estarei aqui o dia inteiro se precisar de mim.";
		close;
	}
	
	.@refResult = false;								// Refine result
	useSecure = -1;										// secure item usage
	useChance = -1;										// chance item usage
	for (.@i = 0; .@i < .@refTimes; .@i++) {
		@secId = GetSecure();
		@refCount = getequiprefinerycnt(@part);			// refine count
		@chance = getequippercentrefinery(@part);		// Refine Chance
		
		if (@secId && ConsumeSecure()) {
			if (!countitem(@secId)) {
				@secId = 0;
				useSecure = false;
			}
			else if (countitem(@secId) && ((.SecureAsk == 1) || (.SecureAsk == 2 && useSecure == -1))) {
				mes .npcname$;
				mes "Parece que você tem " + getitemname(@secId) + ".";
				mes "Deseja usá-lo para proteger seu item?";
				next;
				if (select("Sim:Não") == 1)
					useSecure = true;
				else
					useSecure = false;
				mes .npcname$;
				mes "Tudo certo!";
				next;
			}
		}
		
		GetChanceBonus();
		if (@bonusId && ConsumeChance()) {
			if (!countitem(@bonusId)) {
				@bonusId = 0;
				@bonus = 0;
				useChance = false;
			}
			else if ((.ChanceAsk == 1) || (.ChanceAsk == 2 && useChance == -1)) {
				mes .npcname$;
				mes "Parece que você tem " + getitemname(@bonusId) + ".";
				mes "Você quer usá-lo para aumentar sua taxa de sucesso?";
				next;
				if (select("Sim:Não") == 1)
					useChance = true;
				else
					useChance = false;
				mes .npcname$;
				mes "All right";
				next;
			}
		}
		
		if (((@chance + @bonus) < 95) && useSecure != true && (.BreakWarning == 0 || (.BreakWarning > 0 && .@warningShown == 0))) {
			mes .npcname$;
			mes "Ah não! Se eu refinar isso novamente, há o risco de voltar a zero!";
			mes "Isso significa que se eu falhar, o refino desse equipamento voltará a zero.";
			next;
			mes .npcname$;
			mes "Você ainda quer continuar?";
			next;
			if (select("Sim:Não") == 2) {
				mes .npcname$;
				mes "Eu concordo completamente...";
				mes "Eu poderia ser um ótimo refinador, mas às vezes até cometo erros.";
				close;
			}
			.@warningShown = 1;
		}
		
		.@refineRes = Refine();
		if (.@refineRes) {
			.@refineCount++;
		}
	}

	if (! .@refineRes) {
		mes .npcname$;
		mes "Bem, não foi um trabalho perfeito, mas pelo menos seus itens estão em boa forma!";
		close;
	}
	
	mes .npcname$;
	successrefitem .@part;
		emotion ET_SMILE;
	.@win = rand(1,3);
	if (.@win == 1) {
		mes "Perfeito!";
		mes "Heh heh!";
		mes "Mais uma vez, o trabalho impecável do mestre.";
	} else if(.@win == 2) {
		mes "Sucesso...!";
		mes "Mais uma vez, meu incrível talento realmente deslumbra e brilha hoje.";
	} else {
		mes "Heh heh!";
		mes "Estou pronto.";
		mes "Sem dúvida, meu trabalho é para sua satisfação.";
		mes "Perfeição pura, absoluta.";
	}
	close;

	// Refine ()
	// Tenta refinar item em @part
	function Refine {
		// verificações personalizadas
		if(getequipisequiped(@part) == 0) { // Hacker removeu o item (não alterado, por quê?)
			mes .npcname$;
			mes "Olhe aqui... Você não tem nenhum item em...";
			close;
		}
		else if(getequiprefinerycnt(@part) != @refCount || getequipid(@part) != @refId) { // hacker mudou o item
			mes .npcname$;
			emotion ET_FRET;
			mes "Espere um segundo...";
			mes "Você acha que eu sou estúpido ?!";
			mes "Você mudou o item enquanto eu não estava olhando! Saia daqui!";
			close;
		}
		
		delitem @item, 1;
		Zeny -= @price;

		.@refineChance = @chance;
		
		if (useChance == true) {
			delitem @bonusId, 1;
			.@refineChance += @bonus;
		}
		
		if (.@refineChance <= rand(95)) {
			// Falhou
			if (useSecure == true) {
				delitem @secId, 1;
				downrefitem @part, 0;
				mes .npcname$;
				mes "Infelizmente falhou, mas pelo menos seu artigo está em uma boa forma, certo?";
				next;
			}
			else {
				.@failType = .FailResults[rand(getarraysize(.FailResults))];
				switch(.@failType) {
					// Item destruído
					case 0: failedrefitem @part; break;
					// -1 refine
					case 1: downrefitem @part, 1; break;
					// +0
					case 2: downrefitem @part, @refCount; break;
					// Stay as is
					case 3: downrefitem @part, 0; break;
				}

				mes .npcname$;
				emotion (!rand(5))?ET_MONEY:ET_HUK;
				
				if(.@failType == 1) {
					// -1
					mes "Porcaria!";
					mes "Não poderia ter muito mais temperamento!";
					mes "Desculpe por isto...";
					next;
				} else if (.@failType == 2) {
					// Down to +0
					mes "OH! MEU DEUS!";
					mes "Droga! De novo não!";
					mes "Eu sinto muito, mas você sabe que a prática faz perfeito.";
					mes "Huum, certo? Heh heh...";
					next;
				} else if (.@failType == 3) {
					// Nada
					mes "Infelizmente falhou, mas pelo menos seu item está em uma boa forma, certo?";
					return true;
				} else {
					// Pausa
					mes "Nooooooo!";
					mes "Quebrou!";
					mes "Eu-eu sinto muito!";
					close;
				}

				return false;
			}

		}
		else {
			// Secure - Consume always
			if (useSecure == true && ((.SecureConsumeType == 1 && .@refineChance < 95) || .SecureConsumeType == 2))
				delitem @secId, 1;
			successrefitem @part;
		}
		
		return true;
	}

	// ShowChanceInfo()
	// Exibe informações sobre refinar chances de sucesso e itens
	function ShowChanceInfo {
		GetChanceBonus(); 			// sets @bonus and @bonusId
		if (@bonusId && ((@chance >= 95 && .ChanceConsumeType > 0) || (@chance < 95))) {
			.@tChance = @chance + @bonus;
			mes "+" + (@refCount+1) +" Chance de Sucesso: ^228B22" + (.@tChance > 100 ? 95 : .@tChance) +"%^000000";
			mes "Item para Aumentar Chance:";
			mes "^A020F0" + getitemname(@bonusId) + "^000000 ^228B22(+"+@bonus+"%)^000000";
		}
		else {
			mes "+" + (@refCount+1) +" Chance de Sucesso: ^228B22" + @chance + "%^000000";
		}
	}

	// ShowSecureInfo()
	// Exibe informações sobre refinar itens seguros
	function ShowSecureInfo {
		.@secId = GetSecure();
		if (.@secId && ((@chance >= 95 && .SecureConsumeType > 0) || (@chance < 95))) {
			if (.SecureType == 0) {
				mes "Item de Proteger Refinamento:";
				mes "^A020F0" + getitemname(.@secId);
			}
			else if (.SecureType == 1) {
				mes "+"+@refCount+" Item de Proteger Refinamento: ^A020F0" + getitemname(.@secId);
			}
		}
	}

	// GetChanceBonus()
	// Recupera a chance eo item usado
	// e armazena em @bonus e @bonusId
	function GetChanceBonus {
		@bonus = 0; @bonusId = 0;
		if (.UseChanceItems) {
			@bonusId = .ChanceItems[@refLv * 2];
			if (@bonusId)
				@bonus = .ChanceItems[@refLv * 2 + 1];
		}
	}

	// <secId> GetSecure()
	// Recuperar as informações de segurança para este item
	// Retorna: o Item ID
	function GetSecure {
		if (.UseSecureItems) {
			if (.SecureType == 0) {													// Cada tipo de arma tem um item para protegê-lo
				return .SecureItems[@refLv];
			}
			else {																	// Cada nível de refinamento + tipo de item tem um item para protegê-lo
				if (@part == EQI_HAND_R || (@part == EQI_HAND_L && @wLvl > 0))						// Arma
					return .SecureItems[(.@curRef * 3)];
				else if (@part == EQI_HEAD_TOP || @part == EQI_HEAD_MID || @part == EQI_HEAD_LOW)	// Chapelaria
					return .SecureItems[(.@curRef * 3) + 1];
				else																				// Armadura
					return .SecureItems[(.@curRef * 3) + 2];
			}
		}
	}
	
	// ConsumeChance()
	// Verifica se ele pode consumir item casual
	function ConsumeChance {
		if (.UseChanceItems) {
			if ((.ChanceConsumeType > 0) || (@refCount >= @safe))
				return true;
		}
		return false;
	}
	
	// ConsumeSecure()
	// Verifica se ele pode consumir item seguro
	function ConsumeSecure {
		if (.UseSecureItems) {
			if ((.SecureConsumeType <= 1 && @refCount >= @safe) || .SecureConsumeType == 2)
				return true;
		}
		return false;
	}

	OnInit:
		// ======================
		// 		Configurações básicas
		// ======================
		.npcname$ = "^A020F0[Refinador]^000000";	// Nome do NPC para diálogos
		
		.UseMinLv = 0;							// Grupo de usuários mínimo para usar este NPC
		
		.MultipleRefineMinLv = 100;				// Grupo de usuários necessário para refinar mais de uma vez
												// de uma vez só
		
		.DisplayRefineInfo = true;				// O NPC deve exibir informações sobre
												// Refinar (como chance de sucesso)
									
		.UseSecureItems = false;					// Permite o uso de itens para proteger
												// De falha (consulte a matriz .SecureItems)
									
		.UseChanceItems = false;					// Permite o uso de itens que aumentam
												//A chance de sucesso (veja a matriz .ChanceItems)

		.MaxRefine = 10;						// O máximo refinar
		
		// Exibir a mensagem "O refinamento pode falhar e seu item será destruído"
		// 0 - Exibir sempre (quando chance é menor que 100% e refinar não é protegido por item)
		// 1 - Exibir somente por uma vez refina
		// 2 - Exibir para uma vez refina e uma vez para refinamentos múltiplos
		.BreakWarning = 1;
		
		// Efeitos de uma tentativa de refinamento com falha
		// Quando o refinamento falha, o que acontece com o item?
		// 0 - Item é destruído
		// 1 - Item desce 1 nível de refinação
		// 2 - Item desce para +0
		// 3 - Nada acontece
		//
		// Adicione os efeitos desejados a .FailResults, repita seu número
		// para aumentar a chance de que isso aconteça.
		//
		// Exemplos:
		// .FailResults [0], 0;				// item é destruído ao falhar
		// .FailResults [0], 0, 3;			// 50% de chance de ser destruído, 50% de chance de ficar como está
		// .FailResults [0], 0, 0, 1, 2;	//50% de chance de destruir, 25% para -1, 25% para ir para +0
		setarray .FailResults[0], 2;
		
		// Itens utilizados para refinar por Nível da Arma:
		setarray .RefineItems[0],
			7619,	// Elunium - Armor (Level 0)
			7620,	// Phracon - Level 1
			7620,	// Emveretarcon - Level 2
			7620,	// Oridecon - Level 3
			7620;	// Oridecon - Level 4
		
		// Preço em Z de nível de arma:
		setarray .RefinePrices[0],
			1000000,		// Armor (Level 0)
			1000000,		// Level 1
			1000000,		// Level 2
			1000000,		// Level 3
			1000000;		// Level 4
		
		// Nível de segurança por Nível da arma:
		setarray .SafeLevels[0],
			4,	// Armor (Level 0)
			7,	// Level 1
			6,	// Level 2
			5,	// Level 3
			4;	// Level 4
			
		// ======================
		// 		Refinar o Protetor
		// ======================
		if (.UseSecureItems)
		{
			// Essas configurações são usadas somente se .UseSecureItems for true.
			
			// Como os itens .SecureItems funcionarão?
			// 0 - Cada tipo de arma tem um item para protegê-lo
			// 1 - Cada nível de refinamento + tipo de item tem um item para protegê-lo
			.SecureType = 1;
			
			// Perguntar se quer usar um item seguro?
			// 0 - não perguntar (se o item é inventário, use-o)
			// 1 - Perguntar antes de cada tentativa de refinamento
			// 2 - Perguntar uma vez para todas as tentativas de refinamento
			// (ao refinar várias vezes, caso contrário funciona como 1)
			.SecureAsk = 1;
			
			// Como os itens seguros são consumidos?
			// 0 - Se ele vai quebrar, consumir.
			// 1 - Consumir sempre (exceto em refinamento seguro)
			// 2 - Consumir sempre (mesmo em refinamentos seguros)
			.SecureConsumeType = 0;
			
			// Itens utilizados para proteger o refinamento.
			// Estes são os itens consumidos ao
			// refinar, eles são consumidos de acordo com .SecureConsumeType;
			// Use 0 para não usar um item para este nível.
			// Se .SecureType for 0, cada item de array significa um nível de arma.
			// Se .SecureType for 1, cada três itens de matriz significa um refinar
			// nível, e segue a ordem
			// <weapon>, <headgear>, <armor>
			//
			// Configurar o array abaixo, de acordo com o seu .SecureType acima.
			//
			// Nota: Oficialmente não há Nível de Arma superior a 4,
			// estes valores existem lá principalmente para refinar a proteção,
			// mas pode ser usado para itens personalizados.
			
			if (.SecureType == 0)
			{ // If .SecureType is 0
				setarray .SecureItems[0],
					6395,		// Armor (Level 0)
					6395,		// Level 1
					6395,		// Level 2
					6395, 		// Level 3
					6395;		// Level 4
			}
			else
			{ // If .SecureType is 1
				// Tipos de Item:
				// Arma
				// Chapelaria
				// Armadura (Todas as armaduras exceto o capacete)
				setarray .SecureItems[0],
					501, 502, 503, // +0
					501, 502, 503, // +1
					501, 502, 503, // +2
					501, 502, 503, // +3
					501, 502, 503, // +4
					6456, 6457, 6457, // +5
					6231, 6235, 6235, // +6
					6230, 6234, 6234, // +7
					6229, 6233, 6233, // +8
					6228, 6232, 6232, // +9
					6993, 6994, 6994, // +10
					6238, 6239, 6239, // +11
					6584, 6585, 6585, // +12
					6870, 6876, 6876, // +13
					6871, 6877, 6877, // +14
					6872, 6878, 6878; // +15
			}
		}
		
		// ===============================
		// 		Refine Chance Increase
		// ===============================
		if (.UseChanceItems)
		{
			// Essas configurações são usadas somente se .UseChanceItems for true.

			// Como os Itens de Chance são consumidos?
			// 0 - Consumir se acima do nível seguro
			// 1 - Consumir sempre (mesmo em refinamentos seguros)
			.ChanceConsumeType = 0;
			
			// Pergunte se quer usar um item casual?
			// 0 - não perguntar (se o item é inventário, use-o)
			// 1 - Perguntar antes de cada tentativa de refinamento
			// 2 - Perguntar uma vez para todas as tentativas de refinamento
			// (ao refinar várias vezes, caso contrário funciona como 1)
			.ChanceAsk = 2;
			
			// Itens usados para aumentar o sucesso de refinamento eo aumento, por Nível de Arma.
			// Estes são os itens consumidos durante o refinamento para aumentar
			// a taxa de sucesso do refinamento, eles são consumidos de acordo com
			// .ChanceConsumeType;
			// Formato: <Item ID>, <Increase>
			// Um aumento de 1 é igual a 1% do total,
			// então se a taxa de sucesso for 80%, será 81%.
			// Use 0 como ID para não usar um item para este nível.
			setarray .ChanceItems[0],
				40728, 5,		// Armor (Level 0)
				40728, 4,		// Level 1
				40727, 3,		// Level 2
				40730, 2,	// Level 3
				40729, 1;	// Level 4
		}
	end;
}