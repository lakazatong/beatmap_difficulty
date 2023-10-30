#include "difficulty.h"

void set_mods(int mods){
	mods = mods;
}

void set_mods_from_slist(sList* mods){
	for (int i = 0; i < mods->size; i++){
		if 		(strncmp(mods[i], "NF", 2) == 0) mods |= 0b1000000000000;
		else if (strncmp(mods[i], "SD", 2) == 0) mods |= 0b0100000000000;
		else if (strncmp(mods[i], "PF", 2) == 0) mods |= 0b0010000000000;
		else if (strncmp(mods[i], "EZ", 2) == 0) mods |= 0b0001000000000;
		else if (strncmp(mods[i], "HR", 2) == 0) mods |= 0b0000100000000;
		else if (strncmp(mods[i], "HD", 2) == 0) mods |= 0b0000010000000;
		else if (strncmp(mods[i], "DT", 2) == 0) mods |= 0b0000001000000;
		else if (strncmp(mods[i], "NC", 2) == 0) mods |= 0b0000000100000;
		else if (strncmp(mods[i], "HT", 2) == 0) mods |= 0b0000000010000;
		else if (strncmp(mods[i], "FL", 2) == 0) mods |= 0b0000000001000;
		else if (strncmp(mods[i], "SO", 2) == 0) mods |= 0b0000000000100;
		else if (strncmp(mods[i], "FI", 2) == 0) mods |= 0b0000000000010;
		else if (strncmp(mods[i], "MR", 2) == 0) mods |= 0b0000000000001;
		else
			printf("set_mods_from_slist: Unkown mod (%s)\n", mods[i]);
	}
}

Skill** new_osuSkills(){
	OsuSkill* skill1 = new_osuSkill();
	skill1->skill = new_osuAimSkill();
	skill1->skill->withSliders = 1;

	OsuSkill* skill2 = new_osuSkill();
	skill2->skill = new_osuAimSkill();

	OsuSkill* skill3 = new_osuSkill();
	skill3->skill = new_osuSpeedSkill();

	OsuSkill* skill4 = new_osuSkill();
	skill4->skill = new_osuFlashLightSkill();
	return {skill1, skill2, skill3, skill4};
}

Skill** new_taikoSkills(){
	OsuSkill* skill1 = new_osuSkill();
	skill1->skill = new_osuAimSkill();
	skill1->skill->withSliders = 1;

	OsuSkill* skill2 = new_osuSkill();
	skill2->skill = new_osuAimSkill();

	OsuSkill* skill3 = new_osuSkill();
	skill3->skill = new_osuSpeedSkill();

	OsuSkill* skill4 = new_osuSkill();
	skill4->skill = new_osuFlashLightSkill();
	return {skill1, skill2, skill3, skill4};
}

Skill** new_catchSkills(){
	OsuAimSkill* osuAimSkill_withSliders = new_osuAimSkill();
	osuAimSkill_withSliders->withSliders = 1;
	OsuAimSkill* osuAimSkill = new_osuAimSkill();
	Skill* osuSpeedSkill = new_osuSpeedSkill();
	Skill* osuFlashLightSkill = new_osuFlashLightSkill();
	return {osuAimSkill_withSliders, osuAimSkill, osuSpeedSkill, osuFlashLightSkill};
}

Skill** new_maniaSkills(){
	OsuAimSkill* osuAimSkill_withSliders = new_osuAimSkill();
	osuAimSkill_withSliders->withSliders = 1;
	OsuAimSkill* osuAimSkill = new_osuAimSkill();
	Skill* osuSpeedSkill = new_osuSpeedSkill();
	Skill* osuFlashLightSkill = new_osuFlashLightSkill();
	return {osuAimSkill_withSliders, osuAimSkill, osuSpeedSkill, osuFlashLightSkill};
}

void free_osuSkills(OsuSkill* osuSkills[4]){

}

void free_taikoSkills(TaikoSkill* taikoSkills[4]){

}

void free_catchSkills(CatchSkill* catchSkills[4]){

}

void free_maniaSkills(ManiaSkill* maniaSkills[4]){

}