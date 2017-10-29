#define _count

new
	bool:VSL_count[MAX_PLAYERS] = false,
	VSL_TIME_COUNT[MAX_PLAYERS],
	VSL_ALL_TIME,
	bool:VSL_ALL_COUNT = false;

#define IsCountDownAll() VSL_ALL_COUNT
#define IsCountDownPlayer(%0) VSL_count[%0]
	
forward DownCountDown(playerid, style, const function[]);
forward AllDownCountDown(style, const function[]);

stock CreatePlayerCountDown(playerid, time, style, const function[])
{
	if(VSL_count[playerid]) return print("**WARING** Error countdown");

	new
		str[70];
	VSL_TIME_COUNT[playerid] = time;
	VSL_count[playerid] = true;
	format(str, sizeof(str), "Decompte : %ds", time);
	GameTextForPlayer(playerid, str, 3600, style)
	SetTimerEx("DownCountDown", 3600, false, "iis", playerid, style, function);
	return 1;
}
public DownCountDown(playerid, style, const function[])
{
	if(VSL_TIME_COUNT[playerid] == 0)
		{VSL_count[playerid] = false; return CallRemoteFunction(function, "i", playerid);}
	new
		str[70];
		
	VSL_TIME_COUNT[playerid]--;
	
	format(str, sizeof(str), "Decompte : %ds", VSL_TIME_COUNT[playerid]);
	GameTextForPlayer(playerid, str, 3600, style);
	SetTimerEx("DownCountDown", 3600, false, "is", playerid, function);
	return 1;
}
stock CreateAllCountDown(time, style, const function[])
{
	if(VSL_ALL_COUNT) return print("**WARNING** Countdown all used");
	
	VSL_ALL_TIME = time;
	
	new
		str[70];
	format(str, sizeof(str), "Décompte : %ds", VSL_ALL_TIME);
	GameTextForAll(str, 3600, style);
	SetTimerEx("AllDownCountDown", 3600, false, "is", style, function);
	return 1;
}
public AllDownCountDown(style, const function[])
{
	if(VSL_ALL_TIME == 0)
		{VSL_ALL_COUNT = false; return CallRemoteFunction(function, "");}
		
	VSL_ALL_TIME--;
	
	new
		str[70];
	format(str, sizeof(str), "Décompte : %ds", VSL_ALL_TIME);
	GameTextForAll(str, 3600, style);
	SetTimerEx("AllDownCountDown", 3600, false, "s", function);
	return 1;
}