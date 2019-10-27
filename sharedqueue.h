#ifndef SHAREDQUEUE_H
#define SHAREDQUEUE_H

#include <queue>
#include <mutex>

#include <QDebug>
#include <QMessageLogContext>


template<typename T>
/**
 * @brief The SharedQueue class
 */
class SharedQueue
{

private:

    /**
     * @brief queue
     */
    std::queue<T>* queue;

    /**
     * @brief mutex
     */
    std::mutex mutex;

public:

    /**
     * @brief SharedQueue
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
     * @brief front
     * @return
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
     * @brief pop
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
     * @brief push
     * @param item
     */
    void push(const T& item)
    {
        qDebug() << "push() called" << endl;
        mutex.lock();
        queue->push(item);
        mutex.unlock();
    }

    /**
     * @brief push
     * @param item
     */
    void push(T&& item)
    {
        qDebug() << "push() called" << endl;
        mutex.lock();
        this->queue.push(item);
        mutex.unlock();
    }

    /**
     * @brief size
     * @return
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
     * @brief empty
     * @return
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
