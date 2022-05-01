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
import AeroGCSLoginLib 1.0
import CommLinkSettingsLib 1.0
import LocalStringsLib 1.0
import StyleGlobalConstsLib 1.0
import DroneDetailsHelperLib 1.0
import RestApiHelperLib 1.0
import NPNT_Data_helperLib 1.0
import SettingsHandlerLib 1.0
import MainWindowGlobalContextLib 1.0
import AudioModuleLib 1.0
import BluetoothLinkLib 1.0
import AeromeghAccountHandlerLib 1.0

Rectangle {
    id:mainWindowSerialPort
    objectName: qsTr("MyserialPortWnd")
    visible: true
    width: StyleGlobalConsts.windowWidth()
    height:StyleGlobalConsts.windowHeight()
    color: StyleGlobalConsts.getBackgroundPrimaryColor()

    signal sendPushNewProject()
    signal sendPushDroneDetails()
    property var connectionTargetMessage: null
    property var droneRegistrationCheck: null
    property int dataBit : 8;
    property int parity;
    property var nextScreen;
    property int screen;
    property int selectedInterface: 0

    property var subEditConfig: BluetoothLink.m_config

    MessageBox{
        id: droneRegCheck
        messageDescription: LocalStrings.getLocalTextValue("registerDrone")
        onOkButtonClickSignal: {
             droneRegCheck.hide()
            sendPushDroneDetails()
        }
    }

    Connections{
        target: DroneDetailsHelper
        onGetDroneStatus:{
            console.log("onGetDroneStatus------------")
            if(!DroneDetailsHelper.getDroneIDStatus()) {
                  console.log("Drone not found in list")
                if(getCurrentViewName() === LocalStrings.getLocalTextValue("themegenSettings"))
                {
                     droneRegCheck.show()
                }
                else{
                    sendPushDroneDetails()
                }
             }
            else{
                if(getCurrentViewName() !== LocalStrings.getLocalTextValue("themegenSettings")){
                    console.log("onGetDroneStatus: called-------" , getCurrentViewName())
                    if(SettingsHandler.getManualRebootFlag() === 0){
                        console.log("onGetDroneStatus if called-------")
                        mainWindowSerialPort.connectionTargetMessage = null
                        mainWindowSerialPort.droneRegistrationCheck = null
                        mainStackView.pop()
                    }
                    SettingsHandler.setManualRebootFlag(0)
                }
           }
             AudioModule.speak("Drone Connected",true)
        }
    }

    SerialPortAdvancedSettings{
        id:advanceSettings
    }

   onFocusChanged: {
        if(focus)
        {
            mainWindowWithStackView.navBar.onUpdateNavBar(objectName, LocalStrings.getLocalTextValue("navbarSerialPortTitle"))
            mainWindowSerialPort.connectionTargetMessage = MySerialPort
            mainWindowSerialPort.droneRegistrationCheck = RestApiHelper
            serialUpdateTimer.start()
            selectedInterface = MySerialPort.getInterFace()
            if(selectedInterface == 1)
            {
                tcpHostLabel.visible = true
                listeningPortLabel.visible = true
                targetHostLabel.visible = true
                targetPortLabel.visible = true
                mainTcpsettingsRect.visible = true
                portTextRect.visible = true
                mainTargetsettingsRect.visible = true
                targetportTextRect.visible = true
                flowControlSelector.visible = false
                parityRect.visible = false
                dataBitRect.visible = false
                baudRateSelector.visible = false
                serialPortLabel.visible = false
                serialPortSelector.visible = false

                deviceLabel.visible = false
                deviceStrLabel.visible = false
                addressLabel.visible = false
                addressStrLabel.visible = false
                bluetoothLabel.visible=false
                currentDevice.visible = false
                bluetootshScan.visible = false
                bluetoothStop.visible = false
//                bluetoothconnect.visible = false
            }
            else if(selectedInterface == 2)
            {
                tcpHostLabel.visible = true
                listeningPortLabel.visible = true
                targetHostLabel.visible = false
                targetPortLabel.visible = false
                mainTcpsettingsRect.visible = true
                portTextRect.visible = true
                mainTargetsettingsRect.visible = false
                targetportTextRect.visible = false
                flowControlSelector.visible = false
                parityRect.visible = false
                dataBitRect.visible = false
                baudRateSelector.visible = false
                serialPortLabel.visible = false
                serialPortSelector.visible = false

                deviceLabel.visible = false
                deviceStrLabel.visible = false
                addressLabel.visible = false
                addressStrLabel.visible = false
                bluetoothLabel.visible=false
                currentDevice.visible = false
                bluetootshScan.visible = false
                bluetoothStop.visible = false
//                bluetoothconnect.visible = false
            }
            else if(selectedInterface == 3)
            {
                tcpHostLabel.visible = false
                listeningPortLabel.visible = false
                targetHostLabel.visible = false
                targetPortLabel.visible = false
                mainTcpsettingsRect.visible = false
                portTextRect.visible = false
                mainTargetsettingsRect.visible = false
                targetportTextRect.visible = false
                flowControlSelector.visible = false
                parityRect.visible = false
                dataBitRect.visible = false
                baudRateSelector.visible = false
                serialPortLabel.visible = false
                serialPortSelector.visible = false

                deviceLabel.visible = true
                deviceStrLabel.visible = true
                addressLabel.visible = true
                addressStrLabel.visible = true
                bluetoothLabel.visible=true
                currentDevice.visible = true
                bluetootshScan.visible = true
                bluetoothStop.visible = true
//                bluetoothconnect.visible = true
            }
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
            if(selectedInterface === 0)
            {
                connectButtonRect.color =  StyleGlobalConsts.getThemeColor()
                disconnectButtonRect.color = StyleGlobalConsts.whiteColor()
                connectButtonText.color = StyleGlobalConsts.whiteColor()
                disconnectButtonText.color = StyleGlobalConsts.getThemeColor()
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
            }
            else if(selectedInterface === 2 || selectedInterface === 1)
            {
                MySerialPort.setHostAddr(tcpHostAddr.text)
                MySerialPort.setHostPort(hostPortNum.text)
                MySerialPort.setTargetAddr(targetHostAddr.text);
                MySerialPort.setTargetPort(targethostPortNum.text)
            }
            MySerialPort.openSerialPort();
            if(MySerialPort.isSerialPortOpen())
            {

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
        visible: false
        anchors.centerIn: parent
        description: LocalStrings.getLocalTextValue("paramDownload")
        width: Qt.platform.os == "android" ?  StyleGlobalConsts.windowWidth() * 0.45 : StyleGlobalConsts.windowWidth() * 0.28
        height: Qt.platform.os == "android" ?  StyleGlobalConsts.windowHeight() * 0.34 : StyleGlobalConsts.windowHeight() * 0.2
        callAfterComplete:comp
        updateProgress:update
        cancelButton: cancelProgressBar
    }


    function cancelProgressBar(){
        disconnectConfirmationMessagebox.show()
    }
    function comp()
    {
        if(MySerialPort.getSerialPortParamFlag() === 1){
            MySerialPort.callAfterParameterDownload()
            progressBar.end()
            if(MainWindowGlobalContext.getNPNTFlagStatus() === 1){
                if(selectedInterface === 0)
                {
                    serialPortNotConnectedMessage.messageDescription = LocalStrings.getLocalTextValue("checkDroneReg")
                    serialPortNotConnectedMessage.show()
                    console.log("Checking for drone registration")
                    RestApiHelper.startCheckDroneRegistrartion()
                    console.log("Checking for ownership")
                    RestApiHelper.checkOwnerShip(NPNT_Data_helper.droneIdProperty)
                }
                else if(selectedInterface === 2 || selectedInterface === 1)
                {
                    serialPortNotConnectedMessage.messageDescription = LocalStrings.getLocalTextValue("checkDroneReg")
                    serialPortNotConnectedMessage.show()
                    RestApiHelper.startCheckDroneRegistrartion()
                    RestApiHelper.checkOwnerShip(NPNT_Data_helper.droneIdProperty)
                }
                else{
                    if(SettingsHandler.getManualRebootFlag() === 0){
                        mainWindowSerialPort.connectionTargetMessage = null
                        mainWindowSerialPort.droneRegistrationCheck = null
                        mainStackView.pop()
                    }
                    SettingsHandler.setManualRebootFlag(0)
                }
            }
            else{
                if(AeromeghAccountHandler.getAeroMeghLoginStatus()){
                    console.log("Login with aeromegh acc----------")
                    DroneDetailsHelper.callGetDroneRegStatus();
                }
                else{
                console.log("called from skip login-------------")
                     serialPortMessage.show()
                 }
                /*if(DroneDetailsHelper.getCurrentDroneRegisteredStatus() === 0)*/
//                if(!DroneDetailsHelper.getDroneIDStatus()) {
//                      console.log("Drone not found in list")
//                      sendPushDroneDetails()
//                }
//                else{
//                    if(SettingsHandler.getManualRebootFlag() === 0){
//                        mainWindowSerialPort.connectionTargetMessage = null
//                        mainWindowSerialPort.droneRegistrationCheck = null
//                        mainStackView.pop()
//                    }
//                    SettingsHandler.setManualRebootFlag(0)
//                }
//                AudioModule.speak("Drone Connected",true)
            }
        }
        else{
            MySerialPort.setSerialPortParamFlag(0)
            MySerialPort.closeSerialPort(0)
        }
    }

    function update()
    {
        var progCount = MySerialPort.updateProgressBarValue()
        if(progCount>100)
            serialUpdateTimer.stop()
        return (progCount * 100)
    }

    MessageBox{
        id: serialPortMessage
        messageDescription: LocalStrings.getLocalTextValue("serialPortConnected")
        onOkButtonClickSignal: {
            mainWindowSerialPort.connectionTargetMessage = null
            mainWindowSerialPort.droneRegistrationCheck = null
            serialPortMessage.hide()
            mainStackView.pop()
        }
    }

    MessageBox{
        id: disconnectConfirmationMessagebox
        messageDetails: LocalStrings.getLocalTextValue("yes")
        messageDescription: LocalStrings.getLocalTextValue("disconnectConfirmation")
        onOkButtonClickSignal: {
            MySerialPort.closeSerialPort(1)
            disconnectConfirmationMessagebox.hide()
        }
        onCancelButtonClickSignal: {
            comp()
            disconnectConfirmationMessagebox.hide()
        }
    }

    MessageBox{
        id: serialPortNotConnectedMessage
        messageDescription: LocalStrings.getLocalTextValue("unableToConnectPort")
        onOkButtonClickSignal: {
            serialPortNotConnectedMessage.hide()
        }
    }

    MessageBox{
        id: droneOwnerShipCheckFailed
        messageDescription:LocalStrings.getLocalTextValue("droneOwnCheckFail")
        onOkButtonClickSignal: {
            droneOwnerShipCheckFailed.hide()
            mainWindowSerialPort.connectionTargetMessage = null
            mainWindowSerialPort.droneRegistrationCheck = null
            mainStackView.pop(mainStackView.mainDashboardStackView)
        }
    }

    MessageBox{
        id: serialPortAlreadyConnectedMessage
        messageDescription: LocalStrings.getLocalTextValue("portAlreadyConnected")
        onOkButtonClickSignal: {
            serialPortAlreadyConnectedMessage.hide()
            mainWindowSerialPort.connectionTargetMessage = null
            mainWindowSerialPort.droneRegistrationCheck = null
            mainStackView.pop()
        }
    }

    Timer{
        id: serialUpdateTimer
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            if(SettingsHandler.isAndroid())
            {
                serialPortSelector.model = CommLinkSettings.getSerialPort()
                serialUpdateTimer.stop()
            }
            else{
                serialPortSelector.model = CommLinkSettings.getSerialPort()
            }
        }
    }

    SerialPortSettings{
        id: serialPortSettings
    }

    Rectangle {
        id : mainWindowRect
        height: mainWindowSerialPort.height
        width: mainWindowSerialPort.width
        color: StyleGlobalConsts.getBackgroundPrimaryColor()
    }


    Rectangle {
        id : mainCommLinKRect
        anchors.left: mainWindowRect.left
        anchors.right : mainWindowRect.right
        anchors.bottom: mainWindowRect.bottom
        anchors.top: mainWindowRect.top
        color: StyleGlobalConsts.getBackgroundPrimaryColor()
    }

    Rectangle{
        id: navBar
        width: mainWindowWithStackView.navBar.width
        height: mainWindowWithStackView.navBar.height
    }

    /*-------------------------- Communication Link Settings ---------------------------*/

    Rectangle{
        id  : commLinkSettingsOuterRect
        width: StyleGlobalConsts.getRectWidth() * 1.2
        height: StyleGlobalConsts.getRectHeight()
        anchors.top: parent.top
        anchors.topMargin: StyleGlobalConsts.getRectHeight() * 0.18
        anchors.horizontalCenter: mainCommLinKRect.horizontalCenter
        color: StyleGlobalConsts.getBackgroundSecondaryColor()
        Rectangle{
            id: commLinkSettingsRect
            width: StyleGlobalConsts.getRectWidth() * 0.65
            height: StyleGlobalConsts.getRectHeight()
            anchors.verticalCenter: commLinkSettingsOuterRect.verticalCenter
            anchors.left: commLinkSettingsOuterRect.left
            anchors.leftMargin: commLinkSettingsRect.width * 0.08
            color: StyleGlobalConsts.getBackgroundSecondaryColor()

            Rectangle {
                id : commLinkLabelRect
                visible: true
                height: commLinkSettingsRect.height * 0.05
                width: commLinkSettingsRect.width * 0.9
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: commLinkSettingsRect.height * 0.06
                color: StyleGlobalConsts.getTransparentColor()
                Text {
                    id: commLinkLabelText
                    text: LocalStrings.getLocalTextValue("commlinkSettings")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getRPASettingsLabelPixelSize()//16
                    color: StyleGlobalConsts.getThemeColor()
                }
                AeroGCSComboBox {
                    id : interfaceCombobox
                    width: parent.width*0.4
                    height: Qt.platform.os == "android" ?commLinkSettingsRect.width * 0.13:commLinkSettingsRect.width * 0.1
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    model:[
                        "Serial",
                        "TCP",
                        "UDP",
                        "Bluetooth",
                    ]
                    onCurrentIndexChanged: {
                        console.log("Interface : ",currentText,currentIndex)
                        if(currentIndex === 0)
                        {
                            tcpHostLabel.visible = false
                            listeningPortLabel.visible = false
                            targetHostLabel.visible = false
                            targetPortLabel.visible = false
                            mainTcpsettingsRect.visible = false
                            portTextRect.visible = false
                            mainTargetsettingsRect.visible = false
                            targetportTextRect.visible = false
                            flowControlSelector.visible = true
                            parityRect.visible = true
                            dataBitRect.visible = true
                            baudRateSelector.visible = true
                            serialPortLabel.visible = true
                            serialPortSelector.visible = true

                            deviceLabel.visible = false
                            deviceStrLabel.visible = false
                            addressLabel.visible = false
                            addressStrLabel.visible = false
                            bluetoothLabel.visible=false
                            currentDevice.visible = false
                            bluetootshScan.visible = false
                            bluetoothStop.visible = false
//                            bluetoothconnect.visible = false
                            selectedInterface = 0
                            MySerialPort.setInterFace(selectedInterface)
                        }
                        else if(currentIndex === 1)
                        {
                            tcpHostLabel.visible = true
                            listeningPortLabel.visible = true
                            targetHostLabel.visible = true
                            targetPortLabel.visible = true
                            mainTcpsettingsRect.visible = true
                            portTextRect.visible = true
                            mainTargetsettingsRect.visible = true
                            targetportTextRect.visible = true
                            flowControlSelector.visible = false
                            parityRect.visible = false
                            dataBitRect.visible = false
                            baudRateSelector.visible = false
                            serialPortLabel.visible = false
                            serialPortSelector.visible = false

                            deviceLabel.visible = false
                            deviceStrLabel.visible = false
                            addressLabel.visible = false
                            addressStrLabel.visible = false
                            bluetoothLabel.visible=false
                            currentDevice.visible = false
                            bluetootshScan.visible = false
                            bluetoothStop.visible = false
//                            bluetoothconnect.visible = false
                            selectedInterface = 1

                            MySerialPort.setInterFace(selectedInterface)
                        }
                        else if(currentIndex === 2)
                        {
                            tcpHostLabel.visible = true
                            listeningPortLabel.visible = true
                            targetHostLabel.visible = false
                            targetPortLabel.visible = false
                            mainTcpsettingsRect.visible = true
                            portTextRect.visible = true
                            mainTargetsettingsRect.visible = false
                            targetportTextRect.visible = false
                            flowControlSelector.visible = false
                            parityRect.visible = false
                            dataBitRect.visible = false
                            baudRateSelector.visible = false
                            serialPortLabel.visible = false
                            serialPortSelector.visible = false

                            deviceLabel.visible = false
                            deviceStrLabel.visible = false
                            addressLabel.visible = false
                            addressStrLabel.visible = false
                            bluetoothLabel.visible=false
                            currentDevice.visible = false
                            bluetootshScan.visible = false
                            bluetoothStop.visible = false
//                            bluetoothconnect.visible = false
                            selectedInterface = 2

                            MySerialPort.setInterFace(selectedInterface)
                        }
                        else if(currentIndex === 3)
                        {
                            tcpHostLabel.visible = false
                            listeningPortLabel.visible = false
                            targetHostLabel.visible = false
                            targetPortLabel.visible = false
                            mainTcpsettingsRect.visible = false
                            portTextRect.visible = false
                            mainTargetsettingsRect.visible = false
                            targetportTextRect.visible = false
                            flowControlSelector.visible = false
                            parityRect.visible = false
                            dataBitRect.visible = false
                            baudRateSelector.visible = false
                            serialPortLabel.visible = false
                            serialPortSelector.visible = false

                            deviceLabel.visible = true
                            deviceStrLabel.visible = true
                            addressLabel.visible = true
                            addressStrLabel.visible = true
                            bluetoothLabel.visible=true
                            currentDevice.visible = true
                            bluetootshScan.visible = true
                            bluetoothStop.visible = true
//                            bluetoothconnect.visible = true
                            selectedInterface = 3
                            MySerialPort.setInterFace(selectedInterface)
                        }                       
                    }
                }
            }


            Label{
                id: deviceLabel
                anchors.top: commLinkLabelRect.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.06
                anchors.left: commLinkLabelRect.left
                width: commLinkSettingsRect.width * 0.9/2
                height: commLinkSettingsRect.height * 0.05
                Text{
                    id: deviceLabelText
                    anchors.left: parent.left
                    text: qsTr("Device ")
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getRPASettingsLabelPixelSize()
                    color: StyleGlobalConsts.getTextSecondaryColor()
                }
            }

            Label{
                id: deviceStrLabel
                anchors.top: commLinkLabelRect.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.06
                anchors.right : parent.right
                width: commLinkSettingsRect.width * 0.9/2
                height: commLinkSettingsRect.height * 0.05
                Text{
                    id: deviceField
                    anchors.centerIn: parent
                    text:   subEditConfig.devName
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getTextEditLabelPixelSize()
                    color: StyleGlobalConsts.getTextSecondaryColor()
                }
            }

            Label{
                id: addressLabel
                anchors.top: deviceLabel.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.06
                anchors.left: commLinkLabelRect.left
                width: commLinkSettingsRect.width * 0.9/2
                height: commLinkSettingsRect.height * 0.05
                Text{
                    id: addressLabelText
                    anchors.left: parent.left
                    text: qsTr("Address: ")
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getRPASettingsLabelPixelSize()
                    color: StyleGlobalConsts.getTextSecondaryColor()
                }
            }
            Label{
                id: addressStrLabel
                anchors.top: deviceLabel.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.06
                anchors.right : parent.right
                width: commLinkSettingsRect.width * 0.9/2
                height: commLinkSettingsRect.height * 0.05
                Text{
                    id: addressField
                    anchors.centerIn: parent
                    text:   subEditConfig.address
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getTextEditLabelPixelSize()
                    color: StyleGlobalConsts.getTextSecondaryColor()
                }
            }

            Label {
                id: bluetoothLabel
                anchors.top: currentDevice.top
                anchors.topMargin: -(currentDevice.height * 0.4)
                anchors.left: currentDevice.left
                width: bluetoothText.contentWidth + 10
                height: currentDevice.height * 0.3
                Text{
                    id: bluetoothText
                    anchors.centerIn: bluetoothLabel
                    text: qsTr("Bluetooth Devices")
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getRPASettingsLabelPixelSize()
                    color: StyleGlobalConsts.getTextSecondaryColor()
                }
            }

            AeroGCSComboBox {
                id : currentDevice
                width: commLinkSettingsRect.width * 0.9
                height: Qt.platform.os == "android" ?commLinkSettingsRect.width * 0.13:commLinkSettingsRect.width * 0.1
                anchors.top: addressLabel.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.1
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                model:subEditConfig.nameList
                onCurrentIndexChanged: {
                    console.log("Device name : ",subEditConfig.getDeviceNameAt(currentIndex),currentIndex)
                    subEditConfig.devName = subEditConfig.getDeviceNameAt(currentIndex)//modelData
                    subEditConfig.setDevName(subEditConfig.getDeviceNameAt(currentIndex))
                }
            }
            Rectangle{
                id : mainTcpsettingsRect
                width: commLinkSettingsRect.width * 0.9
                height: commLinkSettingsRect.width * 0.1
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                anchors.top: commLinkSettingsRect.top
                anchors.topMargin: commLinkSettingsRect.height * 0.2
                visible: false
                border.color: StyleGlobalConsts.getTextSecondaryColor()
                border.width: 1
                radius: 4
                color: StyleGlobalConsts.getTransparentColor()
                TextInput{
                    id: tcpHostAddr
                    width: mainTcpsettingsRect.width
                    height: mainTcpsettingsRect.height
                    verticalAlignment: Text.AlignVCenter
                    anchors.horizontalCenter: mainTcpsettingsRect.horizontalCenter
                    anchors.verticalCenter: mainTcpsettingsRect.verticalCenter
                    anchors.left: mainTcpsettingsRect.left
                    anchors.leftMargin: 20
                    maximumLength: 30
                    clip: true
                    color: StyleGlobalConsts.getTextPrimaryColor()
                    font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                    focus: true
                    text: "127.0.0.1"
                    property string placeholderText: LocalStrings.getLocalTextValue("enterSimulIP")
                    Text {
                        width: tcpHostAddr.width
                        height: tcpHostAddr.height
                        text: "127.0.0.1"
                        verticalAlignment: Text.AlignVCenter
                        color: StyleGlobalConsts.getTextSecondaryColor()//"#C6C6C6"
                        font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                        font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                        visible: !tcpHostAddr.text
                        anchors.left: tcpHostAddr.left
                        anchors.top: tcpHostAddr.top
                    }
                }
            }

            Label{
                id: tcpHostLabel
                anchors.top: mainTcpsettingsRect.top
                anchors.topMargin: -(mainTcpsettingsRect.width * 0.06)
                anchors.left: mainTcpsettingsRect.left
                width: tcpHostLabelText.contentWidth + 10
                height: mainTcpsettingsRect.height * 0.3
                Text{
                    id: tcpHostLabelText
                    anchors.centerIn: tcpHostLabel
                    text: LocalStrings.getLocalTextValue("hostaddr")
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getTextEditLabelPixelSize()
                    color: StyleGlobalConsts.getTextSecondaryColor()
                }
            }

            Rectangle{
                id : portTextRect
                width: commLinkSettingsRect.width * 0.9
                height: Qt.platform.os == "android" ?commLinkSettingsRect.width * 0.13:commLinkSettingsRect.width * 0.1
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                anchors.top: mainTcpsettingsRect.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.08
                visible: false
                border.color: StyleGlobalConsts.getTextSecondaryColor()
                border.width: 1
                radius: 4
                color: StyleGlobalConsts.getTransparentColor()
                TextInput{
                    id: hostPortNum
                    width: portTextRect.width
                    height: portTextRect.height
                    text: "14551"
                    color: StyleGlobalConsts.getTextPrimaryColor()
                    verticalAlignment: Text.AlignVCenter
                    anchors.horizontalCenter: portTextRect.horizontalCenter
                    anchors.verticalCenter: portTextRect.verticalCenter
                    anchors.left: portTextRect.left
                    anchors.leftMargin: 20
                    maximumLength: 30
                    clip: true
                    focus: true
                    font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                    validator: RegExpValidator { regExp: /[0-9]+/ }
                    property string placeholderText: LocalStrings.getLocalTextValue("enterSimulPort")
                    Text {
                        width: hostPortNum.width
                        height: hostPortNum.height
                        text: "5772"
                        verticalAlignment: Text.AlignVCenter
                        color: StyleGlobalConsts.getTextSecondaryColor()
                        font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                        font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                        visible: !hostPortNum.text
                        anchors.left: hostPortNum.left
                        anchors.top: hostPortNum.top
                    }
                }
            }

            Label {
                id: listeningPortLabel
                anchors.top: portTextRect.top
                anchors.topMargin: -(portTextRect.width * 0.06)
                anchors.left: portTextRect.left
                width: listeningPortLabelText.contentWidth + 10
                height: portTextRect.height * 0.3
                Text{
                    id: listeningPortLabelText
                    anchors.centerIn: listeningPortLabel
                    text: LocalStrings.getLocalTextValue("listeningPort")
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getTextEditLabelPixelSize()
                    color: StyleGlobalConsts.getTextSecondaryColor()
                }
            }

            Rectangle{
                id : mainTargetsettingsRect
                width: commLinkSettingsRect.width * 0.9
                height: Qt.platform.os == "android" ?commLinkSettingsRect.width * 0.13:commLinkSettingsRect.width * 0.1
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                anchors.top: portTextRect.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.08
                visible: false
                border.color: StyleGlobalConsts.getTextSecondaryColor()
                border.width: 1
                radius: 4
                color: StyleGlobalConsts.getTransparentColor()
                TextInput{
                    id: targetHostAddr
                    width: mainTargetsettingsRect.width
                    height: mainTargetsettingsRect.height
                    verticalAlignment: Text.AlignVCenter
                    anchors.horizontalCenter: mainTargetsettingsRect.horizontalCenter
                    anchors.verticalCenter: mainTargetsettingsRect.verticalCenter
                    anchors.left: mainTargetsettingsRect.left
                    anchors.leftMargin: 20
                    maximumLength: 30
                    clip: true
                    focus: true
                    color: StyleGlobalConsts.getTextPrimaryColor()
                    font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                    text: "127.0.0.1"
                    property string placeholderText: LocalStrings.getLocalTextValue("enterSimulIP")
                    Text {
                        width: targetHostAddr.width
                        height: targetHostAddr.height
                        text: "127.0.0.1"
                        verticalAlignment: Text.AlignVCenter
                        color: StyleGlobalConsts.getTextSecondaryColor()
                        font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                        font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                        visible: !targetHostAddr.text
                        anchors.left: targetHostAddr.left
                        anchors.top: targetHostAddr.top
                    }
                }
            }

            Label{
                id: targetHostLabel
                anchors.top: mainTargetsettingsRect.top
                anchors.topMargin: -(mainTargetsettingsRect.width * 0.06)
                anchors.left: mainTargetsettingsRect.left
                width: targetHostLabelText.contentWidth + 10
                height: mainTargetsettingsRect.height * 0.3
                Text{
                    id: targetHostLabelText
                    anchors.centerIn: targetHostLabel
                    text: LocalStrings.getLocalTextValue("targetAddr")
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getTextEditLabelPixelSize()
                    color: StyleGlobalConsts.getTextSecondaryColor()
                }
            }


            Rectangle{
                id : targetportTextRect
                width: commLinkSettingsRect.width * 0.9
                height: Qt.platform.os == "android" ?commLinkSettingsRect.width * 0.13:commLinkSettingsRect.width * 0.1
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                anchors.top: mainTargetsettingsRect.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.08
                visible: false
                border.color: StyleGlobalConsts.getTextSecondaryColor()
                border.width: 1
                radius: 4
                color: StyleGlobalConsts.getTransparentColor()
                TextInput{
                    id: targethostPortNum
                    width: targetportTextRect.width
                    height: targetportTextRect.height
                    text: "14552"
                    verticalAlignment: Text.AlignVCenter
                    anchors.horizontalCenter: targetportTextRect.horizontalCenter
                    anchors.verticalCenter: targetportTextRect.verticalCenter
                    anchors.left: targetportTextRect.left
                    anchors.leftMargin: 20
                    maximumLength: 30
                    clip: true
                    focus: true
                    color: StyleGlobalConsts.getTextPrimaryColor()
                    font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                    validator: RegExpValidator { regExp: /[0-9]+/ }
                    property string placeholderText: LocalStrings.getLocalTextValue("enterSimulPort")
                    Text {
                        width: targethostPortNum.width
                        height: targethostPortNum.height
                        text: "14552"
                        verticalAlignment: Text.AlignVCenter
                        color: StyleGlobalConsts.getTextSecondaryColor()
                        font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                        font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                        visible: !targethostPortNum.text
                        anchors.left: targethostPortNum.left
                        anchors.top: targethostPortNum.top
                    }
                }
            }

            Label{
                id: targetPortLabel
                anchors.top: targetportTextRect.top
                anchors.topMargin: -(targetportTextRect.width * 0.06)
                anchors.left: targetportTextRect.left
                width: targetPortLabelText.contentWidth + 10
                height: targetportTextRect.height * 0.3
                Text{
                    id: targetPortLabelText
                    anchors.centerIn: targetPortLabel
                    text: LocalStrings.getLocalTextValue("targetPrt")
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getTextEditLabelPixelSize()
                    color: StyleGlobalConsts.getTextSecondaryColor()
                }
            }


            AeroGCSComboBox {
                id : serialPortSelector
                width: commLinkSettingsRect.width * 0.9
                height: Qt.platform.os == "android" ?commLinkSettingsRect.width * 0.13:commLinkSettingsRect.width * 0.1
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                anchors.top: commLinkSettingsRect.top
                anchors.topMargin: commLinkSettingsRect.height * 0.21
                font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                }

            Label{
                id: serialPortLabel
                anchors.top: serialPortSelector.top
                anchors.topMargin: -(serialPortSelector.width * 0.1)
                anchors.left: serialPortSelector.left
                width: contentWidth
                height: serialPortSelector.height * 0.3
                text: LocalStrings.getLocalTextValue("serialPort")
                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                color: StyleGlobalConsts.getTextSecondaryColor()
            }

            AeroGCSComboBox {
                id : baudRateSelector
                width: commLinkSettingsRect.width * 0.9
                height: Qt.platform.os == "android" ?commLinkSettingsRect.width * 0.13:commLinkSettingsRect.width * 0.1
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                anchors.top: serialPortSelector.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.05
                font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                model: [ LocalStrings.getLocalTextValue("baud9600"),
                    LocalStrings.getLocalTextValue("baud19200"),
                    LocalStrings.getLocalTextValue("baud38400"),
                    LocalStrings.getLocalTextValue("baud57600"),
                    LocalStrings.getLocalTextValue("baud115200")]
                }

            Rectangle{
                id: dataBitRect
                height: baudRateSelector.height * 0.68
                width: baudRateSelector.width
                anchors.top: baudRateSelector.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.06
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                color: StyleGlobalConsts.getTransparentColor()

                Label{
                    id: dataBitsText
                    anchors.verticalCenter: dataBitRect.verticalCenter
                    anchors.left: dataBitRect.left
                    anchors.leftMargin: dataBitsText.width * 0.1
                    height: dataBitRect.height
                    width: dataBitRect.width * 0.2
                    text: LocalStrings.getLocalTextValue("dataBits")
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.weight: "DemiBold"
                    font.pixelSize: StyleGlobalConsts.getRPASettingsLabelPixelSize()
                    color: StyleGlobalConsts.getTextPrimaryColor()
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
                        color: StyleGlobalConsts.getTransparentColor()
                        border.width: 0.5
                        border.color: StyleGlobalConsts.getThemeColor()
                    }
                    Text{
                        id: dataBitsOption1Text
                        anchors.centerIn: dataBitsOption1
                        text: "6"
                        font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                        font.weight: "Normal"
                        font.pixelSize: StyleGlobalConsts.getSmallLabelPixelSize()//12
                        color: StyleGlobalConsts.getThemeColor()
                    }
                    onClicked: {
                        dataBit = 6;
                        dataBitsOption1BgRect.color =  StyleGlobalConsts.getThemeColor()
                        dataBitsOption1BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        dataBitsOption1Text.color = StyleGlobalConsts.getSolidButtonTextColor()
                        dataBitsOption2BgRect.color = StyleGlobalConsts.getTransparentColor()
                        dataBitsOption2BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        dataBitsOption2Text.color =  StyleGlobalConsts.getThemeColor()
                        dataBitsOption3BgRect.color = StyleGlobalConsts.getTransparentColor()
                        dataBitsOption3BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        dataBitsOption3Text.color = StyleGlobalConsts.getThemeColor()
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
                        color: StyleGlobalConsts.getTransparentColor()
                        border.width: 0.5
                        border.color: StyleGlobalConsts.getThemeColor()
                    }
                    Text{
                        id: dataBitsOption2Text
                        anchors.centerIn: dataBitsOption2
                        text: "7"
                        font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                        font.weight: "Normal"
                        font.pixelSize: StyleGlobalConsts.getSmallLabelPixelSize()
                        color: StyleGlobalConsts.getThemeColor()
                    }
                    onClicked: {
                        dataBit = 7;
                        dataBitsOption2BgRect.color =  StyleGlobalConsts.getThemeColor()
                        dataBitsOption2BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        dataBitsOption2Text.color = StyleGlobalConsts.getSolidButtonTextColor()
                        dataBitsOption1BgRect.color = StyleGlobalConsts.getTransparentColor()
                        dataBitsOption1BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        dataBitsOption1Text.color =  StyleGlobalConsts.getThemeColor()
                        dataBitsOption3BgRect.color = StyleGlobalConsts.getTransparentColor()
                        dataBitsOption3BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        dataBitsOption3Text.color = StyleGlobalConsts.getThemeColor()
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
                        border.width: 0.5
                        border.color: StyleGlobalConsts.getThemeColor()
                        color :  StyleGlobalConsts.getThemeColor()
                    }
                    Text{
                        id: dataBitsOption3Text
                        anchors.centerIn: dataBitsOption3
                        text: "8"
                        font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                        font.weight: "Normal"
                        font.pixelSize: StyleGlobalConsts.getSmallLabelPixelSize()
                        color: StyleGlobalConsts.getSolidButtonTextColor()
                    }
                    onClicked: {
                        dataBit = 8;
                        dataBitsOption3BgRect.color =  StyleGlobalConsts.getThemeColor()
                        dataBitsOption3BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        dataBitsOption3Text.color = StyleGlobalConsts.getSolidButtonTextColor()
                        dataBitsOption1BgRect.color = StyleGlobalConsts.getTransparentColor()
                        dataBitsOption1BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        dataBitsOption1Text.color =  StyleGlobalConsts.getThemeColor()
                        dataBitsOption2BgRect.color = StyleGlobalConsts.getTransparentColor()
                        dataBitsOption2BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        dataBitsOption2Text.color = StyleGlobalConsts.getThemeColor()
                    }
                }
            }

            /*----------------------------- Parity Bits Row----------------------------------*/
            Rectangle{
                id: parityRect
                height: dataBitRect.height
                width: dataBitRect.width
                anchors.top: dataBitRect.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.045
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                color: StyleGlobalConsts.getTransparentColor()
                Label{
                    id: parityText
                    anchors.verticalCenter: parityRect.verticalCenter
                    anchors.left: parityRect.left
                    anchors.leftMargin: parityText.width * 0.1
                    height: parityRect.height
                    width: parityRect.width * 0.2
                    text: LocalStrings.getLocalTextValue("parity")
                    font.weight: "DemiBold"
                    font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                    font.pixelSize: StyleGlobalConsts.getRPASettingsLabelPixelSize()
                    color: StyleGlobalConsts.getTextPrimaryColor()
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
                        color: StyleGlobalConsts.getThemeColor()
                        border.width: 0.5
                        border.color: StyleGlobalConsts.getThemeColor()
                    }
                    Text{
                        id: parityOption1Text
                        anchors.centerIn: parityOption1
                        text: LocalStrings.getLocalTextValue("none")
                        font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                        font.weight: "Normal"
                        font.pixelSize: StyleGlobalConsts.getSmallLabelPixelSize()
                        color: StyleGlobalConsts.whiteColor()
                    }
                    onClicked: {
                        parity = 1
                        parityOption1BgRect.color =  StyleGlobalConsts.getThemeColor()
                        parityOption1BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        parityOption1Text.color = StyleGlobalConsts.whiteColor()
                        parityOption2BgRect.color = StyleGlobalConsts.getTransparentColor()
                        parityOption2BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        parityOption2Text.color =  StyleGlobalConsts.getThemeColor()
                        parityOption3BgRect.color = StyleGlobalConsts.getTransparentColor()
                        parityOption3BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        parityOption3Text.color = StyleGlobalConsts.getThemeColor()
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
                        color :  StyleGlobalConsts.getTransparentColor()
                        border.width: 0.5
                        border.color: StyleGlobalConsts.getThemeColor()
                    }
                    Text{
                        id: parityOption2Text
                        anchors.centerIn: parityOption2
                        text: "Even"
                        font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                        font.weight: "Normal"
                        font.pixelSize: StyleGlobalConsts.getSmallLabelPixelSize()
                        color: StyleGlobalConsts.getThemeColor()
                    }
                    onClicked: {
                        parity = 2
                        parityOption2BgRect.color =  StyleGlobalConsts.getThemeColor()
                        parityOption2BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        parityOption2Text.color = StyleGlobalConsts.getSolidButtonTextColor()
                        parityOption1BgRect.color = StyleGlobalConsts.getTransparentColor()
                        parityOption1BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        parityOption1Text.color =  StyleGlobalConsts.getThemeColor()
                        parityOption3BgRect.color = StyleGlobalConsts.getTransparentColor()
                        parityOption3BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        parityOption3Text.color = StyleGlobalConsts.getThemeColor()
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
                        color: StyleGlobalConsts.getTransparentColor()
                        border.width: 0.5
                        border.color: StyleGlobalConsts.getThemeColor()
                    }
                    Text{
                        id: parityOption3Text
                        anchors.centerIn: parityOption3
                        text: LocalStrings.getLocalTextValue("odd")
                        font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                        font.weight: "Normal"
                        font.pixelSize: StyleGlobalConsts.getSmallLabelPixelSize()
                        color: StyleGlobalConsts.getThemeColor()
                    }
                    onClicked: {
                        parity = 3
                        parityOption3BgRect.color =  StyleGlobalConsts.getThemeColor()
                        parityOption3BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        parityOption3Text.color = StyleGlobalConsts.getSolidButtonTextColor()
                        parityOption1BgRect.color = StyleGlobalConsts.getTransparentColor()
                        parityOption1BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        parityOption1Text.color =  StyleGlobalConsts.getThemeColor()
                        parityOption2BgRect.color = StyleGlobalConsts.getTransparentColor()
                        parityOption2BgRect.border.color = StyleGlobalConsts.getThemeColor()
                        parityOption2Text.color = StyleGlobalConsts.getThemeColor()
                    }
                }
            }

            AeroGCSComboBox {
                id : flowControlSelector
                width: commLinkSettingsRect.width * 0.9
                height: Qt.platform.os == "android" ?commLinkSettingsRect.width * 0.13:commLinkSettingsRect.width * 0.1
                anchors.top: parityRect.bottom
                anchors.topMargin: commLinkSettingsRect.height * 0.06
                anchors.horizontalCenter: commLinkSettingsRect.horizontalCenter
                font.pixelSize: StyleGlobalConsts.getTextEditPixelSize()
                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                model: [LocalStrings.getLocalTextValue("none"),
                    LocalStrings.getLocalTextValue("rtsORcts"),
                    LocalStrings.getLocalTextValue("xonORxoff")]
            }
        }
        RoundButton{
            id : connectButton
            width: StyleGlobalConsts.defaultButtonWidth()
            height: StyleGlobalConsts.defaultButtonHeight()
            radius: StyleGlobalConsts.defaultButtonRadius()
            anchors.right: commLinkSettingsOuterRect.right
            anchors.rightMargin: commLinkSettingsRect.width * 0.09
            anchors.top: commLinkSettingsOuterRect.top
            anchors.topMargin: commLinkSettingsRect.height * 0.06
            background: Rectangle{
                id: connectButtonRect
                radius: connectButton.radius
                color: StyleGlobalConsts.getThemeColor()
                border.color: StyleGlobalConsts.getThemeColor()
                border.width: 1
            }
            onClicked: {
                if(selectedInterface === 0)
                {
                    disconnectButtonRect.color = StyleGlobalConsts.getTransparentColor()
                    disconnectButtonRect.border.color =  StyleGlobalConsts.getThemeColor()
                    disconnectButtonText.color = StyleGlobalConsts.getThemeColor()
                    connectButtonText.color = StyleGlobalConsts.getSolidButtonTextColor()
                    connectButtonRect.border.color = StyleGlobalConsts.getThemeColor()
                    connectButtonRect.color = StyleGlobalConsts.getThemeColor()
                    advancedButtonRect.color = StyleGlobalConsts.getTransparentColor()
                    advancedButtonRect.border.color = StyleGlobalConsts.getThemeColor()
                    advancedButtonText.color = StyleGlobalConsts.getThemeColor()

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

                    }
                }
                if(selectedInterface === 2 || selectedInterface === 1)
                {
                    MySerialPort.setHostAddr(tcpHostAddr.text)
                    MySerialPort.setHostPort(hostPortNum.text)
                    MySerialPort.setTargetAddr(targetHostAddr.text);
                    MySerialPort.setTargetPort(targethostPortNum.text)

                    MySerialPort.openSerialPort();
                    if(MySerialPort.isSerialPortOpen())
                    {

                    }
                }
                if(selectedInterface === 3 )
                {
                    if(subEditConfig)
                        BluetoothLink._connect()
                }
            }
            Text {
                id: connectButtonText
                text: LocalStrings.getLocalTextValue("connect")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                color: StyleGlobalConsts.getSolidButtonTextColor()
                height: connectButton.height
                width: connectButton.width
                anchors.left: connectButton.left
            }
        }

        RoundButton {
            id : disconnectButton
            width: StyleGlobalConsts.defaultButtonWidth()
            height: StyleGlobalConsts.defaultButtonHeight()
            radius: StyleGlobalConsts.defaultButtonRadius()
            anchors.right: commLinkSettingsOuterRect.right
            anchors.rightMargin: commLinkSettingsRect.width * 0.09
            anchors.top: connectButton.bottom
            anchors.topMargin: commLinkSettingsRect.height * 0.06
            background: Rectangle{
                id: disconnectButtonRect
                radius: disconnectButton.radius
                color: StyleGlobalConsts.getTransparentColor()
                border.color: StyleGlobalConsts.getThemeColor()
                border.width: 1
            }
            onClicked: {
                disconnectButtonRect.color =  StyleGlobalConsts.getThemeColor()
                disconnectButtonText.color = StyleGlobalConsts.getSolidButtonTextColor()
                connectButtonText.color = StyleGlobalConsts.getThemeColor()
                connectButtonRect.border.color = StyleGlobalConsts.getThemeColor()
                connectButtonRect.color = StyleGlobalConsts.getTransparentColor()
                advancedButtonRect.color = StyleGlobalConsts.getTransparentColor()
                advancedButtonRect.border.color = StyleGlobalConsts.getThemeColor()
                advancedButtonText.color = StyleGlobalConsts.getThemeColor()
                MySerialPort.closeSerialPort(1)
            }

            Text {
                id: disconnectButtonText
                text: LocalStrings.getLocalTextValue("disconnect")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                color: StyleGlobalConsts.getThemeColor()
                height: disconnectButton.height
                width: disconnectButton.width
            }
        }

        RoundButton {
            id : bluetootshScan
            width: StyleGlobalConsts.defaultButtonWidth()
            height: StyleGlobalConsts.defaultButtonHeight()
            radius: StyleGlobalConsts.defaultButtonRadius()
            anchors.right: commLinkSettingsOuterRect.right
            anchors.rightMargin: commLinkSettingsRect.width * 0.09
            anchors.top: disconnectButton.bottom
            anchors.topMargin: commLinkSettingsRect.height * 0.06
            background: Rectangle{
                id: bluetootshScanRect
                radius: parent.radius
                color: StyleGlobalConsts.getTransparentColor()
                border.color: StyleGlobalConsts.getThemeColor()
                border.width: 1
            }

            Text {
                id: bluetootshScanText
                text: "Scan"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                color: StyleGlobalConsts.getThemeColor()
                height: disconnectButton.height
                width: disconnectButton.width
            }
            onClicked: {

                if(subEditConfig)
                    subEditConfig.startScan()

                bluetootshScanRect.color =  StyleGlobalConsts.getThemeColor()
                bluetootshScanRect.border.color = StyleGlobalConsts.getThemeColor()
                bluetootshScanText.color = StyleGlobalConsts.getSolidButtonTextColor()

                bluetoothStopBgRect.color = StyleGlobalConsts.getTransparentColor()
                bluetoothStopBgRect.border.color = StyleGlobalConsts.getThemeColor()
                bluetoothStopText.color =  StyleGlobalConsts.getThemeColor()

//                bluetoothconnectBgRect.color = StyleGlobalConsts.getTransparentColor()
//                bluetoothconnectBgRect.border.color = StyleGlobalConsts.getThemeColor()
//                bluetoothconnectText.color = StyleGlobalConsts.getThemeColor()
            }
        }



        RoundButton {
            id : bluetoothStop
            width: StyleGlobalConsts.defaultButtonWidth()
            height: StyleGlobalConsts.defaultButtonHeight()
            radius: StyleGlobalConsts.defaultButtonRadius()
            anchors.right: commLinkSettingsOuterRect.right
            anchors.rightMargin: commLinkSettingsRect.width * 0.09
            anchors.top: bluetootshScan.bottom
            anchors.topMargin: commLinkSettingsRect.height * 0.06
            background: Rectangle{
                id: bluetoothStopBgRect
                radius: parent.radius
                color: StyleGlobalConsts.getTransparentColor()
                border.color: StyleGlobalConsts.getThemeColor()
                border.width: 1
            }

            Text {
                id: bluetoothStopText
                text: "Stop"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                color: StyleGlobalConsts.getThemeColor()
                height: disconnectButton.height
                width: disconnectButton.width
            }
            onClicked: {
                if(subEditConfig)
                    subEditConfig.stopScan()

                bluetootshScanRect.color =  StyleGlobalConsts.getTransparentColor()
                bluetootshScanRect.border.color = StyleGlobalConsts.getThemeColor()
                bluetootshScanText.color = StyleGlobalConsts.getThemeColor()

                bluetoothStopBgRect.color = StyleGlobalConsts.getThemeColor()
                bluetoothStopBgRect.border.color = StyleGlobalConsts.getThemeColor()
                bluetoothStopText.color =  StyleGlobalConsts.getSolidButtonTextColor()

//                bluetoothconnectBgRect.color = StyleGlobalConsts.getTransparentColor()
//                bluetoothconnectBgRect.border.color = StyleGlobalConsts.getThemeColor()
//                bluetoothconnectText.color = StyleGlobalConsts.getThemeColor()
            }
        }

//        RoundButton {
//            id : bluetoothconnect
//            width: StyleGlobalConsts.defaultButtonWidth()
//            height: StyleGlobalConsts.defaultButtonHeight()
//            radius: StyleGlobalConsts.defaultButtonRadius()
//            anchors.right: commLinkSettingsOuterRect.right
//            anchors.rightMargin: commLinkSettingsRect.width * 0.09
//            anchors.top: bluetoothStop.bottom
//            anchors.topMargin: commLinkSettingsRect.height * 0.06
//            background: Rectangle{
//                id: bluetoothconnectBgRect
//                radius: parent.radius
//                color: StyleGlobalConsts.getTransparentColor()
//                border.color: StyleGlobalConsts.getThemeColor()
//                border.width: 1
//            }

//            Text {
//                id: bluetoothconnectText
//                text: "Connect"
//                verticalAlignment: Text.AlignVCenter
//                horizontalAlignment: Text.AlignHCenter
//                font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
//                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
//                color: StyleGlobalConsts.getThemeColor()
//                height: disconnectButton.height
//                width: disconnectButton.width
//            }
//            onClicked: {
//                if(subEditConfig)
////                    MySerialPort.openSerialPort();
//                    BluetoothLink._connect()
//                bluetootshScanRect.color =  StyleGlobalConsts.getTransparentColor()
//                bluetootshScanRect.border.color = StyleGlobalConsts.getThemeColor()
//                bluetootshScanText.color = StyleGlobalConsts.getThemeColor()

//                bluetoothStopBgRect.color = StyleGlobalConsts.getTransparentColor()
//                bluetoothStopBgRect.border.color = StyleGlobalConsts.getThemeColor()
//                bluetoothStopText.color =  StyleGlobalConsts.getThemeColor()

//                bluetoothconnectBgRect.color = StyleGlobalConsts.getThemeColor()
//                bluetoothconnectBgRect.border.color = StyleGlobalConsts.getThemeColor()
//                bluetoothconnectText.color = StyleGlobalConsts.getSolidButtonTextColor()
//            }
//        }
        /*---------------------- Advanced Settings Button-----------------------------*/
        RoundButton {
            id : advancedButton
            width: StyleGlobalConsts.defaultButtonWidth()
            height: StyleGlobalConsts.defaultButtonHeight()
            radius: StyleGlobalConsts.defaultButtonRadius()
            anchors.right: commLinkSettingsOuterRect.right
            anchors.rightMargin: commLinkSettingsRect.width * 0.08
            anchors.bottom: commLinkSettingsOuterRect.bottom
            anchors.bottomMargin: commLinkSettingsRect.height * 0.06
            background: Rectangle{
                id: advancedButtonRect
                radius: advancedButton.radius
                color: StyleGlobalConsts.getTransparentColor()
                border.color: StyleGlobalConsts.getThemeColor()
                border.width: 1
            }

            Text {
                id: advancedButtonText
                text: LocalStrings.getLocalTextValue("advanced")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                font.family: mainWindowWithStackView.aeroGCSDefaultFonts
                color: StyleGlobalConsts.getThemeColor()
                height: disconnectButton.height
                width: disconnectButton.width
            }
            onClicked: {
                disconnectButtonRect.color = StyleGlobalConsts.getTransparentColor()
                disconnectButtonRect.border.color =  StyleGlobalConsts.getThemeColor()
                disconnectButtonText.color = StyleGlobalConsts.getThemeColor()
                connectButtonText.color = StyleGlobalConsts.getThemeColor()
                connectButtonRect.border.color = StyleGlobalConsts.getThemeColor()
                connectButtonRect.color = StyleGlobalConsts.getTransparentColor()
                advancedButtonRect.color = StyleGlobalConsts.getThemeColor()
                advancedButtonRect.border.color = StyleGlobalConsts.getThemeColor()
                advancedButtonText.color = StyleGlobalConsts.getSolidButtonTextColor()
                advanceSettings.show()
            }
        }

    }
    /*------------------------ DropShadow Effect ------------------------------*/

    DropShadow{
        id: dropShadow1
        anchors.fill: commLinkSettingsOuterRect
        verticalOffset: StyleGlobalConsts.getDropshadowVerticalOffset()
        horizontalOffset: StyleGlobalConsts.getDropshadowHorizontalOffset()
        radius: StyleGlobalConsts.getDropshadowRadius()
        samples: StyleGlobalConsts.getDropshadowSamples()
        color: StyleGlobalConsts.getDropshadowColor()
        source: commLinkSettingsOuterRect
    }

    Connections{
        target: mainWindowSerialPort.connectionTargetMessage
        onShowMessageBoxToConnectSerialPort :
        {
            progressBar.start()
        }
        onShowMessageBoxUnableToConnectSeralPort :
        {
            serialPortNotConnectedMessage.messageDescription = LocalStrings.getLocalTextValue("unableToConnectPort")
            serialPortNotConnectedMessage.show()
        }
        onShowMessageBoxSerialPortAlreadyConnected :
        {
            serialPortAlreadyConnectedMessage.show()
        }
        onShowMessageBoxSerialPortDisconnected :
        {

        }
        onCommLinkError:{
            MySerialPort.setSerialPortParamFlag(0)
            MySerialPort.closeSerialPort(0)
            progressBar.end()
        }
    }

    Connections{
        target: mainWindowSerialPort.droneRegistrationCheck
        onDroneOwnershipCheckFailed :
        {
            MySerialPort.closeSerialPort(0)
            serialPortNotConnectedMessage.hide()
            droneOwnerShipCheckFailed.show()
        }

        onDroneAlreadyRegister:
        {
            AudioModule.speak("Drone Connected",true)
            serialPortNotConnectedMessage.hide()
            serialPortMessage.show()
            DroneDetailsHelper.registerdrone()
        }

        onDroneNeedToRegister:
        {
            serialPortNotConnectedMessage.messageDescription = LocalStrings.getLocalTextValue("registerDrone")
            mainStackView.pop(null);
            mainStackView.push(mainStackView.mainLoginStackView)
            mainStackView.mainLoginStackView.logInPageStackView.pop(null)
            mainStackView.mainLoginStackView.logInPageStackView.push(mainStackView.mainLoginStackView.logInPageStackView.login)
        }
    }

    Connections{
        target: BluetoothLink
        onConnected:
        {
            MySerialPort.openSerialPort();
        }
    }
}