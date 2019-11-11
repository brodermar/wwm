#include "gameconsoleview.h"
using namespace std;

GameConsoleView::GameConsoleView(Model* model) :
    ViewObservable(),
    GameObserver()
{
    this->model = model;
//    this->running = true;
    this->counter = new SharedCounter();
    qDebug() << "initialized new GameConsoleView" << endl;
}

GameConsoleView::~GameConsoleView()
{
    delete counter;
    qDebug() << "~GameConsoleView() called" << endl;
}

void GameConsoleView::operator()()
{
    qDebug() << "started view" << endl;
    promise<void> exitSignal;
    future<void> futureObj = exitSignal.get_future();
    thread paintingThread(&GameConsoleView::repeatedPaint, std::move(futureObj), model, counter);
    stringstream sstr;
    string input;
    while (model->isProgramRunning())
    {
        getline(cin, input);
        notifyObservers(input);
        this_thread::sleep_for(chrono::milliseconds(2));
    }
    exitSignal.set_value();
    qDebug() << "wait for paining process to terminate" << endl;
    paintingThread.join();
    qDebug() << "terminated view" << endl;
}

void GameConsoleView::repeatedPaint(std::future<void> futureObj, Model* model, SharedCounter* counter)
{
    qDebug() << "started painting process" << endl;
    GameConsoleView::paint(model);
    while(futureObj.wait_for(chrono::milliseconds(1)) == future_status::timeout)
    {
        if(counter->isGreaterZero())
        {
            GameConsoleView::paint(model);
            counter->decrease();
        }
        this_thread::sleep_for(chrono::milliseconds(2));
    }
    qDebug() << "terminated paining process" << endl;
}

void GameConsoleView::paint(Model* model)
{
    stringstream sstr;
    if(model->isProgramRunning())
    {
        sstr << endl << "program status: running" << endl;
        Game* currentGame = model->getCurrentGame();
        if(currentGame == nullptr)
        {
            sstr << "game status: no game running" << endl;
        }
        else
        {
            sstr << "game status: game running" << endl;
            sstr << endl;
            sstr << "round cound: " << currentGame->getRoundCount() << endl;
            sstr << "current reward: " << currentGame->getCurReward() << endl;
            sstr << "game finished: " << currentGame->isFinished() << endl;
            if(!currentGame->isFinished())
            {
                Question* currentQuestion = currentGame->getCurQuestion();
                sstr << endl;
                sstr << "current question: " << currentQuestion->getQuestion() << endl;
                sstr << "answer 1: " << currentQuestion->getAnswerA()->getAnswer() << endl;
                sstr << "answer 2: " << currentQuestion->getAnswerB()->getAnswer() << endl;
                sstr << "answer 3: " << currentQuestion->getAnswerC()->getAnswer() << endl;
                sstr << "answer 4: " << currentQuestion->getAnswerD()->getAnswer() << endl;
            }
        }
    }
    else
    {
        sstr << "program status: quit program" << endl;
    }
    sstr << endl;
    sstr << "program options: " << endl;
    sstr << "exit program: " << model->EXIT_EXP << endl;
    sstr << "start new game: " << model->START_GAME_EXP << endl;
    sstr << "quit game: " << model->QUIT_GAME_EXP << endl;
    sstr << "... or type an answer" << endl;
    cout << sstr.str() << endl;
}

void GameConsoleView::update()
{
    qDebug() << "update called";
    counter->increase();
}

//void GameConsoleView::stop()
//{
//    qDebug() << "stop called";
//    running = false;
//}
