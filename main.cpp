#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "convertqrcode2qml.h"
#include "qrcodegen.hpp"
#include<QMetaType>
#include <QQmlEngine>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<ConvertQRcode2QML>("io.qt.forum", 1, 0, "PixmapImage");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    ConvertQRcode2QML convert;
    engine.rootContext()->setContextProperty("convert2qml", &convert);
//    ConvertQRcode2QML convert2qml;
//    const char *text = "loc dep trai";
//    const QrCode::Ecc errCorLvl = QrCode::Ecc::HIGH;
//    const QrCode qr = QrCode::encodeText(text,errCorLvl);
//    QPixmap qrcode = convert2qml.printQr(qr);
//    qrcode =  qrcode.scaled(250,250);
//    //convert2qml.paint(qrcode);
    return app.exec();
}
