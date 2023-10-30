#ifndef BEATMAP_DIFFICULTY_STRUCTS_H
#define BEATMAP_DIFFICULTY_STRUCTS_H

#ifdef BEATMAP_DIFFICULTY_TEST
	// used as the main program
	#include "libs/beatmap_parser/parser.h"
#else
	// used as a library (inside a libs folder)
	#include "../beatmap_parser/parser.h"
#endif

// game //

typedef struct {
	int index;
	HitObject* hitObject;
	HitObject* lastHitObject;
	double deltaTime;
	double startTime;
	double endTime;
	int type; // 0 OsuDifficultyHitObject 1 TaikoDifficultyHitObject 2 CatchDifficultyHitObject 3 ManiaDifficultyHitObject
	void* object;
} DifficultyHitObject;

typedef struct {
	double skillMultiplier;
	double strainDecayBase;
	double currentStrain;
} StrainDecaySkill;

typedef struct {
	double decayWeight;
	int sectionLength;
	double currentSectionPeak;
	double currentSectionEnd;
	dList* strainPeaks;
} StrainSkill;

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
	HitObject* lastLasthitObject;
	HitObject* lastHitObject;
} OsuDifficultyHitObject;

typedef struct {
	int withSliders;
	double skillMultiplier;
	double strainDecayBase;
	double currentStrain;
} OsuAimSkill;

typedef struct {
	int hasHiddenMod;
	double skillMultiplier;
	double strainDecayBase;
	double currentStrain;
	 // OsuStrainSkill* osuStrainSkill = NULL;
} OsuFlashLightSkill;

typedef struct {
	double skillMultiplier;
	double strainDecayBase;
	double currentStrain;
	double currentRhythm;
	int reducedSectionCount;
	double difficultyMultiplier;
} OsuSpeedSkill;

typedef struct {
	double defaultDifficultyMultiplier;
	int reducedSectionCount;
	double reducedStrainBaseline;
	double difficultyMultiplier;
} OsuStrainSkill;

typedef struct {
	OsuStrainSkill* osuStrainSkill;
	StrainSkill* strainSkill;
	int type; // 0 OsuAimSkill 1 OsuFlashLightSkill 2 OsuSpeedSkill
	void* skill;
	int mods;
} OsuSkill;

// taiko //

typedef struct {
	double difficulty;
	double ratio;
} TaikoDifficultyHitObjectRhythm;

typedef struct {
	int maxRepetitionInterval;
	List* alternatingMonoPatterns; // AlternatingMonoPattern*
	TaikoDifficultyHitObject* firstHitObject;
	RepeatingHitPatterns* previous;
	int repetitionInterval;
} RepeatingHitPatterns;

typedef struct {
	List* monoStreaks; // MonoStreak*
	RepeatingHitPatterns* parent;
	int index;
	TaikoDifficultyHitObject* firstHitObject;
} AlternatingMonoPattern;

typedef struct {
	List* hitObjects; // TaikoDifficultyHitObject*
	AlternatingMonoPattern* parent;
	int index;
	TaikoDifficultyHitObject* firstHitObject;
	TaikoDifficultyHitObject* lastHitObject;
	int hitType; // 0 Centre 1 Rim
	int runLength;
} MonoStreak;

typedef struct {
	// From TaikoDifficultyHitObjectColour
	MonoStreak* monoStreak;
	AlternatingMonoPattern* alternatingMonoPattern;
	RepeatingHitPatterns* repeatingHitPattern;
	TaikoDifficultyHitObject* previousColourChange;
	TaikoDifficultyHitObject* nextColourChange;
} TaikoDifficultyHitObjectColour;

typedef struct {
	// From TaikoDifficultyHitObject
	List* monoDifficultyHitObjects; // TaikoDifficultyHitObject*
	int monoIndex;
	List* noteDifficultyHitObjects; // TaikoDifficultyHitObject*
	int noteIndex;
	TaikoDifficultyHitObjectRhythm* rhythm;
	TaikoDifficultyHitObjectColour* colour;
} TaikoDifficultyHitObject;

typedef struct {
	double skillMultiplier;
	double strainDecayBase;
} TaikoColourSkill;

typedef struct {
	double skillMultiplier;
	double strainDecayBase;
	double strainDecay;
	int rhythmHistoryMaxLength;
	Queue* rhythmHistory; // TaikoDifficultyHitObject*
	double currentStrain;
	int notesSinceRhythmChange;
} TaikoRhythmSkill;

typedef struct {
	double skillMultiplier;
	double strainDecayBase;
} TaikoStaminaSkill;

typedef struct {
	double finalMultiplier;
	double colourSkillMultiplier;
	double rhythmSkillMultiplier;
	double staminaSkillMultiplier;
	TaikoColourSkill* colour;
	TaikoRhythmSkill* rhythm;
	TaikoStaminaSkill* stamina;
	double colourDifficultyValue;
	double rhythmDifficultyValue;
	double staminaDifficultyValue;
	// StrainDecaySkill* strainDecaySkill = NULL;
	// StrainSkill* strainSkill = NULL;
} TaikoPeaksSkill;

typedef struct {
	StrainDecaySkill* strainDecaySkill;
	StrainSkill* strainSkill;
	int type; // 0 TaikoColourSkill 1 TaikoRhythmSkill 2 TaikoStaminaSkill 3 TaikoPeaksSkill
	void* skill;
	int mods;
} TaikoSkill;

// catch //

/*
typedef struct {
	From PalpableCatchHitObject
	float distanceToHyperDash;
	HitObjectProperty<bool> hyperDash;
	Bindable<bool> hyperDashBindable;
	int hyperDash;
	CatchHitObject* hyperDashTarget;
	...
} PalpableCatchHitObject;
*/

typedef struct {
	float normalizedHitobjectRadius;
	// PalpableCatchHitObject* baseObject;
	// PalpableCatchHitObject* lastObject;
	float normalizedPosition;
	float lastNormalizedPosition;
	double strainTime;
} CatchDifficultyHitObject;

typedef struct {
	float absolutePlayerPositioningError;
	float normalizedHitobjectRadius;
	double direction_changeBonus;
	double skillMultiplier;
	double strainDecayBase;
	double decayWeight;
	int sectionLength;
	float halfCatcherWidth;
	float lastPlayerPosition;
	float lastDistanceMoved;
	double lastStrainTime;
	double catcherSpeedMultiplier;
} CatchMovementSkill;

typedef struct {
	StrainDecaySkill* strainDecaySkill;
	StrainSkill* strainSkill;
	int type; // 0 CatchMovementSkill
	void* skill;
	int mods;
} CatchSkill;

// mania //

/* no additional params
typedef struct {

} ManiaDifficultyHitObject; */

typedef struct {
	double individualDecayBase;
	double overallDecayBase;
	double releaseThreshold;
	double skillMultiplier;
	double strainDecayBase;
	dList* startTimes;
	dList* endTimes;
	dList* individualStrains;
	double individualStrain;
	double overallStrain;
} ManiaStrainSkill;

typedef struct {
	StrainDecaySkill* strainDecaySkill;
	StrainSkill* strainSkill;
	int type; // 0 ManiaStrainSkill
	void* skill;
	int mods;
} ManiaSkill;

#endif