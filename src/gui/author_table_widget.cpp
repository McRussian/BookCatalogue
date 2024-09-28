#include "author_table_widget.h"
#include "ui_author_table_widget.h"

AuthorTableWidget::AuthorTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthorTableWidget)
{
    ui->setupUi(this);
    ui->table_author->setColumnWidth(0, 20);
    ui->table_author->setColumnWidth(1, 40);
    ui->table_author->setColumnWidth(2, 390);

    this->_fillTableAuthor(this->_authors);
}

AuthorTableWidget::~AuthorTableWidget()
{
    this->_clearTableAuthor();
    delete ui;
}

void AuthorTableWidget::setAuthors(const QList<Author> &newAuthors)
{
    this->_authors = newAuthors;
    this->_fillTableAuthor(this->_authors);
}

void AuthorTableWidget::_clearTableAuthor()
{
    while (ui->table_author->rowCount() > 0) {
        QCheckBox* check = (QCheckBox*)ui->table_author->cellWidget(0, 0);
        ui->table_author->removeRow(0);
        delete check;
    }
}

void AuthorTableWidget::_fillTableAuthor(QList<Author> &authors)
{
    this->_clearTableAuthor();
    for (QList<Author>::iterator it = authors.begin(); it != authors.end(); it++) {
        QCheckBox *check = new QCheckBox();
        check->setChecked(false);
        int number_row = ui->table_author->rowCount();
        ui->table_author->insertRow(number_row);
        ui->table_author->setCellWidget(number_row, 0, check);
        ui->table_author->setItem(number_row, 1, new QTableWidgetItem(it->id()));
        ui->table_author->setItem(number_row, 2, new QTableWidgetItem(it->fullname()));
    }
}
