//import QtQuick 2.0
import GStyleLib 1.0
import QtQuick.Controls 2.14
import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id : segmetDisplay
    width: parent.width
    height: parent.height
    property int digit: 6
    property string unit: ""
    property double value: 0
    property double dataFieldChecked: 4294967295
    property variant dataFieldArr : [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]

     Component.onCompleted :{
         if(4294967295 < dataFieldChecked)
         {
             dataFieldChecked = 4294967295
         }
         for (var i = 0; i < dataFieldArr.length; i++)
         {
           dataFieldArr[i] = GStyle.isBitSet(dataFieldChecked,i)
         }
         textInput.text = GStyle.numToHexStr(dataFieldChecked)
         checkRepeater.model = dataFieldArr
     }

    Rectangle{
        id : bgRect
        color: GStyle.gP("trans")
        anchors.fill: parent

        Text {
            id: element
            text: "Bit Field"//GStyle.getFloat(value,digit)
            verticalAlignment: Text.AlignVCenter
            transformOrigin: Item.Center
            //            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: GStyle.getTextEditPixelSize()
            font.bold: true
            font.family: fontLdr.defaultFont
            color: GStyle.mainThemeActiveColor()
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: parent.height * 0.2
        }
        Row {
            id : bitFiledRow
            width: parent.width * 0.9
            anchors.centerIn: parent
            layoutDirection : Qt.RightToLeft
            //            visible: false
            Repeater {
                id : checkRepeater
                model: dataFieldArr
                Rectangle {
                    width: parent.width/32
                    height: 20
                    anchors.leftMargin: width*0.3
                    CheckBox {
                        id: control
                        width: parent.width
                        checked: dataFieldArr[index]
                        text: index
                        onToggled: {
                            dataFieldChecked = GStyle.toggleBit(dataFieldChecked,index)
                            console.log("Model : ",dataFieldChecked )
                            textInput.text = GStyle.numToHexStr(dataFieldChecked)
                            dataFieldArr[index] = checked
                        }

                        indicator: Rectangle {
                            implicitWidth: parent.width
                            implicitHeight: implicitWidth
                            anchors.centerIn: parent
                            radius: 3
                            border.color: control.down ?"#21be2b" : GStyle.mainThemeActiveColor()

                            Rectangle {
                                width: parent.implicitWidth*0.7
                                height: width
                                anchors.centerIn: parent
                                radius: 2
                                color: control.down ? "#21be2b" : GStyle.mainThemeActiveColor()
                                visible: control.checked
                            }
                        }

                        contentItem: Text {
                            text: control.text
                            font: control.font
                            opacity: enabled ? 1.0 : 0.3
                            color: control.checked ? GStyle.mainThemeActiveColor() : "#66949494"
                            verticalAlignment: Text.AlignVCenter
                            //                            leftPadding: control.indicator.width + control.spacing
                            topPadding: control.indicator.height * 0.05
                            anchors.top:  control.bottom
                            anchors.horizontalCenter: control.horizontalCenter
                            rotation: control.width < 10 ? 270 : 0
                        }
                    }
                }
            }
        }
        TextField {
            id: textInput
            width: parent.width*0.2
//            text: GStyle.numToHexStr(dataFieldChecked)
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            anchors.right: bitFiledRow.right
            anchors.top: bitFiledRow.bottom
            anchors.topMargin: bitFiledRow.height*2
            font.pixelSize: 12
            validator: RegExpValidator { regExp: /^0x[A-Fa-f0-9]{1,}([,.][0-9]{1,2})?$/ }

            onTextEdited: {
                if(text.indexOf("0x") !== -1)
                {
                    //hex
                    var num = GStyle.hexstrToNum(text)
                    if(4294967295 < num)
                    {
                        num = 4294967295
                        text = GStyle.numToHexStr("0xffffffff")
                    }
                    for (var i = 0; i < dataFieldArr.length; i++)
                    {
                      dataFieldArr[i] = GStyle.isBitSet(num,i)
                    }
                    if(dataFieldChecked !== num)
                        dataFieldChecked = num
                    checkRepeater.model = dataFieldArr

                }
                else
                {
                    //decimal
//                    console.log("Dec num")
                }
            }
            background: Rectangle {
                implicitWidth: textInput.width
                implicitHeight: textInput.height
                color: textInput.enabled ? "#cad9c3" : "#afb5ac"
                border.color: textInput.enabled ? "#21be2b" : "transparent"
            }
        }
    }

    function val(val)
    {
         dataFieldChecked = val
        if(4294967295 < dataFieldChecked)
        {
            dataFieldChecked = 4294967295
        }
        for (var i = 0; i < dataFieldArr.length; i++)
        {
          dataFieldArr[i] = GStyle.isBitSet(dataFieldChecked,i)
        }
        textInput.text = GStyle.numToHexStr(dataFieldChecked)
        checkRepeater.model = dataFieldArr
    }
}
