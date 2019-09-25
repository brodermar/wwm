#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <viewobserver.h>
#include <model.h>
#include <thread>
#include <iostream>

class GameController : public ViewObserver
{

private:
    Model* model;

public:
    GameController(Model* model);
    ~GameController();
    void operator()() const;

};

#endif // GAMECONTROLLER_H
