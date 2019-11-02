#include "gamecontroller.h"

GameController::GameController(Model* model)
{
    this->model = model;
    this->running = true;
    this->controlStatements = new SharedQueue<std::string>();
    qDebug() << "initialized new GameController" << endl;
}

GameController::~GameController()
{
    qDebug() << "~GameController() called" << endl;
}

void GameController::operator()()
{
    qDebug() << "controller started";
    while (running)
    {
        if(!controlStatements->empty())
        {
            qDebug() << "poll new control statement ... " << endl;
            std::string answer = controlStatements->front();
            qDebug() << "new control statement: " << QString::fromStdString(answer) << endl;
            if(answer == model->EXIT_EXP)
            {
                qDebug() << "terminate program" << endl;
                model->terminateProgram();
                break;
            }
            else if(answer == model->QUIT_GAME_EXP)
            {
                qDebug() << "quit game" << endl;
                model->quitGame();
            }
            else if(answer == model->START_GAME_EXP)
            {
                qDebug() << "start new game" << endl;
                model->startNewGame();
            }
            else if(model->getCurrentGame() != nullptr)
            {
                qDebug() << "evaluate answer" << endl;
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
