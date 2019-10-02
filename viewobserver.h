#ifndef VIEWOBSERVER_H
#define VIEWOBSERVER_H

#pragma once

#include <answer.h>
#include <string>

#include <QDebug>
#include <QString>

class ViewObserver
{

public:
    virtual ~ViewObserver(){}
    virtual void update(std::string message) = 0;

};

#endif // VIEWOBSERVER_H
