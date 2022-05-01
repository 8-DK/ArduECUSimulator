import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0
import GStyleLib 1.0

Rectangle {
    id: root
    width:  GStyle.windowWidth() * 0.2
    height: GStyle.windowHeight() * 0.04

    property var activeColor: GStyle.gP("themeDefaultColor") //activeColor
    property var mainColor:  GStyle.gP("widgetActiveColor") //"#17a81a"
    property var textBoxBgColor: GStyle.gP("textBoxBgColor")

    property color checkedColor: activeColor
    property alias text: textInput.text
    property alias textF: textInput
    property alias title: titileLabelText.text

    property int mradius: 5

    TextField {
        id: textInput
        width: parent.width
        height: parent.height
        text: ""
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        anchors.centerIn: parent
        font.weight: "DemiBold"
        font.pixelSize: GStyle.getTextEditPixelSize()
        font.family: fontLdr.robotoRegular
//        validator: RegExpValidator { regExp: /^[0-9]{1,}([,.][0-9]{1,2})?$/ }

        background: Rectangle {
            width: parent.width
            height: parent.height
            color: root.down ? Qt.darker(root.checkedColor, 1.2) : root.checkedColor
            radius: root.mradius

            layer.enabled: root.hovered | root.down
            layer.effect: DropShadow {
                transparentBorder: true
                color: root.checkedColor
                samples: 10 /*20*/
            }
        }
    }

    Rectangle{
        id : borderRect
        width: root.width+root.height*0.2
        height: root.height+root.height*0.2
        anchors.centerIn: parent
        color: GStyle.gP("trans")
        border.width: 1
        border.color: activeColor
        radius: root.mradius
        opacity: 0.5
    }

    Label{
        id: titileLabel
        anchors.bottom: borderRect.top
        anchors.bottomMargin: root.height*0.1
        anchors.left: parent.left
        //        anchors.leftMargin: parent.width * 0.03
        width: titileLabelText.width * 1.5
        height: titileLabelText.height * 1.2
        visible: titileLabelText.text !== "" ? true : false
        Text{
            id: titileLabelText
            anchors.centerIn: parent
            text: ""
            font.family: fontLdr.openSansRegular
            font.pixelSize: getFontSize("H5")//16
            color: GStyle.borderColor()
        }
        background: Rectangle{
            color: GStyle.whiteColor()//"white"
            opacity: 0.5
            anchors.fill: parent
            border.width: 1
            border.color: activeColor
            radius: height/2
        }
    }
}
