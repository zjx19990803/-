#include "patientmodel.h"

PatientModel::PatientModel()
{

}


Qt::ItemFlags PatientModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);

    if (index.column() == 1 || index.column() == 2)
        flags |= Qt::ItemIsEditable;

    return flags;
}
bool  PatientModel::setName(int id, QString name)
{
    QSqlQuery query;
    query.prepare("UPDATE patient set name = ? where id = ?");
    query.addBindValue(name);
    query.addBindValue(id);
    return query.exec();
}

bool  PatientModel::setSex(int id, QString sex)
{
    QSqlQuery query;
    query.prepare("UPDATE patient set sex = ? where id = ?");
    query.addBindValue(sex);
    query.addBindValue(id);
    return query.exec();
}

bool PatientModel::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
    // 只处理第1，第2列
    if (index.column() < 1 || index.column() > 2)
        return false;

    // index.row() 返回被编辑的行
    // 第二个参数0，代表第一列
    // 这里是获取一个单元格位置的对象
    QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
    qDebug()<<primaryKeyIndex;
    // 把第一个单元格内容，病人ID提取出来
    int id = this->data(primaryKeyIndex).toInt();
    qDebug()<<"id="<<id;

    bool ok = false;
    if (index.column() == 1)
    {
        ok = this->setName(id, value.toString());
        qDebug()<<"name update done";
        if (ok)
                this->setQuery("SELECT * FROM patient");
    }else if (index.column() == 2)
    {
        ok = this->setSex(id, value.toString());
        qDebug()<<"sex update done";
        if (ok)
                this->setQuery("SELECT * FROM patient");
    }
    else
    {
        // 错误日志
        qDebug()<<"somthing error";
    }
    return ok;



}
