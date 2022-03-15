import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtGraphicalEffects  1.12
import QtQuick.Dialogs 1.1
import GStyleLib 1.0
import LocalStringsLib 1.0


Dialog{
    id: progressbar
    modal: true
    focus: true
    width: GStyle.windowHeight() * 0.5
    height: GStyle.windowHeight() * 0.2
    parent: ApplicationWindow.overlay
    closePolicy: Dialog.CloseOnEscape //| Dialog.CloseOnPressOutsideParent

    anchors.centerIn: parent

    background: Rectangle
    {
        color :"white"
        radius: 7
    }

    property real progress: 0
    property real progress_old: 0

    property var callAfterComplete : onCompleteProgress
    property var callAfterTimeOut : onTimeOutProcess
    property var updateProgress : onUpdate
    property var onCancel : onCancel

    property var show : visible

    property var description: ""
    property int updateInterval: 1000
    property var primaryButtonTextValue: "Cancel"


    FontLoader {
        id:openSansRegular
        source:'qrc:/Fonts/Open_Sans_Regular.ttf'
    }
    FontLoader {
        id: montserratRegular
        source:'qrc:/Fonts/Montserrat-Regular.ttf'
    }
    FontLoader {
        id: robotoRegular
        source:'qrc:/Fonts/Roboto-Regular.ttf'
    }

    Timer{
        id: timerUPdateProgress
        interval: updateInterval
        running: false
        repeat: true
        onTriggered: {
            progress = updateProgress()
            if(progress>100)
                progress = 100
//            console.log("TimerCalled from progress bar",Number(progress))
            if(progress_old != progress)
            {
                //restart timeout timerTimeOut
                progress_old = progress
                timerTimeOut.restart()
            }
            else
            {
                //start timeout timer
                if(!timerTimeOut.running)
                    timerTimeOut.start()
            }

            //if progress 100 then close
            if(progress >=100)
            {
                timerTimeOut.stop()
                timerUPdateProgress.stop()
                callAfterComplete()
            }
//            progress++;
        }
    }

    Timer{
        id: timerTimeOut
        interval: 5000
        running: false
        repeat: false
        onTriggered: {
            timerTimeOut.stop()
            callAfterTimeOut()
        }
    }

    property int minimum: 0
    property int maximum: 100
    property int value: progress
    property color color: "#77B753"

    clip: true

    Rectangle {
        id: progerssRect
        x:parent.x
        y:parent.y

        anchors.bottom: primaryButton.top
        anchors.bottomMargin: progerssRect.height * 0.3
        anchors.rightMargin: 1
        height: parent.height * 0.6
        width: parent.width - (parent.height * 0.2)
        opacity: 0.5
        clip: true


        Rectangle {
            id: highlight
            anchors.bottom: parent.bottom
            height: progerssRect.height * 0.3
            clip: true
//             radius: 7
            Image {
                width: 130;
                height: progerssRect.height * 0.3//30
                //source: "assets/progressbar_bg.png";
                fillMode: Image.Tile;
                anchors.fill: parent;
//                opacity: 0.3
            }

            property int widthDest: ( ( progressbar.width * ( value- minimum ) ) / ( maximum - minimum ) - 4 )
            width: highlight.widthDest
            Behavior on width {
                SmoothedAnimation {
                    velocity: 1200
                }
            }
            color: GStyle.blueColor()

            Text {
                id: percentTxt
                x: 136
                y: 0

                anchors.left: progressbar.left
                anchors.right: progressbar.right
                text: Number(progress.toFixed(0))+"%"

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                font.family: robotoRegular.name
                font.pixelSize: GStyle.getTextEditLabelPixelSize()//14
                font.letterSpacing: 1

                wrapMode: Text.WordWrap
                color: GStyle.blackColor()//"Black"
            }
        }

    }
    Text {
        id: prgressBarDesc
        text: description
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: robotoRegular.name
        font.pixelSize: GStyle.getMessageBoxTextPixelSize()
        font.letterSpacing: 1
        anchors.top: progerssRect.top
        anchors.topMargin: progerssRect.height * 0.2
        anchors.horizontalCenter: progerssRect.horizontalCenter
        Layout.fillWidth: true
        wrapMode: Text.WordWrap
        color: GStyle.blackColor()//"Black"
    }

    RoundButton{
        id: primaryButton
        width: progressbar.width * 0.25
        height: progressbar.height * 0.18
        anchors.right: parent.right
        anchors.rightMargin: progressbar.width * 0.05
        anchors.bottom: parent.bottom
        anchors.bottomMargin: progressbar.height * 0.05
        radius: GStyle.defaultButtonRadius()
        palette {
            button: GStyle.blueColor()
        }
        Text{
            id: primaryButtonText
            anchors.centerIn: primaryButton
            text:  primaryButtonTextValue
            font.family: openSansRegular.name
            font.pixelSize: GStyle.getTextEditLabelPixelSize()//14
            font.weight: "Bold"
            color: GStyle.whiteColor()//"#FFFFFF"
            font.letterSpacing: 0.5
        }
        onClicked: {
                end()
        }
    }

    function start()
    {
        timerUPdateProgress.start()
        progressbar.progress = 0
        progressbar.visible = true
    }


    function end()
    {
        timerUPdateProgress.stop()
        progressbar.progress = 0
        progressbar.visible = false
    }

    function onCompleteProgress()
    {

    }

    function onTimeOutProcess()
    {

    }

    function onUpdate()
    {

    }

    function onCancel()
    {

    }

}
