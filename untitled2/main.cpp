#include "mainwindow.h"

#include <QApplication>
#include "question.h"
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFont f=QApplication::font();
    f.setStyleStrategy(QFont::PreferAntialias);
    QApplication::setFont(f);
    w.show();
    w.roundLoop();
    w.delay(5000);

    return a.exec();
}
