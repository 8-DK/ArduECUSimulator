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

    Rectangle {
        width: 1280
        height: 680

        property int newVal : 0

        Timer {
            interval: 1000; running: true; repeat: true
            onTriggered: newVal = Math.floor((Math.random() * 100) + 0)
        }

        Column {
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            spacing: 30
            Row {
                spacing: 5

                Knob {
                    size: 200
                    style: Knob.Pie
                    pieType: Knob.Flat
                    value: 75
                }

                Knob {
                    size: 200
                    style: Knob.Arc
                    value: 25
                    color: "#EF6555"
                }

                Knob {
                    size: 200
                    readOnly: true
                    style: Knob.Needle
                    needleType: Knob.Point
                    value: newVal
                    color: "#FEC56B"
                }

                Knob {
                    size: 200
                    readOnly: true
                    style: Knob.Pie
                    pieType: Knob.Curve
                    value: newVal
                    color: "#C55186"
                }

                Knob {
                    size: 200
                    style: Knob.Needle
                    needleType: Knob.Groove
                    value: 35
                }

                Knob {
                    size: 200
                    style: Knob.Needle
                    needleType: Knob.Round
                    value: 88
                    color: "#96040F"
                }
            }

            Row {
                spacing: 5

                Knob {
                    size: 200
                    style: Knob.Arc
                    percent: 50
                    mode: Knob.Percent
                    color: "#EF6555"
                }

                Knob {
                    size: 200
                    style: Knob.Pie
                    pieType: Knob.Curve
                    percent: 90
                    mode: Knob.Percent
                    color: "#C55186"
                }

                Knob {
                    size: 200
                    style: Knob.Arc
                    value: 2500
                    maximumValue: 5000
                }

                Knob {
                    size: 200
                    style: Knob.Pie
                    value: 8563
                    maximumValue: 10000
                    color: "#EF6555"
                }

                Item {
                    width: 200
                    height: 200
                    Knob {
                        size: 100
                        style: Knob.Pie
                        pieType: Knob.Curve
                        value: 135
                        maximumValue: 200
                        color: "#D7AAFB"
                    }
                }

                Knob {
                    size: 200
                    style: Knob.Pie
                    pieType: Knob.Curve
                    value: 25
                    maximumValue: 100
                    color: "#FF3300"
                    backgroundColor: "black"
                    foregroundColor: "#00FF99"
                    borderColor: "#003399"
                    textColor: "#8D18D7"
                }
            }

            Row {
                spacing: 5

                Knob {
                    size: 200
                    style: Knob.Arc
                    minimumValue: 500
                    maximumValue: 1500
                    color: "#05A8AA"
                }
            }
        }
    }
}
