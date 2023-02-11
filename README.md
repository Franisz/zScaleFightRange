# zScaleFightRange

This is a plugin that fixes fight range for NPCs that have scaled model. It's made in [Union](https://worldofplayers.ru/threads/40376/) for Gothic I and II.

### Features

In vanilla game, NPCs with changed model scale via `Mdl_SetModelScale` function for example have changed model and hitbox but not the fight range, that is defined in guilds table. The plugin adjusts the fight range via hooks, so it's safe to add or remove at any point in the game. The range of NPCs is multiplied by the `z` scale, the length of the model.

A Giant bug monster with scale set to `Mdl_SetModelScale(self,0.4,0.4,0.35)`:
  - In vanilla would have whopping: `240` range  (`120` base range + `120` fist range)
  - With this plugin, it would be: `84` range

This work on larger NPCs as well, so NPCs with larger scale, will no longer have to walk into you in order to hit you, their range is multiplied the same way.

This plugin **does not** scale the range of an equipped weapon, so for example range of goblin itself will be scaled but the range of his weapon **not**.

Plugin has 3 options (all enabled by default) that can be changed in gothic.ini or ingame menu:
  - `ScaleSmallerNpcs` - enables scalling of NPCs with scale smaller than 1
  - `ScaleLargerNpcs` - enables scalling of NPCs with scale larger than 1
  - `ScalePlayer` - enables scalling of player
