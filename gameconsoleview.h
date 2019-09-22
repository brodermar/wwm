#ifndef GAMECONSOLEVIEW_H
#define GAMECONSOLEVIEW_H

#include <viewobservable.h>
#include <gameobserver.h>

class GameConsoleView : public ViewObservable, public GameObserver
{

public:
    GameConsoleView();
    ~GameConsoleView();

};

#endif // GAMECONSOLEVIEW_H
