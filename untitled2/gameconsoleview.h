#ifndef GAMECONSOLEVIEW_H
#define GAMECONSOLEVIEW_H

#include <viewobservable.h>
#include <gameobserver.h>
#include <model.h>
#include <question.h>
#include <sharedcounter.h>

#include <future>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <sstream>

#include <QApplication>
#include <QWindow>
#include <QLabel>
#include <QTextEdit>
#include <QDebug>
#include <QString>
#include <QMessageLogContext>

#include <windows.h>

/**
 * @brief The GameConsoleView class represents a simple console view
 * view for the program.
 *
 * GameConsoleView works as an executeable and therefore it overrides
 * operator()(). Start it as a thread! Please note, that the view runs
 * with two threads, one as an encapsulated inner one.
 */
class GameConsoleView : public ViewObservable, public GameObserver
{

private:

    /**
     * @brief model the underlaying data model for the view
     */
    Model* model;

    /**
     * @brief running true, if the view is running, false else
     */
    //bool running;

    /**
     * @brief counter a threadsafe counter to count the calls of
     * the update() method
     */
    SharedCounter* counter;

    /**
     * @brief repeatedPaint repeated calls paint() for the model
     * 
     * The method is executed as long as the the method get_future()
     * on futureObj isn't called. paint() is only called if the 
     * value of the counter is larger than zero. The method will
     * decrease the counter for every paint.
     * 
     * @param futureObj a future object
     * @param model the data model
     * @param counter the counter
     */
    static void repeatedPaint(std::future<void> futureObj, Model* model, SharedCounter* counter);

    /**
     * @brief paint paints the data of the model to std::out
     * @param model the data model
     */
    static void paint(Model* model);

public:

    /**
     * @brief GameConsoleView constructs a new view referring to 
     * a model
     * @param model a data model
     */
    GameConsoleView(Model* model);

    ~GameConsoleView() override;

    /**
     * @brief update increases the shared counter of the view
     */
    void update() override;

    /**
     * @brief operator() defines the thread behaviour of the main
     * thread of the view
     */
    void operator()();

    /**
     * @brief stop stops the view thread (operator()() function)
     */
    //void stop();

};

#endif // GAMECONSOLEVIEW_H
