#include "book_catalogue_window.h"
#include "ui_bookcataloguewindow.h"

BookCatalogueWindow::BookCatalogueWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookCatalogueWindow)
{
    ui->setupUi(this);
}

BookCatalogueWindow::~BookCatalogueWindow()
{
    delete ui;
}
