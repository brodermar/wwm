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
 * @brief The GameConsoleView class
 */
class GameConsoleView : public ViewObservable, public GameObserver
{

private:

    /**
     * @brief model
     */
    Model* model;

    /**
     * @brief running
     */
    bool running;

    /**
     * @brief counter
     */
    SharedCounter* counter;

    /**
     * @brief repeatedPaint
     * @param futureObj
     * @param model
     * @param counter
     */
    static void repeatedPaint(std::future<void> futureObj, Model* model, SharedCounter* counter);

    /**
     * @brief paint
     * @param model
     */
    static void paint(Model* model);

public:

    /**
     * @brief GameConsoleView
     * @param model
     */
    GameConsoleView(Model* model);

    ~GameConsoleView() override;

    /**
     * @brief update
     */
    void update() override;

    /**
     * @brief operator ()
     */
    void operator()();

    /**
     * @brief stop
     */
    void stop();

};

#endif // GAMECONSOLEVIEW_H
