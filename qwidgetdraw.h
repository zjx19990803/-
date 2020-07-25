#ifndef QWIDGETDRAW_H
#define QWIDGETDRAW_H

#include <QWidget>
#include <QTimer>
class QWidgetDraw : public QWidget
{
    Q_OBJECT
public:
    QTimer *timer;
    QPixmap *pixmap;
    int pointX = 0;
    int pointY = 0;

    int cnt = 0, dir = 0;
    explicit QWidgetDraw(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *event) override;
    void drawTriangle(QPainter *painter);
    void drawSinWave(QPainter *painter);
    void refresh();
    void drawPixmap();
    void drawWidget(void);
signals:

};

#endif // QWIDGETDRAW_H
