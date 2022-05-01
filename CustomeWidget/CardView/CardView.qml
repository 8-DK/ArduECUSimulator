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
import "../Dial2"
import "../SegmentDisplay"
import "../SliderInput"
import "../Switch"
import "../Header"
import "../BitMapView"

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
                   slider.setValue(GStyle.getRandomeInt(slider.minVal,slider.maxVal))
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
                onMvalueChanged: {
                    modelValue = slider.value
                    console.log("modelIndex ",modelIndex)
                }
            }
        }
    }

    Component{
        id:custDia2
        Rectangle{
            radius: GStyle.getCardRadius()
            clip: true

            Timer{
                id : randModeValueGenerator
                running: slider.isRandomeOn
                repeat: true
                interval: 1000
                onTriggered: {
                    slider.setValue(GStyle.getRandomeInt(slider.minVal,slider.maxVal))
                }
            }

            CustomeDial2
            {
                id: dial
                anchors.centerIn: parent
                value :  slider.value
                minVal: 0
                maxVal : 120
                height: parent.height*0.7
            }
            SlideInput{
                id:slider
                minVal: 0
                maxVal: 120
                stepVal: 1
                //randomeChk:false
                height: parent.height*0.3
                onValueChanged: {
                    modelValue = slider.value
                }
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
                onValueChanged: {
                    modelValue = slider.value
                }
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
                onValueChanged: {
                    modelValue = slider.value
                }
            }
        }
    }

    Component{
        id:custBitMap
        Rectangle{
            radius: GStyle.getCardRadius()
            clip: true

            BitMapView
            {
                id: dial
                anchors.centerIn: parent
                height: parent.height*0.7
                dataFieldChecked: 255
            }
        }
    }
    model: ListModel {
        id: colorModel
        ListElement { color: "blue"; type : 0}
    }
    //! [1]
    delegate: DropArea {
        id: delegateRoot
        width: rootGrid.cellWidth; height: rootGrid.cellHeight
        onEntered: visualModel.items.move(drag.source.visualIndex, icon.visualIndex)
        property int visualIndex: DelegateModel.itemsIndex
        Binding { target: icon; property: "visualIndex"; value: visualIndex }

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
            Loader {
                property string modelValue
                property int modelIndex: index
                anchors.fill: parent
                sourceComponent: {                    
                    if(widgetType === 0)
                        return custDia
                    else if(widgetType === 1)
                        return segDisp
                    else if(widgetType === 2)
                        return slidInp
                    else if(widgetType === 3)
                        return custBitMap
                    else if(widgetType === 4)
                        return custDia2
                    else
                        return slidInp

                }
            }

            CustomHeader{
                id: header
                radius :GStyle.getCardRadius()
                headerText: pidName
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
