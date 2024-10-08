#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QString>
#include <QList>

#include "../field/basefield.h"

class ModelException : public std::exception
{
public:
    ModelException(QString msg): _message(msg) {}
    const char * what () {
        return this->_message.toStdString().c_str();
    }
private:
    QString _message;
};


class BaseModel
{
public:
    BaseModel(const QString, const QList<BaseField>);
    ~BaseModel();

    QString createTable();

private:
    QStringList _calculate_primary_keys();

private:
    QString _table_name;
    QList<BaseField> _fields;
};

#endif // BASEMODEL_H
