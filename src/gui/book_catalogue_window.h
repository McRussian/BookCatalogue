#ifndef BOOK_CATALOGUE_WINDOW_H
#define BOOK_CATALOGUE_WINDOW_H

#include <QMainWindow>

namespace Ui {
class BookCatalogueWindow;
}

class BookCatalogueWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookCatalogueWindow(QWidget *parent = nullptr);
    ~BookCatalogueWindow();

private:
    Ui::BookCatalogueWindow *ui;
};

#endif // BOOK_CATALOGUE_WINDOW_H
