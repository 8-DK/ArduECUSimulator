import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtGraphicalEffects  1.12
import QtQuick 2.6
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import QtQuick 2.2
import QtQuick.Dialogs 1.1
import SerialPortLib 1.0
import SerialPortSettingsLib 1.0
import CommLinkSettingsLib 1.0
import LocalStringsLib 1.0
import GStyleLib 1.0

Item {
    id:mainWindowSerialPort
    objectName: qsTr("MyserialPortWnd")
    visible: true
    width: GStyle.windowWidth()
    height: GStyle.windowHeight()
    signal sendPushNewProject()
    property var connectionTargetMessage: null
    property int  dataBit : 8;
    property int   parity;
    property var nextScreen;
    property int screen;

    onFocusChanged: {
        if(focus)
        {
            mainWindowSerialPort.connectionTargetMessage = MySerialPort
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
            connectButtonRect.color =  GStyle.blueColor()//"#48B0E5"
            disconnectButtonRect.color = GStyle.whiteColor()//"#FFFFFF"
            connectButtonText.color = GStyle.whiteColor()//"#FFFFFF"
            disconnectButtonText.color = GStyle.blueColor()//"#48B0E5"
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

            MySerialPort.openSerialPort();
            if(MySerialPort.isSerialPortOpen())
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
        //        console.log("Progress completed--------------++++++++")
        MySerialPort.callAfterParameterDownload()
        mainStackView.pop()
        progressBar.end()
    }

    function update()
    {
        //        console.log("Progress Update--------------++++++++")
        var progCount = MySerialPort.updateProgressBarValue()
        if(progCount>100)
            serialUpdateTimer.stop()
        return (progCount*100)
    }
    MessageBox{
        id: serialPortMessage
        messageDescription: " Serial port is connected."
        onOkButtonClickSignal: {
            mainWindowSerialPort.connectionTargetMessage = null
            serialPortMessage.hide()
            mainStackView.pop()
        }
    }

    MessageBox{
        id: serialPortNotConnectedMessage
        messageDescription: " Unable to connect serial port."//Serial Port is already Opened"//
        onOkButtonClickSignal: {
            serialPortNotConnectedMessage.hide()
        }
    }

    MessageBox{
        id: serialPortAlreadyConnectedMessage
        messageDescription: " Serial Port is already connected"
        onOkButtonClickSignal: {
            mainWindowSerialPort.connectionTargetMessage = null
            serialPortAlreadyConnectedMessage.hide()
            mainStackView.pop()
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

    FontLoader {
        id:openSansNormal
        source:'Fonts/Open_Sans_Regular.ttf'
    }
    FontLoader {
        id:openSansRegular
        source:'Fonts/Open_Sans_Regular.ttf'
    }
    FontLoader{
        id: montserratRegular
        source: "qrc:/Fonts/Montserrat-Regular.ttf"
    }
    FontLoader{
        id: robotoRegular
        source: "qrc:/Fonts/Roboto-Regular.ttf"
    }

    NavBar {
        id:navBar
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        header: LocalStrings.getLocalTextValue("navbarSerialPortTitle")
        onClickedMenu: print('Button onClicked')
    }

    /*-------------------------- Communication Link Settings ---------------------------*/
    Rectangle {
        id : mainCommsettingsRect
        width: parent.width * 0.5
        height: parent.height * 0.7
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: navBar.bottom
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
                font.family: montserratRegular.name
                font.pixelSize: getFontSize("H4")//16
                font.letterSpacing: 2.77
            }
        }

        ComboBox {
            id : serialPortSelector
            width: parent.width * 0.7
            height: parent.width * 0.05
            anchors.horizontalCenter: mainCommsettingsRect.horizontalCenter
            anchors.top: commLinkLabelRect.bottom
            anchors.topMargin: parent.height * 0.05
            font.pixelSize:  getFontSize("H4")//16
            font.family: robotoRegular.name
            opacity: 0.8
            model: CommLinkSettings.getSerialPort()
            //            onFocusChanged:{
            //                serialPortSelectorBgRect.border.color = GStyle.blueColor()
            //                serialPortText.color = GStyle.blueColor()
            //                baudRateSelectorBgRect.border.color = GStyle.borderColor()
            //                flowControlSelectorBgRect.border.color = GStyle.borderColor()
            //            }

            background: Rectangle {
                id: serialPortSelectorBgRect
                radius: GStyle.rpaSettingsTextEditRadius()
                color: GStyle.whiteColor()//"white"
                border.color: GStyle.borderColor()
                border.width: 0.7
            }
        }

        Label{
            id: serialPortLabel
            anchors.top: serialPortSelector.top
            anchors.topMargin: -(height/2)//-10
            anchors.left: serialPortSelector.left
            anchors.leftMargin: serialPortSelector.width * 0.03
            width: serialPortText.width * 1.5
            height: serialPortText.height * 1.2
            Text{
                id: serialPortText
                anchors.centerIn: serialPortLabel
                text: "Serial Port"
                font.family: openSansRegular.name
                font.pixelSize: getFontSize("H5")//16
                color: GStyle.borderColor()
            }
            background: Rectangle{
                color: GStyle.whiteColor()//"white"
                //border.width: 1
            }
        }

        ComboBox {
            id : baudRateSelector
            width: parent.width * 0.7
            height: parent.width * 0.05
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: serialPortSelector.bottom
            anchors.topMargin: parent.height * 0.05
            font.pixelSize:  getFontSize("H4")//16
            font.family: robotoRegular.name
            opacity: 0.8
            model: [ "9600",
                "19200",
                "38400",
                "57600",
                "115200" ]

            background: Rectangle {
                id: baudRateSelectorBgRect
                radius: GStyle.rpaSettingsTextEditRadius()
                color: GStyle.whiteColor()//"white"
                border.color: GStyle.borderColor()//"#184BFF"
                border.width: 0.7
            }
        }

        Label{
            id: baudRateSelectorLabel
            anchors.top: baudRateSelector.top
            anchors.topMargin: -(height/2)//-10
            anchors.left: baudRateSelector.left
            anchors.leftMargin: baudRateSelector.width * 0.03
            width: baudRateSelectorText.width * 1.5
            height: baudRateSelectorText.height * 1.2
            Text{
                id: baudRateSelectorText
                anchors.centerIn: baudRateSelectorLabel
                text: "Baud Rate"
                font.family: openSansRegular.name
                font.pixelSize: getFontSize("H5")//16
                color: GStyle.borderColor()
            }
            background: Rectangle{
                color: GStyle.whiteColor()//"white"
                //border.width: 1
            }
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
                    font.family: robotoRegular.name
                    font.weight: "DemiBold"
                    font.pixelSize: getFontSize("H4")
                    color: GStyle.blackColor()
                    opacity: 0.6
                }
            }



            Button{
                id : dataBitsOption1
                height: dataBitRect.height
                width: dataBitRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: dataBitsText.right
                anchors.leftMargin: dataBitRect.width * 0.05
                background: Rectangle {
                    id: dataBitsOption1BgRect
                    color: GStyle.whiteColor()//"white"
                    border.width: 0.5
                    border.color: GStyle.borderColor()//"#B0ADAB"
                }
                Text{
                    id: dataBitsOption1Text
                    anchors.centerIn: dataBitsOption1
                    text: "6"
                    font.family: openSansNormal.name
                    font.weight: "Normal"
                    font.pixelSize: getFontSize("H4")
                    color: GStyle.darkGrayColor()
                }
                onClicked: {
                    dataBit = 6;
                    dataBitsOption1BgRect.color =  GStyle.blueColor()//"#48B0E5"
                    dataBitsOption1BgRect.border.color = GStyle.blueColor()
                    dataBitsOption1Text.color = GStyle.whiteColor()//"#FFFFFF"
                    dataBitsOption2BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    dataBitsOption2BgRect.border.color = GStyle.borderColor()
                    dataBitsOption2Text.color =  GStyle.darkGrayColor()//"#706E6B"
                    dataBitsOption3BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    dataBitsOption3BgRect.border.color = GStyle.borderColor()
                    dataBitsOption3Text.color = GStyle.darkGrayColor()//"#706E6B"
                }
            }

            Button{
                id : dataBitsOption2
                height: dataBitRect.height
                width: dataBitRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: dataBitsOption1.right
                anchors.leftMargin: dataBitRect.width * 0.05
                background: Rectangle {
                    id: dataBitsOption2BgRect
                    color: GStyle.whiteColor()//"white"
                    border.width: 0.5
                    border.color: GStyle.borderColor()//"#B0ADAB"
                }
                Text{
                    id: dataBitsOption2Text
                    anchors.centerIn: dataBitsOption2
                    text: "7"
                    font.family: openSansNormal.name
                    font.weight: "Normal"
                    font.pixelSize: getFontSize("H4")
                    color: GStyle.darkGrayColor()
                }
                onClicked: {
                    dataBit = 7;
                    dataBitsOption1BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    dataBitsOption1BgRect.border.color = GStyle.borderColor()
                    dataBitsOption1Text.color = GStyle.darkGrayColor()//"#706E6B"
                    dataBitsOption2BgRect.color =  GStyle.blueColor()//"#48B0E5"
                    dataBitsOption2BgRect.border.color = GStyle.blueColor()
                    dataBitsOption2Text.color = GStyle.whiteColor()//"#FFFFFF"
                    dataBitsOption3BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    dataBitsOption3Text.color = GStyle.darkGrayColor()//"#706E6B"
                    dataBitsOption3BgRect.border.color = GStyle.borderColor()
                }
            }

            Button{
                id : dataBitsOption3
                height: dataBitRect.height
                width: dataBitRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: dataBitsOption2.right
                anchors.leftMargin: dataBitRect.width * 0.05
                background: Rectangle {
                    id: dataBitsOption3BgRect
                    //color: "white"
                    border.width: 0.5
                    border.color: GStyle.blueColor()
                    color :  GStyle.blueColor()//"#48B0E5"
                }
                Text{
                    id: dataBitsOption3Text
                    anchors.centerIn: dataBitsOption3
                    text: "8"
                    font.family: openSansNormal.name
                    font.weight: "Normal"
                    font.pixelSize: getFontSize("H4")
                    color: GStyle.whiteColor()
                }
                onClicked: {
                    dataBit = 8;
                    dataBitsOption1BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    dataBitsOption1BgRect.border.color = GStyle.borderColor()
                    dataBitsOption1Text.color = GStyle.darkGrayColor()//"#706E6B"
                    dataBitsOption3BgRect.color =  GStyle.blueColor()//"#48B0E5"
                    dataBitsOption3BgRect.border.color = GStyle.blueColor()
                    dataBitsOption3Text.color = GStyle.whiteColor()//"#FFFFFF"
                    dataBitsOption2BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    dataBitsOption2BgRect.border.color = GStyle.borderColor()
                    dataBitsOption2Text.color =  GStyle.darkGrayColor()//"#706E6B"
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
                    font.family: robotoRegular.name
                    font.pixelSize: getFontSize("H4")
                    color: GStyle.blackColor()//"#000000"
                    opacity: 0.6
                }
            }

            Button{
                id : parityOption1
                height: parityRect.height
                width: parityRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parityText.right
                anchors.leftMargin: parityRect.width * 0.05
                background: Rectangle {
                    id: parityOption1BgRect
                    color: GStyle.blueColor()
                    border.width: 0.5
                    border.color: GStyle.blueColor()
                }
                Text{
                    id: parityOption1Text
                    anchors.centerIn: parityOption1
                    text: "None"
                    font.family: openSansNormal.name
                    font.weight: "Normal"
                    font.pixelSize: getFontSize("H4")
                    color: GStyle.whiteColor()
                }
                onClicked: {
                    parity = 1
                    parityOption1BgRect.color =  GStyle.blueColor()//"#48B0E5"
                    parityOption1BgRect.border.color = GStyle.blueColor()
                    parityOption1Text.color = GStyle.whiteColor()//"#FFFFFF"
                    parityOption2BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    parityOption2BgRect.border.color = GStyle.borderColor()
                    parityOption2Text.color =  GStyle.darkGrayColor()//"#706E6B"
                    parityOption3BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    parityOption3BgRect.border.color = GStyle.borderColor()
                    parityOption3Text.color = GStyle.darkGrayColor()//"#706E6B"
                }
            }

            Button{
                id : parityOption2
                height: parityRect.height
                width: parityRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parityOption1.right
                anchors.leftMargin: parityRect.width * 0.05
                background: Rectangle {
                    id: parityOption2BgRect
                    //color: "white"
                    color :  GStyle.whiteColor()
                    border.width: 0.5
                    border.color: GStyle.borderColor()//"#B0ADAB"
                }
                Text{
                    id: parityOption2Text
                    anchors.centerIn: parityOption2
                    text: "Even"
                    font.family: openSansNormal.name
                    font.weight: "Normal"
                    font.pixelSize: getFontSize("H4")
                    color: GStyle.darkGrayColor()
                }
                onClicked: {
                    parity = 2
                    parityOption2BgRect.color =  GStyle.blueColor()//"#48B0E5"
                    parityOption2BgRect.border.color = GStyle.blueColor()
                    parityOption2Text.color = GStyle.whiteColor()//"#FFFFFF"
                    parityOption1BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    parityOption1BgRect.border.color = GStyle.borderColor()
                    parityOption1Text.color =  GStyle.darkGrayColor()//"#706E6B"
                    parityOption3BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    parityOption3BgRect.border.color = GStyle.borderColor()
                    parityOption3Text.color = GStyle.darkGrayColor()//"#706E6B"
                }

            }

            Button{
                id : parityOption3
                height: parityRect.height
                width: parityRect.width * 0.2
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parityOption2.right
                anchors.leftMargin: parityRect.width * 0.05
                background: Rectangle {
                    id: parityOption3BgRect
                    color: GStyle.whiteColor()//"white"
                    border.width: 0.5
                    border.color: GStyle.borderColor()//"#B0ADAB"
                }
                Text{
                    id: parityOption3Text
                    anchors.centerIn: parityOption3
                    text: "Odd"
                    font.family: openSansNormal.name
                    font.weight: "Normal"
                    font.pixelSize: getFontSize("H4")
                    color: GStyle.darkGrayColor()
                }
                onClicked: {
                    parity = 3
                    parityOption3BgRect.color =  GStyle.blueColor()//"#48B0E5"
                    parityOption3BgRect.border.color = GStyle.blueColor()
                    parityOption3Text.color = GStyle.whiteColor()//"#FFFFFF"
                    parityOption1BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    parityOption1BgRect.border.color = GStyle.borderColor()
                    parityOption1Text.color =  GStyle.darkGrayColor()//"#706E6B"
                    parityOption2BgRect.color = GStyle.whiteColor()//"#FFFFFF"
                    parityOption2BgRect.border.color = GStyle.borderColor()
                    parityOption2Text.color = GStyle.darkGrayColor()//"#706E6B"
                }
            }
        }



        ComboBox {
            id : flowControlSelector
            width: parent.width * 0.7
            height: parent.width * 0.05
            anchors.horizontalCenterOffset: 1
            anchors.top: parityRect.bottom
            anchors.horizontalCenter: mainCommsettingsRect.horizontalCenter
            anchors.topMargin: parent.height * 0.05
            font.pixelSize:  getFontSize("H4")//16
            font.family: robotoRegular.name
            opacity: 0.8

            background: Rectangle {
                id: flowControlSelectorBgRect
                radius: GStyle.rpaSettingsTextEditRadius()
                color: GStyle.whiteColor()//"white"
                border.color: GStyle.borderColor()//"#184BFF"
                border.width: 0.7
            }
            model: ["None", "RTS/CTS", "XON/XOFF"]
        }

        Label{
            id: flowControlSelectorLabel
            anchors.top: flowControlSelector.top
            anchors.topMargin: -(height/2)//-10
            anchors.left: flowControlSelector.left
            anchors.leftMargin: flowControlSelector.width * 0.03
            width: flowControlSelectorText.width * 1.5
            height: flowControlSelectorText.height * 1.2
            Text{
                id: flowControlSelectorText
                anchors.centerIn: flowControlSelectorLabel
                text: "Flow Control"
                font.family: openSansRegular.name
                font.pixelSize: getFontSize("H5")//16
                color: GStyle.borderColor()
            }
            background: Rectangle{
                color: GStyle.whiteColor()//"white"
            }
        }


        RoundButton{
            id : connectButton
            width: getStdButtonWidth()
            height: getStdButtonHeight()
            radius: GStyle.defaultButtonRadius()
            anchors.right: mainCommsettingsRect.right
            anchors.rightMargin: mainCommsettingsRect.width * 0.1
            anchors.bottom: mainCommsettingsRect.bottom
            anchors.bottomMargin: mainCommsettingsRect.height * 0.05
            font.pixelSize: getFontSize("H5")//16

            background: Rectangle{
                id: connectButtonRect
                radius: connectButton.radius
                color: GStyle.blueColor()//"#48B0E5"
                border.color: GStyle.blueColor()//"#48B0E5"
                border.width: 1
            }
            onClicked: {
                connectButtonRect.color =  GStyle.blueColor()//"#48B0E5"
                disconnectButtonRect.color = GStyle.whiteColor()//"#FFFFFF"
                connectButtonText.color = GStyle.whiteColor()//"#FFFFFF"
                disconnectButtonText.color = GStyle.blueColor()//"#48B0E5"
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

                MySerialPort.openSerialPort();
                if(MySerialPort.isSerialPortOpen())
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
                font.family: openSansRegular.name

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
            radius: GStyle.defaultButtonRadius()
            anchors.left: mainCommsettingsRect.left
            anchors.leftMargin: mainCommsettingsRect.width * 0.1
            anchors.bottom: mainCommsettingsRect.bottom
            anchors.bottomMargin: mainCommsettingsRect.height * 0.05
            font.pixelSize: getFontSize("H5")//16

            background: Rectangle{
                id: disconnectButtonRect
                radius: disconnectButton.radius
                color: GStyle.whiteColor()//"white"
                border.color: GStyle.blueColor()//"#48B0E5"
                border.width: 1
            }
            onClicked: {
                disconnectButtonRect.color =  GStyle.blueColor()//"#48B0E5"
                connectButtonRect.color = GStyle.whiteColor()//"#FFFFFF"
                disconnectButtonText.color = GStyle.whiteColor()//"#FFFFFF"
                connectButtonText.color = GStyle.blueColor()//"#48B0E5"
                MySerialPort.closeSerialPort(1)
                //loader.source= "main.qml"

            }

            Text {
                id: disconnectButtonText
                text: qsTr("Disconnect")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: GStyle.getButtonPixelSize()
                font.family: openSansRegular.name
                font.weight: "DemiBold"
                color: GStyle.blueColor()//"#48B0E5"
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
        onShowMessageBoxToConnectSerialPort :
        {
            //            serialPortMessage.show()
            //progressBar.start()
            sendPushNewProject()
        }
        onShowMessageBoxUnableToConnectSeralPort :
        {
            serialPortNotConnectedMessage.show()
        }
        onShowMessageBoxSerialPortAlreadyConnected :
        {
            serialPortAlreadyConnectedMessage.show()
        }
        onShowMessageBoxSerialPortDisconnected :
        {
            progressBar.end()
            serialPortDisconnectedMessage.show()
        }
    }
}

/*##^##
Designer {
    D{i:12;anchors_height:0;anchors_width:0}D{i:13;anchors_width:252}
}
##^##*/
