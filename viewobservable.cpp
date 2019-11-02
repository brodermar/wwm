#include "viewobservable.h"

ViewObservable::ViewObservable()
{
    observers = std::set<ViewObserver*>();
    qDebug() << "initialized new ViewObservable" << endl;
}

ViewObservable::~ViewObservable()
{
    qDebug() << "~ViewObservable() called" << endl;
}

ViewObservable::ViewObservable(const ViewObservable& viewObservable)
{
    observers = viewObservable.observers;
}

void ViewObservable::addObserver(ViewObserver* observer)
{
    mutex.lock();
    observers.insert(observer);
    mutex.unlock();
    qDebug() << "added observer" << endl;
}

void ViewObservable::removeObserver(ViewObserver* observer)
{
    mutex.lock();
    observers.erase(observer);
    mutex.unlock();
    qDebug() << "erased observer" << endl;
}

void ViewObservable::notifyObservers(std::string message)
{
    qDebug() << "notify called with message: " << QString::fromStdString(message);
    mutex.lock();
    for(std::set<ViewObserver*>::iterator it = observers.begin(); it != observers.end(); ++it)
    {
        (*it)->update(message);
    }
    mutex.unlock();
}
