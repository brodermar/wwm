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
    std::queue<std::string, std::list<std::string>> answers;

public:
    GameController(Model* model);
    ~GameController() override;
    void operator()() const;
    void update(std::string message) override;

};

#endif // GAMECONTROLLER_H
