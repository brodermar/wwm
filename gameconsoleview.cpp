#include "gameconsoleview.h"
using namespace std;

GameConsoleView::GameConsoleView(Model* model) : ViewObservable(), GameObserver()
{
    this->model = model;
    this->running = true;
}

GameConsoleView::~GameConsoleView()
{

}

void GameConsoleView::operator()()
{
    promise<void> exitSignal;
    future<void> futureObj = exitSignal.get_future();
    thread outputThread(&GameConsoleView::output, std::move(futureObj));
    while (running)
    {
        cout << "View here" << endl;
        this_thread::sleep_for(chrono::milliseconds(2));
    }
    exitSignal.set_value();
    outputThread.join();
}

void GameConsoleView::output(future<void> futureObj)
{
    while (futureObj.wait_for(chrono::milliseconds(1)) == future_status::timeout)
    {
        cout << "View: printed output" << endl;
        this_thread::sleep_for(chrono::milliseconds(2));
    }
}

void GameConsoleView::update()
{

}

void GameConsoleView::stop()
{
    running = false;
}
