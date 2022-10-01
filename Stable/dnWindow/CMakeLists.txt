set(PROJECT_NAME dnWindow)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "README.TXT"
)
source_group("" FILES ${no_group_source_files})

set(Classes
    "Classes/DukeConsole.uc"
    "Classes/DukeIntro.uc"
    "Classes/UDukeRootWindow.uc"
)
source_group("Classes" FILES ${Classes})

set(Classes__Audio
    "Classes/UDukeAudioCW.uc"
    "Classes/UDukeAudioSC.uc"
    "Classes/UDukeAudioWindow.uc"
)
source_group("Classes\\Audio" FILES ${Classes__Audio})

set(Classes__Custom_Controls
    "Classes/UDukeArrowButton.uc"
    "Classes/UDukeColoredDynamicTextRow.uc"
    "Classes/UDukeConsoleWindow.uc"
    "Classes/UDukeDialogClientWindow.uc"
    "Classes/UDukeEmbeddedClient.uc"
    "Classes/UDukeFrameButton.uc"
    "Classes/UDukeFramedWindow.uc"
    "Classes/UDukeHTMLTextHandler.uc"
    "Classes/UDukeHTTPClient.uc"
    "Classes/UDukeLabelControl.uc"
    "Classes/UDukeMissionOverButton.uc"
    "Classes/UDukePageWindow.uc"
    "Classes/UDukeRaisedButton.uc"
    "Classes/UDukeTabControl.uc"
)
source_group("Classes\\Custom Controls" FILES ${Classes__Custom_Controls})

set(Classes__Desktop
    "Classes/UDukeButton.uc"
    "Classes/UDukeDesktopWindow.uc"
    "Classes/UDukeDesktopWindowBase.uc"
    "Classes/UDukeFakeIcon.uc"
)
source_group("Classes\\Desktop" FILES ${Classes__Desktop})

set(Classes__Game
    "Classes/UDukeGameOptionsCW.uc"
    "Classes/UDukeGameOptionsSC.uc"
    "Classes/UDukeGameWindow.uc"
)
source_group("Classes\\Game" FILES ${Classes__Game})

set(Classes__InGameWindow
    "Classes/NotifyButton.uc"
    "Classes/NotifyWindow.uc"
    "Classes/UDukeInGameButton.uc"
    "Classes/UDukeInGameWindow.uc"
    "Classes/UDukeInGameWindowClasses.uc"
    "Classes/UDukeInGameWindowSpectator.uc"
    "Classes/UDukeInGameWindowSpeech.uc"
    "Classes/UDukeInGameWindowTeams.uc"
)
source_group("Classes\\InGameWindow" FILES ${Classes__InGameWindow})

set(Classes__InGameWindow__Pulldown_Menu_Version
    "Classes/UDukeInGamePulldownClassesMenu.uc"
    "Classes/UDukeInGamePulldownMenu.uc"
    "Classes/UDukeInGamePulldownSpectatorMenu.uc"
    "Classes/UDukeInGamePulldownTauntMenu.uc"
    "Classes/UDukeInGamePulldownTeamsMenu.uc"
)
source_group("Classes\\InGameWindow\\Pulldown Menu Version" FILES ${Classes__InGameWindow__Pulldown_Menu_Version})

set(Classes__Key_Binder
    "Classes/UDukeControlsBinder.uc"
    "Classes/UDukeControlsCW.uc"
    "Classes/UDukeControlsSC.uc"
    "Classes/UDukeControlsWindow.uc"
)
source_group("Classes\\Key Binder" FILES ${Classes__Key_Binder})

set(Classes__Load_Game
    "Classes/UDukeLoadGameWindow.uc"
    "Classes/UDukeLoadGameWindowCW.uc"
)
source_group("Classes\\Load Game" FILES ${Classes__Load_Game})

set(Classes__LookandFeel
    "Classes/UDukeLookAndFeel.uc"
)
source_group("Classes\\LookandFeel" FILES ${Classes__LookandFeel})

set(Classes__Multiplayer__Create_Game
    "Classes/UDukeCreateMultiCW.uc"
    "Classes/UDukeCreateMultiSC.uc"
    "Classes/UDukeCreateMultiWindow.uc"
)
source_group("Classes\\Multiplayer\\Create Game" FILES ${Classes__Multiplayer__Create_Game})

set(Classes__Multiplayer__DukeNet_NOT_USED
    "Classes/DukeNetLink.uc"
    "Classes/UDukeBannerAd.uc"
    "Classes/UDukeDukeNetWindow.uc"
    "Classes/UDukeNetCW.uc"
    "Classes/UDukeNetSC.uc"
    "Classes/UDukeNetTabWindow.uc"
    "Classes/UDukeNetTabWindowCreate.uc"
    "Classes/UDukeNetTabWindowNews.uc"
)
source_group("Classes\\Multiplayer\\DukeNet NOT USED" FILES ${Classes__Multiplayer__DukeNet_NOT_USED})

set(Classes__Multiplayer__DukeNet_NOT_USED__ChatClient
    "Classes/UDukeNetChannelItem.uc"
    "Classes/UDukeNetChannelListBox.uc"
    "Classes/UDukeNetTabWindowChat.uc"
    "Classes/UDukeNetTextArea.uc"
    "Classes/UDukeNetUserItem.uc"
    "Classes/UDukeNetUserListBox.uc"
)
source_group("Classes\\Multiplayer\\DukeNet NOT USED\\ChatClient" FILES ${Classes__Multiplayer__DukeNet_NOT_USED__ChatClient})

set(Classes__Multiplayer__Join_Game
    "Classes/UDukeJoinMultiCW.uc"
    "Classes/UDukeJoinMultiSC.uc"
    "Classes/UDukeJoinMultiWindow.uc"
)
source_group("Classes\\Multiplayer\\Join Game" FILES ${Classes__Multiplayer__Join_Game})

set(Classes__Multiplayer__MapList
    "Classes/dnMapList.uc"
    "Classes/dnMapListBox.uc"
    "Classes/dnMapListCW.uc"
    "Classes/dnMapListExclude.uc"
    "Classes/dnMapListInclude.uc"
    "Classes/dnMapListSC.uc"
    "Classes/dnMapListWindow.uc"
)
source_group("Classes\\Multiplayer\\MapList" FILES ${Classes__Multiplayer__MapList})

set(Classes__Multiplayer__MutatorList
    "Classes/dnMutatorList.uc"
    "Classes/dnMutatorListBox.uc"
    "Classes/dnMutatorListCW.uc"
    "Classes/dnMutatorListExclude.uc"
    "Classes/dnMutatorListInclude.uc"
    "Classes/dnMutatorListSC.uc"
    "Classes/dnMutatorListWindow.uc"
)
source_group("Classes\\Multiplayer\\MutatorList" FILES ${Classes__Multiplayer__MutatorList})

set(Classes__Multiplayer__Password
    "Classes/UDukePasswordCW.uc"
    "Classes/UDukePasswordWindow.uc"
)
source_group("Classes\\Multiplayer\\Password" FILES ${Classes__Multiplayer__Password})

set(Classes__Multiplayer__Player_Setup
    "Classes/MeshActor.uc"
    "Classes/UDukePlayerMeshCW.uc"
    "Classes/UDukePlayerSetupCW.uc"
    "Classes/UDukePlayerSetupSC.uc"
    "Classes/UDukePlayerSetupTopCW.uc"
    "Classes/UDukePlayerSetupTopSC.uc"
    "Classes/UDukePlayerSetupWindow.uc"
)
source_group("Classes\\Multiplayer\\Player Setup" FILES ${Classes__Multiplayer__Player_Setup})

set(Classes__Multiplayer__Rules
    "Classes/UDukeMultiRulesBase.uc"
    "Classes/UDukeMultiRulesCW.uc"
    "Classes/UDukeMultiRulesSC.uc"
    "Classes/UDukeStartMatchCW.uc"
    "Classes/UDukeStartMatchSC.uc"
)
source_group("Classes\\Multiplayer\\Rules" FILES ${Classes__Multiplayer__Rules})

set(Classes__Multiplayer__Scoreboard
    "Classes/UDukeScoreboard.uc"
    "Classes/UDukeScoreboardCW.uc"
    "Classes/UDukeScoreboardGrid.uc"
    "Classes/UDukeScoreboardList.uc"
    "Classes/UDukeScoreboardMenu.uc"
    "Classes/UDukeScoreboardSC.uc"
    "Classes/UDukeScoreboardTauntMenu.uc"
)
source_group("Classes\\Multiplayer\\Scoreboard" FILES ${Classes__Multiplayer__Scoreboard})

set(Classes__Multiplayer__ServerBrowser
    "Classes/UDukeInfoCW.uc"
    "Classes/UDukeRightClickMenu.uc"
    "Classes/UDukeScreenshotCW.uc"
    "Classes/UDukeServerBrowserControlsCW.uc"
    "Classes/UDukeServerBrowserCW.uc"
    "Classes/UDukeServerBrowserSC.uc"
    "Classes/UDukeServerPing.uc"
)
source_group("Classes\\Multiplayer\\ServerBrowser" FILES ${Classes__Multiplayer__ServerBrowser})

set(Classes__Multiplayer__ServerBrowser__Factories
    "Classes/UDukeGSpyFact.uc"
    "Classes/UDukeGSpyLink.uc"
    "Classes/UDukeLocalFact.uc"
    "Classes/UDukeLocalLink.uc"
    "Classes/UDukeServerListFactory.uc"
)
source_group("Classes\\Multiplayer\\ServerBrowser\\Factories" FILES ${Classes__Multiplayer__ServerBrowser__Factories})

set(Classes__Multiplayer__ServerBrowser__Filters
    "Classes/UDukeBuddyList.uc"
    "Classes/UDukeBuddyListBox.uc"
    "Classes/UDukeRightClickBuddyMenu.uc"
    "Classes/UDukeServerFilterCW.uc"
    "Classes/UDukeServerFilterSC.uc"
)
source_group("Classes\\Multiplayer\\ServerBrowser\\Filters" FILES ${Classes__Multiplayer__ServerBrowser__Filters})

set(Classes__Multiplayer__ServerBrowser__Grids
    "Classes/UDukePlayerGrid.uc"
    "Classes/UDukePlayerList.uc"
    "Classes/UDukeRulesGrid.uc"
    "Classes/UDukeRulesList.uc"
    "Classes/UDukeServerGrid.uc"
    "Classes/UDukeServerList.uc"
)
source_group("Classes\\Multiplayer\\ServerBrowser\\Grids" FILES ${Classes__Multiplayer__ServerBrowser__Grids})

set(Classes__New_Game
    "Classes/UDukeNewGameWindow.uc"
    "Classes/UDukeNewGameWindowCW.uc"
    "Classes/UDukeNewGameWindowSC.uc"
)
source_group("Classes\\New Game" FILES ${Classes__New_Game})

set(Classes__Parent_Lock
    "Classes/UDukeParentLockWindow.uc"
    "Classes/UDukeParentLockWindowCW.uc"
    "Classes/UDukeParentLockWindowSC.uc"
)
source_group("Classes\\Parent Lock" FILES ${Classes__Parent_Lock})

set(Classes__Profile
    "Classes/UDukeProfileWindow.uc"
    "Classes/UDukeProfileWindowCW.uc"
)
source_group("Classes\\Profile" FILES ${Classes__Profile})

set(Classes__SOS
    "Classes/UDukeSOSCW.uc"
    "Classes/UDukeSOSSC.uc"
    "Classes/UDukeSOSWindow.uc"
)
source_group("Classes\\SOS" FILES ${Classes__SOS})

set(Classes__Save_Game
    "Classes/UDukeSaveEditBox.uc"
    "Classes/UDukeSaveGameWindow.uc"
    "Classes/UDukeSaveGameWindowCW.uc"
    "Classes/UDukeSaveGameWindowSC.uc"
    "Classes/UDukeSaveLoadGrid.uc"
    "Classes/UDukeSaveLoadList.uc"
)
source_group("Classes\\Save Game" FILES ${Classes__Save_Game})

set(Classes__Video
    "Classes/UDukeVideoCW.uc"
    "Classes/UDukeVideoSC.uc"
    "Classes/UDukeVideoWindow.uc"
)
source_group("Classes\\Video" FILES ${Classes__Video})

set(ALL_FILES
    ${no_group_source_files}
    ${Classes}
    ${Classes__Audio}
    ${Classes__Custom_Controls}
    ${Classes__Desktop}
    ${Classes__Game}
    ${Classes__InGameWindow}
    ${Classes__InGameWindow__Pulldown_Menu_Version}
    ${Classes__Key_Binder}
    ${Classes__Load_Game}
    ${Classes__LookandFeel}
    ${Classes__Multiplayer__Create_Game}
    ${Classes__Multiplayer__DukeNet_NOT_USED}
    ${Classes__Multiplayer__DukeNet_NOT_USED__ChatClient}
    ${Classes__Multiplayer__Join_Game}
    ${Classes__Multiplayer__MapList}
    ${Classes__Multiplayer__MutatorList}
    ${Classes__Multiplayer__Password}
    ${Classes__Multiplayer__Player_Setup}
    ${Classes__Multiplayer__Rules}
    ${Classes__Multiplayer__Scoreboard}
    ${Classes__Multiplayer__ServerBrowser}
    ${Classes__Multiplayer__ServerBrowser__Factories}
    ${Classes__Multiplayer__ServerBrowser__Filters}
    ${Classes__Multiplayer__ServerBrowser__Grids}
    ${Classes__New_Game}
    ${Classes__Parent_Lock}
    ${Classes__Profile}
    ${Classes__SOS}
    ${Classes__Save_Game}
    ${Classes__Video}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})

