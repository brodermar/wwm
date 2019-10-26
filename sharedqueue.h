#ifndef SHAREDQUEUE_H
#define SHAREDQUEUE_H

#pragma once

#include <queue>
#include <mutex>

#include <QDebug>

template<typename T>
class SharedQueue
{

private:
    std::queue<T>* queue;
    std::mutex mutex;

public:

    SharedQueue()
    {
        this->queue = new std::queue<T>();
    }

    ~SharedQueue()
    {
        delete queue;
    }

    T& front()
    {
        qDebug() << "front called()" << endl;
        T emptyVal = NULL;
        T& elem = emptyVal;
        mutex.lock();
        if(!queue->empty())
        {
            elem = queue->front();
        }
        mutex.unlock();
        return elem;
    }

    void pop()
    {
        qDebug() << "pop() called" << endl;
        mutex.lock();
        if (!queue->empty())
        {
            queue->pop();
        }
        mutex.unlock();
    }

    void push(const T& item)
    {
        qDebug() << "push() called" << endl;
        mutex.lock();
        queue->push(item);
        mutex.unlock();
    }

    void push(T&& item)
    {
        qDebug() << "push() called" << endl;
        mutex.lock();
        this->queue.push(item);
        mutex.unlock();
    }

    int size()
    {
        qDebug() << "size() called" << endl;
        mutex.lock();
        int size = this->queue.size();
        mutex.unlock();
        return size;
    }

    bool empty()
    {
        // qDebug() << "emtpy() called" << endl;
        mutex.lock();
        bool empty = queue->empty();
        mutex.unlock();
        return empty;
    }

};

#endif // SHAREDQUEUE_H
