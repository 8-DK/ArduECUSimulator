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
import GStyleLib 1.0
import "CustomeWidget/CardView"
import PIDEncoderDecoderLib 1.0

Item {
    id:mainGridViewWndw
    objectName: qsTr("MainGridViewWndw")
    visible: true
    width: mainWindowWithStackView.width //GStyle.windowWidth()
    height: mainWindowWithStackView.height //GStyle.windowHeight()
    signal sendPushNewProject()
    property var connectionTargetMessage: null
    property int  dataBit : 8;
    property int   parity;
    property var nextScreen;
    property int screen;

    property int dialVal : 0;

    onFocusChanged: {
        if(focus)
        {
            console.debug("Cell width ",mainGridViewWndw*1.2)
            PIDEncoderDecoder.getPIDList()
        }
    }

    function onPop()
    {

    }

    NavBar {
        id:navBar
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        header: LocalStrings.getLocalTextValue("navbarSerialPortTitle")
        onClickedMenu: print('Button onClicked')
    }

    Rectangle{
        id: gridRect
        anchors.top: navBar.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.leftMargin: 100
        width: parent.width
        height: parent.height-navBar.height
        color: GStyle.gP("colPrime")

        GridView {
            id: rootGrid
            anchors.leftMargin: 50
            anchors.centerIn: parent
            width: parent.width
            height: parent.height
            cellHeight:300 //630x300
            snapMode : GridView.SnapToRow
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
            model: CardView{
                id :cardView
                model:PIDList
            }
        }
    }
}
