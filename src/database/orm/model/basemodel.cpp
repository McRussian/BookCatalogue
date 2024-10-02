#include "basemodel.h"

BaseModel::BaseModel(QString table, QList<BaseField> fields):
    _table_name(table),
    _fields(fields)
{

}

BaseModel::~BaseModel()
{

}
