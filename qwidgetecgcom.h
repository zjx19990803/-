#ifndef QWIDGETECGCOM_H
#define QWIDGETECGCOM_H
#include <QApplication>
#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class QWidgetEcgCom : public QWidget
{
public:
    QSerialPort *com;



    char status = 0;
    char pkgHead;
    char pkgDataHead;
    unsigned int pkgDataBuf[]; // 心电图数据数组ecg2
    char pkgData[10];
    char pkgCrc;
    int  pkgDataCnt;
    int  pkgCnt;
    int ecg1, ecg2, ecg3;

    // 计算心率相关变量
    int ecg2PulseMax;
    int ecg2PulseMid;
    int ecg2Zero = 2048; // 无信号输入时输出结果为2048
    int ecg2Buff[2000]; //采样率为500=每秒钟采样500次，假设心率很慢2s一次，一个周期有1000个数据，这里取2000个
    unsigned int ecg2BuffIndex = 0;
    char prePulse;
    char pulse;
    long long pulseStart = 0, pulseEnd = 0;
    int ecg2Period;
    int ecg2Bpm;

    QWidgetEcgCom(QWidget *parent = nullptr) : QWidget(parent)
    {
        this->status=-1;
        this->serialInit();
    }

    int serialInit(void);
    void serialRx(void);
    void rxDataHandle(char data);
    char bccCheck(char *data, int len);
    void ecgBpmCalc(int ecgData);
    int get_max(int * data, int len);
signals:

};

#endif // QWIDGETECGCOM_H
