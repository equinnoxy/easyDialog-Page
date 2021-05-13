# easyDialog

### Note: You must use https://github.com/sampctl/samp-stdlib otherwise, you'll get more warnings!!

The purpose of this include is to make dialogs easier to use in general.

Imagine having over 100 dialog checks under OnDialogResponse. It's just too messy and most of the time, it's unorganized and harder to look for certain dialogs for future editing, and remembering certain dialog ID's can be a pain in the ass.

However, easyDialog.inc fixes that by introducing a "named dialog feature" which allows scripters to declare a dialog by name, rather than ID.

| Feature                      | OnDialogResponse | easyDialog.inc |
|------------------------------|:----------------:|:--------------:|
| Crash Proof                  |        No        |       Yes      |
| Named Dialogs                |        No        |       Yes      |
| Calling a dialog manually    |        No        |       Yes      |
| Custom callback for handling |        No        |       Yes      |

## Functions

Show dialog to player

```pawn
Dialog_Show(playerid, dialog, style, caption[], info[], button1[], button2[]);
```

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
```

## Credits
Emmet_ - for easyDialog
HPQ123 - for new version
Southclaws - for sampctl
