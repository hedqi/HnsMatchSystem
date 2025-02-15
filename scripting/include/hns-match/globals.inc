#if defined _globals_included
  #endinput
#endif

#define _globals_included

#define access ADMIN_MAP

#define TASK_TIMER 54345
#define HUD_PAUSE 23931

#define TASK_WAIT 12319
#define TASK_STARTED 13339

#define TASK_WAITCAP 13131

#define TASK_SURRENDER 55566


new g_PluginId;

enum NATCH_RULES {
	RULES_MR,
	RULES_TIMER,
	RULES_DUEL
}

new NATCH_RULES:g_iCurrentRules;
new g_iVoteRules[NATCH_RULES];

enum MATCH_STATUS {
	MATCH_NONE,
	MATCH_CAPTAINPICK,
	MATCH_CAPTAINKNIFE,
	MATCH_TEAMPICK,
	MATCH_TEAMKNIFE,
	MATCH_MAPPICK,
	MATCH_WAITCONNECT,
	MATCH_STARTED
}
new MATCH_STATUS:g_iMatchStatus;

enum MODE_STATES {
	STATE_DISABLED,
	STATE_PREPARE,
	STATE_PAUSED,
	STATE_ENABLED
}
new MODE_STATES:g_eMatchState;

enum HNS_TEAM {
	HNS_TEAM_B,
	HNS_TEAM_A
}

new HNS_TEAM:g_isTeamTT;

enum _:MatchInfo_s {
	e_mTeamSize,
	e_mTeamSizeTT,
	Float:e_flSidesTime[HNS_TEAM],
	e_iRoundsPlayed[HNS_TEAM],
	e_iMatchSwapped
};

new g_eMatchInfo[MatchInfo_s];

enum _:SurrenderData_s {
	bool:e_sStarted,
	e_sInitiator,
	Float:e_sFlDelay,
	Float:e_sFlTime
};
new g_eSurrenderData[SurrenderData_s];

new bool:g_bNoplay[MAX_PLAYERS + 1];
new bool:g_bPlayersListLoaded;

new Float:g_flRoundTime;

new g_szMapName[32]
new g_iHostageEnt;

// const
new const sndDenySelect[] = "common/wpn_denyselect.wav";
new const sndUseSound[] = "buttons/blip1.wav";

enum _: Forwards {
	MATCH_START,
	MATCH_RESET_ROUND,
	MATCH_FINISH,
	MATCH_CANCEL,
	HNS_ROUND_START,
	HNS_ROUND_END,
	HNS_ROUND_FREEZEEND
};

new g_hForwards[Forwards];

enum _: PlayerData_s {
	bool:PLAYER_MATCH,
	PLAYER_TEAM[16],
	PLAYER_SAVE_SWAP
};

new g_ePlayerData[MAX_PLAYERS + 1][PlayerData_s];

new Trie:g_PlayersLeaveData;

new bool:g_bPlayersLeaved;

enum _:PlayersLoad_s {
	e_pAuth[24],
	e_pTeam
};

new Array:g_aPlayersLoadData;

new g_szBuffer[2048];

enum SPEC_BACK {
	bool:sb_isSpec,
	TeamName:sb_hTeam
}

new g_eSpecBack[MAX_PLAYERS + 1][SPEC_BACK];

new g_msgMoney;