/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "Bin/bin.h"
#include <QNetworkInterface>
#include <QAbstractSocket>
#include <QNetworkSession>
#include <QHostAddress>
#include <QHostAddress>
#include <QTimerEvent>
#include <QTcpSocket>
#include <QHostInfo>
#include <QtNetwork>

#ifndef CONNECTIONF2F_H
#define CONNECTIONF2F_H
class ConnectionF2F : public QTcpSocket
{
    Q_OBJECT

public:
    ConnectionF2F(QObject *parent = nullptr);
    ~ConnectionF2F();

    void ConnectingToPeer();
    void ReadyReadOfData();

    void AskForConnectingToPortPeer();
    void AskForDisconnectingFromPortPeer();

public:
    void PassOnWANIp(QString &buffer);

private:
    void GetIpAddressFromWAN(QString &textWithIPAddres);
};
#endif