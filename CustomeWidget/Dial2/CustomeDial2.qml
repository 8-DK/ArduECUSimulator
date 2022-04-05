import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
import QtQuick.Extras.Private 1.0

Item {
    id: root
    property real value : 0

    width: 185; height: width

    property alias value : gauge.value
    property alias minVal : gauge.minimumValue
    property alias maxVal : gauge.maximumValue
    Rectangle{
        width: parent.width*1.1
        height: width
        anchors.centerIn: parent
        color: "#8da6b5"
        radius: width/2
    }
    CircularGauge {
        id: gauge
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        style: CircularGaugeStyle {
            id: style

            function degreesToRadians(degrees) {
                return degrees * (Math.PI / 180);
            }

            background: Canvas {
                onPaint: {
                    var ctx = getContext("2d");
                    ctx.reset();

                    ctx.beginPath();
                    ctx.strokeStyle = "#e34c22";
                    ctx.lineWidth = outerRadius * 0.02;

                    ctx.arc(outerRadius, outerRadius, outerRadius - ctx.lineWidth / 2,
                        degreesToRadians(valueToAngle(80) - 90), degreesToRadians(valueToAngle(100) - 90));
                    ctx.stroke();
                }
            }

            tickmark: Rectangle {
                visible: styleData.value < 80 || styleData.value % 10 == 0
                implicitWidth: outerRadius * 0.02
                antialiasing: true
                implicitHeight: outerRadius * 0.06
                color: styleData.value >= 80 ? "#e34c22" : "#e5e5e5"
            }

            minorTickmark: Rectangle {
                visible: styleData.value < 80
                implicitWidth: outerRadius * 0.01
                antialiasing: true
                implicitHeight: outerRadius * 0.03
                color: "#e5e5e5"
            }

            tickmarkLabel:  Text {
                font.pixelSize: Math.max(6, outerRadius * 0.12)
                text: styleData.value
                color: styleData.value >= 80 ? "#e34c22" : "#e5e5e5"
                antialiasing: true
            }

            needle: Rectangle {
                y: outerRadius * 0.15
                implicitWidth: outerRadius * 0.03
                implicitHeight: outerRadius * 0.9
                antialiasing: true
                color: "#e5e5e5"               
            }

            foreground: Item {
                Rectangle {
                    width: outerRadius * 0.2
                    height: width
                    radius: width / 2
                    color: "#e5e5e5"
                    anchors.centerIn: parent
                }
            }
        }
    }
}
