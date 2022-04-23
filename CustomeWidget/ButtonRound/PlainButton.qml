import QtQuick 2.4
import QtQuick.Window 2.12
import ComHelperLib 1.0
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import LocalStringsLib 1.0
import GStyleLib 1.0

Rectangle{
    id: rootButton
    implicitWidth: GStyle.windowWidth() * 0.1
    implicitHeight: GStyle.windowHeight() * 0.04
    radius: GStyle.defaultWdgtRadius()
    focus: true
    activeFocusOnTab: false

    property alias text : buttonText.text
    property string activeColor: GStyle.whiteColor()
    property var group : undefined
    property bool hovered : false
    property alias textColor : buttonText.color
    color: GStyle.gP("White")

    border.width: 1
    border.color:GStyle.gP("themeDefaultColor")

    signal buttonClicked()
    signal buttonReleased()

    layer.enabled: rootButton.hovered
    layer.effect: DropShadow {
        transparentBorder: true
        color: "#F3F4F5"
        samples: 10
    }

    states: [
        State { name: "selected"
            PropertyChanges { target: rootButton; color: GStyle.gP("themeDefaultColor")}
            PropertyChanges { target: rootButton; textColor: GStyle.gP("White")}
        },
        State { name: "notselected"
            PropertyChanges { target: rootButton; color: GStyle.gP("White")}
            PropertyChanges { target: rootButton; textColor: GStyle.gP("themeDefaultColor")}
        },
        State { name: "activated" },
        State { name: "deactivated" }
    ]

    Component.onCompleted: {
        if(group != undefined)
        {
            group.addItem(rootButton)
        }
        if(rootButton.state === "selected")
        {
            console.log("State selected")
            rootButton.color = GStyle.gP("themeDefaultColor")
            rootButton.textColor  = GStyle.whiteColor()
        }
    }

    Text{
        id: buttonText
        anchors.centerIn: parent
        text: text
        font.family: fontLdr.openSansRegular
        font.pixelSize: GStyle.getTextEditLabelPixelSize()
        font.weight: "DemiBold"
        color: GStyle.gP("themeDefaultColor")
        font.letterSpacing: 0.5
    }
    MouseArea{
        id : rootMouseArea
        hoverEnabled : true
        anchors.fill: parent
        onClicked: {
            rootButton.color = activeColor
            buttonText.color = color
            buttonClicked()
            if(group != undefined)
            {
                group.setCurrItem(rootButton)
            }
        }

        onReleased:{
            rootButton.color = color
            buttonText.color = activeColor
            buttonReleased()
        }

        onEntered: rootButton.hovered = true
        onExited: rootButton.hovered = false
    }
}
