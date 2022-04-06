import QtQuick 2.4
import QtQuick.Window 2.12
import SerialPortLib 1.0
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import LocalStringsLib 1.0
import GStyleLib 1.0
import "CustomeWidget/SideDrawer"

Rectangle {
    id:root
    z: 150
    width: mainWindowWithStackView.width
    height: mainWindowWithStackView.height * 0.065//0.09
    signal onClickedNotification(); // onClicked: print('onClicked')
    signal clickedMenu();
    property string header: ''

    function updateNavTitle(title)
    {
        root.header = title
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
            //            mainStackView.push(mainStackView.mainComHelperStackView)
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
        color : GStyle.whiteColor()
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
            source: "/assets/Logo.png"
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
            width: GStyle.windowWidth() * 0.0141 //navBar.width * 0.015
            height: GStyle.windowHeight() * 0.025 //navBar.height * 0.5
            anchors.right: navBar.right
            anchors.rightMargin: navBar.width * 0.02
            anchors.verticalCenter: navBar.verticalCenter
            fillMode: Image.PreserveAspectFit
            source: "assets/menu.png"
        }
        ColorOverlay {
            anchors.fill: image1
            source: image1
            color: "#80800000"
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
            width: GStyle.windowWidth() * 0.02
            height: GStyle.windowWidth() * 0.02
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
            font.pixelSize: GStyle.getNavbarHeadingPixelSize()
            font.family: fontLdr.openSansRegular
        }
    }

    DropShadow {
        id: dropShadow
        anchors.fill: navBar
        verticalOffset: GStyle.getDropshadowVerticalOffset()
        horizontalOffset: GStyle.getDropshadowHorizontalOffset()
        radius: GStyle.getDropshadowRadius()
        samples: GStyle.getDropshadowSamples()
        color: GStyle.getDropshadowColor()
        source: navBar
    }


    SideDrawer {
        id: drawer
        edge: Qt.RightEdge
        width: mainWindowWithStackView.width * 0.20
        height: mainWindowWithStackView.height

        //
        // Icon properties
        //
        iconTitle: "ArduOBD2 Sim"
        iconSource: "/assets/Logo.png"
        iconSubtitle: qsTr ("Version 1.0 Beta - Developed by 8-DK")

        //
        // Define the actions to take for each drawer item
        // Drawers 5 and 6 are ignored, because they are used for
        // displaying a spacer and a separator
        //
        actions: {
            0: function() { console.log ("Item 1 clicked!") },
            1: function() {
                    connectComm()
             },
            2: function() { console.log ("Item 3 clicked!") },
            3: function() { console.log ("Item 4 clicked!") },
            4: function() { console.log ("Item 5 clicked!") },
            7: function() { console.log ("Item 6 clicked!") },
            8: function()
            {
                drawer.close()
                appExitMessagebox.show()
            }
        }

        //
        // Define the drawer items
        //
        items: ListModel {
            id: pagesModel

            ListElement {
                pageTitle: qsTr ("Item 1")
                pageIcon: "qrc:/assets/icons/dashboard.svg"
            }

            ListElement {
                pageTitle: qsTr ("Item 2")
                pageIcon: "qrc:/assets/icons/automotive-gear-oil.svg"
            }

            ListElement {
                pageTitle: qsTr ("Item 3")
                pageIcon: "qrc:/assets/icons/car-inspection.svg"
            }

            ListElement {
                pageTitle: qsTr ("Item 4")
                pageIcon: "qrc:/assets/icons/car-tire-wheel.svg"
            }

            ListElement {
                pageTitle: qsTr ("Item 5")
                pageIcon: "qrc:/assets/icons/engine-motor.svg"
            }

            ListElement {
                spacer: true
            }

            ListElement {
                separator: true
            }

            ListElement {
                pageTitle: qsTr ("Item 6")
                pageIcon: "qrc:/assets/icons/lubricant-oil.svg"
            }

            ListElement {
                pageTitle: qsTr ("Exit")
                pageIcon: "qrc:/assets/icons/open-door.svg"
            }
        }
    }

    function connectComm()
    {
        if(ComHelper.isSerialPortOpen() === true)
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


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
