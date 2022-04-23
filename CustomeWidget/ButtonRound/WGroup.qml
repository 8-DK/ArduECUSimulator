import QtQuick 2.4
import QtQuick.Window 2.12
import ComHelperLib 1.0
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import LocalStringsLib 1.0
import GStyleLib 1.0

QtObject {
    id: groupObj
    property var currentActiveItem
    property var groupItems : []
    signal itemChanged()

    function addItem(mitem)
    {        
        var isAreadyAdded = false
        for (var i = 0; i < groupItems.length; i++)
            if(mitem === groupItems[i])
                isAreadyAdded = true

        if(isAreadyAdded === false)
            groupItems.push(mitem)
    }

    function setCurrItem(mitem)
    {
        for (var i = 0; i < groupItems.length; i++)
            groupItems[i].state = "notselected"
        mitem.state = "selected"
        currentActiveItem  = mitem
        itemChanged()
    }

    function getCurrentItem()
    {
        return currentActiveItem
    }
}

