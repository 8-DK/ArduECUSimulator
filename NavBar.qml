import QtQuick 2.4
import QtQuick.Window 2.12
import SerialPortLib 1.0
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import LocalStringsLib 1.0
import StyleGlobalConstsLib 1.0

Rectangle {
    id:root
    z: 150
    width: mainWindowWithStackView.width
    height: mainWindowWithStackView.height * 0.065//0.09
    signal onClickedNotification(); // onClicked: print('onClicked')
    signal clickedMenu();
    property string header: ''

    FontLoader {
        id:openSansRegular
        source:'Fonts/Open_Sans_Regular.ttf'
    }

    FontLoader {
        id:openSansNormal
        source:'Fonts/Open_Sans_Regular.ttf'
    }

    FontLoader {
        id: montserratRegular
        source:'Fonts/Montserrat-Regular.ttf'
    }

    FontLoader {
        id: robotoRegular
        source:'Fonts/Roboto-Regular.ttf'
    }

    MessageBox{
        id: messageBox
        messageDescription: LocalStrings.getLocalTextValue("serialPortMessage")
        onOkButtonClickSignal: {
            messageBox.hide()
            drawer.close()
            mainWindowWithStackView.close();
        }
    }

    MessageBox{
        id: notLogFile
        messageDescription: LocalStrings.getLocalTextValue("logFileNotExist")
        onOkButtonClickSignal: {
            notLogFile.hide()
            drawer.close()
        }
    }

    MessageBox{
        id: serialPortNotConnectedMessage
        messageDetails: "Yes"
        messageDescription: "Device is not connected! Do you want to connect the device?"
        onOkButtonClickSignal: {
            drawer.close()
            serialPortNotConnectedMessage.hide()
            //            mainStackView.push(mainStackView.mainMyserilPortStackView)
            mainStackView.push(mainStackView.mainSensorStackView)
            //setNextScreen(1)
        }
        onCancelButtonClickSignal: {
            drawer.close()
            serialPortNotConnectedMessage.hide()
        }
    }
        MessageBox{
            id: serialDisconnectedMessage
            onOkButtonClickSignal: {
                drawer.close()
                serialDisconnectedMessage.hide()
            }
        }

    MessageBox{
        id: appExitMessagebox
        messageDetails: LocalStrings.getLocalTextValue("yes")
        messageDescription: LocalStrings.getLocalTextValue("softwareExit")
        onOkButtonClickSignal: {
            appExitMessagebox.hide()
            drawer.close()
            mainWindowWithStackView.close();
            Qt.quit()
        }
        onCancelButtonClickSignal: {
            appExitMessagebox.hide()
            drawer.close()
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
                disconnectConfirmationMessagebox.hide()
                drawer.close()
            }
        }


    Rectangle {
        id:navBar
        visible: true
        width: mainWindowWithStackView.width
        height: mainWindowWithStackView.height * 0.065//0.09
        color : StyleGlobalConsts.whiteColor()
        anchors.top: mainWindowWithStackView.top
        Image {
            id: image
            width: navBar.width * 0.08
            height: navBar.height * 0.6
            anchors.verticalCenter: navBar.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: navBar.width * 0.01
            fillMode: Image.PreserveAspectFit
            mipmap: true
            smooth: true
            source: "/assets/PDRL_Logo_Medium.svg"
        }
        MouseArea {
            x:image.x
            y:image.y
            width: image.width
            height: image.height
            onClicked: {
                drawer.close()
                console.log("Current view Name : "+getCurrentViewName()+" Prev View : "+getPreviousViewName());
                mainStackView.pop()
            }
        }

        Image {
            id: image1
            width: StyleGlobalConsts.windowWidth() * 0.0141 //navBar.width * 0.015
            height: StyleGlobalConsts.windowHeight() * 0.025 //navBar.height * 0.5
            anchors.right: navBar.right
            anchors.rightMargin: StyleGlobalConsts.windowWidth() * 0.053//navBar.width * 0.03
            anchors.verticalCenter: navBar.verticalCenter
            fillMode: Image.PreserveAspectFit
            source: "assets/menu.png"
        }

        MouseArea {
            x:image1.x
            y:image1.y
            height: image1.height
            width: image1.width

            onClicked: {
                drawer.open()
                root.clickedMenu()
            }
        }

        Image {
            id: image2
            width: StyleGlobalConsts.windowWidth() * 0.02
            height: StyleGlobalConsts.windowWidth() * 0.02
            anchors.right: image1.right
            anchors.rightMargin: navBar.width * 0.034
            anchors.verticalCenter: parent.verticalCenter
            fillMode: Image.PreserveAspectFit
            source: "assets/bell.png"
        }

        MouseArea {
            x:image2.x
            y:image2.y
            height: image2.height
            width: image2.width
            onClicked: {
                drawer.close()
                mainStackView.push(mainStackView.mainNotificationStackView)
            }
        }

        Text {
            id: element
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            text: root.header
            font.weight: "DemiBold"
            font.pixelSize: StyleGlobalConsts.getNavbarHeadingPixelSize()
            font.family: openSansNormal.name
        }
    }

    DropShadow {
        id: dropShadow
        anchors.fill: navBar
        verticalOffset: StyleGlobalConsts.getDropshadowVerticalOffset()
        horizontalOffset: StyleGlobalConsts.getDropshadowHorizontalOffset()
        radius: StyleGlobalConsts.getDropshadowRadius()
        samples: StyleGlobalConsts.getDropshadowSamples()
        color: StyleGlobalConsts.getDropshadowColor()
        source: navBar
    }

    Drawer {
        id: drawer
        edge: Qt.RightEdge
        width: mainWindowWithStackView.width * 0.20
        height: mainWindowWithStackView.height
        background: Rectangle{
            id: drawerRect
            border.width: 1
            border.color: StyleGlobalConsts.borderColor()//"blue"

            Button{
                id: homeButton
                anchors.top: parent.top
                anchors.topMargin: drawer.height * 0.05
                anchors.left: parent.left
                anchors.leftMargin: drawer.width * 0.1
                width: drawer.width * 0.6
                height: drawer.height * 0.03

                background: Rectangle{
                    color: "transparent"
                    //border.width: 1
                }
                Text{
                    id: homeButtonText
                    anchors.verticalCenter: homeButton.verticalCenter
                    text: "Home"
                    font.family: openSansNormal.name
                    font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                    font.weight: "Normal"
                }
                onClicked:
                {
                    drawer.close()
                    mainStackView.pop(mainStackView.mainDashboardStackView)
                }
            }

            Button
            {
                id: configurationButton
                anchors.top: homeButton.bottom
                anchors.topMargin: drawer.height * 0.02
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.1
                width: drawer.width * 0.6
                height: drawer.height * 0.03
                background: Rectangle{
                    color: "transparent"
                    //border.width: 1
                }

                Text{
                    id: configurationButtonText
                    anchors.verticalCenter: configurationButton.verticalCenter
                    text: "RPA Configuration"
                    font.family: openSansNormal.name
                    font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                    font.weight: "Normal"
                }
                onClicked:{
                    if(MySerialPort.isSerialPortOpen() === true)
                    {
                        drawer.close()
                        mainStackView.push(mainStackView.mainSensorStackView)
                    }
                    else{

                        serialPortNotConnectedMessage.show()
                    }
                }
            }

            Button{
                id: logButton
                anchors.top: configurationButton.bottom
                anchors.topMargin: drawer.height * 0.02
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.1
                width: drawer.width * 0.6
                height: drawer.height * 0.03
                background: Rectangle{
                    color: "transparent"
                    //border.width: 1
                }

                Text{
                    id: logButtonText
                    anchors.verticalCenter: logButton.verticalCenter
                    text: "RPA Logs"
                    font.family: openSansNormal.name
                    font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                    font.weight: "Normal"
                }
                onClicked: {
                    drawer.close()
                    if(0 === fileOpenObject.openFileInTextEditor("logfile.txt"))
                    {
                        notLogFile.show()   //no log fileOpenObject
                    }
                }
            }

            Button{
                id: systemSettingsButton
                anchors.top: logButton.bottom
                anchors.topMargin: drawer.height * 0.02
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.1
                width: drawer.width * 0.6
                height: drawer.height * 0.03
                background: Rectangle{
                    color: "transparent"
                    //border.width: 1
                }

                Text{
                    id: systemSettingsButtonText
                    anchors.verticalCenter: systemSettingsButton.verticalCenter
                    text: "User Setting"
                    font.family: openSansNormal.name
                    font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                    font.weight: "Normal"
                }
                onClicked: {
                    drawer.close()
                    mainStackView.push(mainStackView.mainSystemSettingsStackView)
                }
            }


            Button{
                            id: disconnectButton
                            anchors.top: systemSettingsButton.bottom
                            anchors.topMargin: drawer.height * 0.02
                            anchors.left: parent.left
                            anchors.leftMargin: parent.width * 0.1
                            width: drawer.width * 0.6
                            height: drawer.height * 0.03
                            background: Rectangle{
                                color: "transparent"
                            }
                            Text{
                                id: disconnectButtonText
                                anchors.verticalCenter: disconnectButton.verticalCenter
                                text:  LocalStrings.getLocalTextValue("disconnect")
                                font.family: openSansNormal.name
                                font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                                font.weight: "Normal"
                            }
                            onClicked: {
                                if(MySerialPort.isSerialPortOpen() === true)
                                                    {
                                                        drawer.close()
                                                        disconnectConfirmationMessagebox.show()
                                                    }
                                                    else{
                                                        serialDisconnectedMessage.messageDetails = LocalStrings.getLocalTextValue("ok")
                                                        serialDisconnectedMessage.messageDescription = LocalStrings.getLocalTextValue("deviceNotConnected")
                                                        serialDisconnectedMessage.show()
                                                    }
                                                }
                            }



            Button{
                id: syncButton
                anchors.top: disconnectButton.bottom
                anchors.topMargin: drawer.height * 0.02
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.1
                width: drawer.width * 0.6
                height: drawer.height * 0.03
                background: Rectangle{
                    color: "transparent"
                    //border.width: 1
                }

                Text{
                    id: syncText
                    anchors.verticalCenter: syncButton.verticalCenter
                    text: "Cloud Sync"
                    font.family: openSansNormal.name
                    font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                    font.weight: "Normal"
                }
                onClicked: {
                    drawer.close()
                    syncComponent.startSyncFlow()
                }
            }

            Button{
                id: aboutButton
                anchors.top: syncButton.bottom
                anchors.topMargin: drawer.height * 0.02
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.1
                width: drawer.width * 0.6
                height: drawer.height * 0.03
                background: Rectangle{
                    color: "transparent"
                    //border.width: 1
                }

                Text{
                    id: aboutButtonText
                    anchors.verticalCenter: aboutButton.verticalCenter
                    text: LocalStrings.getLocalTextValue("about")
                    font.family: openSansNormal.name
                    font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                    font.weight: "Normal"
                }
                onClicked: {
                    drawer.close()
                    aeroGCSInfoPopup.open()
                   // appExitMessagebox.show()
                    // Qt.quit()
                }
            }

            Button{
                id: exitButton
                anchors.top: aboutButton.bottom
                anchors.topMargin: drawer.height * 0.02
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.1
                width: drawer.width * 0.6
                height: drawer.height * 0.03
                background: Rectangle{
                    color: "transparent"
                    //border.width: 1
                }

                Text{
                    id: exitButtonText
                    anchors.verticalCenter: exitButton.verticalCenter
                    text:  LocalStrings.getLocalTextValue("exit")
                    font.family: openSansNormal.name
                    font.pixelSize: StyleGlobalConsts.getButtonPixelSize()
                    font.weight: "Normal"
                }
                onClicked: {
                    drawer.close()
                    appExitMessagebox.show()
                }
            }
        }
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
