/*
		Fichier : vsl_tdmsg.inc
		
		Created by : Vitespirite
			Date : 28/10/2017
*/

#define _tdmsg

new
	// Text:VS_All_MSG[2],
	PlayerText:VS_Player_MSG[MAX_PLAYERS][2];
	
forward HideTextDrawPlayerMessage(playerid);
	
stock SendPlayerTextDrawMessage(playerid, const title[], const msg[], color_title, color_msg, color_box, time_hide)
{
	VS_Player_MSG[playerid][0] = CreatePlayerTextDraw(playerid, 101.185943, 230.833251, msg);
	PlayerTextDrawLetterSize(playerid, VS_Player_MSG[playerid][0], 0.400000, 1.600000);
	PlayerTextDrawTextSize(playerid, VS_Player_MSG[playerid][0], 0.000000, 123.000000);
	PlayerTextDrawAlignment(playerid, VS_Player_MSG[playerid][0], 2);
	PlayerTextDrawColor(playerid, VS_Player_MSG[playerid][0], color_msg);
	PlayerTextDrawUseBox(playerid, VS_Player_MSG[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, VS_Player_MSG[playerid][0], color_box);
	PlayerTextDrawSetShadow(playerid, VS_Player_MSG[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, VS_Player_MSG[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, VS_Player_MSG[playerid][0], 255);
	PlayerTextDrawFont(playerid, VS_Player_MSG[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, VS_Player_MSG[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, VS_Player_MSG[playerid][0], 0);

	VS_Player_MSG[playerid][1] = CreatePlayerTextDraw(playerid, 40.746734, 208.666641, title);
	PlayerTextDrawLetterSize(playerid, VS_Player_MSG[playerid][1], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, VS_Player_MSG[playerid][1], 1);
	PlayerTextDrawColor(playerid, VS_Player_MSG[playerid][1], color_title);
	PlayerTextDrawSetShadow(playerid, VS_Player_MSG[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, VS_Player_MSG[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, VS_Player_MSG[playerid][1], 255);
	PlayerTextDrawFont(playerid, VS_Player_MSG[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, VS_Player_MSG[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, VS_Player_MSG[playerid][1], 0);
	
	PlayerTextDrawShow(playerid, VS_Player_MSG[playerid][0]);
	PlayerTextDrawShow(playerid, VS_Player_MSG[playerid][1]);
	
	SetTimerEx("HideTextDrawPlayerMessage", time_hide, false, "i", playerid);
	return 1;
}
public HideTextDrawPlayerMessage(playerid)
{
	PlayerTextDrawHide(playerid, VS_Player_MSG[playerid][0]);
	PlayerTextDrawHide(playerid, VS_Player_MSG[playerid][1]);
	return 1;
}
