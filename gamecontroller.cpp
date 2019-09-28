#include "gamecontroller.h"

GameController::GameController(Model* model)
{
    this->model = model;
    this->answers = new std::queue<std::string(), std::list<std::string>()>();
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

void GameController::update(std::string message)
{
    this->answers.push(message);
}
