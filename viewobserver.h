#ifndef VIEWOBSERVER_H
#define VIEWOBSERVER_H

#include <answer.h>
#include <string>

#include <QDebug>
#include <QMessageLogContext>
#include <QString>

/**
 * @brief The ViewObserver class represents the observer side of the 
 * observer patter for view observers
 */
class ViewObserver
{

public:

    virtual ~ViewObserver(){}

    /**
     * @brief update will be called by a instance of GameObservable if
     * this observer is registered
     * @param message a message string
     */
    virtual void update(std::string message) = 0;

};

#endif // VIEWOBSERVER_H
