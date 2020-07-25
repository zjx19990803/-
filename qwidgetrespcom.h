#ifndef QWIDGETRESPCOM_H
#define QWIDGETRESPCOM_H
#include <QApplication>
#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class QWidgetRespCom : public QWidget
{
public:
    QSerialPort *com2;



    char status2 = 0;
    char pkgHead2;
    char pkgDataHead2;
    unsigned char pkgDataBuf2[]; // 数据长度最大为4血压
    //unsigned int pkgDataBuf2[4];
    char pkgData2[4];
    char pkgCrc2;
    int  pkgDataCnt2 ;
     //int  pkgDataCnt2 =0;
    int spo2;
    char dataTmp2;


    QWidgetRespCom(QWidget *parent = nullptr) : QWidget(parent)
    {
        this->status2=-1;
        this->serialInit2();
    }

    int serialInit2(void);
    void serialRx2(void);
    void rxDataHandle2(char data1);
    char bccCheck2(char *data1, int len1);
    void ecgBpmCalc2(int respData);
    int get_max2(int * data2, int len2);
signals:

};

#endif // QWIDGETECGCOM_H
