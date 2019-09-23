#ifndef GAMECONSOLEVIEW_H
#define GAMECONSOLEVIEW_H

#include <viewobservable.h>
#include <gameobserver.h>
#include <model.h>
#include <thread>
#include <iostream>

class GameConsoleView : public ViewObservable, public GameObserver
{

private:
    Model* model;

public:
    GameConsoleView(Model* model);
    ~GameConsoleView();
    void operator()() const;

};

#endif // GAMECONSOLEVIEW_H
