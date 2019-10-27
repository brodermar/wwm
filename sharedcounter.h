#ifndef SHAREDCOUNTER_H
#define SHAREDCOUNTER_H

#include <mutex>

#include <QDebug>
#include <QString>
#include <QMessageLogContext>

/**
 * @brief The SharedCounter class
 */
class SharedCounter
{

private:

    /**
     * @brief counter
     */
    unsigned int counter;

    /**
     * @brief mutex
     */
    std::mutex mutex;

public:

    /**
     * @brief SharedCounter
     */
    SharedCounter();

    ~SharedCounter();

    /**
     * @brief increase
     */
    void increase();

    /**
     * @brief decrease
     * @return
     */
    bool decrease();

    /**
     * @brief isGreaterZero
     * @return
     */
    bool isGreaterZero();

};

#endif // SHAREDCOUNTER_H
