#include "gameconsoleview.h"

GameConsoleView::GameConsoleView(Model* model)
{
    this->model = model;
}

GameConsoleView::~GameConsoleView()
{

}

void GameConsoleView::operator()() const
{
    while (true)
    {
        std::cout << "View here" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}
