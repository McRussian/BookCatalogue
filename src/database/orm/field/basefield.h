#ifndef BASEFIELD_H
#define BASEFIELD_H

#include <QString>
#include <QStringList>

class FieldException : public std::exception
{
public:
    FieldException(QString msg): _message(msg) {}
    const char * what () {
        return this->_message.toStdString().c_str();
    }
private:
    QString _message;
};

class BaseField
{
public:
    BaseField(const QString, const QString, const bool pk = false, const bool n = false, const bool u = false);
    ~BaseField();

    static void setValidTypes(QStringList);

    QString create();

    bool is_key() const;

private:
    static QStringList _valid_types;
    QString _field_name;
    QString _field_type;
    bool _is_key;
    bool _is_null;
    bool _is_unique;
};

#endif // BASEFIELD_H
