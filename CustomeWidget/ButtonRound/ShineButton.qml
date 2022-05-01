import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import LocalStringsLib 1.0
import GStyleLib 1.0
import QtGraphicalEffects 1.12

Button {
    id: rootButton
    width: Math.min(window.width, window.height) - 20
    height: width * 0.3
    text: "Button"    
    property string color : GStyle.gP("White")//"#00c0f5"
    property var group : undefined
    property string textColor
    readonly property real radius: height / 5
    property string activeColor: GStyle.whiteColor()

    signal buttonClicked()
//    signal buttonReleased()

    layer.enabled: rootButton.hovered
    layer.effect: DropShadow {
//        transparentBorder: true
        radius: 4
        verticalOffset: 0
        spread: 0
        color: "#cccccc"
        samples: 17
    }

    onClicked: {
//        rootButton.color = activeColor
//        buttonText.color = color
        buttonClicked()
        if(group != undefined)
        {
            group.setCurrItem(rootButton)
        }
    }

    states: [
        State { name: "selected"
//            PropertyChanges { target: rootButton; color: GStyle.gP("themeDefaultColor")}
//            PropertyChanges { target: rootButton; textColor: GStyle.gP("White")}
        },
        State { name: "notselected"
//            PropertyChanges { target: rootButton; color: GStyle.gP("White")}
//            PropertyChanges { target: rootButton; textColor: GStyle.gP("themeDefaultColor")}
        },
        State { name: "activated" },
        State { name: "deactivated" }
    ]

    Component.onCompleted: {
        if(group != undefined)
        {
            group.addItem(rootButton)
        }
        if(rootButton.state === "selected")
        {
            rootButton.color = GStyle.gP("themeDefaultColor")
            rootButton.textColor  = GStyle.whiteColor()
        }
    }

    style: ButtonStyle {
        background: Item {
            Canvas {
                anchors.fill: parent

                onPaint: {
                    var ctx = getContext("2d");
                    ctx.reset();

                    ctx.beginPath();
                    ctx.lineWidth = height * 0.1;
                    ctx.roundedRect(ctx.lineWidth / 2, ctx.lineWidth / 2,
                        width - ctx.lineWidth, height - ctx.lineWidth, rootButton.radius, rootButton.radius);
                    ctx.strokeStyle = "grey";
                    ctx.stroke();
                    ctx.fillStyle = color;
                    ctx.fill();
                }
            }

            Label {
                id: buttonText
                text: rootButton.text
                color: textColor//"#ddd"
                font.pixelSize: rootButton.height * 0.5
                anchors.centerIn: parent
            }

            Canvas {
                anchors.fill: parent
                onPaint: {
                    var ctx = getContext("2d");
                    ctx.reset();

                    ctx.beginPath();
                    ctx.lineWidth = height * 0.1;
                    ctx.roundedRect(ctx.lineWidth / 2, ctx.lineWidth / 2,
                        width - ctx.lineWidth, height - ctx.lineWidth, rootButton.radius, rootButton.radius);
                    ctx.moveTo(0, height * 0.4);
                    ctx.bezierCurveTo(width * 0.25, height * 0.6, width * 0.75, height * 0.6, width, height * 0.4);
                    ctx.lineTo(width, height);
                    ctx.lineTo(0, height);
                    ctx.lineTo(0, height * 0.4);
                    ctx.clip();

                    ctx.beginPath();
                    ctx.roundedRect(ctx.lineWidth / 2, ctx.lineWidth / 2,
                        width - ctx.lineWidth, height - ctx.lineWidth,
                        rootButton.radius, rootButton.radius);
                    var gradient = ctx.createLinearGradient(0, 0, 0, height);
                    gradient.addColorStop(0, "#bbffffff");
                    gradient.addColorStop(0.6, "#00ffffff");
                    ctx.fillStyle = gradient;
                    ctx.fill();
                }
            }
        }

        label: null
    }
}
