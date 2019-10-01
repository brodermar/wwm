#include "sharedqueue.h"

template<class T>
SharedQueue<T>::SharedQueue()
{
    queue();
}

template<class T>
SharedQueue<T>::~SharedQueue()
{

}

template <class T>
T& SharedQueue<T>::front()
{
    T& elem = nullptr;
    mutex.lock();
//    std::unique_lock<std::mutex> mlock(mutex);
    if(!queue.empty())
    {
        elem = queue.front();
    }
    mutex.unlock();
    return elem;
}

template <class T>
void SharedQueue<T>::pop()
{
//    std::unique_lock<std::mutex> mlock(mutex);
    mutex.lock();
    if (!queue.empty())
    {
        queue.pop();
    }
    mutex.unlock();
}

template <class T>
void SharedQueue<T>::push(const T& item)
{
    mutex.lock();
    queue.push(item);
    mutex.unlock();
//    std::unique_lock<std::mutex> mlock(mutex);
//    queue.push_back(item);
//    mlock.unlock();     // unlock before notificiation to minimize mutex con
//    cond_.notify_one(); // notify one waiting thread
}

template <class T>
void SharedQueue<T>::push(T&& item)
{
    mutex.lock();
    queue.push(item);
    mutex.unlock();
//    std::unique_lock<std::mutex> mlock(mutex);
//    queue.push_back(std::move(item));
//    mlock.unlock();     // unlock before notificiation to minimize mutex con
//    cond_.notify_one(); // notify one waiting thread
}

template <class T>
int SharedQueue<T>::size()
{
    mutex.lock();
//    std::unique_lock<std::mutex> mlock(mutex);
    int size = queue.size();
    mutex.unlock();
//    mlock.unlock();
    return size;
}

template <class T>
bool SharedQueue<T>::empty()
{
    mutex.lock();
    bool empty = queue.empty();
    mutex.unlock();
    return empty;
}
