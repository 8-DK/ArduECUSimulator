import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Button {
    id: button
    width: Math.min(window.width, window.height) - 20
    height: width * 0.3
    text: "Button"
    property string color : "#00c0f5"

    readonly property real radius: height / 5    

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
                        width - ctx.lineWidth, height - ctx.lineWidth, button.radius, button.radius);
                    ctx.strokeStyle = "grey";
                    ctx.stroke();
                    ctx.fillStyle = color;
                    ctx.fill();
                }
            }

            Label {
                text: button.text
                color: "#ddd"
                font.pixelSize: button.height * 0.5
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
                        width - ctx.lineWidth, height - ctx.lineWidth, button.radius, button.radius);
                    ctx.moveTo(0, height * 0.4);
                    ctx.bezierCurveTo(width * 0.25, height * 0.6, width * 0.75, height * 0.6, width, height * 0.4);
                    ctx.lineTo(width, height);
                    ctx.lineTo(0, height);
                    ctx.lineTo(0, height * 0.4);
                    ctx.clip();

                    ctx.beginPath();
                    ctx.roundedRect(ctx.lineWidth / 2, ctx.lineWidth / 2,
                        width - ctx.lineWidth, height - ctx.lineWidth,
                        button.radius, button.radius);
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
