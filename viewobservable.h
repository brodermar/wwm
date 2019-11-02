#ifndef VIEWOBSERVABLE_H
#define VIEWOBSERVABLE_H

#include <viewobserver.h>

#include <string>
#include <set>
#include <iterator>
#include <mutex>

#include <QDebug>
#include <QMessageLogContext>
#include <QString>

/**
 * @brief The ViewObservable class represents the subject side of the
 * observer pattern for view observers
 */
class ViewObservable
{

private:

    /**
     * @brief observers a set of view observers
     */
    std::set<ViewObserver*> observers;

    /**
     * @brief mutex to lock and unlock data of the object
     */
    std::mutex mutex;

public:

    /**
     * @brief ViewObservable constructs a new view observable
     */
    ViewObservable();

    ~ViewObservable();

    /**
     * @brief ViewObservable copies a view observable
     */
    ViewObservable(const ViewObservable &viewObservable);

    /**
     * @brief addObserver register a new observer, this means 
     * the observer will be added to the set of observers
     * @param observer a view observer
     */
    void addObserver(ViewObserver* observer);

    /**
     * @brief removeObserver unregister a observer, this means
     * the observer will be removed from the set of observers
     * if present
     * @param observer a view observer
     */
    void removeObserver(ViewObserver* observer);

    /**
     * @brief notifyObservers calls update(std::string message) 
     * on each registered observer
     * @param message a message string
     */
    void notifyObservers(std::string message);

};

#endif // VIEWOBSERVABLE_H
