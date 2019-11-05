#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QPushButton>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("{background-image: url(:C:\Qt\Resouces)";);
    ui->ButtonQuestion->setInteractiv(false);
    ui->ButtonSum->setInteractiv(false);

    round = 0;
    trueAnswer = "0";
    Rounds[0] = 50;
    Rounds[1] = 100;
    Rounds[2] = 200;
    Rounds[3] = 300;
    Rounds[4] = 500;
    Rounds[5] = 1000;
    Rounds[6] = 2000;
    Rounds[7] = 4000;
    Rounds[8] = 8000;
    Rounds[9] = 16000;
    Rounds[10] = 32000;
    Rounds[11] = 64000;
    Rounds[12] = 125000;
    Rounds[13] = 500000;
    Rounds[14] = 1000000;

    ui->ButtonAnswerA->setLetter("A");
    ui->ButtonAnswerB->setLetter("B");
    ui->ButtonAnswerC->setLetter("C");
    ui->ButtonAnswerD->setLetter("D");
}

void MainWindow::SetAnswerA(string answer)
{
    ui->ButtonAnswerA->setText(answer);
}

void MainWindow::SetAnswerB(string answer)
{
     ui->ButtonAnswerB->setText(answer);
}

void MainWindow::SetAnswerC(string answer)
{
     ui->ButtonAnswerC->setText(answer);
}

void MainWindow::SetAnswerD(string answer)
{
     ui->ButtonAnswerD->setText(answer);
}

void MainWindow::SetQuestion(string question)
{
    ui->ButtonQuestion->setText(question);
}

void MainWindow::SetSum(int sum)
{
    ui->ButtonSum->setText(to_string(sum));
}

void MainWindow::setUpRound(Question q)
{
    SetAnswerA(q.answerA);
    ui->ButtonAnswerA->setTrigger();
    SetAnswerB(q.answerB);
    ui->ButtonAnswerB->setTrigger();
    SetAnswerC(q.answerC);
    ui->ButtonAnswerC->setTrigger();
    SetAnswerD(q.answerD);
    ui->ButtonAnswerD->setTrigger();
    SetQuestion(q.question);
    trueAnswer = q.answerTrue;
    selcetedAnswer = "n";
    SetSum(Rounds[round]);
    round++;
}

void MainWindow::delay(int ms)
{
QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::defuseButtons()
{
    ui->ButtonAnswerA->setInteractiv(false);
    ui->ButtonAnswerB->setInteractiv(false);
    ui->ButtonAnswerC->setInteractiv(false);
    ui->ButtonAnswerD->setInteractiv(false);
}

void MainWindow::roundLoop()
{
    setUpRound(getQuestion());

    while(selcetedAnswer == "n")
    {
        checkAnswer();
        delay(20);
    }
    defuseButtons();
    delay(2000);
        if(trueAnswer == "A")
        {
            ui->ButtonAnswerA->goGreen();
        }
        else if(trueAnswer == "B")
        {
            ui->ButtonAnswerB->goGreen();
        }
        else if(trueAnswer == "C")
        {
            ui->ButtonAnswerC->goGreen();
        }
        else if(trueAnswer == "D")
        {
            ui->ButtonAnswerD->goGreen();
        }
             delay(2000);
        if(trueAnswer != selcetedAnswer)
        {
            //gameLoss();
        }
        else
        {
            setUpRound(getQuestion());
        }
}

void MainWindow::checkAnswer()
{
    if(ui->ButtonAnswerA->IsSelected() != "n")
    {
         selcetedAnswer = ui->ButtonAnswerA->IsSelected();
    }
    else if(ui->ButtonAnswerB->IsSelected() != "n")
    {
        selcetedAnswer = ui->ButtonAnswerB->IsSelected();
    }
    else if(ui->ButtonAnswerC->IsSelected() != "n")
    {
        selcetedAnswer = ui->ButtonAnswerC->IsSelected();
    }
    else if(ui->ButtonAnswerD->IsSelected() != "n")
    {
        selcetedAnswer = ui->ButtonAnswerD->IsSelected();
    }
    return;
}

MainWindow::~MainWindow()
{
    delete ui;
}

Question MainWindow::getQuestion()
{
    Question p;
    p.answerA = "Gurke";
    p.answerB = "Mein Penis";
    p.answerC = "Banane";
    p.answerD = "Deine Nase";
    p.question = "Was ist krum und Gelb?";
    p.answerTrue = "C";
    return p;
}
