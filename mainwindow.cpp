#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent, Model *model) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ViewObservable(),
    GameObserver()
{
    ui->setupUi(this);
    this->model = model;
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
    qDebug() << "initialized new MainWindow" << endl;
}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow() called" << endl;
    delete ui;
}

void MainWindow::CommandParser(string command)
{
    qDebug() << "CommandParser() called" << endl;
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
    qDebug() << "SetAnswerA() called" << endl;
    ui->ButtonAnswerA->setText(answer);
}

void MainWindow::SetAnswerB(string answer)
{
    qDebug() << "SetAnswerB() called" << endl;
    ui->ButtonAnswerB->setText(answer);
}

void MainWindow::SetAnswerC(string answer)
{
    qDebug() << "SetAnswerC() called" << endl;
    ui->ButtonAnswerC->setText(answer);
}

void MainWindow::SetAnswerD(string answer)
{
    qDebug() << "SetAnswerD() called" << endl;
    ui->ButtonAnswerD->setText(answer);
}

void MainWindow::SetQuestion(string question)
{
    qDebug() << "SetQuestion() called" << endl;
    ui->ButtonQuestion->setText(question);
}

void MainWindow::SetSum(string sum)
{
    qDebug() << "SetSum() called" << endl;
    ui->ButtonSum->setText(sum);
}

void MainWindow::SetUpRound(string a, string b, string c, string d, string question, string sum)
{
    qDebug() << "SetUpRound() called" << endl;
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
    qDebug() << "ShowMenuScreen() called" << endl;
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
    qDebug() << "ShowQuestionScreen() called" << endl;

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
    qDebug() << "ShowRightAnswer() called" << endl;

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
    qDebug() << "GetButtonGreen() called" << endl;
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
    qDebug() << "buttonClickedA() called" << endl;
    notifyObservers(model->getCurrentGame()->getCurQuestion()->getAnswerA()->getAnswer());
}

void MainWindow::buttonClickedB()
{
    qDebug() << "buttonClickedB() called" << endl;
    notifyObservers(model->getCurrentGame()->getCurQuestion()->getAnswerB()->getAnswer());
}

void MainWindow::buttonClickedC()
{
    qDebug() << "buttonClickedC() called" << endl;
    notifyObservers(model->getCurrentGame()->getCurQuestion()->getAnswerC()->getAnswer());
}

void MainWindow::buttonClickedD()
{
    qDebug() << "buttonClickedD() called" << endl;
    notifyObservers(model->getCurrentGame()->getCurQuestion()->getAnswerD()->getAnswer());
}

void MainWindow::buttonClickedMenu()
{
    qDebug() << "buttonClickedMenu() called" << endl;
    notifyObservers(model->START_GAME_EXP);
}

void MainWindow::delay(int ms)
{
    qDebug() << "delay(int) called" << endl;
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::update()
{
    qDebug() << "update() called" << endl;
    QCoreApplication::postEvent(this, new UpdateEvent());
    qDebug() << "posted event" << endl;

//    if(model->isProgramRunning())
//    {
//        qDebug() << "program status: running" << endl;
//        Game* currentGame = model->getCurrentGame();
//        if(currentGame == nullptr)
//        {
//            ShowMenuScreen("start new game");
//        }
//        else
//        {
//            if(!currentGame->isFinished())
//            {
//                Question* currentQuestion = currentGame->getCurQuestion();
//                ShowQuestionScreen();
//                SetUpRound(currentQuestion->getAnswerA()->getAnswer(),
//                           currentQuestion->getAnswerB()->getAnswer(),
//                           currentQuestion->getAnswerC()->getAnswer(),
//                           currentQuestion->getAnswerD()->getAnswer(),
//                           currentQuestion->getQuestion(),
//                           to_string(model->getCurrentGame()->getCurReward()));
//            } else {
//                ShowMenuScreen(to_string(model->getCurrentGame()->getCurReward()));
//            }
//        }
//    }
//    else
//    {
//        qDebug() << "program status: exit program" << endl;
//    }
//    if(model->getCurrentGame() != nullptr)
//    {
//        qDebug() << "1" << endl;
//        Question * p = model->getCurrentGame()->getCurQuestion();
//        if(true) // anstatt true sollte hier am besten ein boolischer wert im Model sein der angibt ob die richtige antwort angezeigt werden kann.
//        {
//            qDebug() << "2" << endl;
//           ShowQuestionScreen();
//            SetUpRound(p->getAnswerA()->getAnswer(), p->getAnswerB()->getAnswer(), p->getAnswerC()->getAnswer(), p->getAnswerD()->getAnswer(), p->getQuestion(), to_string(model->getCurrentGame()->getCurReward()));
//       }
//        else
//        {
//            qDebug() << "3" << endl;
//            ShowRightAnswer(p->getRightAnswer()->getAnswer());
//       }
//    }
//    else
//    {
//        qDebug() << "4" << endl;
//        ShowMenuScreen(to_string(model->getCurrentGame()->getCurReward()));
//    }

}

void MainWindow::onUpdateEvent(UpdateEvent* event)
{
    qDebug() << "onUpdateEvent() called" << endl;
}
