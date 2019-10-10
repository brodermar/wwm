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
    SharedQueue<T>();
    ~SharedQueue<T>();

    T& front();
    void pop();

    void push(const T& item);
    void push(T&& item);

    int size();
    bool empty();
};

#include "sharedqueue.tpp"

#endif // SHAREDQUEUE_H
