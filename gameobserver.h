#ifndef GAMEOBSERVER_H
#define GAMEOBSERVER_H


class GameObserver
{

public:
    GameObserver();
    virtual ~GameObserver();
    virtual void update();
};

#endif // GAMEOBSERVER_H
