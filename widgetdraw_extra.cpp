#include "widgetdraw_extra.h"
#include <QPaintEvent>
#include <QPainter>
#include "ecgdata.h"
WidgetDraw_extra::WidgetDraw_extra(QWidget *parent) : QWidget(parent)
{
    this->resize(1728,480);

    pixmap = new QPixmap(this->width(), this->height());
    //pixmap->fill(Qt::black);
    timer = new QTimer(parent);
    connect(timer, &QTimer::timeout, this, WidgetDraw_extra::refresh);
    timer->start(4);
}

void WidgetDraw_extra::refresh()
{
    drawPixmap();
    this->update();
}

void WidgetDraw_extra::paintEvent(QPaintEvent *event)
{
    drawWidget();
}

void WidgetDraw_extra::drawWidget()
{
    QPainter *painter = new QPainter();

    painter->begin(this);
    painter->drawPixmap(0,0,*pixmap);

    painter->end();
}

void WidgetDraw_extra::drawPixmap()
{
    QPainter *painter = new QPainter();

    painter->begin(pixmap);

    this->drawData(painter);

    painter->end();
}

void WidgetDraw_extra::drawData(QPainter *painter)
{
    painter->setPen(QPen(Qt::green,2,Qt::DashLine,Qt::RoundCap));

    int height = this->height();
    int width = this->width();
    temp = temp + 2;
    pointX = pointX + 1;
    painter->save();
    painter->setPen(QPen(Qt::black,8));
    painter->drawRect(pointX+4,0,1,height);
    painter->restore();
    painter->drawLine(QPoint(pointX,height - (ecgWave[(temp)%500]-1900)/800*height),QPoint(pointX+1,height - (ecgWave[((temp+2))%500]-1900)/800*height));
    if(pointX > width-4)
    {
        pointX = 0;
    }
    if(temp >= 2500)
    {
        temp = 0;
    }
}
