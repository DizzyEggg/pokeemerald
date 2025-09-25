MansionFloor2Entrance_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, MansionFloor2Entrance_OnFrame
	.byte 0
    
MansionFloor2Entrance_OnFrame:
	map_script_2 VAR_FLOOR2_ENTRANCE_STATE, 0, MansionFloor2Entrance_RandomizeEnemies
	.2byte 0
    
MansionFloor2Entrance_RandomizeEnemies:
    lockall
    callnative ChooseRandomFloorMons
    setvar VAR_FLOOR2_ENTRANCE_STATE, 1
    releaseall
    end