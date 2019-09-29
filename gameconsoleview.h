#ifndef GAMECONSOLEVIEW_H
#define GAMECONSOLEVIEW_H

#include <viewobservable.h>
#include <gameobserver.h>
#include <model.h>

#include <future>
#include <chrono>
#include <thread>
#include <iostream>

#include <windows.h>

class GameConsoleView : public ViewObservable, public GameObserver
{

private:
    Model* model;
    static void output(std::future<void> futureObj);
    bool running;

public:
    GameConsoleView(Model* model);
    ~GameConsoleView() override;
    void update() override;
    void operator()();
    void stop();

};

#endif // GAMECONSOLEVIEW_H
