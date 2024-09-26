#ifndef BOOKCATALOUEWINDOW_H
#define BOOKCATALOUEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BookCataloueWindow; }
QT_END_NAMESPACE

class BookCataloueWindow : public QMainWindow
{
    Q_OBJECT

public:
    BookCataloueWindow(QWidget *parent = nullptr);
    ~BookCataloueWindow();

private:
    Ui::BookCataloueWindow *ui;
};
#endif // BOOKCATALOUEWINDOW_H
