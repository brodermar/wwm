#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

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

/**
 * @brief The GameController class
 */
class GameController : public ViewObserver
{

private:

    /**
     * @brief model
     */
    Model* model;

    /**
     * @brief controlStatements
     */
    SharedQueue<std::string>* controlStatements;

    /**
     * @brief running
     */
    bool running;

public:

    /**
     * @brief GameController
     * @param model
     */
    GameController(Model* model);

    ~GameController() override;

    /**
     * @brief update
     * @param message
     */
    void update(std::string message) override;

    /**
     * @brief operator ()
     */
    void operator()();

    /**
     * @brief stop
     */
    void stop();

};

#endif // GAMECONTROLLER_H
