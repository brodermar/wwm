#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <viewobserver.h>
#include <model.h>

class GameController : public ViewObserver
{

private:
    Model* model;

public:
    GameController(Model* model);
    void run();

};

#endif // GAMECONTROLLER_H
