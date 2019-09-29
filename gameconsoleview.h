#ifndef GAMECONSOLEVIEW_H
#define GAMECONSOLEVIEW_H

#include <viewobservable.h>
#include <gameobserver.h>
#include <model.h>

#include <future>
#include <chrono>
#include <thread>
#include <iostream>

#include <QApplication>
#include <QWindow>
#include <QLabel>
#include <QTextEdit>

#include <windows.h>

class GameConsoleView : public ViewObservable, public GameObserver
{

private:
    Model* model;
    static void output(std::future<void> futureObj, unsigned int* updateCounter, int argc, char** argv);
    bool running;
    unsigned int updateCounter;

public:
    GameConsoleView(Model* model);
    ~GameConsoleView() override;
    void update() override;
    void operator()(int argc, char** argv);
    void stop();

};

#endif // GAMECONSOLEVIEW_H
