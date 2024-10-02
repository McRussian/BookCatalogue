#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QString>
#include <QList>

#include "../field/basefield.h"

class BaseModel
{
public:
    BaseModel(QString, QList<BaseField>);
    ~BaseModel();

private:
    QString _table_name;
    QList<BaseField> _fields;
};

#endif // BASEMODEL_H
