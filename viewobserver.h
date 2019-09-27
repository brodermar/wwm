#ifndef VIEWOBSERVER_H
#define VIEWOBSERVER_H

#include <answer.h>
#include <string>

class ViewObserver
{

public:
    virtual void update(std::string message);

};

#endif // VIEWOBSERVER_H
