/*************************************************************************
 @Author: 
 @Created Time : 2021年01月18日 星期一 15时55分28秒
 @File Name: seqQueue.hpp
 @Description:
 ************************************************************************/
#ifndef SEQQUEUE_HPP
#define SEQQUEUE_HPP

#include <iostream>
#include <cassert>
#include "queue.h"

template<typename T>
class seqQueue : public queue<T>
{
    private:
        int maxsize;
        int frontSite;
        int rearSite;
        T* data;
    public:
        seqQueue(int sz = 10);
        ~seqQueue() {delete []data;};

        virtual void push(const T& x);
        virtual T front() const;
        virtual T back() const;
        virtual void pop();
        virtual int size() const;
        virtual bool empty() const;
        bool full() const;
        void makeEmpty() { rearSite = frontSite = 0; }
        friend std::ostream& operator<<(std::ostream& os, seqQueue<T>& Q)
        {
            os << "front = " << Q.frontSite << ", rear = " << Q.rearSite << std::endl;
            for (int i = Q.frontSite; i != Q.rearSite; i = (i + 1) % Q.maxsize) {
                os << '#' << i << ": " << Q.data[i] << std::endl;
            }
            return os;
        }
};

template<typename T>
seqQueue<T>::seqQueue(int sz) : maxsize(sz), frontSite(0), rearSite(0)
{
    data = new T[maxsize];
    assert(data != nullptr);
}

template<typename T>
void seqQueue<T>::push(const T& x)
{
    if (this->full() == true) return ;
    data[rearSite] = x;
    rearSite = (rearSite + 1) % maxsize;
}

template<typename T>
T seqQueue<T>::front() const
{
    if (this->empty() == true) 
        throw "error";
    return data[frontSite];
}

template<typename T>
T seqQueue<T>::back() const
{
    if (this->empty() == true) 
        throw "error";
    return data[(rearSite - 1) % maxsize];
}

template<typename T>
void seqQueue<T>::pop() 
{
    if (this->empty() == true) {
        std::cout << "this queue is empty!" << std::endl;
        return ;
    }

    frontSite = (frontSite + 1) % maxsize;
}

template<typename T>
int seqQueue<T>::size() const
{
    return (rearSite - frontSite + maxsize) % maxsize;
}

template<typename T>
bool seqQueue<T>::empty() const
{
    return rearSite == frontSite;
}

template<typename T>
bool seqQueue<T>::full() const
{
    return (rearSite + 1) % maxsize == frontSite;
}

#endif
