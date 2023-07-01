#include "structs.h"

// osu //

OsuDifficultyHitObject* new_osuDifficultyHitObject() {
	OsuDifficultyHitObject* r = malloc(sizeof(OsuDifficultyHitObject));
	r->normalisedRadius = 0;
	r->minDeltaTime = 0;
	r->maximumSliderRadius = 0.0f;
	r->assumedSliderRadius = 0.0f;
	r->strainTime = 0.0;
	r->lazyJumpDistance = 0.0;
	r->minimumJumpDistance = 0.0;
	r->minimumJumpTime = 0.0;
	r->travelDistance = 0.0;
	r->travelTime = 0.0;
	r->angle = 0.0;
	r->hitWindowGreat = 0.0;
	return r;
}

OsuAimStrainSkill* new_osuAimStrainSkill() {
	OsuAimStrainSkill* r = malloc(sizeof(OsuAimStrainSkill));
	r->skillMultiplier = 0.0;
	r->strainDecayBase = 0.0;
	r->currentStrain = 0.0;
	r->withSliders = 0;
	return r;
}

OsuSpeedStrainSkill* new_osuSpeedStrainSkill() {
	OsuSpeedStrainSkill* r = malloc(sizeof(OsuSpeedStrainSkill));
	r->skillMultiplier = 0.0;
	r->strainDecayBase = 0.0;
	r->currentStrain = 0.0;
	r->reducedSectionCount = 0;
	r->difficultyMultiplier = 0.0;
	r->currentRhythm = 0.0;
	return r;
}

OsuFlashLightSkill* new_osuFlashLightSkill() {
	OsuFlashLightSkill* r = malloc(sizeof(OsuFlashLightSkill));
	r->skillMultiplier = 0.0;
	r->strainDecayBase = 0.0;
	r->currentStrain = 0.0;
	r->hasHiddenMod = 0;
	return r;
}

OsuStrainSkill* new_osuStrainSkill() {
	OsuStrainSkill* r = malloc(sizeof(OsuStrainSkill));
	r->reducedSectionCount = 0;
	r->difficultyMultiplier = 0.0;
	r->reducedStrainBaseline = 0.0;
	r->defaultDifficultyMulitplier = 0.0;
	r->type = 0;
	r->osuStrainSkill = NULL;
	return r;
}

void free_osuDifficultyHitObject(OsuDifficultyHitObject* osuDifficultyHitObject) {
	free(osuDifficultyHitObject);
}

void free_osuAimStrainSkill(OsuAimStrainSkill* osuAimStrainSkill) {
	free(osuAimStrainSkill);
}

void free_osuSpeedStrainSkill(OsuSpeedStrainSkill* osuSpeedStrainSkill) {
	free(osuSpeedStrainSkill);
}

void free_osuFlashLightSkill(OsuFlashLightSkill* osuFlashLightSkill) {
	free(osuFlashLightSkill);
}

void free_osuStrainSkill(OsuStrainSkill* osuStrainSkill) {
	if (osuStrainSkill->osuStrainSkill != NULL) {
		if (osuStrainSkill->type == 0)
			free_osuAimStrainSkill((OsuAimStrainSkill*)osuStrainSkill->osuStrainSkill);
		else if (osuStrainSkill->type == 1)
			free_osuSpeedStrainSkill((OsuSpeedStrainSkill*)osuStrainSkill->osuStrainSkill);
	}
	free(osuStrainSkill);
}

// game //

DifficultyHitObject* new_difficultyHitObject() {
	DifficultyHitObject* r = malloc(sizeof(DifficultyHitObject));
	r->index = 0;
	r->hitObject = NULL;
	r->lastHitObject = NULL;
	r->lastLastHitObject = NULL;
	r->deltaTime = 0.0;
	r->startTime = 0.0;
	r->endTime = 0.0;
	r->type = 0;
	r->object = NULL;
	return r;
}

StrainDecaySkill* new_strainDecaySkill() {
	StrainDecaySkill* r = malloc(sizeof(StrainDecaySkill));
	r->skillMultiplier = 0.0;
	r->strainDecayBase = 0.0;
	r->currentStrain = 0.0;
	r->type = 0;
	r->strainDecaySkill = NULL;
	return r;
}

StrainSkill* new_strainSkill() {
	StrainSkill* r = malloc(sizeof(StrainSkill));
	r->decayWeight = 0.0;
	r->sectionLength = 0;
	r->currentSectionPeak = 0.0;
	r->currentSectionEnd = 0.0;
	r->strainPeaks = new_dlist(0);
	r->type = 0;
	r->strainSkill = NULL;
	return r;
}

Skill* new_skill() {
	Skill* r = malloc(sizeof(Skill));
	r->mods = 0;
	r->type = 0;
	r->skill = NULL;
	return r;
}

void free_difficultyHitObject(DifficultyHitObject* difficultyHitObject) {
	if (difficultyHitObject->object != NULL) {
		if (difficultyHitObject->type == 0)
			free_osuDifficultyHitObject((OsuDifficultyHitObject*)difficultyHitObject->object);
		// else if (difficultyHitObject->type == 1)
		// 	free_TaikoDifficultyHitObject((TaikoDifficultyHitObject*)difficultyHitObject->object);
		// else if (difficultyHitObject->type == 2)
		// 	free_FruitsDifficultyHitObject((FruitsDifficultyHitObject*)difficultyHitObject->object);
		// else if (difficultyHitObject->type == 3)
		// 	free_ManiaDifficultyHitObject((ManiaDifficultyHitObject*)difficultyHitObject->object);
	}
	free(difficultyHitObject);
}

void free_strainDecaySkill(StrainDecaySkill* strainDecaySkill) {
	// if (strainDecaySkill->strainDecaySkill != NULL) {
	// 	if (strainDecaySkill->type == 0)
	// 		free_FruitsMovementSkill((FruitsMovementSkill*)strainDecaySkill->strainDecaySkill);
	// 	else if (strainDecaySkill->type == 1)
	// 		free_ManiaStrainSkill((ManiaStrainSkill*)strainDecaySkill->strainDecaySkill);
	// 	else if (strainDecaySkill->type == 2)
	// 		free_TaikoRhythmSkill((TaikoRhythmSkill*)strainDecaySkill->strainDecaySkill);
	// 	else if (strainDecaySkill->type == 3)
	// 		free_TaikoColourSkill((TaikoColourSkill*)strainDecaySkill->strainDecaySkill);
	// 	else if (strainDecaySkill->type == 4)
	// 		free_TaikoStaminaSkill((TaikoStaminaSkill*)strainDecaySkill->strainDecaySkill);
	// }
	free(strainDecaySkill);
}

void free_strainSkill(StrainSkill* strainSkill) {
	if (strainSkill->strainSkill != NULL) {
		if (strainSkill->type == 0)
			free_osuFlashLightSkill((OsuFlashLightSkill*)strainSkill->strainSkill);
		else if (strainSkill->type == 1)
			free_osuStrainSkill((OsuStrainSkill*)strainSkill->strainSkill);
		else if (strainSkill->type == 2)
			free_strainDecaySkill((StrainDecaySkill*)strainSkill->strainSkill);
	}
	free_dlist(strainSkill->strainPeaks);
	free(strainSkill);
}

void free_skill(Skill* skill) {
	if (skill->skill != NULL) {
		// if (skill->type == 0)
		// 	free_TaikoPeaks((TaikoPeaks*)skill->skill);
		if (skill->type == 1)
			free_strainSkill((StrainSkill*)skill->skill);
	}
	free(skill);
}