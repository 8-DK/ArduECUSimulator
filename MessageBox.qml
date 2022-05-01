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
import GStyleLib 1.0
import "CustomeWidget/ButtonRound"
import "CustomeWidget/CutomeTextField"

Dialog{
    id: root
    modal: true
    focus: true
    parent: ApplicationWindow.overlay
    closePolicy: Dialog.CloseOnEscape
    width: GStyle.windowWidth() * 0.28
    height: GStyle.windowHeight() * 0.2
    property string messageDetails

    property string messageTitle: "ArduECUSim"
    property string messageDescription: ''
    signal clickedMenu();
    signal okButtonClickSignal();
    signal cancelButtonClickSignal();
    anchors.centerIn: ApplicationWindow.overlay

    onFocusChanged: {
        if(focus)
        {            
            okButton.focus = true
        }
    }

    background: Rectangle
    {
        color :"transparent"
        radius: 7
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
                font.family: fontLdr.robotoRegular
                font.pixelSize: GStyle.getMessageBoxTextPixelSize()
                font.letterSpacing: 1
                anchors.left: messageTitleRect.left
                anchors.leftMargin: messageTitleRect.height * 0.3
                Layout.fillWidth: true
                wrapMode: Text.WordWrap
                font.weight: "DemiBold"
                color: GStyle.blackColor()
            }
        }

        Rectangle{
            id : dividerLineRectangle
            width: root.width - (root.width * 0.1)
            height: 1.5
            radius: 2
            color: GStyle.gP("themeDefaultColor")
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
                font.family: fontLdr.robotoRegular
                font.letterSpacing: 1
                font.weight: "Normal"
                anchors.left: messageDescLabel.left
                anchors.top: messageDescLabel.top
                anchors.topMargin: parent.height * 0.1
                font.pixelSize: GStyle.getMessageBoxTextPixelSize()
                wrapMode: Text.Wrap
                color: GStyle.blackColor()
            }
        }

        WGroup{
            id : btnGrp
        }

        ShineButton{
            id: okButton
            width: messageBoxRectangle.width * 0.25
            height: messageBoxRectangle.height * 0.18
            anchors.right: parent.right
            anchors.rightMargin: messageBoxRectangle.width * 0.05
            anchors.bottom: parent.bottom
            anchors.bottomMargin: messageBoxRectangle.height * 0.1
            text: LocalStrings.getLocalTextValue("ok")
            color:GStyle.gP("themeDefaultColor")
            group:btnGrp
            onClicked: {
                root.okButtonClickSignal()                
            }
            Keys.onReleased: {
                if(event.key === Qt.Key_Return ||event.key === Qt.Key_Enter )
                {
                    root.okButtonClickSignal()
                }
            }
        }

        ShineButton{
            id: cancelButton
            width: messageBoxRectangle.width * 0.3
            height: messageBoxRectangle.height * 0.18
            visible: false
            anchors.left: parent.left
            anchors.leftMargin: messageBoxRectangle.width * 0.05
            anchors.bottom: parent.bottom
            anchors.bottomMargin: messageBoxRectangle.height * 0.1
            text : LocalStrings.getLocalTextValue("cancel")
            color:GStyle.gP("themeDefaultColor")
            group:btnGrp
            onClicked: {
                root.cancelButtonClickSignal()
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
            okButton.text = LocalStrings.getLocalTextValue("yes")
            cancelButton.text = LocalStrings.getLocalTextValue("no")
            cancelButton.visible = true
        }
        else
        {
            okButton.text = LocalStrings.getLocalTextValue("yes")
            cancelButton.text = LocalStrings.getLocalTextValue("no")
            cancelButton.visible = false
        }

        root.visible = true
    }

    function showMsg(msg)
    {
        messageDescription = msg
        show()
    }
}
