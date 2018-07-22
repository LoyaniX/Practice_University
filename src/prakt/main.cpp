#include "mymainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWindow w;
    w.setWindowTitle("Программа расчета");
    w.setWindowIcon(QIcon(":Programming-System-Task-icon.png"));
    w.setFixedSize(750,580);
    w.show();
    return a.exec();
}
