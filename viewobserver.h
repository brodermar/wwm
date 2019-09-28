#ifndef VIEWOBSERVER_H
#define VIEWOBSERVER_H

#include <answer.h>
#include <string>

class ViewObserver
{

public:
    virtual ~ViewObserver();
    virtual void update(std::string message) = 0;

};

#endif // VIEWOBSERVER_H
