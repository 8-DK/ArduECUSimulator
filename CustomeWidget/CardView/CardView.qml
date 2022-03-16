import QtQuick 2.12
import QtQml.Models 2.1
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtGraphicalEffects  1.12
import QtQuick 2.6
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import QtQuick 2.2
import QtQuick.Dialogs 1.1
import CommLinkSettingsLib 1.0
import LocalStringsLib 1.0
import GStyleLib 1.0
import "../Dial"
import "../SegmentDisplay"
import "../SliderInput"
import "../Switch"
import "../Header"

DelegateModel {
    //! [0]
    id: visualModel
    Component{
        id:custDia
        Rectangle{
            radius: GStyle.getCardRadius()
            clip: true

            Timer{
                id : randModeValueGenerator
                running: slider.isRandomeOn
                repeat: true
                interval: 1000
                onTriggered: {
                    slider.value = GStyle.getRandomeInt(slider.minVal,slider.maxVal)
                }
            }

            CustomeDial
            {
                id: dial
                anchors.centerIn: parent
                value :  slider.value
                height: parent.height*0.7
            }
            SlideInput{
                id:slider
                maxVal: 120
                minVal: 0
                stepVal: 1
                //randomeChk:false
                height: parent.height*0.3
            }
        }
    }

    Component{
        id:segDisp
        Rectangle{
            radius: GStyle.getCardRadius()
            clip: true

            Timer{
                id : randModeValueGenerator
                running: slider.isRandomeOn
                repeat: true
                interval: 1000
                onTriggered: {
                    //                        slider.value = GStyle.getRandomeInt(slider.minVal,slider.maxVal)
                    slider.setValue(GStyle.getRandomeInt(slider.minVal,slider.maxVal))
                }
            }
            SegementDisplay
            {
                id : segmentVal
                value: slider.value
            }
            SlideInput{
                id:slider
                maxVal: 120
                minVal: 0
                stepVal: 1
                //randomeChk:false
                height: parent.height*0.3
            }
        }
    }

    Component{
        id:slidInp
        Rectangle{
            radius: GStyle.getCardRadius()
            clip: true
            SlideInput{
                id:slider
                maxVal: 120
                minVal: 0
                stepVal: 1
                //randomeChk:false
                height: parent.height*0.5
            }
        }
    }
    model: ListModel {
        id: colorModel
        ListElement { color: "blue"; type : 0}
        ListElement { color: "green" ; type : 1 }
        ListElement { color: "red" ; type : 2 }
        ListElement { color: "yellow" ; type : 2 }
        ListElement { color: "orange" ; type : 1 }
        ListElement { color: "purple" ; type : 0 }
        ListElement { color: "cyan" ; type : 0 }
        ListElement { color: "magenta" ; type : 0 }
        ListElement { color: "chartreuse" ; type : 1 }
        ListElement { color: "aquamarine" ; type : 2 }
        ListElement { color: "indigo" ; type : 0 }
        ListElement { color: "black" ; type : 1 }
        ListElement { color: "lightsteelblue" ; type : 2 }
        ListElement { color: "violet" ; type : 0 }
        ListElement { color: "grey" ; type : 0 }
        ListElement { color: "springgreen" ; type : 0 }
        ListElement { color: "salmon" ; type : 1 }
        ListElement { color: "blanchedalmond" ; type : 0 }
        ListElement { color: "forestgreen" ; type : 0 }
        ListElement { color: "pink" ; type : 0 }
        ListElement { color: "navy" ; type : 2 }
        ListElement { color: "goldenrod" ; type : 0 }
        ListElement { color: "crimson" ; type : 0 }
        ListElement { color: "teal" ; type : 0 }
    }
    //! [1]
    delegate: DropArea {
        id: delegateRoot
        width: rootGrid.cellWidth; height: rootGrid.cellHeight
        onEntered: visualModel.items.move(drag.source.visualIndex, icon.visualIndex)
        property int visualIndex: DelegateModel.itemsIndex
        Binding { target: icon; property: "visualIndex"; value: visualIndex }
        //                                Rectangle{
        //                                    width: parent.width
        //                                    height: parent.height
        //                                    color: "yellow"
        //                                }

        Rectangle {
            id: icon
            property int visualIndex: 0
            width: delegateRoot.width*0.98
            height: delegateRoot.height*0.95
            radius: GStyle.getCardRadius()
            anchors {
                horizontalCenter: parent.horizontalCenter;
                verticalCenter: parent.verticalCenter
            }
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#e3e3e3"
                }

                GradientStop {
                    position: 1
                    color: "#ffffff"
                }
            }
            //color: model.color
            Loader {
                anchors.fill: parent
                sourceComponent: {
                    if(model.type === 0)
                        return custDia
                    if(model.type === 1)
                        return segDisp
                    if(model.type === 2)
                        return slidInp
                }
            }

            CustomHeader{
                id: header
                radius :GStyle.getCardRadius()
            }

            DragHandler {
                id: dragHandler
            }

            Drag.active: dragHandler.active
            Drag.source: icon
            Drag.hotSpot.x: 0//icon.width//36
            Drag.hotSpot.y: 0//36

            states: [
                State {
                    when: icon.Drag.active
                    ParentChange {
                        target: icon
                        parent: rootGrid
                    }

                    AnchorChanges {
                        target: icon
                        anchors.horizontalCenter: undefined
                        anchors.verticalCenter: undefined
                    }
                }
            ]
        }
    }
    //! [1]
}
