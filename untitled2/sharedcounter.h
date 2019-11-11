#ifndef SHAREDCOUNTER_H
#define SHAREDCOUNTER_H

#include <mutex>

#include <QDebug>
#include <QString>
#include <QMessageLogContext>

/**
 * @brief The SharedCounter class represents a thread safe counter, wrapping
 * an unsigned int with the help of a std::mutex object.
 */
class SharedCounter
{

private:

    /**
     * @brief counter the unterlying counter
     */
    unsigned int counter;

    /**
     * @brief mutex a std::mutex object to lock the access to the counter
     */
    std::mutex mutex;

public:

    /**
     * @brief SharedCounter constructs a new counter, it will be initialized with 0
     */
    SharedCounter();

    ~SharedCounter();

    /**
     * @brief increase increases the counter
     */
    void increase();

    /**
     * @brief decrease decreases the counter if possible
     * @return
     */
    bool decrease();

    /**
     * @brief isGreaterZero checks if the counter is >0
     * @return true, if the counter is largner than 0, false else
     */
    bool isGreaterZero();

};

#endif // SHAREDCOUNTER_H
