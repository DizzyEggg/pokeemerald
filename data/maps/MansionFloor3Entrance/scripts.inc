MansionFloor3Entrance_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, MansionFloor3Entrance_OnFrame
	.byte 0
    
MansionFloor3Entrance_OnFrame:
	map_script_2 VAR_FLOOR3_ENTRANCE_STATE, 0, MansionFloor3Entrance_RandomizeEnemies
	.2byte 0
    
MansionFloor3Entrance_RandomizeEnemies:
    lockall
    callnative ChooseRandomFloorMons
    setvar VAR_FLOOR3_ENTRANCE_STATE, 1
    releaseall
    end
