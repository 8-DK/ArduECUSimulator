import QtQuick 2.4
import QtQuick.Window 2.12
import ComHelperLib 1.0
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import LocalStringsLib 1.0
import GStyleLib 1.0

RoundButton{
    id: rootButton
    width: messageBoxRectangle.width * 0.25
    height: messageBoxRectangle.height * 0.18
    anchors.right: parent.right
    anchors.rightMargin: messageBoxRectangle.width * 0.05
    anchors.bottom: parent.bottom
    anchors.bottomMargin: messageBoxRectangle.height * 0.1
    radius: GStyle.defaultButtonRadius()
    focus: true
    activeFocusOnTab: false
    property string text : ""
    property alias color: okButtonBgRect.color
    property string activeColor: GStyle.whiteColor()
    Text{
        id: okButtonText
        anchors.centerIn: okButton
        text: text
        font.family: openSansRegular.name
        font.pixelSize: GStyle.getTextEditLabelPixelSize()
        font.weight: "DemiBold"
        color: GStyle.whiteColor()
        font.letterSpacing: 0.5
    }
    onClicked: {
        okButtonBgRect.color = activeColor
        okButtonText.color = color
    }

    onReleased:{
        okButtonBgRect.color = color
        okButtonText.color = activeColor
    }

    background: Rectangle{
        id: okButtonBgRect
        width: parent.width
        height: parent.height
        radius: parent.radius
        color: GStyle.gP("themeDefaultColor")
        border.width: 1
        border.color: GStyle.gP("themeDefaultColor")
    }
}
