#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <iostream>

#include <viewobservable.h>
#include <gameobserver.h>
#include <sharedcounter.h>
#include <model.h>
#include <question.h>
#include <updateevent.h>

#include <QMainWindow>
#include <QDesktopWidget>
#include <QDebug>
#include <QString>
#include <QMessageLogContext>
#include <QTime>
#include <QPushButton>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow :
    public QMainWindow,
    public ViewObservable,
    public GameObserver
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent, Model* model);
    MainWindow(Model* model) : MainWindow(0, model) {}
    ~MainWindow() override;
    void update() override;
    void CommandParser(string command);
    void TellController(string content);

private slots:
    void buttonClickedA();
    void buttonClickedB();
    void buttonClickedC();
    void buttonClickedD();
    void buttonClickedMenu();

private:
    Ui::MainWindow* ui;
    Model* model;
    SharedCounter counter;
    string selcetedAnswer;
    string trueAnswer;
    void SetAnswerA(string answer);
    void SetAnswerB(string answer);
    void SetAnswerC(string answer);
    void SetAnswerD(string answer);
    void SetQuestion(string question);
    void SetSum(string sum);
    void SetUpRound(string a, string b, string c, string d, string question, string sum);
    void ShowRightAnswer(string answer);
    void ShowMenuScreen(string text);
    void ShowQuestionScreen();
    void defuseButtons();
    void GetButtonGreen(string answer, bool green);
    void delay(int ms);
    void onUpdateEvent(UpdateEvent* event);

};
#endif // MAINWINDOW_H
