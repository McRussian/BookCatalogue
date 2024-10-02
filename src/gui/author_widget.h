#ifndef AUTHOR_WIDGET_H
#define AUTHOR_WIDGET_H

#include <QWidget>
#include <QString>
#include <QMessageBox>

#include "../models/author.h"

namespace Ui {
class AuthorWidget;
}

class AuthorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorWidget(Author*, QWidget *parent = nullptr);
    ~AuthorWidget();

private slots:
    void _handleButtonOK();
    void _handleButtonCancel();

private:
    void _showError(QString);

private:
    Ui::AuthorWidget *ui;
    Author* _author;
};

#endif // AUTHOR_WIDGET_H
