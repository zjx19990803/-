#ifndef WIDGETTABLE_H
#define WIDGETTABLE_H

#include <QWidget>
#include <QLineEdit>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QSqlQueryModel>
#include <QTableView>
#include <QPushButton>
#include <QLabel>
#include "patientmodel.h"

class WidgetTable : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetTable(QWidget *parent = nullptr);

signals:

public slots:
    void sendCmd();

private:
    QLineEdit * editId;
    QLineEdit * editName;
    QLineEdit * editSex;
    QPushButton *btnSendCmd;
    QLabel *labelUsername;

    QSqlDatabase db;

    PatientModel *patientsModel;
    QTableView * patientTableView;

};

#endif // WIDGETTABLE_H
