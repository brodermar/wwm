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
#include <mutex>
#include <future>
#include <chrono>

#include <QDebug>
#include <QString>
#include <QMessageLogContext>

/**
 * @brief The GameController class manages the command coming from
 * the view and manipulates the model if possible and necessary. 
 *
 * The controller with the model together defines the game logic and
 * works as an executeable. It therefore overrides operator()(). Start
 * it as a thread!.
 */
class GameController : public ViewObserver
{

private:

    /**
     * @brief model the underlaing model of the controller
     */
    Model* model;

    /**
     * @brief controlStatements a queue of control statements, added
     * by the update(std::string) function.
     */
    SharedQueue<std::string>* controlStatements;

    /**
     * @brief running true, if the controller is running, false else
     */
//    bool running;

//    std::promise<void> exitSignal;

public:

    /**
     * @brief GameController constructs a new controller referring to a model
     * @param model a data model
     */
    GameController(Model* model);

    ~GameController() override;

    GameController(const GameController& gameController);

    /**
     * @brief update add the string to the shared queue of control statements
     * to be evaluated later
     * @param message a control statement, defined in the data model
     */
    void update(std::string message) override;

    /**
     * @brief operator() defines the thread behaviour of the controller
     */
    void operator()();

    /**
     * @brief stop stops the controller thread (operator()() function)
     */
//    void stop();

};

#endif // GAMECONTROLLER_H
