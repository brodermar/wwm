#ifndef GAMECONSOLEVIEW_H
#define GAMECONSOLEVIEW_H

#include <viewobservable.h>
#include <gameobserver.h>
#include <model.h>
#include <thread>
#include <iostream>
#include <windows.h>

class GameConsoleView : public ViewObservable, public GameObserver
{

private:
    Model* model;
    void output();

public:
    GameConsoleView(Model* model);
    ~GameConsoleView() override;
    void operator()() const;
    void update() override;
    void operator()();

};

#endif // GAMECONSOLEVIEW_H
