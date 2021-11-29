# easyDialog

The purpose of this include is to make dialogs easier to use in general.

Imagine having over 100 dialog checks under OnDialogResponse. It's just too messy and most of the time, it's unorganized and harder to look for certain dialogs for future editing, and remembering certain dialog ID's can be a pain in the ass.

However, easyDialog.inc fixes that by introducing a "named dialog feature" which allows scripters to declare a dialog by name, rather than ID.

| Feature                      | OnDialogResponse | easyDialog.inc |
|------------------------------|:----------------:|:--------------:|
| Crash Proof                  |        No        |       Yes      |
| Named Dialogs                |        No        |       Yes      |
| Calling a dialog manually    |        No        |       Yes      |
| Custom callback for handling |        No        |       Yes      |
| Fake Dialog                  |        No        |       Yes      |

## Functions

Show dialog to player

```pawn
Dialog_Show(playerid, dialog, style, caption[], info[], button1[], button2[]);
```

Show format dialog to player

```pawn
Dialog_ShowEx(playerid, dialog, style, caption[], info[], button1[], button2[], ...);
```

Show pages dialog to player

```pawn
Dialog_ShowPages(playerid, dialog, style, caption[], info[], button1[], button2[]);
```
* style
    * DIALOG_STYLE_LIST
    * DIALOG_STYLE_TABLIST
    * DIALOG_STYLE_TABLIST_HEADERS
    
## Important
   always use '\n' it at the end! 

Show format pages dialog to player
```pawn
Dialog_ShowPagesEx(playerid, dialog, style, caption[], info[], button1[], button2[], ...);
```
![Capture](https://user-images.githubusercontent.com/72431287/143889707-a718aa8f-5def-4790-95a2-213d40d61f61.PNG)
![Capture](https://user-images.githubusercontent.com/72431287/143889750-29343d4d-34c3-470a-b1d5-601f7e3cda9a.PNG)
![Capture](https://user-images.githubusercontent.com/72431287/143889800-bd18d443-6d51-4c56-a362-a2555591944c.PNG)


Closes any opened dialogs.

```pawn
Dialog_Close(playerid);
```

Returns 1 if the dialog is opened for the specified player.

```pawn
Dialog_Opened(playerid);
```

## Example

```pawn
CMD:weapons(playerid, params[])
{
    Dialog_Show(playerid, WeaponMenu, DIALOG_STYLE_LIST, "Weapon Menu", "9mm\nSilenced 9mm\nDesert Eagle\nShotgun\nSawn-off Shotgun\nCombat Shotgun", "Select", "Cancel");
    return 1;
}

Dialog:WeaponMenu(playerid, response, listitem, inputtext[])
{
    if (response)
    {
        new str[64];
        format(str, 64, "You have selected the '%s'.", inputtext);

        GivePlayerWeapon(playerid, listitem + 22, 500);
        SendClientMessage(playerid, -1, str);
    }
    return 1;
}

CMD:vehicles(playerid, params[]) {
    Dialog_Show(playerid, vehicles, DIALOG_STYLE_LIST, "Weapon Menu", "Infernus\nSultan\nBullet\nInfernus\nSultan\nBullet\nInfernus\nSultan\nBullet\nMaverick\nShamal", "Select", "Cancel");
    return 1;
}

Dialog:vehicles(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new str[64];
    format(str, 64, "You have selected the '%s' and id %d.", inputtext, listitem);
    SendClientMessage(playerid, -1, str);
    return 1;
}
```

## Credits
* Creator: HPQ123
* Tester: IonchyAdv
