#include "mainwindow.h"
#include <QApplication>
#include <controller.h>
#include <model.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    Model myModel;
    cout << myModel.get_question().answer_a << endl;

    Controller myController;
    myController.start_game();

    //return a.exec();
}
