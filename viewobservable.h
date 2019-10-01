#ifndef VIEWOBSERVABLE_H
#define VIEWOBSERVABLE_H

#include <viewobserver.h>

#include <string>
#include <set>
#include <iterator>

#include <QDebug>
#include <QString>

class ViewObservable
{

private:
    std::set<ViewObserver*>* observers;

public:
    ViewObservable();
    ~ViewObservable();
    void addObserver(ViewObserver* observer);
    void removeObserver(ViewObserver* observer);
    void notifyObservers(std::string message);

};

#endif // VIEWOBSERVABLE_H
