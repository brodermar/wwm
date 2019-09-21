#ifndef VIEWOBSERVABLE_H
#define VIEWOBSERVABLE_H

#include <viewobserver.h>
#include <vector>

class ViewObservable
{

private:
    std::vector<ViewObserver> observers;

public:
    ViewObservable();
    void add(ViewObserver* observer);
    void remove(ViewObserver* observer);
    void notify();

};

#endif // VIEWOBSERVABLE_H
