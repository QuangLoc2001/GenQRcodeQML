import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
import io.qt.forum 1.0
Window {
    width: 1000
    height: 1000
    visible: true
    title: qsTr("Hello World")
    Rectangle{
        width: 400
        height: width
        anchors.horizontalCenter: parent.horizontalCenter
    PixmapImage {
         id: pixmapImage
         anchors.fill: parent
     }
    Rectangle{
        id: rectLogo
        visible: false
        width: 60
        height: width
        radius: width/2
        color: "blue"
        anchors.centerIn: parent

    }
    }

    Button {
        text: "Generate Qrcode"
         anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            rectLogo.visible= true
            pixmapImage.setImage(textInput.text)

        }
        anchors.bottom: parent.bottom

    }
    Rectangle{
        width: 1000
        height: 100
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 100
        color:"#99c1f1"
        TextField {
        id: textInput
        anchors.fill: parent
    }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
