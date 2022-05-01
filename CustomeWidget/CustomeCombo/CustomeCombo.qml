import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0
import GStyleLib 1.0

ComboBox {
    id: root
    implicitWidth: GStyle.windowWidth() * 0.2
    implicitHeight: GStyle.windowHeight() * 0.04
    property var activeColor: GStyle.gP("themeDefaultColor") //activeColor
    property var mainColor:  GStyle.gP("widgetActiveColor") //"#17a81a"
    property var textBoxBgColor: GStyle.gP("textBoxBgColor")

    property color checkedColor: activeColor
    property alias title: titileLabelText.text

    property int mradius: 5

    delegate: ItemDelegate {
        width: root.width

        contentItem: Text {
            text: modelData
            color: root.highlightedIndex === index ? "white" : "black"
            font.family: "Arial"
            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
        }

        background: Rectangle {
             width: parent.width
             height: parent.height
             color: root.highlightedIndex === index ? root.checkedColor : mainColor
         }
    }

    indicator: Canvas {
        id: canvas
        x: root.width - width - 10
        y: (root.availableHeight - height) / 2
        width: 12
        height: 8
        contextType: "2d"

        Connections {
            target: root
            onPressedChanged: canvas.requestPaint()
        }

        onPaint: {
            var context = getContext("2d");
            context.reset();
            context.moveTo(0, 0);
            context.lineTo(width, 0);
            context.lineTo(width / 2, height);
            context.closePath();
            context.fillStyle = "white"
            context.fill();
        }
    }

    contentItem: Item {
        width: root.background.width - root.indicator.width - 10
        height: root.background.height

        Text {
            anchors.verticalCenter: parent.verticalCenter
            x: 10
            text: root.displayText
            elide: Text.ElideRight

            font.pixelSize: 15
            font.family: "Arial"
            font.weight: Font.Thin
            color: root.down ? Qt.rgba(255, 255, 255, 0.75) : "white"
        }
    }

    background: Rectangle {
        implicitWidth: 102
        implicitHeight: 41
        color: root.down ? Qt.darker(root.checkedColor, 1.2) : root.checkedColor
        radius: root.mradius

        layer.enabled: root.hovered | root.down
        layer.effect: DropShadow {
            transparentBorder: true
            color: root.checkedColor
            samples: 10 /*20*/
        }
    }

    popup: Popup {
        y: root.height - 1
        width: root.width
        implicitHeight: contentItem.implicitHeight
        padding: 0

        contentItem: ListView {
            implicitHeight: contentHeight
            model: root.popup.visible ? root.delegateModel : null
            clip: true
            currentIndex: root.highlightedIndex

            ScrollIndicator.vertical: ScrollIndicator { }
        }

        background: Rectangle {
            color: "#F3F4F5"
            radius: root.mradius
            clip: true

            layer.enabled: root.hovered | root.down
            layer.effect: DropShadow {
                transparentBorder: true
                color: "#F3F4F5"
                samples: 10
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
