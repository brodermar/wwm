#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Model *model) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ViewObservable(),
    GameObserver()
{
    ui->setupUi(this);
    this->setFixedSize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    QPixmap background(":/resources/background.jpg");
    if(background.isNull())
    {
        qWarning() << "background pixmap is null" << endl;
    }
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
    QPixmap logoPixmap = QPixmap(":/resources/logo.jpg");
    if(logoPixmap.isNull())
    {
        qWarning() << "logo pixmap is null" << endl;
    }
    ui->logo->setPixmap(logoPixmap);
    ui->logo->show();
    this->model = model;
    qDebug() << "initialized new MainWindow" << endl;
}

//MainWindow::MainWindow(Model *model) : MainWindow(0, model)
//    QMainWindow(0),
//    ui(new Ui::MainWindow),
//    ViewObservable(),
//    GameObserver()
//{
//    ui->setupUi(this);
//    this->setFixedSize(QDesktopWidget().availableGeometry(this).size() * 0.7);
//    QPixmap background(":/resources/background.jpg");
//    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
//    QPalette palette;
//    palette.setBrush(QPalette::Background, background);
//    this->setPalette(palette);
//    QPixmap logoPixmap = QPixmap(":/resources/logo.jpg");
//    if(logoPixmap.isNull())
//    {
//        qWarning() << "logo pixmap is null" << endl;
//   }
//    ui->logo->setPixmap(logoPixmap);
//    ui->logo->show();
//    this->model = model;
//    qDebug() << "initialized new MainWindow" << endl;
//}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow() called" << endl;
    delete ui;
}

void MainWindow::update()
{
    qDebug() << "update() called" << endl;
    counter.increase();
}
