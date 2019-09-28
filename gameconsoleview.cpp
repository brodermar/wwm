#include "gameconsoleview.h"
using namespace std;

GameConsoleView::GameConsoleView(Model* model) : ViewObservable(), GameObserver()
{
    this->model = model;
}

GameConsoleView::~GameConsoleView()
{

}

void GameConsoleView::operator()()
{
    while (true)
    {
        cout << "View here" << endl;
        this_thread::sleep_for(chrono::milliseconds(2));
    }
}

void GameConsoleView::output()
{

}



void GameConsoleView::update()
{

}
