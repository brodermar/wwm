#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ui_mainwindow.h"
#include <QString>
#include <QPushButton>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent, Model *model) :
    QMainWindow(parent),
    ViewObservable(),
    GameObserver(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->model = model;
    qDebug() << "initialized new MainWindow" << endl;
    ui->ButtonQuestion->setInteractiv(false);
    ui->ButtonSum->setInteractiv(false);
    ui->ButtonAnswerA->setLetter("A");
    ui->ButtonAnswerB->setLetter("B");
    ui->ButtonAnswerC->setLetter("C");
    ui->ButtonAnswerD->setLetter("D");
    ui->ButtonMenu->ButtonGold(true);
    connect(ui->ButtonAnswerA, SIGNAL(clicked()), this, SLOT(buttonClickedA()));
    connect(ui->ButtonAnswerB, SIGNAL(clicked()), this, SLOT(buttonClickedB()));
    connect(ui->ButtonAnswerC, SIGNAL(clicked()), this, SLOT(buttonClickedC()));
    connect(ui->ButtonAnswerD, SIGNAL(clicked()), this, SLOT(buttonClickedD()));
    connect(ui->ButtonMenu, SIGNAL(clicked()), this, SLOT(buttonClickedMenu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CommandParser(string command)
{
    if(command == "ShowMenuScreen")
    {
        ShowMenuScreen("Wer wird Millionär");
    }
    else if(command == "ShowQuestionScreen")
    {
        SetUpRound(command, command, command, command, command, command);
        ShowQuestionScreen();
    }
    else if(command.find("ShowRightAnswer") !=  std::string::npos)
    {
        cout << "hallo" << endl;
        ShowRightAnswer("b");
    }

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

void MainWindow::SetSum(string sum)
{
    ui->ButtonSum->setText(sum);
}

void MainWindow::SetUpRound(string a, string b, string c, string d, string question, string sum)
{
    SetAnswerA(a);
    ui->ButtonAnswerA->setTrigger();
    SetAnswerB(b);
    ui->ButtonAnswerB->setTrigger();
    SetAnswerC(c);
    ui->ButtonAnswerC->setTrigger();
    SetAnswerD(d);
    ui->ButtonAnswerD->setTrigger();
    SetQuestion(question);
    SetSum(sum);
}

void MainWindow::ShowMenuScreen(string text)
{
   ui->ButtonAnswerA->setVisible2(false);
   ui->ButtonAnswerB->setVisible2(false);
   ui->ButtonAnswerC->setVisible2(false);
   ui->ButtonAnswerD->setVisible2(false);
   ui->ButtonQuestion->setVisible2(false);
   ui->ButtonSum->setVisible2(false);
   ui->ButtonMenu->setVisible2(true);
   ui->ButtonMenu->setInteractiv(true);
   ui->ButtonMenu->setText(text);

}

void MainWindow::ShowQuestionScreen()
{
    ui->ButtonAnswerA->setVisible2(true);
    ui->ButtonAnswerB->setVisible2(true);
    ui->ButtonAnswerC->setVisible2(true);
    ui->ButtonAnswerD->setVisible2(true);
    ui->ButtonQuestion->setVisible2(true);
    ui->ButtonSum->setVisible2(true);

    ui->ButtonMenu->setVisible2(false);
}

void MainWindow::ShowRightAnswer(string answer)
{
    ui->ButtonAnswerA->setVisible2(true);
    ui->ButtonAnswerB->setVisible2(true);
    ui->ButtonAnswerC->setVisible2(true);
    ui->ButtonAnswerD->setVisible2(true);
    ui->ButtonQuestion->setVisible2(true);
    ui->ButtonSum->setVisible2(true);
    ui->ButtonMenu->setVisible2(false);

    ui->ButtonAnswerA->setInteractiv(false);
    ui->ButtonAnswerB->setInteractiv(false);
    ui->ButtonAnswerC->setInteractiv(false);
    ui->ButtonAnswerD->setInteractiv(false);
    ui->ButtonQuestion->setInteractiv(false);
    ui->ButtonSum->setInteractiv(false);
    ui->ButtonMenu->setInteractiv(false);

    delay(2000);
    GetButtonGreen(answer, true);
    delay(2000);
}

void MainWindow::GetButtonGreen(string answer, bool green)
{
    if(answer == "a")
    {
        if(green)
        {
            ui->ButtonAnswerA->goGreen();
        }
        else
        {
            ui->ButtonAnswerA->ButtonStatic(true);
        }
    }
    else if(answer == "b")
    {
        if(green)
        {
            ui->ButtonAnswerB->goGreen();
        }
        else
        {
            ui->ButtonAnswerB->ButtonStatic(true);
        }
    }
    else if(answer == "c")
    {
        if(green)
        {
            ui->ButtonAnswerC->goGreen();
        }
        else
        {
            ui->ButtonAnswerC->ButtonStatic(true);
        }
    }
    else if(answer == "d")
    {
        if(green)
        {
            ui->ButtonAnswerD->goGreen();
        }
        else
        {
            ui->ButtonAnswerD->ButtonStatic(true);
        }
    }
}

void MainWindow::buttonClickedA()
{
    notifyObservers("a");
}

void MainWindow::buttonClickedB()
{
     notifyObservers("b");
}

void MainWindow::buttonClickedC()
{
    notifyObservers("c");
}

void MainWindow::buttonClickedD()
{
    notifyObservers("d");
}

void MainWindow::buttonClickedMenu()
{
    notifyObservers("START_GAME_EXP");
}

void MainWindow::delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
        while (QTime::currentTime() < dieTime)
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
}

void MainWindow::update()
{
    if(model->getCurrentGame() != nullptr)
    {
        Question * p = model->getCurrentGame()->getCurQuestion();
        if(true) // anstatt true sollte hier am besten ein boolischer wert im Model sein der angibt ob die richtige antwort angezeigt werden kann.
        {
            ShowQuestionScreen();
            SetUpRound(p->getAnswerA()->getAnswer(), p->getAnswerB()->getAnswer(), p->getAnswerC()->getAnswer(), p->getAnswerD()->getAnswer(), p->getQuestion(), to_string(model->getCurrentGame()->getCurReward()));
        }
        else
        {
            ShowRightAnswer(p->getRightAnswer()->getAnswer());
        }
    }
    else
    {
        ShowMenuScreen(to_string(model->getCurrentGame()->getCurReward()));
    }

}
