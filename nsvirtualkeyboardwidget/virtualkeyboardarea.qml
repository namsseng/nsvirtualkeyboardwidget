import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.VirtualKeyboard 2.1

Item {
    signal inputPanelFocusChanged(bool active)
    signal inputPanelGeometryChanged(int x, int y, int width, int height)
   focus: false

    InputPanel {
        id: inputPanel
        z: 99
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        onActiveChanged :{
            inputPanelGeometryChanged(x,y,width,height)
            inputPanelFocusChanged(active)
        }

        onXChanged: {
            inputPanelGeometryChanged(x,y,width,height)
        }
        onYChanged: {
            inputPanelGeometryChanged(x,y,width,height)
        }
        onWidthChanged: {
            inputPanelGeometryChanged(x,y,width,height)
        }
        onHeightChanged: {
            inputPanelGeometryChanged(x,y,width,height)
        }

        Component.onCompleted: {
        }

    }
}




