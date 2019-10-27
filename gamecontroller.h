#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#pragma once

#include <viewobserver.h>
#include <model.h>
#include <sharedqueue.h>

#include <thread>
#include <iostream>
#include <queue>
#include <string>
#include <list>

#include <QDebug>
#include <QString>
#include <QMessageLogContext>

class GameController : public ViewObserver
{

private:
    Model* model;
    SharedQueue<std::string>* controlStatements;
//    std::queue<std::string, std::list<std::string>>* answers;
    bool running;

public:
    GameController(Model* model);
    ~GameController() override;
    void update(std::string message) override;
    void operator()();
    void stop();

};

#endif // GAMECONTROLLER_H
