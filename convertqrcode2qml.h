#ifndef CONVERTQRCODE2QML_H
#define CONVERTQRCODE2QML_H
#include "qrcodegen.hpp"
#include <QObject>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <QBitmap>
#include <QGenericMatrix>
#include <QPainter>
#include <QQuickPaintedItem>
using namespace qrcodegen;
class ConvertQRcode2QML : public QQuickPaintedItem
{
    Q_OBJECT

public:
     ConvertQRcode2QML(QQuickItem *parent = nullptr);
    Q_INVOKABLE void setImage(QString data);
     QPixmap QRcode;
     static QPixmap printQr(const QrCode &qr);


     const std::string &Data() const;



protected:
       void paint(QPainter *painter) ;

};

#endif // CONVERTQRCODE2QML_H
