#include "gamecontroller.h"

GameController::GameController(Model* model)
{
    this->model = model;
    this->running = true;
    this->controlStatements = new SharedQueue<std::string>();
}

GameController::~GameController()
{

}

void GameController::operator()()
{
    qDebug() << "controller started";
    while (running)
    {
//        std::cout << "Controller here" << std::endl;
        if(!controlStatements->empty())
        {
            qDebug() << "poll new control statement" << endl;
            std::string answer = controlStatements->front();
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
            controlStatements->pop();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    qDebug() << "controller terminated";
}

void GameController::update(std::string message)
{
    qDebug() << "update called with message: " << QString::fromStdString(message);
    this->controlStatements->push(message);
}

void GameController::stop()
{
    qDebug() << "stop called";
    running = false;
}
