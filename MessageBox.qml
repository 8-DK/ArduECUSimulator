import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtGraphicalEffects  1.12
import QtQuick.Dialogs 1.1
import QtQuick.VirtualKeyboard 2.0
import SerialPortSettingsLib 1.0
import CommLinkSettingsLib 1.0
import LocalStringsLib 1.0
import StyleGlobalConstsLib 1.0

Dialog{
    id: root
    modal: true
    focus: true
    parent: ApplicationWindow.overlay
    closePolicy: Dialog.CloseOnEscape
    width: StyleGlobalConsts.windowWidth() * 0.28
    height: StyleGlobalConsts.windowHeight() * 0.2
    property string messageDetails

    property string messageTitle: "AeroGCS"
    property string messageDescription: ''
    signal clickedMenu();
    signal okButtonClickSignal();
    signal cancelButtonClickSignal();
    anchors.centerIn: ApplicationWindow.overlay

    onFocusChanged: {
        if(focus)
        {
            okButtonBgRect.color = StyleGlobalConsts.blueColor()
            okButtonText.color = StyleGlobalConsts.whiteColor()
            cancelButtonBgRect.color = StyleGlobalConsts.whiteColor()
            cancelButtonText.color = StyleGlobalConsts.blueColor()
            okButton.focus = true
        }
    }

    background: Rectangle
    {
        color :"transparent"
        radius: 7
    }
    FontLoader {
        id:openSansRegular
        source:'qrc:/Fonts/Open_Sans_Regular.ttf'
    }
    FontLoader {
        id: montserratRegular
        source:'qrc:/Fonts/Montserrat-Regular.ttf'
    }
    FontLoader {
        id: robotoRegular
        source:'qrc:/Fonts/Roboto-Regular.ttf'
    }

    property string wrap: Text.WordWrap
    property alias messageDescription : messageDescText.text

    Rectangle {
        id: messageBoxRectangle
        width: root.width
        height: root.height
        radius: 7
        Rectangle{
            id: messageTitleRect
            height: messageBoxRectangle.height * 0.2
            width: parent.width * 0.95
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                id: messageTitleText
                text: messageTitle
                width: messageTitleRect.width
                height: messageTitleRect.height
                verticalAlignment: Text.AlignVCenter
                font.family: robotoRegular.name
                font.pixelSize: StyleGlobalConsts.getMessageBoxTextPixelSize()
                font.letterSpacing: 1
                anchors.left: messageTitleRect.left
                anchors.leftMargin: messageTitleRect.height * 0.3
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
                font.weight: "DemiBold"
                color: StyleGlobalConsts.blackColor()
            }
        }

        Rectangle{
            id : dividerLineRectangle
            width: root.width - (root.width * 0.1)
            height: 1.5
            radius: 2
            color: StyleGlobalConsts.blueColor()
            anchors.top: messageTitleRect.bottom
            anchors.topMargin: 5
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle{
            id: messageDescLabel
            width: parent.width * 0.9
            height: parent.height * 0.45
            anchors.top: dividerLineRectangle.bottom
            anchors.topMargin: 4
            anchors.horizontalCenter: parent.horizontalCenter
            Text{
                id: messageDescText
                text: ""
                width: messageDescLabel.width
                height: messageDescLabel.height
                font.family: robotoRegular.name
                font.letterSpacing: 1
                font.weight: "Normal"
                anchors.left: messageDescLabel.left
                anchors.top: messageDescLabel.top
                anchors.topMargin: parent.height * 0.1
                font.pixelSize: StyleGlobalConsts.getMessageBoxTextPixelSize()
                wrapMode: Text.Wrap
                color: StyleGlobalConsts.blackColor()
            }
        }

        RoundButton{
            id: okButton
            width: messageBoxRectangle.width * 0.25
            height: messageBoxRectangle.height * 0.18
            anchors.right: parent.right
            anchors.rightMargin: messageBoxRectangle.width * 0.05
            anchors.bottom: parent.bottom
            anchors.bottomMargin: messageBoxRectangle.height * 0.1
            radius: StyleGlobalConsts.defaultButtonRadius()
            focus: true
            activeFocusOnTab: false
            Text{
                id: okButtonText
                anchors.centerIn: okButton
                text: LocalStrings.getLocalTextValue("ok")
                font.family: openSansRegular.name
                font.pixelSize: StyleGlobalConsts.getTextEditLabelPixelSize()
                font.weight: "DemiBold"
                color: StyleGlobalConsts.whiteColor()
                font.letterSpacing: 0.5
            }
            onClicked: {
                root.okButtonClickSignal()
                okButtonBgRect.color = StyleGlobalConsts.blueColor()
                okButtonText.color = StyleGlobalConsts.whiteColor()
                cancelButtonBgRect.color = StyleGlobalConsts.whiteColor()
                cancelButtonText.color = StyleGlobalConsts.blueColor()
            }
            Keys.onReleased: {
                if(event.key === Qt.Key_Return ||event.key === Qt.Key_Enter )
                {
                    console.log("Enter Key pressed from messagebox")
                    root.okButtonClickSignal()
                }
            }
            background: Rectangle{
                id: okButtonBgRect
                width: parent.width
                height: parent.height
                radius: parent.radius
                color: StyleGlobalConsts.blueColor()
                border.width: 1
                border.color: StyleGlobalConsts.blueColor()
            }
        }

        RoundButton{
            id: cancelButton
            width: messageBoxRectangle.width * 0.3
            height: messageBoxRectangle.height * 0.18
            visible: false
            anchors.left: parent.left
            anchors.leftMargin: messageBoxRectangle.width * 0.05
            anchors.bottom: parent.bottom
            anchors.bottomMargin: messageBoxRectangle.height * 0.1
            radius: StyleGlobalConsts.defaultButtonRadius()
            activeFocusOnTab: false
            Text{
                id: cancelButtonText
                anchors.centerIn: cancelButton
                text:LocalStrings.getLocalTextValue("cancel")
                font.family: openSansRegular.name
                font.pixelSize: StyleGlobalConsts.getTextEditLabelPixelSize()//14
                font.weight: "Bold"
                color: StyleGlobalConsts.blueColor()
                font.letterSpacing: 0.5
            }
            onClicked: {
                root.cancelButtonClickSignal()
                cancelButtonBgRect.color = StyleGlobalConsts.blueColor()
                cancelButtonText.color = StyleGlobalConsts.whiteColor()
                okButtonBgRect.color = StyleGlobalConsts.whiteColor()
                okButtonText.color = StyleGlobalConsts.blueColor()
            }
            background: Rectangle{
                id: cancelButtonBgRect
                width: parent.width
                height: parent.height
                radius: parent.radius
                color: StyleGlobalConsts.whiteColor()
                border.width: 1
                border.color: StyleGlobalConsts.blueColor()
            }
        }
    }

    function hide()
    {
        root.visible = false
    }

    function show()
    {
        if(messageDetails === LocalStrings.getLocalTextValue("yes"))
        {
            root.visible = true
            okButtonText.text = LocalStrings.getLocalTextValue("yes")
            cancelButtonText.text = LocalStrings.getLocalTextValue("no")
            cancelButton.visible = true
        }
        root.visible = true
    }
}
