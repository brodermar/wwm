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
    w.CommandParser("ShowQuestionScreen");

    return a.exec();
}
