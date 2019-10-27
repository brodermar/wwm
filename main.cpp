#include <QApplication>
#include <QtGlobal>
#include <QLabel>
#include <QLineEdit>

#include <gamecontroller.h>
#include <model.h>
#include <gameconsoleview.h>

#include <thread>
#include <mutex>
#include <stdio.h>
#include <stdlib.h>

void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    std::mutex mutex;
    mutex.lock();
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    }
    mutex.unlock();
}

int main(int argc, char** argv)
{
    qInstallMessageHandler(customMessageHandler);
    QApplication app(argc, argv);

//    QLabel* textbox = new QLabel("");
//    textbox->resize(120, 100);
//    textbox->show();

    Model* model = new Model();
    GameConsoleView* view = new GameConsoleView(model);
    GameController* controller = new GameController(model);

    view->addObserver(controller);
    model->addObserver(view);

    std::thread thread_controller(*controller);
    std::thread thread_view(*view);
    thread_controller.join();
    thread_view.join();

    return app.exec();
}


