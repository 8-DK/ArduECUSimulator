//import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.12
import GStyleLib 1.0
//import QtQuick.Controls 1.4
import "../Switch"


Rectangle {
    id : slideInput
    width: parent.width
    height: parent.height
    color: "#00000000"
    anchors.bottom: parent.bottom
    anchors.left:  parent.left
    anchors.right:  parent.right
    property int digit: 6
    property string unit: ""
    property alias value: valSlider.value
    property bool randomeChk: true
    property real stepVal: 1
    property real maxVal: 5
    property real minVal: 0

    property alias isRandomeOn: randomeCheckBox.isChecked


    property var activeColor: GStyle.gP("themeDefaultColor") //activeColor
    property var mainColor:  GStyle.gP("widgetActiveColor") //"#17a81a"
    property var textBoxBgColor: GStyle.gP("textBoxBgColor")
    FontLoader {
        id:sevenSegmentFont
        source:'qrc:/Fonts/Seven_Segment.ttf'
    }

    function validateInputs()
    {
        if(minVal  > textInput.text)
        {
            valSlider.value = minVal
            textInput.text = minVal
        }
        else if(maxVal  < textInput.text)
        {
            valSlider.value = maxVal
            textInput.text = maxVal
        }
    }

    function setValue(val)
    {
        valSlider.value = val
        textInput.text = valSlider.value
    }

    Rectangle{
        id : bgRect
        color: "#00000000"
        anchors.fill: parent

        Rectangle{
            id: rectangle
            color: "#00000000"            
            height: parent.height*0.5
            anchors.bottom: rectangle1.top
            anchors.right: parent.right
            anchors.left: parent.left
            CustomSwitch{
                id: randomeCheckBox
                width: parent.width*0.5                
                m_text: qsTr("Randome")
                visible: randomeChk
                anchors.left: parent.left
                //anchors.leftMargin: parent.width*0.1
                anchors.verticalCenter: parent.verticalCenter
            }

            TextField {
                id: textInput
                width: parent.width*0.2
                text: valSlider.value
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: parent.width*0.1
                font.weight: "DemiBold"
                font.pixelSize: parent.width*0.03
                font.family: fontLdr.robotoRegular
                validator: RegExpValidator { regExp: /^[0-9]{1,}([,.][0-9]{1,2})?$/ }

                onTextEdited: {
                    valSlider.value = parseInt(textInput.text)
                    validateInputs()
                }
                background: Rectangle {
                    implicitWidth: textInput.width
                    implicitHeight: textInput.height
                    color: textInput.enabled ? textBoxBgColor : "#afb5ac"
                    border.color: textInput.enabled ? activeColor : "transparent"
                    radius: parent.width*0.05
                }
            }
        }

        Rectangle{
            id: rectangle1
            anchors.bottom: parent.bottom
            height: parent.height*0.5
            color: "#00000000"
            anchors.right: parent.right
            anchors.left: parent.left
            Slider {
                id: valSlider
                to: maxVal
                from: minVal
                stepSize: stepVal
                //value: textInput.text
                width: parent.width*0.8
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0                                
                onMoved: {
                     textInput.text = valSlider.value
                }

                background: Rectangle {
                    x: valSlider.leftPadding
                    y: valSlider.topPadding + valSlider.availableHeight / 2 - height / 2
                    implicitWidth: 200
                    implicitHeight: 4
                    width: valSlider.availableWidth
                    height: implicitHeight
                    radius: 2
                    color: "#bdbebf"

                    Rectangle {
                        width: valSlider.visualPosition * parent.width
                        height: parent.height
                        color: activeColor
                        radius: 2
                    }
                }

                handle: Rectangle {
                    x: valSlider.leftPadding + valSlider.visualPosition * (valSlider.availableWidth - width)
                    y: valSlider.topPadding + valSlider.availableHeight / 2 - height / 2
                    implicitWidth: 26
                    implicitHeight: 26
                    radius: 13
                    color: valSlider.pressed ? "#f0f0f0" : "#f6f6f6"
                    border.color: "#bdbebf"
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:3;anchors_width:180}
}
##^##*/
