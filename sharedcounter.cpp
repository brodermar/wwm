#include "sharedcounter.h"

SharedCounter::SharedCounter()
{
    counter = 0;
    qDebug() << "initialized new SharedCounter with value " << counter << endl;
}

SharedCounter::~SharedCounter()
{
    qDebug() << "~SharedCounter() called" << endl;
}

void SharedCounter::increase()
{
    qDebug() << "increase() called" << endl;
    mutex.lock();
    unsigned int oldVal = counter;
    unsigned int newVal = (counter++);
    mutex.unlock();
    qDebug() << "increased counter from " << oldVal << " to " << newVal << endl;
}

bool SharedCounter::decrease()
{
    qDebug() << "decrease() called" << endl;
    bool val = false;
    mutex.lock();
    if(counter > 0)
    {
        unsigned int oldVal = counter;
        unsigned int newVal = (counter--);
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
    if(counter > 0)
    {
        val = true;
    }
    mutex.unlock();
    return val;
}
