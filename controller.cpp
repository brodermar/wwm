#include "controller.h"
#include <iostream>

using namespace std;

Controller::Controller(QObject *parent) : QObject(parent)
{
}

void Controller::start_game()
{
    cout << "Game started" << endl;
}
