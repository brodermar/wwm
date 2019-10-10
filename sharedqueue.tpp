//#include "sharedqueue.h"

template<typename T>
SharedQueue<T>::SharedQueue()
{
    this->queue = new std::queue<T>();
}

template<typename T>
SharedQueue<T>::~SharedQueue()
{
    delete queue;
}

template <typename T>
T& SharedQueue<T>::front()
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

template <typename T>
void SharedQueue<T>::pop()
{
    qDebug() << "pop() called" << endl;
    mutex.lock();
    if (!queue->empty())
    {
        queue->pop();
    }
    mutex.unlock();
}

template <typename T>
void SharedQueue<T>::push(const T& item)
{
    qDebug() << "push() called" << endl;
    mutex.lock();
    queue->push(item);
    mutex.unlock();
}

template <typename T>
void SharedQueue<T>::push(T&& item)
{
    qDebug() << "push() called" << endl;
    mutex.lock();
    queue.push(item);
    mutex.unlock();
}

template <typename T>
int SharedQueue<T>::size()
{
    qDebug() << "size() called" << endl;
    mutex.lock();
    int size = queue.size();
    mutex.unlock();
    return size;
}

template <typename T>
bool SharedQueue<T>::empty()
{
    // qDebug() << "emtpy() called" << endl;
    mutex.lock();
    bool empty = queue->empty();
    mutex.unlock();
    return empty;
}
