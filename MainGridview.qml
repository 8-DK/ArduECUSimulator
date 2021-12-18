/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

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
import StyleGlobalConstsLib 1.0
import "CustomeWidget/Dial"
import "CustomeWidget/SegmentDisplay"
import "CustomeWidget/SliderInput"
import "CustomeWidget/Switch"
import "CustomeWidget/Header"

Item {
    id:mainGridViewWndw
    objectName: qsTr("MainGridViewWndw")
    visible: true
    width: mainWindowWithStackView.width //StyleGlobalConsts.windowWidth()
    height: mainWindowWithStackView.height //StyleGlobalConsts.windowHeight()
    signal sendPushNewProject()
    property var connectionTargetMessage: null
    property int  dataBit : 8;
    property int   parity;
    property var nextScreen;
    property int screen;

    property var dialVal : 0;

    onFocusChanged: {
        if(focus)
        {
            console.debug("Cell width ",mainGridViewWndw*1.2)
        }
    }

    function onPop()
    {

    }

    FontLoader {
        id:openSansNormal
        source:'Fonts/Open_Sans_Regular.ttf'
    }
    FontLoader {
        id:openSansRegular
        source:'Fonts/Open_Sans_Regular.ttf'
    }
    FontLoader{
        id: montserratRegular
        source: "qrc:/Fonts/Montserrat-Regular.ttf"
    }
    FontLoader{
        id: robotoRegular
        source: "qrc:/Fonts/Roboto-Regular.ttf"
    }

    NavBar {
        id:navBar
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        header: LocalStrings.getLocalTextValue("navbarSerialPortTitle")
        onClickedMenu: print('Button onClicked')
    }

    Component{
        id:custDia
        Rectangle{
            radius: StyleGlobalConsts.getCardRadius()
            clip: true

            Timer{
                id : randModeValueGenerator
                running: slider.isRandomeOn
                repeat: true
                interval: 1000
                onTriggered: {
                        slider.value = StyleGlobalConsts.getRandomeInt(slider.minVal,slider.maxVal)
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
            radius: StyleGlobalConsts.getCardRadius()
            clip: true

            Timer{
                id : randModeValueGenerator
                running: slider.isRandomeOn
                repeat: true
                interval: 1000
                onTriggered: {
//                        slider.value = StyleGlobalConsts.getRandomeInt(slider.minVal,slider.maxVal)
                    slider.setValue(StyleGlobalConsts.getRandomeInt(slider.minVal,slider.maxVal))
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
            radius: StyleGlobalConsts.getCardRadius()
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

    Rectangle{
        id: gridRect
        anchors.top: navBar.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.leftMargin: 100
        width: parent.width
        height: parent.height-navBar.height
        color: "#b3ccde"

        GridView {
            id: rootGrid
            anchors.leftMargin: 50
            anchors.centerIn: parent
            width: parent.width
            height: parent.height
            cellHeight:300 //630x300
            cellWidth: {
                if( ( mainGridViewWndw.width/3) < rootGrid.cellHeight )
                    if( (mainGridViewWndw.width/2)<rootGrid.cellHeight)
                        return mainGridViewWndw.width;
                    else
                        return mainGridViewWndw.width/2;

                else
                    mainGridViewWndw.width/3;
            }

            displaced: Transition {
                NumberAnimation { properties: "x,y"; easing.type: Easing.OutQuad }
            }

            //! [0]
            model: DelegateModel {
                //! [0]
                id: visualModel
                model: ListModel {
                    id: colorModel
                    ListElement { color: "blue"; type : 0}
                    ListElement { color: "green" ; type : 1 }
                    ListElement { color: "red" ; type : 2 }
//                    ListElement { color: "yellow" ; type : 2 }
//                    ListElement { color: "orange" ; type : 1 }
//                    ListElement { color: "purple" ; type : 0 }
//                    ListElement { color: "cyan" ; type : 0 }
//                    ListElement { color: "magenta" ; type : 0 }
//                    ListElement { color: "chartreuse" ; type : 1 }
//                    ListElement { color: "aquamarine" ; type : 2 }
//                    ListElement { color: "indigo" ; type : 0 }
//                    ListElement { color: "black" ; type : 1 }
//                    ListElement { color: "lightsteelblue" ; type : 2 }
//                    ListElement { color: "violet" ; type : 0 }
//                    ListElement { color: "grey" ; type : 0 }
//                    ListElement { color: "springgreen" ; type : 0 }
//                    ListElement { color: "salmon" ; type : 1 }
//                    ListElement { color: "blanchedalmond" ; type : 0 }
//                    ListElement { color: "forestgreen" ; type : 0 }
//                    ListElement { color: "pink" ; type : 0 }
//                    ListElement { color: "navy" ; type : 2 }
//                    ListElement { color: "goldenrod" ; type : 0 }
//                    ListElement { color: "crimson" ; type : 0 }
//                    ListElement { color: "teal" ; type : 0 }
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
                        width: delegateRoot.width//*0.98
                        height: delegateRoot.height//*0.95
                        radius: StyleGlobalConsts.getCardRadius()
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
                            radius :StyleGlobalConsts.getCardRadius()
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
        }
    }
}
