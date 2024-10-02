#ifndef AUTHOR_H
#define AUTHOR_H

#include <QString>

#include "../tools/tools.h"

class Author
{
public:
    Author();
    ~Author();

    unsigned int id() const;
    void setId(unsigned int newId);

    const QString &first_name() const;
    void setFirst_name(const QString &newFirst_name);

    const QString &last_name() const;
    void setLast_name(const QString &newLast_name);

    const QString &middle_name() const;
    void setMiddle_name(const QString &newMiddle_name);

    const QString &alias() const;
    void setAlias(const QString &newAlias);

    const QString &comment() const;
    void setComment(const QString &newComment);

    QString fullname();

private:
    unsigned int _id;
    QString _first_name;
    QString _last_name;
    QString _middle_name;
    QString _alias;
    QString _comment;
};

#endif // AUTHOR_H
