import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.1

ColumnLayout {
    MessageDialog {
        id: messageDialog
        title: 'A simple dialog'
        text: 'Gallifrey falls no more!'
        onAccepted: {
            client.emitSignal('newMessage', 'Gallifrey falls no more!');
        }
    }

    Button {
        text: 'Gallifrey stands!'
        onClicked: {
            messageDialog.visible = true;
        }
    }
}
