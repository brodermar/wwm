#ifndef VIEWOBSERVABLE_H
#define VIEWOBSERVABLE_H

#include <viewobserver.h>
#include <set>
#include <iterator>

class ViewObservable
{

private:
    std::set<ViewObserver*>* observers;

public:
    ViewObservable();
    ~ViewObservable();
    void add(ViewObserver* observer);
    void remove(ViewObserver* observer);
    void notify(Answer* answer);

};

#endif // VIEWOBSERVABLE_H
