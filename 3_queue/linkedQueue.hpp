/*************************************************************************
 @Author: 
 @Created Time : 2021年01月18日 星期一 17时09分39秒
 @File Name: linkedQueue.hpp
 @Description:
 ************************************************************************/
#ifndef LINKEDQUEUE_HPP
#define LINKEDQUEUE_HPP

#include <iostream>
#include <cassert>
#include "queue.h"

template<class T>
struct node 
{
    T data;
    node<T>* link;

    node(node<T>* ptr = nullptr) : link(ptr) {}
    node(const T& x, node<T>* ptr = nullptr) : data(x), link(ptr) {}
};

template<class T>
class linkedQueue : public queue<T>
{
    private:
        node<T>* frontSite;
        node<T>* rearSite;
    public:
        linkedQueue();
        ~linkedQueue();

        virtual void push(const T& x); //从尾部添加数据
        virtual T front() const; //返回最前面的数据
        virtual T back() const; //返回最后面的数据
        virtual void pop(); //取出最前面的数据
        virtual int size() const; //返回数组的大小
        virtual bool empty() const; //判断是否为空
        void makeEmpty();
        friend std::ostream& operator<<(std::ostream& os, const linkedQueue<T>& Q)
        {
            os << "队列的大小为：" << Q.size() << std::endl;
            node<T>* ptr = Q.frontSite;
            int i = 1;
            while (ptr->link != nullptr) {
                os << '#' << i++ << ": " << ptr->data << std::endl;
                ptr = ptr->link;
            } 
            return os;
        }
};

template<typename T>
linkedQueue<T>::linkedQueue()
{
    frontSite = rearSite = new node<T>;
}

template<typename T>
linkedQueue<T>::~linkedQueue()
{
    makeEmpty();
    delete frontSite;
}

template<typename T>
void linkedQueue<T>::push(const T& x)
{
    if (frontSite->link == nullptr) {
        frontSite->data = x;
        frontSite->link = new node<T>;
    } else {
        rearSite->link->data = x;
        rearSite = rearSite->link;
        rearSite->link = new node<T>;
    }
}

template<typename T>
T linkedQueue<T>::front() const
{
    if (this->empty() == true) 
        throw "this queue is empty!";
    return frontSite->data;
}

template<typename T>
T linkedQueue<T>::back() const
{
    if (this->empty() == true) 
        throw "this queue is empty!";
    return rearSite->data;
}

template<typename T>
void linkedQueue<T>::pop()
{
    if (this->empty() == true) 
        throw "this queue is empty!";
    node<T>* ptr = frontSite->link;
    if (frontSite == rearSite) {
        delete frontSite;
        frontSite = rearSite = ptr;
    } else {
        delete frontSite;
        frontSite = ptr;
    }
}

template<typename T>
int linkedQueue<T>::size() const
{
    node<T>* ptr = frontSite->link;
    int count = 0;
    while (ptr != nullptr) {
        ++count;
        ptr = ptr->link;
    }
    return count;
}

template<typename T>
bool linkedQueue<T>::empty() const
{
    return frontSite->link == nullptr;
}

template<typename T>
void linkedQueue<T>::makeEmpty()
{
    while (this->empty() == false) {
        this->pop();
    }
}


#endif
