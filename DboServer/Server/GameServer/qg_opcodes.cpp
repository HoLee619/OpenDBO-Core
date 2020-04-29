#include "stdafx.h"
#include "qg_opcodes.h"
#include "QueryServerSession.h"


CQG_Opcodes::CQG_Opcodes()
{
	BuildOpcodeList();
}


CQG_Opcodes::~CQG_Opcodes()
{
	delete[] aOpcodeHandler;
}


void CQG_Opcodes::BuildOpcodeList()
{
	for (int i = 0; i < QG_OPCODE_END - QG_OPCODE_BEGIN; i++)
		aOpcodeHandler[i] = new OpcodeHandler<CQueryServerSession>;

	StoreOpcode(QG_ITEM_CREATE_RES, "QG_ITEM_CREATE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvCreateItemRes);
	StoreOpcode(QG_ITEM_MOVE_RES, "QG_ITEM_MOVE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemMoveRes);
	StoreOpcode(QG_ITEM_MOVE_STACK_RES, "QG_ITEM_MOVE_STACK_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemMoveStackRes);
	StoreOpcode(QG_ITEM_AUTO_EQUIP_RES, "QG_ITEM_AUTO_EQUIP_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemAutoEquipRes);
	StoreOpcode(QG_LOAD_PC_BANK_DATA_RES, "QG_LOAD_PC_BANK_DATA_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvLoadBankDataRes);
	StoreOpcode(QG_LOAD_PC_BANK_DATA, "QG_LOAD_PC_BANK_DATA", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvLoadBankData);
	StoreOpcode(QG_BANK_MOVE_RES, "QG_BANK_MOVE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBankMoveRes);
	StoreOpcode(QG_BANK_MOVE_STACK_RES, "QG_BANK_MOVE_STACK_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBankMoveStackRes);
	StoreOpcode(QG_BANK_BUY_RES, "QG_BANK_BUY_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBankBuyRes);
	StoreOpcode(QG_BANK_ADD_WITH_COMMAND_RES, "QG_BANK_ADD_WITH_COMMAND_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBankAddWithCommandRes);
	StoreOpcode(QG_SHOP_BUY_RES, "QG_SHOP_BUY_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvShopBuyRes);
	StoreOpcode(QG_TRADE_RES, "QG_TRADE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvTradeRes);
	StoreOpcode(QG_MAIL_START_RES, "QG_MAIL_START_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMailStartRes);
	StoreOpcode(QG_MAIL_SEND_RES, "QG_MAIL_SEND_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMailSendRes);
	StoreOpcode(QG_MAIL_RETURN_RES, "QG_MAIL_RETURN_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMailReturnRes);
	StoreOpcode(QG_MAIL_RELOAD_RES, "QG_MAIL_RELOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMailReloadRes);
	StoreOpcode(QG_MAIL_LOAD_RES, "QG_MAIL_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMailLoadRes);
	StoreOpcode(QG_MAIL_ITEM_RECEIVE_RES, "QG_MAIL_ITEM_RECEIVE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMailItemReceiveRes);
	StoreOpcode(QG_PORTAL_START_RES, "QG_PORTAL_START_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPortalLoadRes);
	StoreOpcode(QG_GUILD_BANK_LOAD_RES, "QG_GUILD_BANK_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvGuildBankLoadRes);
	StoreOpcode(QG_GUILD_BANK_MOVE_RES, "QG_GUILD_BANK_MOVE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvGuildBankMoveRes);
	StoreOpcode(QG_GUILD_BANK_MOVE_STACK_RES, "QG_GUILD_BANK_MOVE_STACK_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvGuildBankMoveStackRes);
	StoreOpcode(QG_GUILD_BANK_ZENNY_RES, "QG_GUILD_BANK_ZENNY_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvGuildBankZeniRes);
	StoreOpcode(QG_GUILD_BANK_LOAD_DATA, "QG_GUILD_BANK_LOAD_DATA", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvGuildBankLoadData);

	StoreOpcode(QG_BUDOKAI_DATA_RES, "QG_BUDOKAI_DATA_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiDataRes);
	StoreOpcode(QG_BUDOKAI_INIT_DATA_NFY, "QG_BUDOKAI_INIT_DATA_NFY", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiInitDataNfy);
	StoreOpcode(QG_BUDOKAI_INIT_DATA_RES, "QG_BUDOKAI_INIT_DATA_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiInitDataRes);
	StoreOpcode(QG_BUDOKAI_UPDATE_STATE_RES, "QG_BUDOKAI_UPDATE_STATE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiUpdateStateRes);
	StoreOpcode(QG_BUDOKAI_UPDATE_MATCH_STATE_RES, "QG_BUDOKAI_UPDATE_MATCH_STATE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiUpdateMatchStateRes);
	StoreOpcode(QG_BUDOKAI_UPDATE_CLEAR_RES, "QG_BUDOKAI_UPDATE_CLEAR_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiUpdateClearRes);

	StoreOpcode(QG_RANKPOINT_RESET_RES, "QG_RANKPOINT_RESET_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::OnInvalid);
	StoreOpcode(QG_RANKBATTLE_ALLOW_RES, "QG_RANKBATTLE_ALLOW_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::OnInvalid);

	StoreOpcode(QG_BUDOKAI_INDIVIDUAL_ALLOW_REGISTER_RES, "QG_BUDOKAI_INDIVIDUAL_ALLOW_REGISTER_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiIndividualAllowRegisterRes);
	StoreOpcode(QG_BUDOKAI_JOIN_INDIVIDUAL_RES, "QG_BUDOKAI_JOIN_INDIVIDUAL_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiJoinIndividualRes);
	StoreOpcode(QG_BUDOKAI_LEAVE_INDIVIDUAL_RES, "QG_BUDOKAI_LEAVE_INDIVIDUAL_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiLeaveIndividualRes);
	StoreOpcode(QG_BUDOKAI_INDIVIDUAL_SELECTION_RES, "QG_BUDOKAI_INDIVIDUAL_SELECTION_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiIndividualSelectionRes);
	StoreOpcode(QG_BUDOKAI_INDIVIDUAL_LIST_START, "QG_BUDOKAI_INDIVIDUAL_LIST_START", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiIndividualListStart);
	StoreOpcode(QG_BUDOKAI_INDIVIDUAL_LIST_DATA, "QG_BUDOKAI_INDIVIDUAL_LIST_DATA", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiIndividualListData);
	StoreOpcode(QG_BUDOKAI_INDIVIDUAL_LIST_END, "QG_BUDOKAI_INDIVIDUAL_LIST_END", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiIndividualListEnd);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ADD_ENTRY_LIST_RES, "QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ADD_ENTRY_LIST_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentIndividualAddEntryListRes);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_START, "QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_START", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentIndividualEntryListStart);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_DATA, "QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_DATA", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentIndividualEntryListData);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_END, "QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_LIST_END", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentIndividualEntryListEnd);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ADD_MATCH_RESULT_RES, "QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_ADD_MATCH_RESULT_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentIndividualAddMatchResultRes);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_MATCH_RESULT_RES, "QG_BUDOKAI_TOURNAMENT_INDIVIDUAL_MATCH_RESULT_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentIndividualMatchResultRes);
	StoreOpcode(QG_BUDOKAI_TEAM_ALLOW_REGISTER_RES, "QG_BUDOKAI_TEAM_ALLOW_REGISTER_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTeamAllowRegisterRes);
	StoreOpcode(QG_BUDOKAI_JOIN_TEAM_RES, "QG_BUDOKAI_JOIN_TEAM_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiJoinTeamRes);
	StoreOpcode(QG_BUDOKAI_LEAVE_TEAM_RES, "QG_BUDOKAI_LEAVE_TEAM_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiLeaveTeamRes);
	StoreOpcode(QG_BUDOKAI_LEAVE_TEAM_MEMBER_RES, "QG_BUDOKAI_LEAVE_TEAM_MEMBER_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiLeaveTeamMemberRes);
	StoreOpcode(QG_BUDOKAI_TEAM_SELECTION_RES, "QG_BUDOKAI_TEAM_SELECTION_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTeamSelectionRes);
	StoreOpcode(QG_BUDOKAI_TEAM_LIST_START, "QG_BUDOKAI_TEAM_LIST_START", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTeamListStart);
	StoreOpcode(QG_BUDOKAI_TEAM_LIST_DATA, "QG_BUDOKAI_TEAM_LIST_DATA", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTeamListData);
	StoreOpcode(QG_BUDOKAI_TEAM_LIST_END, "QG_BUDOKAI_TEAM_LIST_END", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTeamListEnd);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_TEAM_ADD_ENTRY_LIST_RES, "QG_BUDOKAI_TOURNAMENT_TEAM_ADD_ENTRY_LIST_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentTeamAddEntryListRes);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_START, "QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_START", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentTeamEntryListStart);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_DATA, "QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_DATA", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentTeamEntryListData);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_END, "QG_BUDOKAI_TOURNAMENT_TEAM_ENTRY_LIST_END", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentTeamEntryListEnd);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_TEAM_ADD_MATCH_RESULT_RES, "QG_BUDOKAI_TOURNAMENT_TEAM_ADD_MATCH_RESULT_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentTeamAddMatchResultRes);
	StoreOpcode(QG_BUDOKAI_TOURNAMENT_TEAM_MATCH_RESULT_RES, "QG_BUDOKAI_TOURNAMENT_TEAM_MATCH_RESULT_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiTournamentTeamMatchResultRes);
	StoreOpcode(QG_BUDOKAI_JOIN_INFO_RES, "QG_BUDOKAI_JOIN_INFO_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiJoinInfoRes);
	StoreOpcode(QG_BUDOKAI_JOIN_STATE_RES, "QG_BUDOKAI_JOIN_STATE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiJoinStateRes);
	StoreOpcode(QG_BUDOKAI_HISTORY_WRITE_RES, "QG_BUDOKAI_HISTORY_WRITE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiHistoryWriteRes);
	StoreOpcode(QG_BUDOKAI_HISTORY_WINNER_PLAYER_RES, "QG_BUDOKAI_HISTORY_WINNER_PLAYER_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiHistoryWinnerPlayerRes);
	StoreOpcode(QG_BUDOKAI_JOIN_STATE_LIST_RES, "QG_BUDOKAI_JOIN_STATE_LIST_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiJoinStateListRes);
	StoreOpcode(QG_BUDOKAI_JOIN_STATE_LIST_DATA, "QG_BUDOKAI_JOIN_STATE_LIST_DATA", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiJoinStateListData);
	StoreOpcode(QG_BUDOKAI_SET_OPEN_TIME_RES, "QG_BUDOKAI_SET_OPEN_TIME_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvBudokaiSetOpenTimeRes);
	StoreOpcode(QG_MATCH_REWARD_RES, "QG_MATCH_REWARD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMatchRewardRes);

	StoreOpcode(QG_SHOP_EVENTITEM_BUY_RES, "QG_SHOP_EVENTITEM_BUY_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvShopEventItemBuyRes);
	StoreOpcode(QG_SHOP_GAMBLE_BUY_RES, "QG_SHOP_GAMBLE_BUY_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvShopGambleBuyRes);

	StoreOpcode(QG_BUDOKAI_ADD_MUDOSA_POINT_RES, "QG_BUDOKAI_ADD_MUDOSA_POINT_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::OnInvalid); //TODO

	StoreOpcode(QG_SKILL_INIT_RES, "QG_SKILL_INIT_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvSkillInitRes);
	StoreOpcode(QG_HOIPOIMIX_ITEM_MAKE_RES, "QG_HOIPOIMIX_ITEM_MAKE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvHoipoiItemMakeRes);
	StoreOpcode(QG_ITEM_CHANGE_DURATIONTIME_RES, "QG_ITEM_CHANGE_DURATIONTIME_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemChangeDurationTimeRes);
	StoreOpcode(QG_SHOP_NETPYITEM_BUY_RES, "QG_SHOP_NETPYITEM_BUY_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvShopNetpyItemBuyRes);
	StoreOpcode(QG_DURATION_ITEM_BUY_RES, "QG_DURATION_ITEM_BUY_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvDurationItemBuyRes);
	StoreOpcode(GQ_CASHITEM_HLSHOP_REFRESH_RES, "GQ_CASHITEM_HLSHOP_REFRESH_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvCashItemRefreshRes);
	StoreOpcode(QG_CASHITEM_INFO, "QG_CASHITEM_INFO", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvCashItemInfo);
	StoreOpcode(QG_CASHITEM_INFO_RES, "QG_CASHITEM_INFO_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvCashItemInfoRes);
	StoreOpcode(QG_CASHITEM_MOVE_RES, "QG_CASHITEM_MOVE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvCashItemMoveRes);
	StoreOpcode(QG_CASHITEM_UNPACK_RES, "QG_CASHITEM_UNPACK_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvCashitemUnpackRes);
	StoreOpcode(QG_CASHITEM_BUY_RES, "QG_CASHITEM_BUY_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvCashitemBuyRes);
	StoreOpcode(QG_PC_DATA_LOAD_RES, "QG_PC_DATA_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcDataLoadRes);
	StoreOpcode(QG_PC_ITEM_LOAD_RES, "QG_PC_ITEM_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcItemLoadRes);
	StoreOpcode(QG_PC_SKILL_LOAD_RES, "QG_PC_SKILL_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcSkillLoadRes);
	StoreOpcode(QG_PC_BUFF_LOAD_RES, "QG_PC_BUFF_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcBuffLoadRes);
	StoreOpcode(QG_PC_HTB_LOAD_RES, "QG_PC_HTB_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcHtbSkillLoadRes);
	StoreOpcode(QG_PC_QUEST_ITEM_LOAD_RES, "QG_PC_QUEST_ITEM_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcQuestItemLoadRes);
	StoreOpcode(QG_PC_QUEST_COMPLETE_LOAD_RES, "QG_PC_QUEST_COMPLETE_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcQuestCompleteLoadRes);
	StoreOpcode(QG_PC_QUEST_PROGRESS_LOAD_RES, "QG_PC_QUEST_PROGRESS_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcQuestProgressLoadRes);
	StoreOpcode(QG_PC_QUICK_SLOT_LOAD_RES, "QG_PC_QUICK_SLOT_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcQuickSlotLoadRes);
	StoreOpcode(QG_PC_SHORTCUT_LOAD_RES, "QG_PC_SHORTCUT_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcShortCutLoadRes);
	StoreOpcode(QG_PC_ITEM_RECIPE_LOAD_RES, "QG_PC_ITEM_RECIPE_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcItemRecipeLoadRes);
	StoreOpcode(QG_MAIL_START_INFO, "QG_MAIL_START_INFO", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMailStartInfo);
	StoreOpcode(QG_MAIL_LOAD_INFO, "QG_MAIL_LOAD_INFO", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMailLoadInfo);
	StoreOpcode(QG_QUICK_TELEPORT_INFO_LOAD_RES, "QG_QUICK_TELEPORT_INFO_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvQuickTeleportInfoLoadRes);
	StoreOpcode(QG_PC_ITEM_COOL_TIME_LOAD_RES, "QG_PC_ITEM_COOL_TIME_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcItemCoolTimeLoadRes);
	StoreOpcode(QG_CASHITEM_SEND_GIFT_RES, "QG_CASHITEM_SEND_GIFT_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvCashitemSendGiftRes);
	StoreOpcode(QG_PC_MASCOT_LOAD_RES, "QG_PC_MASCOT_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvPcMascotLoadRes);
	StoreOpcode(QG_MATERIAL_DISASSEMBLE_RES, "QG_MATERIAL_DISASSEMBLE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMaterialDisassembleRes);
	StoreOpcode(QG_ITEM_SOCKET_INSERT_BEAD_RES, "QG_ITEM_SOCKET_INSERT_BEAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemSocketInsertBeadRes);
	StoreOpcode(QG_ITEM_SOCKET_DESTROY_BEAD_RES, "QG_ITEM_SOCKET_DESTROY_BEAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemSocketDestroyBeadRes);
	StoreOpcode(QG_CASHITEM_PUBLIC_BANK_ADD_RES, "QG_CASHITEM_PUBLIC_BANK_ADD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvCashItemPublicBankAddRes);
	StoreOpcode(QG_ITEM_EXCHANGE_RES, "QGSEND_SERVER_RELAY_DATA", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemExchangeRes);
	StoreOpcode(QG_CHARACTER_RENAME_RES, "QG_CHARACTER_RENAME_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvCharacterRenameRes);
	StoreOpcode(QG_ITEM_CHANGE_OPTION_RES, "QG_ITEM_CHANGE_OPTION_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemChangeOptionRes);
	StoreOpcode(QG_WAGUWAGUMACHINE_COIN_INCREASE_RES, "QG_WAGUWAGUMACHINE_COIN_INCREASE_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvWaguWaguMachineCoinIncreaseRes);
	StoreOpcode(QG_DYNAMIC_FIELD_SYSTEM_COUNTING_RES, "QG_DYNAMIC_FIELD_SYSTEM_COUNTING_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvDynamicFieldSystemCountingRes);
	StoreOpcode(QG_ITEM_SEAL_RES, "QG_ITEM_SEAL_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemSealRes);
	StoreOpcode(QG_ITEM_SEAL_EXTRACT_RES, "QG_ITEM_SEAL_EXTRACT_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemSealExtractRes);

	StoreOpcode(QG_DRAGONBALL_SCRAMBLE_END_NFY, "QG_DRAGONBALL_SCRAMBLE_END_NFY", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvDragonballScrambleEndNfy);
	StoreOpcode(QG_ITEM_UPGRADE_BY_COUPON_RES, "QG_ITEM_UPGRADE_BY_COUPON_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemUpgradeByCouponRes);
	StoreOpcode(QG_ITEM_GRADEINIT_BY_COUPON_RES, "QG_ITEM_GRADEINIT_BY_COUPON_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvItemGradeInitByCouponRes);
	StoreOpcode(QG_EVENT_REWARD_LOAD_INFO, "QG_EVENT_REWARD_LOAD_INFO", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvEventRewardLoadInfo);
	StoreOpcode(QG_EVENT_REWARD_LOAD_RES, "QG_EVENT_REWARD_LOAD_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvEventRewardLoadRes);
	StoreOpcode(QG_EVENT_REWARD_SELECT_RES, "QG_EVENT_REWARD_SELECT_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvEventRewardSelectRes);

	StoreOpcode(QG_MASCOT_SEAL_SET_RES, "QG_MASCOT_SEAL_SET_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMascotSealSetRes);
	StoreOpcode(QG_MASCOT_SEAL_CLEAR_RES, "QG_MASCOT_SEAL_CLEAR_RES", PROCESS_THREADUNSAFE, &CQueryServerSession::RecvMascotSealClearRes);
	
}

