import QtQuick 2.4
import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import SerialPortLib 1.0
import SerialPortSettingsLib 1.0
import CommLinkSettingsLib 1.0
import LocalStringsLib 1.0
import GStyleLib 1.0

ApplicationWindow {
    id: mainWindowWithStackView
    title: "ArduECUSimulator v1.0"
    width: GStyle.windowWidth()
    height: GStyle.windowHeight()
    visible: true
    signal sendPush()
    //flags: Qt.Window | Qt.FramelessWindowHint // | Qt.WindowCloseButtonHint | Qt.CustomizeWindowHint | Qt.WindowTitleHint | Qt.FramelessWindowHint
    //    visibility: Window.FullScreen
    property alias fontLdr: fontLdr
//    property alias navbar: navBar

    MessageBox{
        id: subscriptionAlert
        messageDetails :  LocalStrings.getLocalTextValue("ok")
        messageDescription: ""
        height: GStyle.windowHeight() * 0.21
        onOkButtonClickSignal: {
            subscriptionAlert.close()
        }
    }

    FontHelper{
        id : fontLdr
    }


    NavBar {
        id:navBar
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        header: ""
        onClickedMenu: print('Button onClicked')
    }


    Rectangle{
        id: stackViewRectangle
        width: mainWindowWithStackView.width
        height: mainWindowWithStackView.height-navBar.height
        anchors.top: navBar.bottom
//        anchors.topMargin:mainWindowWithStackView.height
        border.color: "#333333"
        StackView {
            id: mainStackView
            initialItem: mainDashBoard//mainMyserilPortStackView
            anchors.fill: parent
            property MyserilPort mainMyserilPortStackView: MyserilPort{
                onSendPushNewProject: {
                    mainStackView.push(mainStackView.mainDashBoard)
                }
            }

            property MainGridview mainDashBoard: MainGridview{

            }
        }
    }
    function exitToDashBoard()
    {
        mainStackView.pop(mainStackView.mainDashboardStackView)
    }
    function getPreviousViewName()
    {
        var previousItem = mainStackView.get(mainStackView.depth-1-1) //index start from 0 and depth start from 1, need to go extra one view back
        return previousItem.objectName
    }
    function getCurrentViewName()
    {
        var previousItem = mainStackView.get(mainStackView.depth-1) //index start from 0 and depth start from 1, need to go extra one view back
        return previousItem.objectName
    }

    function getWndWidth()
    {
        return mainStackView.width
    }

    function getWndHeight()
    {
        return mainStackView.height
    }

    function getStdButtonWidth()
    {
        return mainStackView.width * 0.1
    }

    function getStdButtonHeight()
    {
        return mainStackView.height * 0.05
    }

    function getFontSize(fontType)
    {
        var scaleFactor = 0
        if(mainStackView.height < mainStackView.width)
            scaleFactor = mainStackView.height
        else
            scaleFactor = mainStackView.width

        if(fontType === "H0")
        {
            return scaleFactor * 0.1
        }
        else if(fontType === "H1")
        {
            return scaleFactor * 0.08
        }
        else if(fontType === "H2")
        {
            return scaleFactor * 0.06
        }
        else if(fontType === "H3")
        {
            return scaleFactor * 0.04
        }
        else if(fontType === "H4")
        {
            return scaleFactor * 0.02
        }
        else if(fontType === "H5")
        {
            return scaleFactor * 0.015
        }
        else if(fontType === "H6")
        {
            return scaleFactor * 0.01
        }
        else if(fontType === "S")
        {
            return scaleFactor * 0.01
        }
        else if(fontType === "M")
        {
            return scaleFactor * 0.1
        }
        else if(fontType === "L")
        {
             return scaleFactor * 0.2
        }
        else
        {
            console.error("Font size of present ",fontType)
        }
    }
}
