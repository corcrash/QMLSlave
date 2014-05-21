#include "connection.h"

#include <QJsonDocument>
#include <QJsonObject>

Connection::Connection(QObject *parent) :
    QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(processReadyRead()));
}

int Connection::readDataIntoBuffer(int maxSize)
{
    if(maxSize > MAX_BUFFER_SIZE)
        return 0;

    int bufferSizeBeforeRead = this->buffer.size();
    if(bufferSizeBeforeRead >= MAX_BUFFER_SIZE)
    {
        this->abort();
        return 0;
    }

    while(this->bytesAvailable() && this->buffer.size() < maxSize)
    {
        this->buffer.append(this->read(1));
    }

    return this->buffer.size() - bufferSizeBeforeRead;

}


bool Connection::sendQMLCode(const QString &QMLCode)
{
    if(QMLCode.isEmpty())
        return false;

    QString code = "{ \"type\" : \"QMLCode\", \"data\": \"" + QMLCode + "\" }";

    qDebug() << "Sending code: " << code;

    QByteArray data = code.toUtf8();

    if(this->write(data) == data.size())
        return true;

    return false;
}

void Connection::processReadyRead()
{
    qDebug() << "Reading data!";
    if(this->readDataIntoBuffer() <= 0)
        return;

    qDebug() << "Recieved data: " << this->buffer;

    QJsonDocument tempDocument = QJsonDocument::fromJson(this->buffer);

    QJsonObject recievedData = tempDocument.object();

    qDebug() << tempDocument;

    if(recievedData["type"].toString() == "eventMessage")
    {
        emit newEventMessage(recievedData["data"].toString());

        this->buffer.clear();
        return;
    }

    if(recievedData["type"].toString() == "QMLRequest")
    {
        emit newQMLCodeRequest();
        qDebug() << this->buffer;
        this->buffer.clear();
        return;
    }
}
