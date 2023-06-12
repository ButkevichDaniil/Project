#include<QApplication>
#include "mainwindow.h"
#include "qapplication.h"
#include "extrafunction.h"

int main(int argc, char *argv[]) // Запускает все остальные файлы
{
    QApplication a(argc, argv);
    MainWindow w;

    if (w.isError)
    {
        return 0;
    }

    w.show();
    return a.exec();
}
