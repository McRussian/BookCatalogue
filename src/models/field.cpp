#include "field.h"

Field::Field()
{

}

Field::~Field()
{

}

const QString &Field::name() const
{
    return _name;
}

void Field::setName(const QString &newName)
{
    _name = newName;
}

const QString &Field::value() const
{
    return _value;
}

void Field::setValue(const QString &newValue)
{
    _value = newValue;
}

unsigned int Field::id() const
{
    return _id;
}

void Field::setId(unsigned int newId)
{
    _id = newId;
}
