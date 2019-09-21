#ifndef VIEWOBSERVER_H
#define VIEWOBSERVER_H

#include <answer.h>

class ViewObserver
{

public:
    ViewObserver();
    virtual ~ViewObserver();
    virtual void update(Answer* answer);

};

#endif // VIEWOBSERVER_H
