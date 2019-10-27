#include "sharedcounter.h"

SharedCounter::SharedCounter()
{
    counter = 0;
    qDebug() << "initialized counter: " << counter << endl;
}

SharedCounter::~SharedCounter()
{

}

void SharedCounter::increase()
{
    mutex.lock();
    counter++;
    qDebug() << "increased counter: " << counter << endl;
    mutex.unlock();
}

bool SharedCounter::decrease()
{
    bool val = false;
    mutex.lock();
    if(counter > 0)
    {
        counter--;
        qDebug() << "decreased counter: " << counter << endl;
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
