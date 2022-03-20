import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtGraphicalEffects  1.12
import QtQuick.Dialogs 1.1
import QtQuick.VirtualKeyboard 2.0
import SerialPortSettingsLib 1.0
import CommLinkSettingsLib 1.0
import LocalStringsLib 1.0
import GStyleLib 1.0

Item {
    id : fontLoader
    property alias defaultFont: defaultGCSFont.name
    property alias sevenSegment: sevenSegmentFont.name
    property alias openSansRegular: openSansRegular.name
    FontLoader {
        id:defaultGCSFont
        source: LocalStrings.getLocalTextValue("fontDefault")
    }

    FontLoader {
        id:sevenSegmentFont
        source: LocalStrings.getLocalTextValue("fontSeven_Segment")
    }

    FontLoader {
        id:openSansRegular
        source:LocalStrings.getLocalTextValue("fontOpen_Sans_Regular")
    }

    FontLoader {
        id: montserratRegular
        source:LocalStrings.getLocalTextValue("fontMontserrat-Regular")
    }

    FontLoader {
        id: robotoRegular
        source:LocalStrings.getLocalTextValue("fontRoboto-Regular")
    }

    FontLoader {
        id: sanRegular
        source:LocalStrings.getLocalTextValue("fontOpen_Sans_Regular")
    }

    FontLoader {
        id: redHadDisp
        source:LocalStrings.getLocalTextValue("fontRedHatDisplay-Regular")
    }
}
