#ifndef GAMEOBSERVABLE_H
#define GAMEOBSERVABLE_H

#include <gameobserver.h>
#include <set>
#include <iterator>

#include <QDebug>
#include <QString>
#include <QMessageLogContext>

/**
 * @brief The GameObservable class
 */
class GameObservable
{

private:

    /**
     * @brief observers
     */
    std::set<GameObserver*>* observers;

public:

    /**
     * @brief GameObservable
     */
    GameObservable();

    ~GameObservable();

    /**
     * @brief addObserver
     * @param observer
     */
    void addObserver(GameObserver* observer);

    /**
     * @brief removeObserver
     * @param observer
     */
    void removeObserver(GameObserver* observer);

    /**
     * @brief notifyObservers
     */
    void notifyObservers();

};

#endif // GAMEOBSERVABLE_H
