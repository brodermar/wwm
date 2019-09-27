#include <gamecontroller.h>
#include <model.h>
#include <gameconsoleview.h>
#include <thread>

int main(int argc, char** argv)
{
    Model* model = new Model();
    GameConsoleView* view = new GameConsoleView(model);
    GameController* controller = new GameController(model);

    view->addObserver(controller);
    model->addObserver(view);

//    std::thread thread_controller(controller);
//    std::thread thread_view(view);
//    thread_view.join();
}
