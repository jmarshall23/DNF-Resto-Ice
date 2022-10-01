set(PROJECT_NAME UBrowser)

################################################################################
# Source groups
################################################################################
set(Classes
    "../Classes/UBrowser.upkg"
    "../Classes/UBrowserBannerAd.uc"
    "../Classes/UBrowserBannerBar.uc"
    "../Classes/UBrowserBrowserButton.uc"
    "../Classes/UBrowserBufferedTCPLink.uc"
    "../Classes/UBrowserColorIRCTextArea.uc"
    "../Classes/UBrowserConsole.uc"
    "../Classes/UBrowserEditFavoriteCW.uc"
    "../Classes/UBrowserEditFavoriteWindow.uc"
    "../Classes/UBrowserFavoriteServers.uc"
    "../Classes/UBrowserFavoritesFact.uc"
    "../Classes/UBrowserFavoritesMenu.uc"
    "../Classes/UBrowserGSpyFact.uc"
    "../Classes/UBrowserGSpyLink.uc"
    "../Classes/UBrowserHTTPClient.uc"
    "../Classes/UBrowserHTTPFact.uc"
    "../Classes/UBrowserHTTPLink.uc"
    "../Classes/UBrowserInfoClientWindow.uc"
    "../Classes/UBrowserInfoMenu.uc"
    "../Classes/UBrowserInfoWindow.uc"
    "../Classes/UBrowserIRCChannelMenu.uc"
    "../Classes/UBrowserIRCChannelPage.uc"
    "../Classes/UBrowserIRCJoinMenu.uc"
    "../Classes/UBrowserIRCLink.uc"
    "../Classes/UBrowserIRCPageBase.uc"
    "../Classes/UBrowserIRCPrivateMenu.uc"
    "../Classes/UBrowserIRCPrivPage.uc"
    "../Classes/UBrowserIRCSetupClient.uc"
    "../Classes/UBrowserIRCSystemMenu.uc"
    "../Classes/UBrowserIRCSystemPage.uc"
    "../Classes/UBrowserIRCTextArea.uc"
    "../Classes/UBrowserIRCUserList.uc"
    "../Classes/UBrowserIRCUserListBox.uc"
    "../Classes/UBrowserIRCWindow.uc"
    "../Classes/UBrowserLocalFact.uc"
    "../Classes/UBrowserLocalLink.uc"
    "../Classes/UBrowserMainClientWindow.uc"
    "../Classes/UBrowserMainWindow.uc"
    "../Classes/UBrowserNewFavoriteCW.uc"
    "../Classes/UBrowserNewFavoriteWindow.uc"
    "../Classes/UBrowserOpenCW.uc"
    "../Classes/UBrowserOpenWindow.uc"
    "../Classes/UBrowserPlayerGrid.uc"
    "../Classes/UBrowserPlayerList.uc"
    "../Classes/UBrowserRightClickMenu.uc"
    "../Classes/UBrowserRootWindow.uc"
    "../Classes/UBrowserRulesGrid.uc"
    "../Classes/UBrowserRulesList.uc"
    "../Classes/UBrowserScreenshotCW.uc"
    "../Classes/UBrowserServerGrid.uc"
    "../Classes/UBrowserServerList.uc"
    "../Classes/UBrowserServerListFactory.uc"
    "../Classes/UBrowserServerListWindow.uc"
    "../Classes/UBrowserServerPing.uc"
    "../Classes/UBrowserSubsetFact.uc"
    "../Classes/UBrowserSubsetList.uc"
    "../Classes/UBrowserSupersetList.uc"
    "../Classes/UBrowserUpdateServerLink.uc"
    "../Classes/UBrowserUpdateServerTextArea.uc"
    "../Classes/UBrowserUpdateServerWindow.uc"
)
source_group("Classes" FILES ${Classes})

set(ALL_FILES
    ${Classes}
)

add_custom_target(${PROJECT_NAME} SOURCES ${ALL_FILES})

