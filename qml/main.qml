import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

RowLayout {
    id: rowLayout1

    ColumnLayout {
        TextField {
            id: textMessage
        }

        Button {
            text: 'Send'
            onClicked: {
                client.emitSignal('newMessage', textMessage.text);
            }
        }
    }

    Button {
        text: 'Next view'
        transformOrigin: Item.Center
        activeFocusOnPress: false
        onClicked: {
            client.emitSignal('QMLRequest', "altview");
        }
    }
}
