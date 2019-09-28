#include "gameconsoleview.h"

GameConsoleView::GameConsoleView(Model* model) : ViewObservable(), GameObserver()
{
    this->model = model;
}

GameConsoleView::~GameConsoleView()
{

}

void GameConsoleView::run()
{
    while (true)
    {
        std::cout << "View here" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

void GameConsoleView::operator()()
{
    while (true)
    {
        std::cout << "View here" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

void GameConsoleView::update()
{

}
