#ifndef AUTHOR_TABLE_WIDGET_H
#define AUTHOR_TABLE_WIDGET_H

#include <QWidget>
#include <QList>
#include <QCheckBox>

#include "../models/author.h"

namespace Ui {
class AuthorTableWidget;
}

class AuthorTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorTableWidget(QWidget *parent = nullptr);
    ~AuthorTableWidget();

    void setAuthors(const QList<Author> &);

private:
    void _clearTableAuthor();
    void _fillTableAuthor(QList<Author> &);

private:
    Ui::AuthorTableWidget *ui;
    QList<Author> _authors;
};

#endif // AUTHOR_TABLE_WIDGET_H
