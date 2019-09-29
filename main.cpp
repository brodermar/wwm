#include <QApplication>
#include <QLabel>
#include <QLineEdit>

#include <gamecontroller.h>
#include <model.h>
#include <gameconsoleview.h>

#include <thread>

int main(int argc, char** argv)
{
//    QApplication app(argc, argv);

//    QLabel* textbox = new QLabel("");
//    textbox->resize(120, 100);
//    textbox->show();

    Model* model = new Model();
    GameConsoleView* view = new GameConsoleView(model);
    GameController* controller = new GameController(model);

    view->addObserver(controller);
    model->addObserver(view);

    std::thread thread_controller(*controller);
    std::thread thread_view(*view, argc, argv);
    thread_controller.join();
    view->stop();
    thread_view.join();

//    return app.exec();
}
