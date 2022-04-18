//IconButton.qml
import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0

Button {

    id: root

    property alias icon: icon.source
    property bool iconRight: false
    property alias iconScalingFactor: icon.scalingFactor

    focusPolicy: Qt.NoFocus
    leftPadding: 12
    rightPadding: 12

    contentItem: Row {

        layoutDirection: iconRight ? Qt.RightToLeft : Qt.LeftToRight

        spacing: 12

        IconSVG {
            id: icon
            source: "cup.svg"
            color: Material.accent
        }

        Label {
            id: label
            anchors.verticalCenter: parent.verticalCenter
            text: root.text
        }
    }

}
