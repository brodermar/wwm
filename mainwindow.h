#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <viewobservable.h>
#include <gameobserver.h>
#include <sharedcounter.h>
#include <model.h>

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QMessageLogContext>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public ViewObservable, public GameObserver
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent, Model* model);
    MainWindow(Model* model);
    ~MainWindow() override;
    void update() override;

private:
    Ui::MainWindow* ui;
    Model* model;
    SharedCounter counter;

};

#endif // MAINWINDOW_H
