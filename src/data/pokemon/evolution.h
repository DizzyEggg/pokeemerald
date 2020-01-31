const struct Evolution gEvolutionTable[NUM_SPECIES][EVOS_PER_MON] =
{
    [SPECIES_BULBASAUR]  = {{EVO_LEVEL, 16, SPECIES_IVYSAUR}},
    [SPECIES_IVYSAUR]    = {{EVO_LEVEL, 32, SPECIES_VENUSAUR}},
    [SPECIES_CHARMANDER] = {{EVO_LEVEL, 16, SPECIES_CHARMELEON}},
    [SPECIES_CHARMELEON] = {{EVO_LEVEL, 36, SPECIES_CHARIZARD}},
    [SPECIES_SQUIRTLE]   = {{EVO_LEVEL, 16, SPECIES_WARTORTLE}},
    [SPECIES_WARTORTLE]  = {{EVO_LEVEL, 36, SPECIES_BLASTOISE}},
    [SPECIES_SNIVY]   = {{EVO_LEVEL,  7, SPECIES_SERVINE}},
    [SPECIES_SERVINE]    = {{EVO_LEVEL, 10, SPECIES_SERPERIOR}},
    [SPECIES_WEEDLE]     = {{EVO_LEVEL,  7, SPECIES_KAKUNA}},
    [SPECIES_KAKUNA]     = {{EVO_LEVEL, 10, SPECIES_BEEDRILL}},
    [SPECIES_PIDGEY]     = {{EVO_LEVEL, 18, SPECIES_PIDGEOTTO}},
    [SPECIES_PIDGEOTTO]  = {{EVO_LEVEL, 36, SPECIES_PIDGEOT}},
    [SPECIES_RATTATA]    = {{EVO_LEVEL, 20, SPECIES_RATICATE}},
    [SPECIES_NOIBAT]    = {{EVO_LEVEL, 20, SPECIES_NOIVERN}},
    [SPECIES_EKANS]      = {{EVO_LEVEL, 22, SPECIES_ARBOK}},
    [SPECIES_PIKACHU]    = {{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_RAICHU}},
    [SPECIES_SANDSHREW]  = {{EVO_LEVEL, 22, SPECIES_SANDSLASH}},
    [SPECIES_NIDORAN_F]  = {{EVO_LEVEL, 16, SPECIES_NIDORINA}},
    [SPECIES_NIDORINA]   = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_NIDOQUEEN}},
    [SPECIES_NIDORAN_M]  = {{EVO_LEVEL, 16, SPECIES_NIDORINO}},
    [SPECIES_NIDORINO]   = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_NIDOKING}},
    [SPECIES_CLEFAIRY]   = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_CLEFABLE}},
    [SPECIES_VULPIX]     = {{EVO_ITEM, ITEM_FIRE_STONE, SPECIES_NINETALES}},
    [SPECIES_FROAKIE] = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_FROGADIER}},
    [SPECIES_GRENINJA]      = {{EVO_LEVEL, 22, SPECIES_BONDED_GRENINJA}},
    [SPECIES_BONDED_GRENINJA]     = {{EVO_FRIENDSHIP, 0, SPECIES_MIMIKYU}},
    [SPECIES_ROWLET]     = {{EVO_LEVEL, 21, SPECIES_DARTRIX}},
    [SPECIES_DARTRIX]      = {{EVO_ITEM, ITEM_LEAF_STONE, SPECIES_DECIDUEYE},
                            {EVO_ITEM, ITEM_SUN_STONE, SPECIES_TREVENANT}},
    [SPECIES_BIDOOF]      = {{EVO_LEVEL, 24, SPECIES_BIBAREL}},
    [SPECIES_VENONAT]    = {{EVO_LEVEL, 31, SPECIES_VENOMOTH}},
    [SPECIES_KARRABLAST]    = {{EVO_LEVEL, 26, SPECIES_ESCAVALIER}},
    [SPECIES_TYRUNT]     = {{EVO_LEVEL, 28, SPECIES_TYRANTRUM}},
    [SPECIES_COMBEE]    = {{EVO_LEVEL, 33, SPECIES_VESPIQUEEN}},
    [SPECIES_PURRLOIN]     = {{EVO_LEVEL, 28, SPECIES_LIEPARD}},
    [SPECIES_GROWLITHE]  = {{EVO_ITEM, ITEM_FIRE_STONE, SPECIES_ARCANINE}},
    [SPECIES_PIDOVE]    = {{EVO_LEVEL, 25, SPECIES_TRANQUILL}},
    [SPECIES_TRANQUILL]  = {{EVO_ITEM, ITEM_WATER_STONE, SPECIES_UNFEZANT},
                            {EVO_TRADE_ITEM, ITEM_KINGS_ROCK, SPECIES_GABITE}},
    [SPECIES_ABRA]       = {{EVO_LEVEL, 16, SPECIES_KADABRA}},
    [SPECIES_KADABRA]    = {{EVO_TRADE, 0, SPECIES_ALAKAZAM}},
    [SPECIES_SCATTERBUG]     = {{EVO_LEVEL, 28, SPECIES_SPEWPA}},
    [SPECIES_SPEWPA]    = {{EVO_TRADE, 0, SPECIES_VIVILLON}},
    [SPECIES_VENIPEDE] = {{EVO_LEVEL, 21, SPECIES_WHIRLIPEDE}},
    [SPECIES_WHIRLIPEDE] = {{EVO_ITEM, ITEM_LEAF_STONE, SPECIES_SCOLIPEDE}},
    [SPECIES_TENTACOOL]  = {{EVO_LEVEL, 30, SPECIES_TENTACRUEL}},
    [SPECIES_ESPURR]    = {{EVO_LEVEL, 25, SPECIES_MEOWSTIC_M}},
    [SPECIES_MEOWSTIC_M]   = {{EVO_TRADE, 0, SPECIES_MEOWSTIC_F}},
    [SPECIES_PONYTA]     = {{EVO_LEVEL, 40, SPECIES_RAPIDASH}},
    [SPECIES_VULLABY]   = {{EVO_LEVEL, 37, SPECIES_MANDIBUZZ},
                            {EVO_TRADE_ITEM, ITEM_KINGS_ROCK, SPECIES_GLACEON}},
    [SPECIES_MAGNEMITE]  = {{EVO_LEVEL, 30, SPECIES_MAGNETON}},
    [SPECIES_ROTOM]      = {{EVO_LEVEL, 31, SPECIES_LILLIPUP}},
    [SPECIES_HERDIER]       = {{EVO_LEVEL, 34, SPECIES_STOUTLAND}},
    [SPECIES_MUDBRAY]     = {{EVO_LEVEL, 38, SPECIES_MUDSDALE}},
    [SPECIES_DUCKLETT]   = {{EVO_ITEM, ITEM_WATER_STONE, SPECIES_SWANNA}},
    [SPECIES_GASTLY]     = {{EVO_LEVEL, 25, SPECIES_HAUNTER}},
    [SPECIES_HAUNTER]    = {{EVO_TRADE, 0, SPECIES_GENGAR}},
    [SPECIES_ONIX]       = {{EVO_TRADE_ITEM, ITEM_METAL_COAT, SPECIES_STEELIX}},
    [SPECIES_RUFFLET]    = {{EVO_LEVEL, 26, SPECIES_BRAVIARY}},
    [SPECIES_KRABBY]     = {{EVO_LEVEL, 28, SPECIES_KINGLER}},
    [SPECIES_SCRAGGY]    = {{EVO_LEVEL, 30, SPECIES_SCRAFTY}},
    [SPECIES_CUBCHOO]  = {{EVO_ITEM, ITEM_LEAF_STONE, SPECIES_BEARTIC}},
    [SPECIES_CUBONE]     = {{EVO_LEVEL, 28, SPECIES_MAROWAK}},
    [SPECIES_DIGGERSBY]    = {{EVO_LEVEL, 35, SPECIES_BONDED_BEARTIC}},
    [SPECIES_RHYHORN]    = {{EVO_LEVEL, 42, SPECIES_RHYDON}},
    [SPECIES_CHANSEY]    = {{EVO_FRIENDSHIP, 0, SPECIES_BLISSEY}},
    [SPECIES_BUIZEL]     = {{EVO_LEVEL, 32, SPECIES_FLOATZEL}},
    [SPECIES_FLOATZEL]     = {{EVO_TRADE_ITEM, ITEM_DRAGON_SCALE, SPECIES_HOUNDREAD}},
    [SPECIES_DRILLBUR]    = {{EVO_LEVEL, 33, SPECIES_EXCADRILL}},
    [SPECIES_STARYU]     = {{EVO_ITEM, ITEM_WATER_STONE, SPECIES_STARMIE}},
    [SPECIES_SCYTHER]    = {{EVO_TRADE_ITEM, ITEM_METAL_COAT, SPECIES_SCIZOR}},
    [SPECIES_MAGIKARP]   = {{EVO_LEVEL, 20, SPECIES_GYARADOS}},
    [SPECIES_EEVEE]      = {{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_JOLTEON},
                            {EVO_ITEM, ITEM_WATER_STONE, SPECIES_VAPOREON},
                            {EVO_ITEM, ITEM_FIRE_STONE, SPECIES_FLAREON},
                            {EVO_FRIENDSHIP_DAY, 0, SPECIES_ESPEON},
                            {EVO_FRIENDSHIP_NIGHT, 0, SPECIES_UMBREON}},
    [SPECIES_PORYGON]    = {{EVO_TRADE_ITEM, ITEM_UP_GRADE, SPECIES_PORYGON2}},
    [SPECIES_SKORUPI]    = {{EVO_LEVEL, 40, SPECIES_DRAPION}},
    [SPECIES_SKRELP]     = {{EVO_LEVEL, 40, SPECIES_DRAGALGE}},
    [SPECIES_GOOMY]    = {{EVO_LEVEL, 30, SPECIES_SLIGGOO}},
    [SPECIES_SLIGGOO]  = {{EVO_LEVEL, 55, SPECIES_GOODRA}},
    [SPECIES_SNOVER]  = {{EVO_LEVEL, 16, SPECIES_ABOMASNOW}},
    [SPECIES_ABOMASNOW]    = {{EVO_LEVEL, 32, SPECIES_ABOMACIER}},
    [SPECIES_CYNDAQUIL]  = {{EVO_LEVEL, 14, SPECIES_QUILAVA}},
    [SPECIES_QUILAVA]    = {{EVO_LEVEL, 36, SPECIES_TYPHLOSION}},
    [SPECIES_BASCULIN]   = {{EVO_LEVEL, 18, SPECIES_WIMPOD}},
    [SPECIES_WIMPOD]   = {{EVO_LEVEL, 30, SPECIES_GOLISOPOD}},
    [SPECIES_SENTRET]    = {{EVO_LEVEL, 15, SPECIES_FURRET}},
    [SPECIES_FERROSEED]   = {{EVO_LEVEL, 20, SPECIES_FERROTHORN}},
    [SPECIES_CLAUNCHER]     = {{EVO_LEVEL, 18, SPECIES_CLAWITZER}},
    [SPECIES_SPINARAK]   = {{EVO_LEVEL, 22, SPECIES_ARIADOS}},
    [SPECIES_CHINCHOU]   = {{EVO_LEVEL, 27, SPECIES_LANTURN}},
    [SPECIES_SEWADDLE]      = {{EVO_FRIENDSHIP, 0, SPECIES_PIKACHU}},
    [SPECIES_SWADLOON]     = {{EVO_FRIENDSHIP, 0, SPECIES_CLEFAIRY}},
    [SPECIES_LEAVANNY]  = {{EVO_FRIENDSHIP, 0, SPECIES_FROAKIE}},
    [SPECIES_TOGEPI]     = {{EVO_FRIENDSHIP, 0, SPECIES_TOGETIC}},
    [SPECIES_TOGEKISS]       = {{EVO_LEVEL, 25, SPECIES_PHANTUMP}},
    [SPECIES_MAREEP]     = {{EVO_LEVEL, 15, SPECIES_FLAAFFY}},
    [SPECIES_FLAAFFY]    = {{EVO_LEVEL, 30, SPECIES_AMPHAROS}},
    [SPECIES_MARILL]     = {{EVO_LEVEL, 18, SPECIES_AZUMARILL}},
    [SPECIES_GARCHOMP]     = {{EVO_LEVEL, 18, SPECIES_HONEDGE}},
    [SPECIES_HONEDGE]   = {{EVO_LEVEL, 27, SPECIES_DOUBLADE}},
    [SPECIES_SCIMITEYE]    = {{EVO_ITEM, ITEM_SUN_STONE, SPECIES_JAWGUILE}},
    [SPECIES_WOOPER]     = {{EVO_LEVEL, 20, SPECIES_QUAGSIRE}},
    [SPECIES_JOLTIK]     = {{EVO_LEVEL, 31, SPECIES_GALVANTULA}},
    [SPECIES_POPPLIO]   = {{EVO_LEVEL, 23, SPECIES_BRIONNE}},
    [SPECIES_TEDDIURSA]  = {{EVO_LEVEL, 30, SPECIES_URSARING}},
    [SPECIES_BRONZOR]     = {{EVO_LEVEL, 38, SPECIES_BRONZONG}},
    [SPECIES_SWINUB]     = {{EVO_LEVEL, 33, SPECIES_PILOSWINE}},
    [SPECIES_ZEKROM]   = {{EVO_LEVEL, 25, SPECIES_SHINX}},
    [SPECIES_HOUNDOUR]   = {{EVO_LEVEL, 24, SPECIES_HOUNDOOM}},
    [SPECIES_LITLEO]     = {{EVO_LEVEL, 25, SPECIES_PYROAR}},
    [SPECIES_TYROGUE]    = {{EVO_LEVEL_ATK_LT_DEF, 20, SPECIES_HITMONCHAN},
                            {EVO_LEVEL_ATK_GT_DEF, 20, SPECIES_HITMONLEE},
                            {EVO_LEVEL_ATK_EQ_DEF, 20, SPECIES_HITMONTOP}},
    [SPECIES_GOTHITA]   = {{EVO_LEVEL, 30, SPECIES_LARVESTA}},
    [SPECIES_GOTHORITA]     = {{EVO_LEVEL, 30, SPECIES_VOLCARONA}},
    [SPECIES_GOTHITELLE]      = {{EVO_LEVEL, 30, SPECIES_FOONGUS}},
    [SPECIES_LARVITAR]   = {{EVO_LEVEL, 30, SPECIES_PUPITAR}},
    [SPECIES_PUPITAR]    = {{EVO_LEVEL, 55, SPECIES_TYRANITAR}},
    [SPECIES_TREECKO]    = {{EVO_LEVEL, 16, SPECIES_GROVYLE}},
    [SPECIES_GROVYLE]    = {{EVO_LEVEL, 36, SPECIES_SCEPTILE}},
    [SPECIES_TORCHIC]    = {{EVO_LEVEL, 16, SPECIES_COMBUSKEN}},
    [SPECIES_COMBUSKEN]  = {{EVO_LEVEL, 36, SPECIES_BLAZIKEN}},
    [SPECIES_MUDKIP]     = {{EVO_LEVEL, 16, SPECIES_MARSHTOMP}},
    [SPECIES_MARSHTOMP]  = {{EVO_LEVEL, 36, SPECIES_SWAMPERT}},
    [SPECIES_POOCHYENA]  = {{EVO_LEVEL, 18, SPECIES_MIGHTYENA}},
    [SPECIES_ZIGZAGOON]  = {{EVO_LEVEL, 20, SPECIES_LINOONE}},
    [SPECIES_PETILIL]    = {{EVO_LEVEL_LILLIGANT, 7, SPECIES_LILLIGANT},
                            {EVO_LEVEL_WHIMSICOTT, 7, SPECIES_WHIMSICOTT}},
    [SPECIES_LILLIGANT]    = {{EVO_LEVEL, 10, SPECIES_COTTONEE}},
    [SPECIES_WHIMSICOTT]    = {{EVO_LEVEL, 10, SPECIES_SOLOSIS}},
    [SPECIES_DUOSION]      = {{EVO_LEVEL, 14, SPECIES_REUNICLUS}},
    [SPECIES_REUNICLUS]     = {{EVO_ITEM, ITEM_WATER_STONE, SPECIES_PANCHAM}},
    [SPECIES_PANGORO]     = {{EVO_LEVEL, 14, SPECIES_MIENFOO}},
    [SPECIES_MIENFOO]    = {{EVO_ITEM, ITEM_LEAF_STONE, SPECIES_MIENSHAO}},
    [SPECIES_AMAURA]    = {{EVO_LEVEL_AURORUS, 20, SPECIES_AURORUS},
                            {EVO_LEVEL_DIALGA, 20, SPECIES_DIALGA}},
    [SPECIES_TAILLOW]    = {{EVO_LEVEL, 22, SPECIES_SWELLOW}},
    [SPECIES_SHROOMISH]  = {{EVO_LEVEL, 23, SPECIES_BRELOOM}},
    [SPECIES_WINGULL]    = {{EVO_LEVEL, 25, SPECIES_PELIPPER}},
    [SPECIES_RIOLU]    = {{EVO_LEVEL, 22, SPECIES_LUCARIO}},
    [SPECIES_WAILMER]    = {{EVO_LEVEL, 40, SPECIES_WAILORD}},
    [SPECIES_SKITTY]     = {{EVO_ITEM, ITEM_MOON_STONE, SPECIES_DELCATTY}},
    [SPECIES_BOLDORE]     = {{EVO_LEVEL, 36, SPECIES_GIGALITH}},
    [SPECIES_LITWICK]   = {{EVO_LEVEL, 30, SPECIES_LAMPENT}},
    [SPECIES_CORPHISH]   = {{EVO_LEVEL, 30, SPECIES_CRAWDAUNT}},
    [SPECIES_FEEBAS]     = {{EVO_BEAUTY, 170, SPECIES_MILOTIC}},
    [SPECIES_CARVANHA]   = {{EVO_LEVEL, 30, SPECIES_SHARPEDO}},
    [SPECIES_TRAPINCH]   = {{EVO_LEVEL, 35, SPECIES_VIBRAVA}},
    [SPECIES_VIBRAVA]    = {{EVO_LEVEL, 45, SPECIES_FLYGON}},
    [SPECIES_DWEBBLE]   = {{EVO_LEVEL, 24, SPECIES_CRUSTLE}},
    [SPECIES_ELECTRIKE]  = {{EVO_LEVEL, 26, SPECIES_MANECTRIC}},
    [SPECIES_MANETHUNDR]      = {{EVO_LEVEL, 33, SPECIES_PORYGONZ}},
    [SPECIES_TYNAMO]     = {{EVO_LEVEL, 32, SPECIES_EELEKTRIK}},
    [SPECIES_EELEKTRIK]     = {{EVO_LEVEL, 44, SPECIES_EELEKTROSS}},
    [SPECIES_CACNEA]     = {{EVO_LEVEL, 32, SPECIES_CACTURNE}},
    [SPECIES_SNORUNT]    = {{EVO_LEVEL, 42, SPECIES_GLALIE}},
    [SPECIES_CARRACOSTA]    = {{EVO_FRIENDSHIP, 0, SPECIES_MARILL}},
    [SPECIES_SPOINK]     = {{EVO_LEVEL, 32, SPECIES_GRUMPIG}},
    [SPECIES_MEDITITE]   = {{EVO_LEVEL, 37, SPECIES_MEDICHAM}},
    [SPECIES_SWABLU]     = {{EVO_LEVEL, 35, SPECIES_ALTARIA}},
    [SPECIES_TIMBURR]     = {{EVO_LEVEL, 15, SPECIES_FLOETTE}},
    [SPECIES_GURDURR]    = {{EVO_LEVEL, 37, SPECIES_CONKELDURR}},
    [SPECIES_FLETCHLING]    = {{EVO_LEVEL, 18, SPECIES_FLETCHINDR}},
    [SPECIES_FLETCHINDR]   = {{EVO_LEVEL, 36, SPECIES_TALONFLAME}},
    [SPECIES_DARKRAI]     = {{EVO_LEVEL, 26, SPECIES_CRESSELIA}},
    [SPECIES_XERNEAS]    = {{EVO_LEVEL, 20, SPECIES_YVELTAL}},
    [SPECIES_YVELTAL]    = {{EVO_LEVEL, 40, SPECIES_ZYGARDE}},
    [SPECIES_AZELF]   = {{EVO_TRADE_ITEM, ITEM_DEEP_SEA_TOOTH, SPECIES_MESPRIT},
                            {EVO_TRADE_ITEM, ITEM_DEEP_SEA_SCALE, SPECIES_UXIE}},
    [SPECIES_SHUPPET]    = {{EVO_LEVEL, 37, SPECIES_BANETTE}},
    [SPECIES_ARON]       = {{EVO_LEVEL, 32, SPECIES_LAIRON}},
    [SPECIES_LAIRON]     = {{EVO_LEVEL, 42, SPECIES_AGGRON}},
    [SPECIES_LILEEP]     = {{EVO_LEVEL, 40, SPECIES_CRADILY}},
    [SPECIES_ANORITH]    = {{EVO_LEVEL, 40, SPECIES_ARMALDO}},
    [SPECIES_RALTS]      = {{EVO_LEVEL, 20, SPECIES_KIRLIA}},
    [SPECIES_KIRLIA]     = {{EVO_LEVEL, 30, SPECIES_GARDEVOIR}},
    [SPECIES_BAGON]      = {{EVO_LEVEL, 30, SPECIES_SHELGON}},
    [SPECIES_SHELGON]    = {{EVO_LEVEL, 50, SPECIES_SALAMENCE}},
    [SPECIES_BELDUM]     = {{EVO_LEVEL, 20, SPECIES_METANG}},
    [SPECIES_METANG]     = {{EVO_LEVEL, 45, SPECIES_METAGROSS}},
};
