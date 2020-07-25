#include "qwidgetdraw.h"
#include <QPaintEvent>
#include <QPainter>
#include <QtCore/qmath.h>
#include <QTimer>
QWidgetDraw::QWidgetDraw(QWidget *parent) : QWidget(parent)
{
    //this->setWindowTitle("第十组-艾秋明");
    this->resize(1728,480);

    pixmap = new QPixmap(this->width(), this->height());
    //pixmap->fill(Qt::black);
    timer = new QTimer(parent);
    connect(timer, &QTimer::timeout, this, QWidgetDraw::refresh);
    timer->start(4);
}

void QWidgetDraw::refresh()
{
    drawPixmap();
    this->update();
}

void QWidgetDraw::paintEvent(QPaintEvent *event)
{
    drawWidget();
}

void QWidgetDraw::drawWidget()
{
    QPainter *painter = new QPainter();

    painter->begin(this);
    painter->drawPixmap(0,0,*pixmap);

    painter->end();
}





//void QWidgetDraw::drawSinWave(QPainter *painter)
//{

//}

void QWidgetDraw::drawPixmap()
{
    QPainter *painter = new QPainter();

    painter->begin(pixmap);

    this->drawTriangle(painter);

    painter->end();
}

void QWidgetDraw::drawTriangle(QPainter *painter)
{

    painter->setPen(QPen(Qt::green,2,Qt::DashLine,Qt::RoundCap));

    int height = this->height();
    int width = this->width();

    pointX = pointX + 1;
    if(dir == 0)
    {
        pointY = pointY + 1;
        if(pointY >= height/2+7)
            dir = 1;
    }
    else
    {
        pointY = pointY - 1;
        if(0 == pointY)
            dir = 0;
    }

    painter->save();
    painter->setPen(QPen(Qt::black,8));
    painter->drawRect(pointX+4,0,1,height);
    painter->restore();

    painter->drawPoint(pointX,height - pointY);
    if(pointX > width-4)
        pointX = 0;
}
