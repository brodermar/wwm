#ifndef GAMEOBSERVABLE_H
#define GAMEOBSERVABLE_H

#include <gameobserver.h>

#include <set>
#include <iterator>
#include <mutex>

#include <QDebug>
#include <QString>
#include <QMessageLogContext>

/**
 * @brief The GameObservable class represents the subject side of the
 * observer pattern for game observers
 *
 * @author Mark Broderius
 */
class GameObservable
{

private:

    /**
     * @brief observers a set of game observer
     */
    std::set<GameObserver*> observers;

    /**
     * @brief mutex to lock and unlock data of the object
     */
    std::mutex mutex;

public:

    /**
     * @brief GameObservable constructs a new game observable
     */
    GameObservable();

    ~GameObservable();

    GameObservable(const GameObservable& gameObservable);

    /**
     * @brief addObserver register a new observer, this means 
     * the observer will be added to the set of observers
     * @param observer a game observer
     */
    void addObserver(GameObserver* observer);

    /**
     * @brief removeObserver unregister a observer, this means
     * the observer will be removed from the set of observers
     * if present
     * @param observer a game observer
     */
    void removeObserver(GameObserver* observer);

    /**
     * @brief notifyObservers calls update() on each registered 
     * observer
     */
    void notifyObservers();

};

#endif // GAMEOBSERVABLE_H
