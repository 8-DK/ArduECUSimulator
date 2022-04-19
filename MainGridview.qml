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
import QtKnobs 1.0
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
            navBar.updateNavTitle("Dashboard")
            console.debug("Cell width ",mainGridViewWndw*1.2)
            PIDEncoderDecoder.getPIDList()
        }
    }

    function onPop()
    {

    }

    Rectangle{
        id: gridRect
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.leftMargin: 100
        width: parent.width
        height: parent.height
        color: GStyle.gP("colPrime")

        GridView {
            id: rootGrid
            anchors.leftMargin: 50
            anchors.centerIn: parent
            width: parent.width
            height: parent.height
            cellHeight:300 //630x300
            snapMode : GridView.SnapToRow
            ScrollBar.vertical :  ScrollBar {
                id: scrollBar
                hoverEnabled: true
                active: hovered || pressed
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: parent.width * 0.015
                orientation: Qt.Vertical
                visible: true// rootGrid.moving?true:false
                policy: ScrollBar.AsNeeded
                contentItem: Rectangle {
                    id:contentItem_rect2
                    width:parent.width
                    implicitHeight:4
                    radius: implicitWidth/2
                    color: GStyle.gP("themeDefaultColor")
                }
            }
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
