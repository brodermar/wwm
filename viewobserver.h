#ifndef VIEWOBSERVER_H
#define VIEWOBSERVER_H

#include <answer.h>

class ViewObserver
{

public:
    virtual ViewObserver();
    virtual update(Answer* answer);

};

#endif // VIEWOBSERVER_H
