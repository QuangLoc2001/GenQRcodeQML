#include "convertqrcode2qml.h"

ConvertQRcode2QML::ConvertQRcode2QML(QQuickItem *parent)
    :   QQuickPaintedItem(parent)
{

}

void ConvertQRcode2QML::setImage(QString data )
{
        ConvertQRcode2QML convert2qml;
      // const char *data  = "{\"is_confirmed\":true,\"machine\":{\"machine_id\":\"may1\",\"machine_token\":\"SVDM1\"},\"order_item\":[{\"cost\":10000,\"ordered_no\":\"000_001\",\"position\":4,\"product_id\":\"sp01\",\"quantity\":1},{\"cost\":20000,\"ordered_no\":\"000_002\",\"position\":7,\"product_id\":\"sp02\",\"quantity\":1},{\"cost\":30000,\"ordered_no\":\"000_003\",\"position\":5,\"product_id\":\"sp03\",\"quantity\":1},{\"cost\":40000,\"ordered_no\":\"000_004\",\"position\":1,\"product_id\":\"sp04\",\"quantity\":1},{\"cost\":50000,\"ordered_no\":\"000_005\",\"position\":2,\"product_id\":\"sp05\",\"quantity\":1}],\"transaction_id\":\"giaodich1\"}";
        //const QrCode::Ecc errCorLvl = QrCode::Ecc::LOW ;
        std::vector<QrSegment> segs0 = QrSegment::makeSegments(data.toLocal8Bit().data());
        const QrCode qr= QrCode::encodeSegments(segs0, QrCode::Ecc::LOW, QrCode::MIN_VERSION, QrCode::MAX_VERSION, -1, true);
        //const QrCode qr = QrCode::encodeText(data,errCorLvl);
        QPixmap qrcode = convert2qml.printQr(qr);
        qrcode =  qrcode.scaled(250,250);
       QRcode =qrcode;
        update();
}

QPixmap ConvertQRcode2QML::printQr(const QrCode &qr)
{
    QImage myQRcode(qr.getSize(),qr.getSize(), QImage::Format_Grayscale8);
        for (int y = 0; y < qr.getSize(); y++) {
            for (int x = 0; x < qr.getSize() ; x++) {
                int pixel =  (qr.getModule(x, y) ? 0 : 255);
                std::cout << pixel;
               myQRcode.setPixel(QPoint(x,y),qRgb(pixel,pixel,pixel));
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return QPixmap::fromImage(myQRcode);

}

void ConvertQRcode2QML::paint(QPainter *painter)
{

    painter->drawPixmap(0, 0, width(), height(),  QRcode);
}



