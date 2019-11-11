#ifndef GAMEOBSERVER_H
#define GAMEOBSERVER_H

/**
 * @brief The GameObserver class represents the observer side of the 
 * observer patter for game observers
 */
class GameObserver
{

public:

    virtual ~GameObserver(){}

    /**
     * @brief update will be called by a instance of GameObservable if
     * this observer is registered
     */
    virtual void update() = 0;

};

#endif // GAMEOBSERVER_H
