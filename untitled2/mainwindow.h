#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <string>
#include <question.h>
#include <QEvent>

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
    void delay(int ms);


    void CommandParser(string command);
    void TellController(string content);
private:
    string selcetedAnswer;
    string trueAnswer;
    void AnswerSelected();
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

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
