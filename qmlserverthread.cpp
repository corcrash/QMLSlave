#include "qmlserverthread.h"

QMLServerThread::QMLServerThread(int socketDescriptor, QObject *parent) :
    QThread(parent), socketDescriptor(socketDescriptor)
{
}
