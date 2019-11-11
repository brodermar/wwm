#ifndef SHAREDQUEUE_H
#define SHAREDQUEUE_H

#include <queue>
#include <mutex>

#include <QDebug>
#include <QMessageLogContext>


template<typename T>
/**
 * @brief The SharedQueue class represents a thread safe version of a std::queue.
 *
 * SharedQueue therefore wraps a std::queue and makes the access thread safe by 
 * locking with a std::mutex object.
 */
class SharedQueue
{

private:

    /**
     * @brief queue the underlaying std::queue of the shared queue
     */
    std::queue<T>* queue;

    /**
     * @brief mutex a std::mutex object to lock the access to the std::queue
     */
    std::mutex mutex;

public:

    /**
     * @brief SharedQueue constructs a new shared queue with
     * a underlying std::queue
     */
    SharedQueue()
    {
        this->queue = new std::queue<T>();
    }

    ~SharedQueue()
    {
        delete queue;
    }

    /**
     * @brief front calls front() on the unerlying std::queue
     * @return the element returned by front() on std::queue
     */
    T& front()
    {
        qDebug() << "front() called" << endl;
        mutex.lock();
        T& elem = queue->front();
        mutex.unlock();
        return elem;
    }

    /**
     * @brief pop calls pop() on the unerlying std::queue
     */
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

    /**
     * @brief push calls push() on the underlying std::queue
     * @param item the element pushed calling push() on std::queue
     */
    void push(const T& item)
    {
        qDebug() << "push() called" << endl;
        mutex.lock();
        queue->push(item);
        mutex.unlock();
    }

    /**
     * @brief push calls push() on the underlying std::queue
     * @param item the element pushed calling push() on std::queue
     */
    void push(T&& item)
    {
        qDebug() << "push() called"<< endl;
        mutex.lock();
        this->queue.push(item);
        mutex.unlock();
    }

    /**
     * @brief size calls size() on the underlying std::queue
     * @return the size of the underlying std::queue
     */
    int size()
    {
        qDebug() << "size() called" << endl;
        mutex.lock();
        int size = this->queue.size();
        mutex.unlock();
        return size;
    }

    /**
     * @brief empty true, if the underlying std::queue is empty, false else
     * @return true or false
     */
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
