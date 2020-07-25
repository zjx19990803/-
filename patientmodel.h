#ifndef PATIENTMODEL_H
#define PATIENTMODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>


class PatientModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    PatientModel();

    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    bool  setName(int id, QString name);
    bool  setSex(int id, QString sex);

    bool  setData(const QModelIndex &index, const QVariant &value, int /* role */);

};

#endif // PATIENTMODEL_H
