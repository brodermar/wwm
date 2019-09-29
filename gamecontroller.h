#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <viewobserver.h>
#include <model.h>

#include <thread>
#include <iostream>
#include <queue>
#include <string>
#include <list>

class GameController : public ViewObserver
{

private:
    Model* model;
    std::queue<std::string, std::list<std::string>>* answers;
    bool running;

public:
    GameController(Model* model);
    ~GameController() override;
    void update(std::string message) override;
    void operator()();
    void stop();

};

#endif // GAMECONTROLLER_H
