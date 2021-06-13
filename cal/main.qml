import QtQuick 2.12
import QtQuick.Window 2.12

import "./RangePicker"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Calendars{
        anchors.fill: parent
    }
}
