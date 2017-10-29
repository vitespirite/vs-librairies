#include <a_samp>

#define _count

new
	bool:VSL_count[MAX_PLAYERS] = false,
	VSL_TIME_COUNT[MAX_PLAYERS];
	
forward DownCountDown(playerid, style, const function[]);

stock CreatePlayerCountDown(playerid, time, color, style, function)
{
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
		return CallRemoteFunction(function, "i", playerid);
	new
		str[70];
		
	VSL_TIME_COUNT[playerid]--;
	format(str, sizeof(str), "Decompte : %ds", VSL_TIME_COUNT[playerid]);
	GameTextForPlayer(playerid, str, 3600, style);
	SetTimerEx("DownCountDown", 3600, false, "is", playerid, function);
	return 1;
}
	