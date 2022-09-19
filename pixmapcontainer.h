#ifndef PIXMAPCONTAINER_H
#define PIXMAPCONTAINER_H

#include <QObject>
#include <QPixmap>
class pixmapcontainer : public QObject
{
    Q_OBJECT
public:
    explicit pixmapcontainer(QObject *parent = 0);
    QPixmap pixmap;
};

#endif // PIXMAPCONTAINER_H
