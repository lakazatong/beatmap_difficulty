#include "structs.h"

// game //

DifficultyHitObject* new_difficultyHitObject() {
	DifficultyHitObject* r = malloc(sizeof(DifficultyHitObject));
	r->index = 0;
	r->hitObject = NULL;
	r->lastHitObject = NULL;
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
	return r;
}

StrainSkill* new_strainSkill() {
	StrainSkill* r = malloc(sizeof(StrainSkill));
	r->decayWeight = 0.0;
	r->sectionLength = 0;
	r->currentSectionPeak = 0.0;
	r->currentSectionEnd = 0.0;
	r->strainPeaks = new_dlist(0);
	return r;
}

void free_difficultyHitObject(DifficultyHitObject* difficultyHitObject) {
	free(difficultyHitObject->hitObject);
	free(difficultyHitObject->lastHitObject);
	free(difficultyHitObject->object);
	free(difficultyHitObject);
}

void free_strainDecaySkill(StrainDecaySkill* strainDecaySkill) {
	free(strainDecaySkill);
}

void free_strainSkill(StrainSkill* strainSkill) {
	free_dlist(strainSkill->strainPeaks);
	free(strainSkill);
}

// osu //

OsuDifficultyHitObject* new_osuDifficultyHitObject() {
	OsuDifficultyHitObject* r = malloc(sizeof(OsuDifficultyHitObject));
	r->normalisedRadius = 50;
	r->minDeltaTime = 25;
	r->maximumSliderRadius = r->normalisedRadius * 2.4f;
	r->assumedSliderRadius = r->normalisedRadius * 1.8f;
	r->strainTime = 0.0;
	r->lazyJumpDistance = 0.0;
	r->minimumJumpDistance = 0.0;
	r->minimumJumpTime = 0.0;
	r->travelDistance = 0.0;
	r->travelTime = 0.0;
	r->angle = 0.0;
	r->hitWindowGreat = 0.0;
	r->lastLastHitObject = NULL;
	r->lastHitObject = NULL;
	return r;
}

OsuAimSkill* new_osuAimSkill() {
	OsuAimSkill* r = malloc(sizeof(OsuAimSkill));
	r->withSliders = 0;
	r->skillMultiplier = 23.55;
	r->strainDecayBase = 0.15;
	r->currentStrain = 0.0;
	return r;
}

OsuFlashLightSkill* new_osuFlashLightSkill() {
	OsuFlashLightSkill* r = malloc(sizeof(OsuFlashLightSkill));
	r->hasHiddenMod = 0;
	r->skillMultiplier = 0.052;
	r->strainDecayBase = 0.15;
	r->currentStrain = 0.0;
	return r;
}

OsuSpeedSkill* new_osuSpeedSkill() {
	OsuSpeedSkill* r = malloc(sizeof(OsuSpeedSkill));
	r->skillMultiplier = 1375;
	r->strainDecayBase = 0.3;
	r->currentStrain = 0.0;
	r->currentRhythm = 0.0;
	r->reducedSectionCount = 5;
	r->difficultyMultiplier = 1.04;
	return r;
}

OsuStrainSkill* new_osuStrainSkill() {
	OsuStrainSkill* r = malloc(sizeof(OsuStrainSkill));
	r->defaultDifficultyMultiplier = 1.06;
	r->reducedSectionCount = 10;
	r->reducedStrainBaseline = 0.75;
	r->difficultyMultiplier = r->defaultDifficultyMultiplier;
	return r;
}

OsuSkill* new_osuSkill() {
	OsuSkill* r = malloc(sizeof(OsuSkill));
	r->osuStrainSkill = new_osuStrainSkill();
	r->strainSkill = new_strainSkill();
	r->type = 0;
	r->skill = NULL;
	r->mods = 0;
	return r;
}

void free_osuDifficultyHitObject(OsuDifficultyHitObject* osuDifficultyHitObject) {
	free(osuDifficultyHitObject->lastLastHitObject);
	free(osuDifficultyHitObject->lastHitObject);
	free(osuDifficultyHitObject);
}

void free_osuAimSkill(OsuAimSkill* osuAimSkill) {
	free(osuAimSkill);
}

void free_osuFlashLightSkill(OsuFlashLightSkill* osuFlashLightSkill) {
	free(osuFlashLightSkill);
}

void free_osuSpeedSkill(OsuSpeedSkill* osuSpeedSkill) {
	free(osuSpeedSkill);
}

void free_osuStrainSkill(OsuStrainSkill* osuStrainSkill) {
	free(osuStrainSkill);
}

void free_osuSkill(OsuSkill* osuSkill) {
	free_osuStrainSkill(osuSkill->osuStrainSkill);
	free_strainSkill(osuSkill->strainSkill);
	if (osuSkill->object != NULL) {
		if (osuSkill->type == 0) free_osuAimSkill((OsuAimSkill*)osuSkill->object);
		else if (osuSkill->type == 1) free_osuFlashLightSkill((OsuFlashLightSkill*)osuSkill->object);
		else free_osuSpeedSkill((OsuSpeedSkill*)osuSkill->object);
	}
	free(osuSkill);
}

// taiko //

TaikoDifficultyHitObjectRhythm* new_taikoDifficultyHitObjectRhythm() {
	TaikoDifficultyHitObjectRhythm* r = malloc(sizeof(TaikoDifficultyHitObjectRhythm));
	r->difficulty = 0.0;
	r->ratio = 0.0;
	return r;
}

RepeatingHitPatterns* new_repeatingHitPatterns() {
	RepeatingHitPatterns* r = malloc(sizeof(RepeatingHitPatterns));
	r->maxRepetitionInterval = 0;
	r->alternatingMonoPatterns = new_list(0);
	r->firstHitObject = NULL;
	r->previous = NULL;
	r->repetitionInterval = 0;
	return r;
}

AlternatingMonoPattern* new_alternatingMonoPattern() {
	AlternatingMonoPattern* r = malloc(sizeof(AlternatingMonoPattern));
	r->monoStreaks = new_list(0);
	r->parent = NULL;
	r->index = 0;
	r->firstHitObject = NULL;
	return r;
}

MonoStreak* new_monoStreak() {
	MonoStreak* r = malloc(sizeof(MonoStreak));
	r->hitObjects = new_list(0);
	r->parent = NULL;
	r->index = 0;
	r->firstHitObject = NULL;
	r->lastHitObject = NULL;
	r->hitType = 0;
	r->runLength = 0;
	return r;
}

TaikoDifficultyHitObjectColour* new_taikoDifficultyHitObjectColour() {
	TaikoDifficultyHitObjectColour* r = malloc(sizeof(TaikoDifficultyHitObjectColour));
	r->monoStreak = NULL;
	r->alternatingMonoPattern = NULL;
	r->repeatingHitPattern = NULL;
	r->previousColourChange = NULL;
	r->nextColourChange = NULL;
	return r;
}

TaikoColourSkill* new_taikoColourSkill() {
	TaikoColourSkill* r = malloc(sizeof(TaikoColourSkill));
	r->skillMultiplier = 0.12;
	r->strainDecayBase = 0.8;
	return r;
}

TaikoRhythmSkill* new_taikoRhythmSkill() {
	TaikoRhythmSkill* r = malloc(sizeof(TaikoRhythmSkill));
	r->skillMultiplier = 10.0;
	r->strainDecayBase = 0.0;
	r->strainDecay = 0.96;
	r->rhythmHistoryMaxLength = 8;
	r->rhythmHistory = new_queue(0);
	r->currentStrain = 0.0;
	r->notesSinceRhythmChange = 0;
	return r;
}

TaikoStaminaSkill* new_taikoStaminaSkill() {
	TaikoStaminaSkill* r = malloc(sizeof(TaikoStaminaSkill));
	r->skillMultiplier = 1.1;
	r->strainDecayBase = 0.4;
	return r;
}

TaikoPeaksSkill* new_taikoPeaksSkill() {
	TaikoPeaksSkill* r = malloc(sizeof(TaikoPeaksSkill));
	r->finalMultiplier = 0.0625;
	r->colourSkillMultiplier = 0.375 * r->finalMultiplier;
	r->rhythmSkillMultiplier = 0.2 * r->finalMultiplier;
	r->staminaSkillMultiplier = 0.375 * r->finalMultiplier;
	r->colour = NULL;
	r->rhythm = NULL;
	r->stamina = NULL;
	r->colourDifficultyValue = 0.0 * r->colourSkillMultiplier;
	r->rhythmDifficultyValue = 0.0 * r->rhythmSkillMultiplier;
	r->staminaDifficultyValue = 0.0 * r->staminaSkillMultiplier;
	return r;
}

TaikoSkill* new_taikoSkill() {
	TaikoSkill* r = malloc(sizeof(TaikoSkill));
	r->strainDecaySkill = new_strainDecaySkill();
	r->strainSkill = new_strainSkill();
	r->type = 0;
	r->skill = NULL;
	r->mods = 0;
	return r;
}

void free_taikoDifficultyHitObjectRhythm(TaikoDifficultyHitObjectRhythm* taikoDifficultyHitObjectRhythm) {
	free(taikoDifficultyHitObjectRhythm);
}

void free_repeatingHitPatterns(RepeatingHitPatterns* repeatingHitPatterns) {
	free_list(repeatingHitPatterns->alternatingMonoPatterns);
	free(repeatingHitPatterns->previous);
	free(repeatingHitPatterns);
}

void free_alternatingMonoPattern(AlternatingMonoPattern* alternatingMonoPattern) {
	free_list(alternatingMonoPattern->monoStreaks);
	free(alternatingMonoPattern);
}

void free_monoStreak(MonoStreak* monoStreak) {
	free_list(monoStreak->hitObjects);
	free(monoStreak);
}

void free_taikoDifficultyHitObjectColour(TaikoDifficultyHitObjectColour* taikoDifficultyHitObjectColour) {
	free(taikoDifficultyHitObjectColour);
}

void free_taikoColourSkill(TaikoColourSkill* taikoColourSkill) {
	free(taikoColourSkill);
}

void free_taikoRhythmSkill(TaikoRhythmSkill* taikoRhythmSkill) {
	free_queue(taikoRhythmSkill->rhythmHistory);
	free(taikoRhythmSkill);
}

void free_taikoStaminaSkill(TaikoStaminaSkill* taikoStaminaSkill) {
	free(taikoStaminaSkill);
}

void free_taikoPeaksSkill(TaikoPeaksSkill* taikoPeaksSkill) {
	free(taikoPeaksSkill->colour);
	free(taikoPeaksSkill->rhythm);
	free(taikoPeaksSkill->stamina);
	free(taikoPeaksSkill);
}

void free_taikoSkill(TaikoSkill* taikoSkill) {
	free(taikoSkill->strainDecaySkill);
	free(taikoSkill->strainSkill);
	if (taikoSkill->skill != NULL) {
		if (taikoSkill->type == 0) free_taikoColourSkill((TaikoColourSkill*)taikoSkill->skill);
		else if (taikoSkill->type == 1) free_taikoRhythmSkill((TaikoRhythmSkill*)taikoSkill->skill);
		else if (taikoSkill->type == 2) free_taikoStaminaSkill((TaikoStaminaSkill*)taikoSkill->skill);
		else free_taikoPeaksSkill((TaikoPeaksSkill*)taikoSkill->skill);
	}
	free(taikoSkill);
}

// fruits //

CatchDifficultyHitObject* new_catchDifficultyHitObject() {
	CatchDifficultyHitObject* r = malloc(sizeof(CatchDifficultyHitObject));
	r->normalizedHitobjectRadius = 0.0;
	r->normalizedPosition = 0.0;
	r->lastNormalizedPosition = 0.0;
	r->strainTime = 0.0;
	return r;
}

CatchMovementSkill* new_catchMovementSkill() {
	CatchMovementSkill* r = malloc(sizeof(CatchMovementSkill));
	r->absolutePlayerPositioningError = 0.0;
	r->normalizedHitobjectRadius = 0.0;
	r->direction_changeBonus = 0.0;
	r->skillMultiplier = 0.0;
	r->strainDecayBase = 0.0;
	r->decayWeight = 0.0;
	r->sectionLength = 0;
	r->halfCatcherWidth = 0.0;
	r->lastPlayerPosition = 0.0;
	r->lastDistanceMoved = 0.0;
	r->lastStrainTime = 0.0;
	r->catcherSpeedMultiplier = 0.0;
	return r;
}

CatchSkill* new_catchSkill() {
	CatchSkill* r = malloc(sizeof(CatchSkill));
	r->strainDecaySkill = new_strainDecaySkill();
	r->strainSkill = new_strainSkill();
	r->type = 0;
	r->skill = NULL;
	r->mods = 0;
	return r;
}

void free_catchDifficultyHitObject(CatchDifficultyHitObject* catchDifficultyHitObject) {
	free(catchDifficultyHitObject);
}

void free_catchMovementSkill(CatchMovementSkill* catchMovementSkill) {
	free(catchMovementSkill);
}

void free_catchSkill(CatchSkill* catchSkill) {
	free(catchSkill->strainDecaySkill);
	free(catchSkill->strainSkill);
	if (catchSkill->skill != NULL) free((CatchMovementSkill*)catchSkill->skill);
	free(catchSkill);
}

// mania //

ManiaStrainSkill* new_maniaStrainSkill() {
	ManiaStrainSkill* r = malloc(sizeof(ManiaStrainSkill));
	r->individualDecayBase = 0.0;
	r->overallDecayBase = 0.0;
	r->releaseThreshold = 0.0;
	r->skillMultiplier = 0.0;
	r->strainDecayBase = 0.0;
	r->startTimes = new_dlist(0);
	r->endTimes = new_dlist(0);
	r->individualStrains = new_dlist(0);
	r->individualStrain = 0.0;
	r->overallStrain = 0.0;
	return r;
}

ManiaSkill* new_maniaSkill() {
	ManiaSkill* r = malloc(sizeof(ManiaSkill));
	r->strainDecaySkill = new_strainDecaySkill();
	r->strainSkill = new_strainSkill();
	r->type = 0;
	r->skill = NULL;
	r->mods = 0;
	return r;
}

void free_maniaStrainSkill(ManiaStrainSkill* maniaStrainSkill) {
	free_dlist(maniaStrainSkill->startTimes);
	free_dlist(maniaStrainSkill->endTimes);
	free_dlist(maniaStrainSkill->individualStrains);
	free(maniaStrainSkill);
}

void free_maniaSkill(ManiaSkill* maniaSkill) {
	free(maniaSkill->strainDecaySkill);
	free(maniaSkill->strainSkill);
	if (maniaSkill->skill != NULL) free(maniaSkill->skill);
	free(maniaSkill);
}