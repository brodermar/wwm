#ifndef GAMECONSOLEVIEW_H
#define GAMECONSOLEVIEW_H

#pragma once

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

class GameConsoleView : public ViewObservable, public GameObserver
{

private:
    Model* model;
    bool running;
    SharedCounter* counter;

    static void repeatedPaint(std::future<void> futureObj, Model* model, SharedCounter* counter);
    static void paint(Model* model);

public:
    GameConsoleView(Model* model);
    ~GameConsoleView() override;
    void update() override;
    void operator()();
    void stop();

};

#endif // GAMECONSOLEVIEW_H
