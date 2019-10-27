#ifndef VIEWOBSERVABLE_H
#define VIEWOBSERVABLE_H

#include <viewobserver.h>

#include <string>
#include <set>
#include <iterator>

#include <QDebug>
#include <QMessageLogContext>
#include <QString>

/**
 * @brief The ViewObservable class
 */
class ViewObservable
{

private:

    /**
     * @brief observers
     */
    std::set<ViewObserver*>* observers;

public:

    /**
     * @brief ViewObservable
     */
    ViewObservable();

    ~ViewObservable();

    /**
     * @brief addObserver
     * @param observer
     */
    void addObserver(ViewObserver* observer);

    /**
     * @brief removeObserver
     * @param observer
     */
    void removeObserver(ViewObserver* observer);

    /**
     * @brief notifyObservers
     * @param message
     */
    void notifyObservers(std::string message);

};

#endif // VIEWOBSERVABLE_H
