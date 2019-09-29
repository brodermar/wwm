#include "gameconsoleview.h"
using namespace std;

GameConsoleView::GameConsoleView(Model* model) : ViewObservable(), GameObserver()
{
    this->model = model;
    this->running = true;
    this->updateCounter = 3;
}

GameConsoleView::~GameConsoleView()
{

}

void GameConsoleView::operator()(int argc, char** argv)
{
    promise<void> exitSignal;
    future<void> futureObj = exitSignal.get_future();
    thread outputThread(&GameConsoleView::output, std::move(futureObj), &updateCounter, argc, argv);
    while (running)
    {
        cout << "View here" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    exitSignal.set_value();
    outputThread.join();
}

void GameConsoleView::output(future<void> futureObj, unsigned int* updateCounter, int argc, char** argv)
{
    QApplication app(argc, argv);

    QTextEdit* textbox = new QTextEdit("empty");
    textbox->resize(120, 100);
    textbox->show();

    while (futureObj.wait_for(chrono::milliseconds(1)) == future_status::timeout)
    {
        if(*updateCounter > 0)
        {
            QString string("View: output");
            textbox->setText(string);
            textbox->repaint();
            (*updateCounter)--;
        }
        this_thread::sleep_for(chrono::milliseconds(2000));
    }

    app.exec();
}

void GameConsoleView::update()
{

}

void GameConsoleView::stop()
{
    running = false;
}
