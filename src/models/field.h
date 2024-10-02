#ifndef FIELD_H
#define FIELD_H

#include <QString>

class Field
{
public:
    Field();
    ~Field();

    const QString &name() const;
    void setName(const QString &newName);

    const QString &value() const;
    void setValue(const QString &newValue);

    unsigned int id() const;
    void setId(unsigned int newId);

private:
    unsigned int _id;
    QString _name;
    QString _value;
};

#endif // FIELD_H
