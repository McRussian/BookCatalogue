#include "bookcatalouewindow.h"
#include "ui_bookcatalouewindow.h"

BookCataloueWindow::BookCataloueWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BookCataloueWindow)
{
    ui->setupUi(this);
}

BookCataloueWindow::~BookCataloueWindow()
{
    delete ui;
}

