import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtGraphicalEffects  1.12
import QtQuick 2.6
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import QtQuick 2.2
import QtQuick.Dialogs 1.1
import ComHelperLib 1.0
import SerialPortSettingsLib 1.0
import CommLinkSettingsLib 1.0
import LocalStringsLib 1.0
import GStyleLib 1.0
import "CustomeWidget/CustomeCombo"
import "CustomeWidget/ButtonRound"

Item {
    id:mainWindowSerialPort
    objectName: qsTr("ComHelperWnd")
    visible: true
    width: GStyle.windowWidth()
    height: GStyle.windowHeight()
    signal sendPushNewProject()
    property var connectionTargetMessage: null
    property int  dataBit : 8;
    property int  parity : 1;
    property var nextScreen;
    property int screen;

    onFocusChanged: {
        if(focus)
        {
            mainWindowSerialPort.connectionTargetMessage = ComHelper
            serialUpdateTimer.start()
        }
    }

    function onPop()
    {
        mainWindowSerialPort.connectionTargetMessage = null
        serialUpdateTimer.stop()
    }

    Keys.onReleased: {
        if(event.key === Qt.Key_Return || event.key === Qt.Key_Enter)
        {
            connectButtonRect.color =  GStyle.gP("themeDefaultColor")//"#48B0E5"
            disconnectButtonRect.color = GStyle.whiteColor()//"#FFFFFF"
            connectButtonText.color = GStyle.whiteColor()//"#FFFFFF"
            disconnectButtonText.color = GStyle.gP("themeDefaultColor")//"#48B0E5"
            var tempxy;
            if(parity  == 1)
            {
                tempxy = "None"
            }
            else if(parity == 2)
            {
                tempxy = "Even"
            }
            else
            {
                tempxy = "Odd"
            }

            var dataBitSelect;
            if(dataBit == 6)
            {
                dataBitSelect = "6"
            }

            if(dataBit == 7)
            {
                dataBitSelect = "7"
            }
            if(dataBit == 8)
            {
                dataBitSelect = "8"
            }

            CommLinkSettings.connectSerialPort(serialPortSelector.currentText.split(' ')[0], baudRateSelector.currentText,
                                               dataBitSelect, tempxy,flowControlSelector.currentText)

            ComHelper.openSerialPort();
            if(ComHelper.isSerialPortOpen())
            {
                //                    mainStackView.push(mainStackView.mainNewProjectStackView)
                //                    loader.source = "NewProject.qml"   //"NewProject.qml"
                //                    mainWindowSerialPort.close();
            }
        }
    }


    KeyNavigation.tab: connectButton


    function setNextScreen(screen)
    {
        nextScreen = screen;
        if(nextScreen === 0)
        {
            mainStackView.push(mainStackView.mainNewProjectStackView)
        }
        if(nextScreen === 1)
        {
            mainStackView.push(mainStackView.mainSensorStackView)
        }

    }

    ProgressBarCustom{
        id: progressBar
        //        parent: mainWindowWithStackView
        visible: false
        anchors.centerIn: parent
        description: "Please wait while downloading parameters."
        width: parent.width * 0.5
        height: parent.height * 0.2
        callAfterComplete:comp
        updateProgress:update
        onCancel:comp
    }

    function comp()
    {        
        ComHelper.callAfterParameterDownload()
        mainStackView.pop()
        progressBar.end()
    }

    function update()
    {        
        var progCount = ComHelper.updateProgressBarValue()
        if(progCount>100)
            serialUpdateTimer.stop()
        return (progCount*100)
    }
    MessageBox{
        id: commlinkmsg
        messageDescription: ""
        onOkButtonClickSignal: {            
            commlinkmsg.hide()
        }
    }

    MessageBox{
        id: serialPortDisconnectedMessage
        messageDescription: "Serial Port Disconnected!"
        onOkButtonClickSignal: {
            mainWindowSerialPort.connectionTargetMessage = null
            serialPortDisconnectedMessage.hide()
            mainStackView.pop(mainStackView.mainDashboardStackView)
        }

    }

    Timer{
        id: serialUpdateTimer
        interval: 1000
        running: true
        repeat: true
        onTriggered: serialPortSelector.model = CommLinkSettings.getSerialPort()
    }

    SerialPortSettings{
        id: serialPortSettings
    }

    /*-------------------------- Communication Link Settings ---------------------------*/
    Rectangle {
        id : mainCommsettingsRect
        width: parent.width * 0.5
        height: parent.height * 0.7
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: navBar.height
        Rectangle {
            id : commLinkLabelRect
            visible: true
            height: mainCommsettingsRect.height * 0.05
            width: mainCommsettingsRect.width * 0.7
            anchors.horizontalCenter: mainCommsettingsRect.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: parent.height * 0.05
            Text {
                id: commLinkLabelText
                text: LocalStrings.getLocalTextValue("commlinkSettings")
                anchors.verticalCenter: parent.verticalCenter
                font.family: fontLdr.montserratRegular
                font.pixelSize: getFontSize("H4")//16
                font.letterSpacing: 2.77
            }
        }

        CustomeCombo {
            id : serialPortSelector
            anchors.horizontalCenter: mainCommsettingsRect.horizontalCenter
            anchors.top: commLinkLabelRect.bottom
            anchors.topMargin: parent.height * 0.05
            font.pixelSize:  getFontSize("H4")//16
            font.family: fontLdr.robotoRegular
            opacity: 0.8
            model: CommLinkSettings.getSerialPort()
            title: "Serial Port"
        }

        CustomeCombo {
            id : baudRateSelector
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: serialPortSelector.bottom
            anchors.topMargin: parent.height * 0.05
            font.pixelSize:  getFontSize("H4")//16
            font.family: fontLdr.robotoRegular
            opacity: 0.8
            model: [ "9600",
                "19200",
                "38400",
                "57600",
                "115200" ]
            title: "Baud Rate"
        }

        Rectangle{
            id: dataBitRect
            height: baudRateSelector.height
            width: baudRateSelector.width
            anchors.top: baudRateSelector.bottom
            anchors.topMargin: parent.height * 0.05
            anchors.horizontalCenter: mainCommsettingsRect.horizontalCenter
            //border.width: 1
            Label{
                id: dataBitsText
                anchors.verticalCenter: dataBitRect.verticalCenter
                anchors.left: dataBitRect.left
                height: dataBitRect.height
                width: dataBitRect.width * 0.2
                background: Rectangle{
                    //border.width: 1
                }

                Text{
                    id: dataBitsText1
                    anchors.left: dataBitsText.left
                    anchors.leftMargin: dataBitsText.width * 0.2
                    text: qsTr("Data Bits")
                    anchors.centerIn: parent
                    font.family: fontLdr.robotoRegular
                    font.weight: "DemiBold"
                    font.pixelSize: getFontSize("H4")
                    color: GStyle.blackColor()
                    opacity: 0.6
                }
            }

            WGroup{
                id : btnGrpDaataBit
            }

            PlainButton{
                id : dataBitsOption1
                height: dataBitRect.height
                width: dataBitRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: dataBitsText.right
                anchors.leftMargin: dataBitRect.width * 0.05
                text: "6"
                group: btnGrpDaataBit
                onButtonClicked: {
                    dataBit = 6;
                }
            }

            PlainButton{
                id : dataBitsOption2
                height: dataBitRect.height
                width: dataBitRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: dataBitsOption1.right
                anchors.leftMargin: dataBitRect.width * 0.05                
                text: "7"
                group: btnGrpDaataBit
                onButtonClicked: {
                    dataBit = 7;
                }
            }

            PlainButton{
                id : dataBitsOption3
                height: dataBitRect.height
                width: dataBitRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: dataBitsOption2.right
                anchors.leftMargin: dataBitRect.width * 0.05
                text: "8"
                state: "selected"
                group: btnGrpDaataBit
                onButtonClicked: {
                    dataBit = 8;
                }
            }
        }

        /*----------------------------- Parity Bits Row----------------------------------*/
        Rectangle{
            id: parityRect
            height: dataBitRect.height
            width: dataBitRect.width
            anchors.top: dataBitRect.bottom
            anchors.topMargin: parent.height * 0.05
            anchors.horizontalCenter: mainCommsettingsRect.horizontalCenter
            Label{
                id: parityText
                anchors.verticalCenter: parityRect.verticalCenter
                anchors.left: parityRect.left
                height: parityRect.height
                width: parityRect.width * 0.2
                background: Rectangle{
                    //border.width: 1
                }

                Text{
                    id: parityText1
                    anchors.verticalCenter: parityText.verticalCenter
                    anchors.left: parityText.left
                    anchors.leftMargin: parityText.width * 0.2
                    text: qsTr("Parity")
                    font.weight: "DemiBold"
                    font.family: fontLdr.robotoRegular
                    font.pixelSize: getFontSize("H4")
                    color: GStyle.blackColor()//"#000000"
                    opacity: 0.6
                }
            }

            WGroup{
                id : btnGrpParity
            }

            PlainButton{
                id : parityOption1
                height: parityRect.height
                width: parityRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parityText.right
                anchors.leftMargin: parityRect.width * 0.05
                group: btnGrpParity
                state: "selected"
                text: "None"
                onButtonClicked: {
                    parity = 1
                }
            }

            PlainButton{
                id : parityOption2
                height: parityRect.height
                width: parityRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parityOption1.right
                anchors.leftMargin: parityRect.width * 0.05
                group: btnGrpParity
                text: "Even"
                onButtonClicked: {
                    parity = 2
                }
            }

            PlainButton{
                id : parityOption3
                height: parityRect.height
                width: parityRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parityOption2.right
                anchors.leftMargin: parityRect.width * 0.05
                group: btnGrpParity
                text: "Odd"
                onButtonClicked: {
                    parity = 2
                }
            }
        }


       CustomeCombo {
            id : flowControlSelector
            anchors.horizontalCenterOffset: 1
            anchors.top: parityRect.bottom
            anchors.horizontalCenter: mainCommsettingsRect.horizontalCenter
            anchors.topMargin: parent.height * 0.05
            font.pixelSize:  getFontSize("H4")//16
            font.family: fontLdr.robotoRegular
            opacity: 0.8
            title: "Flow Control"
            model: ["None", "RTS/CTS", "XON/XOFF"]
        }

        RoundButton{
            id : connectButton
            width: getStdButtonWidth()
            height: getStdButtonHeight()
            radius: GStyle.defaultWdgtRadius()
            anchors.right: mainCommsettingsRect.right
            anchors.rightMargin: mainCommsettingsRect.width * 0.1
            anchors.bottom: mainCommsettingsRect.bottom
            anchors.bottomMargin: mainCommsettingsRect.height * 0.05
            font.pixelSize: getFontSize("H5")//16

            background: Rectangle{
                id: connectButtonRect
                radius: connectButton.radius
                color: GStyle.gP("themeDefaultColor")//"#48B0E5"
                border.color: GStyle.gP("themeDefaultColor")//"#48B0E5"
                border.width: 1
            }
            onClicked: {
                connectButtonRect.color =  GStyle.gP("themeDefaultColor")//"#48B0E5"
                disconnectButtonRect.color = GStyle.whiteColor()//"#FFFFFF"
                connectButtonText.color = GStyle.whiteColor()//"#FFFFFF"
                disconnectButtonText.color = GStyle.gP("themeDefaultColor")//"#48B0E5"
                var tempxy;
                if(parity  == 1)
                {
                    tempxy = "None"
                }
                else if(parity == 2)
                {
                    tempxy = "Even"
                }
                else
                {
                    tempxy = "Odd"
                }

                var dataBitSelect;
                if(dataBit == 6)
                {
                    dataBitSelect = "6"
                }

                if(dataBit == 7)
                {
                    dataBitSelect = "7"
                }
                if(dataBit == 8)
                {
                    dataBitSelect = "8"
                }

                CommLinkSettings.connectSerialPort(serialPortSelector.currentText.split(' ')[0], baudRateSelector.currentText,
                                                   dataBitSelect, tempxy,flowControlSelector.currentText)

                ComHelper.openSerialPort();
                if(ComHelper.isSerialPortOpen())
                {
                    //                    mainStackView.push(mainStackView.mainNewProjectStackView)
                    //                    loader.source = "NewProject.qml"   //"NewProject.qml"
                    //                    mainWindowSerialPort.close();
                }
            }
            Text {
                id: connectButtonText
                text: qsTr("Connect")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: GStyle.getButtonPixelSize()
                font.family: fontLdr.openSansRegular

                font.weight: "DemiBold"
                color: GStyle.whiteColor()//"white"
                height: connectButton.height
                width: connectButton.width
                anchors.left: connectButton.left

            }

        }

        RoundButton {
            id : disconnectButton
            width: getStdButtonWidth()
            height: getStdButtonHeight()
            radius: GStyle.defaultWdgtRadius()
            anchors.left: mainCommsettingsRect.left
            anchors.leftMargin: mainCommsettingsRect.width * 0.1
            anchors.bottom: mainCommsettingsRect.bottom
            anchors.bottomMargin: mainCommsettingsRect.height * 0.05
            font.pixelSize: getFontSize("H5")//16

            background: Rectangle{
                id: disconnectButtonRect
                radius: disconnectButton.radius
                color: GStyle.whiteColor()//"white"
                border.color: GStyle.gP("themeDefaultColor")//"#48B0E5"
                border.width: 1
            }
            onClicked: {
                disconnectButtonRect.color =  GStyle.gP("themeDefaultColor")//"#48B0E5"
                connectButtonRect.color = GStyle.whiteColor()//"#FFFFFF"
                disconnectButtonText.color = GStyle.whiteColor()//"#FFFFFF"
                connectButtonText.color = GStyle.gP("themeDefaultColor")//"#48B0E5"
                ComHelper.closeSerialPort(1)
                //loader.source= "main.qml"

            }

            Text {
                id: disconnectButtonText
                text: qsTr("Disconnect")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: GStyle.getButtonPixelSize()
                font.family: fontLdr.openSansRegular
                font.weight: "DemiBold"
                color: GStyle.gP("themeDefaultColor")//"#48B0E5"
                height: disconnectButton.height
                width: disconnectButton.width
            }

        }
    }

    /*------------------------ DropShadow Effect ------------------------------*/

    DropShadow{
        id: dropShadow1
        anchors.fill: mainCommsettingsRect
        samples: 25//GStyle.getDropshadowSamples()
        color: GStyle.getDropshadowColor()
        spread: 0.5
        source: mainCommsettingsRect
    }

    Connections{
        target: mainWindowSerialPort.connectionTargetMessage
        onCommStatusChanged:{
            console.log("status : ",status)
            if(status === ComHelper.COMM_CONNECTED)
            {
                commlinkmsg.showMsg("Commlink connected.")
                 mainStackView.pop()
            }
            else if(status === ComHelper.COMM_DISCONNECTED)
            {
                commlinkmsg.showMsg("Commlink disconnected.")
                 mainStackView.pop()
            }
            else if(status === ComHelper.COMM_ALREADYCONNECTED)
            {
                commlinkmsg.showMsg("Commlink already connected.")
                 mainStackView.pop()
            }
            else if(status === ComHelper.COMM_FAILED_TO_CONNECT)
            {
               commlinkmsg.showMsg("Failed to connect Commlink.")
            }
        }
    }
}
