#include "widgettable.h"
#include <QDebug>
#include <QSqlQueryModel>
#include "patientmodel.h"
#include <QLineEdit>

WidgetTable::WidgetTable(QWidget *parent) : QWidget(parent)
{
    this->labelUsername = new QLabel(this);
    this->labelUsername->setText("序列号");
    this->labelUsername->move(50,30);


    this->labelUsername = new QLabel(this);
    this->labelUsername->setText("名字");
    this->labelUsername->move(200,30);


    this->labelUsername = new QLabel(this);
    this->labelUsername->setText("性别");
    this->labelUsername->move(350,30);


    // 创建文本输入框
    this->editId = new QLineEdit(this);
    this->editName = new QLineEdit(this);
    this->editSex = new QLineEdit(this);
    // 创建按钮
    this->btnSendCmd = new QPushButton(this);
    this->btnSendCmd->setText("确认");

    //配置窗口控件位置
    this->editId->move(0,0);
    this->editName->move(150,0);
    this->editSex->move(300,0);
    this->btnSendCmd->move(0,50);

    // 加载数据库驱动
    db = QSqlDatabase::addDatabase("QMYSQL");
    // 配置数据库主机名称, 可以是IP地址，域名
    db.setHostName("localhost");
    // 配置数据库名称
    db.setDatabaseName("medical_monitor");
    // 用户名密码
    db.setUserName("doctor1");
    db.setPassword("123456");
    // 打开链接/登陆
    bool openOk = db.open();

    if (openOk)
    {
        qDebug()<<"登陆成功";
    }
    else
    {
        qDebug()<<"登陆错误";
    }

    // 创建病人列表相关对象
//    patientsModel = new QSqlQueryModel();
    patientsModel = new PatientModel();
    patientTableView = new QTableView(this);
    // 关联模型与表格
    patientsModel->setQuery("SELECT * FROM patient");

    patientTableView->setModel(patientsModel);
    // 设置表格显示位置
    patientTableView->move(0,100);
    patientTableView->setMaximumWidth(800);
    patientTableView->setMinimumWidth(800);

    connect(this->btnSendCmd, &QPushButton::clicked, this, &WidgetTable::sendCmd);
}


void WidgetTable::sendCmd()
{
    qDebug()<<"todo";
    QSqlQuery query(db);
    bool cmdOk;

    query.prepare("INSERT INTO patient (name, sex) "
                  "VALUES (:name, :sex)");

    query.bindValue(":name", this->editName->text());
    query.bindValue(":sex", this->editSex->text());
    cmdOk = query.exec();
    if(cmdOk)
    {
        qDebug()<<"发送成功";
        // todo 创建refresh函数
        patientsModel->setQuery("SELECT * FROM patient");
    }
}


/*Qt::ItemFlags WidgetTable::flags(const QModelIndex &index) //const override
{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
}*/

/*    patientsModel->setQuery("SELECT *"
                            "FROM patient, device, device_patient "
                            "WHERE patient.id = device_patient.patient_id and device.dev_id = device_patient.dev_id");
                            */
