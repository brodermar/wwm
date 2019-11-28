#include "sharedcounter.h"

SharedCounter::SharedCounter(int value)
{
    counter = new int(value);
    qDebug() << "initialized new SharedCounter with value " << counter << endl;
}

SharedCounter::SharedCounter(const SharedCounter &sharedCounter)
{
    counter = sharedCounter.counter;
    qDebug() << "SharedCounter() copy called" << endl;

}

SharedCounter::~SharedCounter()
{
    delete counter;
    qDebug() << "~SharedCounter() called" << endl;
}

void SharedCounter::increase()
{
    qDebug() << "increase() called" << endl;
    mutex.lock();
    int oldVal = *counter;
    *counter = *counter + 1;
    int newVal = *counter;
    mutex.unlock();
    qDebug() << "increased counter from " << oldVal << " to " << newVal << endl;
}

bool SharedCounter::decrease()
{
    qDebug() << "decrease() called" << endl;
    bool val = false;
    mutex.lock();
    if(*counter > 0)
    {
        int oldVal = *counter;
        *counter = *counter - 1;
        int newVal = *counter;
        qDebug() << "decreased counter from " << oldVal << " to " << newVal << endl;
        val = true;
    }
    mutex.unlock();
    return val;
}

bool SharedCounter::isGreaterZero()
{
    bool val = false;
    mutex.lock();
    if(*counter > 0)
    {
        val = true;
    }
    mutex.unlock();
    return val;
}
