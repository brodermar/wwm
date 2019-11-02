#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Model *model) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ViewObservable(),
    GameObserver()
{
    ui->setupUi(this);
    this->model = model;
    qDebug() << "initialized new MainWindow" << endl;
}

MainWindow::MainWindow(Model *model) :
    QMainWindow(0),
    ui(new Ui::MainWindow),
    ViewObservable(),
    GameObserver()
{
    ui->setupUi(this);
    this->model = model;
    qDebug() << "initialized new MainWindow" << endl;
}

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
