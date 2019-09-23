#include "gamecontroller.h"

GameController::GameController(Model* model)
{
    this->model = model;
}

GameController::~GameController()
{

}

void GameController::operator()() const
{
    while (true)
    {
        std::cout << "Controller here" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}
