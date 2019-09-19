#ifndef VIEWOBSERVABLE_H
#define VIEWOBSERVABLE_H

#include <viewobserver.h>
#include <vector>

class ViewObservable
{

private:
    std::vector<ViewObserver> observers;

public:
    virtual ViewObservable();
    add(ViewObserver* observer);
    remove(ViewObserver* observer);
    notify();

};

#endif // VIEWOBSERVABLE_H
