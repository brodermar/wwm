#ifndef SHAREDQUEUE_H
#define SHAREDQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template<class T>
class SharedQueue
{

private:
    std::queue<T> queue;
    std::mutex mutex;

public:
    SharedQueue();
    ~SharedQueue();

    T& front();
    void pop();

    void push(const T& item);
    void push(T&& item);

    int size();
    bool empty();
};

#endif // SHAREDQUEUE_H
