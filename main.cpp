#include <gamecontroller.h>
#include <model.h>
#include <gameconsoleview.h>

int main(int argc, char** argv)
{
    Model* model = new Model();
    GameConsoleView* view = new GameConsoleView();
    GameController* controller = new GameController();

    view->add(controller);
    model->add(view);
}
