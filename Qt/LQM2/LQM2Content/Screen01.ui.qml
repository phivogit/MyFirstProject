/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick
import QtQuick.Controls
import LQM2
import QtQuick.Studio.DesignEffects
import QtQuick.Studio.Components

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    Button {
        id: button
        text: qsTr("Press me")
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -297
        anchors.horizontalCenterOffset: 465
        checkable: true
        anchors.horizontalCenter: parent.horizontalCenter

        Connections {
            target: button
            onClicked: animation.start()
        }
    }

    Text {
        id: text1
        x: 763
        y: 213
        width: 431
        height: 85
        text: qsTr("LQM Calculator")
        font.pixelSize: 50
        horizontalAlignment: Text.AlignHCenter
    }

    TextField {
        id: textField
        x: 404
        y: 384
        width: 291
        height: 90
        text: ""
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 16
        placeholderText: qsTr("Số huy hiệu hiện có")
    }

    TextField {
        id: textField1
        x: 404
        y: 498
        width: 291
        height: 85
        text: ""
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 16
        placeholderText: qsTr("Số giấy tuyệt sắc hiện có")
    }

    TextField {
        id: textField2
        x: 404
        y: 608
        width: 291
        height: 89
        text: ""
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 16
        placeholderText: qsTr("Số giấy cuộn S hiện có")
    }

    Button {
        id: button1
        x: 834
        y: 384
        width: 253
        height: 313
        text: qsTr("Tính")
        font.bold: false
        font.pointSize: 74
        autoRepeat: false

        DesignEffect {
            effects: [
                DesignDropShadow {
                }
            ]
        }
    }

    TextField {
        id: textField3
        x: 1215
        y: 471
        width: 260
        height: 139
        readOnly: true
        placeholderText: qsTr("Text Field")
    }

    Label {
        id: label
        x: 701
        y: 409
        width: 120
        height: 36
        text: qsTr("Huy hiệu")
        font.pointSize: 19
    }

    Label {
        id: label1
        x: 701
        y: 522
        width: 120
        height: 36
        text: qsTr("Tuyệt sắc")
        font.pointSize: 19
    }

    Label {
        id: label2
        x: 701
        y: 635
        width: 120
        height: 36
        text: qsTr("Giấy S")
        font.pointSize: 19
    }

    Label {
        id: label3
        x: 1215
        y: 398
        width: 115
        height: 67
        text: qsTr("Số huy hiệu ít nhất")
        font.pointSize: 24
    }

    Item {
        id: __materialLibrary__
    }
    states: [
        State {
            name: "clicked"
            when: button.checked
        }
    ]
}
