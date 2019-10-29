#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <string>
#include <question.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUpRound(Question q);
    void delay(int ms);
    Question getQuestion();

    void roundLoop();
    void checkAnswer();

private:
    int round;
    int Rounds[15];
    string selcetedAnswer;
    string trueAnswer;

    void SetAnswerA(string answer);
    void SetAnswerB(string answer);
    void SetAnswerC(string answer);
    void SetAnswerD(string answer);
    void SetQuestion(string question);
    void SetSum(int sum);

    void gameLoss();
    void gameWin();

    void defuseButtons();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
