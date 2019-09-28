#ifndef GAMEOBSERVER_H
#define GAMEOBSERVER_H


class GameObserver
{

public:
    virtual ~GameObserver(){}
    virtual void update() = 0;

};

#endif // GAMEOBSERVER_H
