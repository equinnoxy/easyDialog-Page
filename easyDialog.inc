

		 ///////////////////////////////////////////////////////////////////
		////		 new version easy dialog by HPQ123 (c) 2021		  /////
	   /////				 Discord: HPQ123#8114		    	      ////
	  //////					Creator: Emmet					      ///
	 ///////////////////////////////////////////////////////////////////


static __dName[MAX_PLAYERS][40 char],__dOpened[MAX_PLAYERS];

#define Dialog:%0(%1) 				forward dialog_%0(%1); public dialog_%0(%1)
#define Dialog_Opened(%0) 			__dOpened[%0]
#define Dialog_Show(%0,%1, 			__Dialog_(%0, #dialog%1,


stock Dialog_Close(playerid) 
	return ShowPlayerDialog(playerid, (__dOpened[playerid]=0)-1, DIALOG_STYLE_MSGBOX, " ", " ", " ", "");

stock __Dialog_(playerid, function[], style, caption[], info[], button1[], button2[])
	return (function[6]=95,strpack(__dName[playerid], function, 40 char)&(__dOpened[playerid]=ShowPlayerDialog(playerid, 31234, style, caption, info, button1, button2)));

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
	new x=-1;
	if dialogid == 31234 && __dName[playerid][0] != 'l' *then {
		while(inputtext[++x]) if inputtext[x] != '%' *then continue; else inputtext[x] = '#';
		CallLocalFunction(__dName[playerid], "iiis", playerid, response, listitem, (!inputtext[0]) ? ("\1") : (inputtext));
	}
	#if defined DR_OnDialogResponse
	    return DR_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
	    return false;
	#endif
}

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse DR_OnDialogResponse

#if defined DR_OnDialogResponse
	forward DR_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif