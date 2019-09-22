#ifndef GAMECONSOLEVIEW_H
#define GAMECONSOLEVIEW_H

#include <viewobservable.h>
#include <gameobserver.h>
#include <model.h>

class GameConsoleView : public ViewObservable, public GameObserver
{

public:
    GameConsoleView(Model* model);
    ~GameConsoleView();
    void run();

};

#endif // GAMECONSOLEVIEW_H
