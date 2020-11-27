import QtQuick 2.12
import QtQuick.Controls 2.12
import StyleGlobalConstsLib 1.0

Item {
    id : largeSwitchCust
    height: 200
    width: 500
    property alias isChecked:  control.checked
    property var onTogle : m_onTogle
    property var m_text: ""

    property var activeColor: StyleGlobalConsts.mainThemeActiveColor() //"#21be2b"
    property var mainColor:  StyleGlobalConsts.mainThemeColor() //"#17a81a"

    Rectangle {
                implicitWidth: parent.width
                implicitHeight: parent.height
                x: control.width - width - control.rightPadding
                y: parent.height / 2 - height / 2
                color: "#f22323"
                radius: parent.height/2
                border.color: control.checked ? mainColor : "#cccccc"
    
                Rectangle {
                    x: control.checked ? parent.width - width : 0
                    implicitWidth: parent.height
                    implicitHeight: parent.height
                    color: "#000080"
                    radius: parent.height/2
                    border.color: control.checked ? (control.down ? mainColor : activeColor) : "#999999"
                }
            }
    
//    SwitchDelegate {
//        id: control
//        text: m_text
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.verticalCenter: parent.verticalCenter
//        checked: true

//        contentItem: Text {
//            rightPadding: control.indicator.width + control.spacing
//            text: control.text
//            font: control.font
//            opacity: enabled ? 1.0 : 0.3
//            color: control.down ? mainColor : activeColor
//            elide: Text.ElideRight
//            verticalAlignment: Text.AlignVCenter
//        }

//        indicator: Rectangle {
//            implicitWidth: 48
//            implicitHeight: 26
//            x: control.width - width - control.rightPadding
//            y: parent.height / 2 - height / 2
//            color: "#f22323"
//            radius: parent.height/2
//            border.color: control.checked ? mainColor : "#cccccc"

//            Rectangle {
//                x: control.checked ? parent.width - width : 0
//                width: 26
//                height: 26
//                color: "#000080"
//                radius: parent.height/2
//                border.color: control.checked ? (control.down ? mainColor : activeColor) : "#999999"
//            }
//        }

//        background: Rectangle {
//            implicitWidth: 100
//            implicitHeight: 40
//            visible: false//control.down || control.highlighted
//            //color: control.down ? "#bdbebf" : "#eeeeee"
//        }
//        onToggled: onTogle()
//    }

//    function m_onTogle(){

//    }
}
