#ifndef GAMECONSOLEVIEW_H
#define GAMECONSOLEVIEW_H

#include <viewobservable.h>
#include <gameobserver.h>
#include <model.h>
#include <question.h>

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

#include <windows.h>

class GameConsoleView : public ViewObservable, public GameObserver
{

private:
    Model* model;
    static void repeatedPaint(std::future<void> futureObj, Model* model, unsigned int* updateCounter);
    static void paint(Model* model);
    bool running;
    unsigned int updateCounter;

public:
    GameConsoleView(Model* model);
    ~GameConsoleView() override;
    void update() override;
    void operator()();
    void stop();

};

#endif // GAMECONSOLEVIEW_H
