//import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.12
import GStyleLib 1.0
import QtGraphicalEffects 1.12
//import QtQuick.Controls 1.4
import "../Switch"


Rectangle {
    id : custHeaeder
    width: parent.width
    height: parent.height*0.15
    color: "#00000000"
    property int digit: 6
    property string headerText: "Card Title"
    property bool enabled: true
    //property alias radius: bgRect.radius

    Rectangle{
        id : bgRect
        width: parent.width
        height: parent.height
        color: GStyle.gP("colSec")
        radius: custHeaeder.radius
//        border.width: 1
//        border.color: "grey"
        clip: true
        Rectangle {
            id: rectangle1
            anchors.right: rectangle.left
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.width*0.7
             color: "#00000000"

            TextInput {
                id: textInput
                width: parent.width
                text: headerText
                anchors.leftMargin: parent.width*0.1
                anchors.bottom: parent.bottom
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.centerIn: parent.Center
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: parent.width*0.05
                font.family: fontLdr.robotoRegular
                readOnly: true
                layer.enabled: true
                layer.effect: Glow {
                    radius:6
                    spread: 0
                    samples: 25
                    color: GStyle.getDropshadowColor()
                    transparentBorder: false
                }
            }
        }

        Rectangle{
            id: rectangle
            width: parent.width*0.3
            color: "#00000000"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            CustomSwitch{
                id: checkBox
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                m_text: qsTr("Enable")
            }
        }
    }
}




