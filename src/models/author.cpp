#include "author.h"

Author::Author()
{

}

Author::~Author()
{

}

unsigned int Author::id() const
{
    return _id;
}

void Author::setId(unsigned int newId)
{
    _id = newId;
}

const QString &Author::first_name() const
{
    return _first_name;
}

void Author::setFirst_name(const QString &newFirst_name)
{
    _first_name = capitalize(normalize(newFirst_name));
}

const QString &Author::last_name() const
{
    return _last_name;
}

void Author::setLast_name(const QString &newLast_name)
{
    _last_name = capitalize(normalize(newLast_name));
}

const QString &Author::middle_name() const
{
    return _middle_name;
}

void Author::setMiddle_name(const QString &newMiddle_name)
{
    _middle_name = capitalize(normalize(newMiddle_name));
}

const QString &Author::alias() const
{
    return _alias;
}

void Author::setAlias(const QString &newAlias)
{
    _alias = capitalize(normalize(newAlias));
}

const QString &Author::comment() const
{
    return _comment;
}

void Author::setComment(const QString &newComment)
{
    _comment = newComment;
}

QString Author::fullname()
{
    QStringList items = {this->_last_name, this->_first_name, this->_middle_name};
    items.removeAll(QString(""));
    return items.join(" ");
}
