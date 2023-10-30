#ifndef BEATMAP_DIFFICULTY_H
#define BEATMAP_DIFFICULTY_H

#include "structs.h"

int mods = 0; // 0 NF 1 SD 2 PF 3 EZ 4 HR 5 HD 6 DT 7 NC 8 HT 9 FL 10 SO 11 FI 12 MR

void set_mods(int mods);
void set_mods_from_slist(sList* mods);

OsuSkill** new_osuSkills();
TaikoSkill** new_taikoSkills();
CatchSkill** new_catchSkills();
ManiaSkill** new_maniaSkills();

void free_osuSkills(OsuSkill* osuSkills[4]);
void free_taikoSkills(TaikoSkill* taikoSkills[4]);
void free_catchSkills(CatchSkill* catchSkills[1]);
void free_maniaSkills(ManiaSkill* maniaSkills[1]);

#endif