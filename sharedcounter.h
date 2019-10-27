#ifndef SHAREDCOUNTER_H
#define SHAREDCOUNTER_H

#include <mutex>

#include <QDebug>
#include <QString>
#include <QMessageLogContext>

class SharedCounter
{

private:
    unsigned int counter;
    std::mutex mutex;

public:
    SharedCounter();
    ~SharedCounter();

    void increase();
    bool decrease();
    bool isGreaterZero();

};

#endif // SHAREDCOUNTER_H
