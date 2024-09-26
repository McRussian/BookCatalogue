#include "gui/book_catalogue_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BookCatalogueWindow w;
    w.show();
    return a.exec();
}
