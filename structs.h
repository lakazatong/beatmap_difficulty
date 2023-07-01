#ifndef BEATMAP_DIFFICULTY_STRUCTS_H
#define BEATMAP_DIFFICULTY_STRUCTS_H

#ifdef BEATMAP_DIFFICULTY_TEST
	// used as the main program
	#include "libs/beatmap_parser/parser.h"
#else
	// used as a library (inside a libs folder)
	#include "../beatmap_parser/parser.h"
#endif

// osu //

typedef struct {
	int normalisedRadius;
	int minDeltaTime;
	float maximumSliderRadius;
	float assumedSliderRadius;
	double strainTime;
	double lazyJumpDistance;
	double minimumJumpDistance;
	double minimumJumpTime;
	double travelDistance;
	double travelTime;
	double angle;
	double hitWindowGreat;
} OsuDifficultyHitObject;

typedef struct {
	double skillMultiplier;
	double strainDecayBase;
	double currentStrain;
	int withSliders;
} OsuAimStrainSkill;

typedef struct {
	double skillMultiplier;
	double strainDecayBase;
	double currentStrain;
	int reducedSectionCount;
	double difficultyMultiplier;
	double currentRhythm;
} OsuSpeedStrainSkill;

typedef struct {
	double skillMultiplier;
	double strainDecayBase;
	double currentStrain;
	int hasHiddenMod;
} OsuFlashLightSkill;

typedef struct {
	int reducedSectionCount;
	double difficultyMultiplier;
	double reducedStrainBaseline;
	double defaultDifficultyMulitplier;
	int type; // 0 OsuAimStrainSkill 1 OsuSpeedStrainSkill
	void* osuStrainSkill;
} OsuStrainSkill;

// taiko //

// fruits //

// mania //

// game //

typedef struct {
	int index;
	HitObject* hitObject;
	HitObject* lastHitObject;
	HitObject* lastLastHitObject;
	double deltaTime;
	double startTime;
	double endTime;
	int type; // 0 OsuDifficultyHitObject 1 TaikoDifficultyHitObject 2 FruitsDifficultyHitObject 3 ManiaDifficultyHitObject
	void* object;
} DifficultyHitObject;

typedef struct {
	double skillMultiplier;
	double strainDecayBase;
	double currentStrain;
	int type; // 0 FruitsMovementSkill 1 ManiaStrainSkill 2 TaikoRhythmSkill 3 TaikoColourSkill 4 TaikoStaminaSkill
	void* strainDecaySkill;
} StrainDecaySkill;

typedef struct {
	double decayWeight;
	int sectionLength;
	double currentSectionPeak;
	double currentSectionEnd;
	dList* strainPeaks;
	int type; // 0 OsuFlashLightSkill 1 OsuStrainSkill 2 StrainDecaySkill
	void* strainSkill;
} StrainSkill;

typedef struct {
	int mods; // 0 NF 1 SD 2 PF 3 EZ 4 HR 5 HD 6 DT 7 NC 8 HT 9 FL 10 SO 11 FI 12 MR
	int type; // 0 TaikoPeaks 1 StrainSkill
	void* skill;
} Skill;

#endif