#ifndef VIEWOBSERVER_H
#define VIEWOBSERVER_H

#include <answer.h>
#include <string>

#include <QDebug>
#include <QMessageLogContext>
#include <QString>

/**
 * @brief The ViewObserver class
 */
class ViewObserver
{

public:

    virtual ~ViewObserver(){}

    /**
     * @brief update
     * @param message
     */
    virtual void update(std::string message) = 0;

};

#endif // VIEWOBSERVER_H
