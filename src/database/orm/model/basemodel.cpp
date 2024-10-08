#include "basemodel.h"

BaseModel::BaseModel(const QString table, const QList<BaseField> fields)
{
    if (fields.empty())
        throw ModelException("List of Fields cannot be Empty.");

    if (table.isEmpty())
        throw ModelException("Table Name cannot be Empty.");
    if (table.contains(" "))
        throw ModelException("Uncorrect Name Table, It Contains Space.");
    this->_fields = fields;
    this->_table_name = table;
}

BaseModel::~BaseModel()
{

}

QString BaseModel::createTable()
{
    QString sql_query = "CREATE TABLE IF NOT EXISTS " + this->_table_name + " (";
    for(QList<BaseField>::iterator it = this->_fields.begin(); it != this->_fields.end(); it++) {
        sql_query  += it->create() + ", ";
    }
    sql_query +=  "PRIMARY KEY (" + this->_calculate_primary_keys().join(", ") + "))";
    return sql_query;
}

QStringList BaseModel::_calculate_primary_keys()
{
    QStringList keys;
    for(QList<BaseField>::iterator it = this->_fields.begin(); it != this->_fields.end(); it++) {
        if (it->is_key())
            keys << it->field_name();
    }

    return keys;
}
