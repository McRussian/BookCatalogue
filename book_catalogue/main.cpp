#include "bookcatalouewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BookCataloueWindow w;
    w.show();
    return a.exec();
}
