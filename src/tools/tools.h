#ifndef TOOLS_H
#define TOOLS_H
#include <QString>
#include <QRegularExpression>
#include <QStringList>

QString capitalize(const QString str) {
    QString tmp = str;
    // if you want to ensure all other letters are lowercase:
    tmp = tmp.toLower();
    tmp[0] = str[0].toUpper();
    return tmp;
}

// Строка очищается от лишних символов (лишних пробелов и других символов), кроме тире
// Каждое слово строки капитализируется и возвращается строка из слов через один пробел
QString normalize(QString str) {
    QStringList words = str.split(QRegularExpression("[^\\w\\d\\-]", QRegularExpression::UseUnicodePropertiesOption));
    words.removeAll(QString(""));
    return words.join(" ").toLower();
}


#endif // TOOLS_H
