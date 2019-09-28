#include "gamecontroller.h"

GameController::GameController(Model* model)
{
    this->model = model;
    this->answers = new std::queue<std::string, std::list<std::string>>();
}

GameController::~GameController()
{

}

void GameController::operator()()
{
    while (true)
    {
        std::cout << "Controller here" << std::endl;
        if(!answers->empty())
        {
            std::string answer = answers->front();
            if(answer == model->EXIT_EXP)
            {
                model->terminateProgram();
                break;
            }
            else if(answer == model->QUIT_GAME_EXP)
            {
                model->quitGame();
            }
            else if(answer == model->START_GAME_EXP)
            {
                model->startNewGame();
            }
            else if(model->getCurrentGame() != nullptr)
            {
                model->getCurrentGame()->evaluateAnswer(answer);
            }
            model->notifyObservers();
            answers->pop();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

void GameController::update(std::string message)
{
    this->answers->push(message);
}
