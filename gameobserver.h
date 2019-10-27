#ifndef GAMEOBSERVER_H
#define GAMEOBSERVER_H

/**
 * @brief The GameObserver class
 */
class GameObserver
{

public:

    virtual ~GameObserver(){}

    /**
     * @brief update
     */
    virtual void update() = 0;

};

#endif // GAMEOBSERVER_H
