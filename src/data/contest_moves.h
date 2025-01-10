const struct ContestEffect gContestEffects[] =
{
    [CONTEST_EFFECT_HIGHLY_APPEALING] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 40,
        .jam = 0,
    },
    [CONTEST_EFFECT_USER_MORE_EASILY_STARTLED] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 60,
        .jam = 0,
    },
    [CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 80,
        .jam = 0,
    },
    [CONTEST_EFFECT_REPETITION_NOT_BORING] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_ONCE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_AVOID_STARTLE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_USER_LESS_EASILY_STARTLED] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_STARTLE_FRONT_MON] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
    },
    [CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 20,
        .jam = 30,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 20,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 10,
        .jam = 40,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 10,
        .jam = 30,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON_2] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS_2] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
    },
    [CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 40,
        .jam = 40,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
    },
    [CONTEST_EFFECT_BETTER_IF_FIRST] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_IF_LAST] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_WHEN_LATER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_IF_SAME_TYPE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_IF_DIFF_TYPE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_EARLIER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_LATER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_MAKE_SCRAMBLING_TURN_ORDER_EASIER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_DONT_EXCITE_AUDIENCE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
    },
};

void (*const gContestEffectFuncs[])(void) =
{
    ContestEffect_HighlyAppealing_contest_effect,
    ContestEffect_UserMoreEasilyStartled_contest_effect,
    ContestEffect_GreatAppealButNoMoreMoves_contest_effect,
    ContestEffect_RepetitionNotBoring_contest_effect,
    ContestEffect_AvoidStartleOnce_contest_effect,
    ContestEffect_AvoidStartle_contest_effect,
    ContestEffect_AvoidStartleSlightly_contest_effect,
    ContestEffect_UserLessEasilyStartled_contest_effect,
    ContestEffect_StartleFrontMon_contest_effect,
    ContestEffect_StartlePrevMons_contest_effect,
    ContestEffect_StartleFrontMon_contest_effect,
    ContestEffect_StartlePrevMons_contest_effect,
    ContestEffect_StartleFrontMon_contest_effect,
    ContestEffect_StartlePrevMons_contest_effect,
    ContestEffect_StartlePrevMon2_contest_effect,
    ContestEffect_StartlePrevMons2_contest_effect,
    ContestEffect_ShiftJudgeAttention_contest_effect,
    ContestEffect_StartleMonWithJudgesAttention_contest_effect,
    ContestEffect_JamsOthersButMissOneTurn_contest_effect,
    ContestEffect_StartleMonsSameTypeAppeal_contest_effect,
    ContestEffect_StartleMonsCoolAppeal_contest_effect,
    ContestEffect_StartleMonsBeautyAppeal_contest_effect,
    ContestEffect_StartleMonsCuteAppeal_contest_effect,
    ContestEffect_StartleMonsSmartAppeal_contest_effect,
    ContestEffect_StartleMonsToughAppeal_contest_effect,
    ContestEffect_MakeFollowingMonNervous_contest_effect,
    ContestEffect_MakeFollowingMonsNervous_contest_effect,
    ContestEffect_WorsenConditionOfPrevMons_contest_effect,
    ContestEffect_BadlyStartlesMonsInGoodCondition_contest_effect,
    ContestEffect_BetterIfFirst_contest_effect,
    ContestEffect_BetterIfLast_contest_effect,
    ContestEffect_AppealAsGoodAsPrevOnes_contest_effect,
    ContestEffect_AppealAsGoodAsPrevOne_contest_effect,
    ContestEffect_BetterWhenLater_contest_effect,
    ContestEffect_QualityDependsOnTiming_contest_effect,
    ContestEffect_BetterIfSameType_contest_effect,
    ContestEffect_BetterIfDiffType_contest_effect,
    ContestEffect_AffectedByPrevAppeal_contest_effect,
    ContestEffect_ImproveConditionPreventNervousness_contest_effect,
    ContestEffect_BetterWithGoodCondition_contest_effect,
    ContestEffect_NextAppealEarlier_contest_effect,
    ContestEffect_NextAppealLater_contest_effect,
    ContestEffect_MakeScramblingTurnOrderEasier_contest_effect,
    ContestEffect_ScrambleNextTurnOrder_contest_effect,
    ContestEffect_ExciteAudienceInAnyContest_contest_effect,
    ContestEffect_BadlyStartleMonsWithGoodAppeals_contest_effect,
    ContestEffect_BetterWhenAudienceExcited_contest_effect,
    ContestEffect_DontExciteAudience_contest_effect,
};
