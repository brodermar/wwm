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
#include <iostream>
#include <stdlib.h>
#include <windows.h>

/**
 * @brief customMessageHandler defines a custom message handler to format qt messages and
 * redirect them to stderr.
 *
 * The message handler have to be installed by calling qInstallMessageHandler(customMessageHandler)
 * even before the actual qt application. At the same time it is not necessary at all to run a
 * qt application. The message handler still works without.
 *
 * You access the handler automatically by using the qt logging methods linke qDebug().
 *
 * @param type a QtMsgType
 * @param context the qt message log context; include <QMessageLogContext> header in the classes
 *        you need information about
 * @param msg a QString message
 */
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

/**
 * @brief main runs the application
 * @param argc the command line argument count
 * @param argv the command line arguments
 * @return the exit status of the application
 */
int main(int argc, char** argv)
{
    qDebug() << "started program" << endl;

    qInstallMessageHandler(customMessageHandler);
    qDebug() << "installed message handler" << endl;

    Model* model = new Model();
    qDebug() << "intialized game model" << endl;
    GameConsoleView* view = new GameConsoleView(model);
    qDebug() << "initialized game view" << endl;
    GameController* controller = new GameController(model);
    qDebug() << "initialized controller" << endl;

    view->addObserver(controller);
    model->addObserver(view);

    std::thread thread_controller(*controller);
    std::thread thread_view(*view);

    thread_controller.join();
    qDebug() << "joined controller" << endl;

    thread_view.join();
    qDebug() << "joined view" << endl;

    qDebug() << "program terminated" << endl;
    return 0;
}


