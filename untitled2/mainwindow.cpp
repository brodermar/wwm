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
    ui->ButtonQuestion->setInteractiv(false);
    ui->ButtonSum->setInteractiv(false);
    ui->ButtonAnswerA->setLetter("A");
    ui->ButtonAnswerB->setLetter("B");
    ui->ButtonAnswerC->setLetter("C");
    ui->ButtonAnswerD->setLetter("D");
    ui->ButtonMenu->setText("Starte Spiel!");
    ui->ButtonMenu->setInteractiv(false);
    ui->ButtonMenu->ButtonGold(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CommandParser(string command)
{
    if(command == "MenuScreen")
    {
        ShowMenuScreen("Wer wird Millionär");
    }
    else if(command == "ShowQuestionScreen")
    {
        SetUpRound(command, command, command, command, command, command);
        ShowQuestionScreen();
    }
    else if(command == "ShowRightAnswerb")
    {
        ShowRightAnswer(to_string(command[command.length()-1]));
    }

}

void MainWindow::TellController(string content)
{
    //antwort
    if(content.length() == 1)
    {

    }
    //geh nach hause
    else
    {

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
    if(answer == "a")
    {
        ui->ButtonAnswerA->goGreen();
    }
    else if(answer == "b")
    {
        ui->ButtonAnswerB->goGreen();
    }
    else if(answer == "c")
    {
        ui->ButtonAnswerC->goGreen();
    }
    else if(answer == "d")
    {
        ui->ButtonAnswerD->goGreen();
    }
    else
    {
        ui->ButtonAnswerA->goGreen();
        ui->ButtonAnswerB->goGreen();
        ui->ButtonAnswerC->goGreen();
        ui->ButtonAnswerD->goGreen();
    }
}

void MainWindow::delay(int ms)
{
    QTime dieTime= QTime::currentTime().addMSecs(ms);
        while (QTime::currentTime() < dieTime)
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
}

void MainWindow::on_pushButton_clicked()
{

}
