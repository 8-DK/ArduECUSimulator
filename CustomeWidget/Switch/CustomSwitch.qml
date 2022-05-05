import QtQuick 2.12
import QtQuick.Controls 2.12
import GStyleLib 1.0

Item {
    id : switchCust
    property alias isChecked:  control.checked
    property var onTogle : m_onTogle
    property var m_text: ""

    property var activeColor: GStyle.gP("themeDefaultColor") //"#21be2b"
    property var mainColor:  GStyle.gP("widgetActiveColor") //"#17a81a"

    signal update(bool value);

    SwitchDelegate {
        id: control
        text: m_text
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        checked: true

        contentItem: Text {
            rightPadding: control.indicator.width + control.spacing
            text: control.text
            font: control.font
            opacity: enabled ? 1.0 : 0.3
            color: control.down ? mainColor : activeColor
            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
        }

        indicator: Rectangle {
            implicitWidth: 48
            implicitHeight: 26
            x: control.width - width - control.rightPadding
            y: parent.height / 2 - height / 2
            radius: parent.height/2
            color: control.checked ? mainColor : "transparent"
            border.color: control.checked ? mainColor : mainColor

            Rectangle {
                x: control.checked ? parent.width - width : 0
                width: 26
                height: 26
                radius: parent.height/2
                color: control.down ? mainColor : "#ffffff"
                border.color: control.checked ? (control.down ? mainColor : activeColor) : "#999999"
            }
        }

        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 40
            visible: false//control.down || control.highlighted
            //color: control.down ? "#bdbebf" : "#eeeeee"
        }
        onToggled: {
            switchCust.update(control.checked)
            onTogle()
        }
    }

    function m_onTogle(){

    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
