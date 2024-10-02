#include "basefield.h"

BaseField::BaseField(const QString name, const QString type, const bool pk, const bool n, const bool u) :
    _field_name(name),
    _is_key(pk),
    _is_null(n),
    _is_unique(u)
{
    if (BaseField::_valid_types.empty())
        throw FieldException("Not Set Valid Type for Field.");
    if (!BaseField::_valid_types.contains(type, Qt::CaseInsensitive))
        throw FieldException("Unknown Type of Field.");
    this->_field_type = type.toUpper();
}

BaseField::~BaseField()
{

}

void BaseField::setValidTypes(QStringList types)
{
    if (types.empty())
        throw FieldException("List of Valid Types cannot be Empty.");
    BaseField::_valid_types = types;
}

QString BaseField::create()
{
    QString pattern = "";
    pattern += this->_field_name + " " + this->_field_type;
    if (this->_is_null)
        pattern += " NOT NULL";
    if (this->_is_unique)
        pattern += " UNIQUE";
    return pattern;
}

bool BaseField::is_key() const
{
    return _is_key;
}
