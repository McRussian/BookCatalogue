#include "author_widget.h"
#include "ui_author_widget.h"

AuthorWidget::AuthorWidget(Author* author, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthorWidget),
    _author(author)
{
    ui->setupUi(this);
    ui->led_firstname->setText(this->_author->first_name());
    ui->led_lastname->setText(this->_author->last_name());
    ui->led_middlename->setText(this->_author->middle_name());
    ui->led_alias->setText(this->_author->alias());
    ui->led_comment->setText(this->_author->comment());
}

AuthorWidget::~AuthorWidget()
{
    delete ui;
}

void AuthorWidget::_handleButtonOK()
{
    if (ui->led_lastname->text() == "") {
        this->_showError("LastName");
    }

    if (ui->led_firstname->text() == "") {
        this->_showError("FirstName");
    }

    this->_author->setLast_name(ui->led_lastname->text());
    this->_author->setFirst_name(ui->led_firstname->text());
    this->_author->setMiddle_name(ui->led_middlename->text());
    this->_author->setAlias(ui->led_alias->text());
    this->_author->setComment(ui->led_comment->text());
}

void AuthorWidget::_handleButtonCancel()
{
    this->close();
}

void AuthorWidget::_showError(QString field)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warning");
    msgBox.setText("Field of " + field + " Must not be Empty.");
    msgBox.exec();
}
