/*************************************************************************
 @Author: 刘名轩
 @Created Time : 2021年01月17日 星期日 18时46分51秒
 @File Name: linkedStack.hpp
 @Description:
 ************************************************************************/
#ifndef LINKEDSTACK_HPP
#define LINKEDSTACK_HPP

#include <iostream>
#include <cassert>
#include "stack.h"

template<class T>
struct node
{
        T data;
        node<T>* link;

        node(node<T>* l = nullptr) : link(l) {}
        node(const T& x, node<T>* l = nullptr) : data(x), link(l) {}
};

template<class T>
class linkedStack : public stack<T>
{
    private:
        node<T>* toptr;
    public:
        linkedStack() : toptr(nullptr) {}
        ~linkedStack() { makeEmpty(); }

        virtual void push(const T& x); //向栈中添加元素e
        virtual void pop(); //取出顶部元素
        virtual T top() const; //返回顶部元素
        virtual int size() const; //返回栈中元素的数量
        virtual bool empty() const { return toptr == nullptr; } //是否为空
        virtual bool full() const { return false; } //是否已满
        void makeEmpty(); 
        friend std::ostream& operator<<(std::ostream& os, const linkedStack<T>& S)
        {
            os << "栈中的元素个数为: " << S.size() << std::endl;
            node<T>* ptr = S.toptr;
            int i = 1;
            while (ptr != nullptr) {
                std::cout << '#' << i++ << ':' << ptr->data << std::endl;
                ptr = ptr->link;
            }
            return os;
        }
};

template<typename T>
void linkedStack<T>::push(const T& x)
{
    toptr = new node<T>(x, toptr);
    assert(toptr != nullptr);
}

template<typename T>
void linkedStack<T>::pop()
{
    if (toptr == nullptr) return ;
    node<T>* ptr = toptr;
    toptr = toptr->link;
    delete ptr;
}

template<typename T>
T linkedStack<T>::top() const
{
    if (toptr == nullptr) 
        throw "error";
    return toptr->data;
}

template<typename T>
int linkedStack<T>::size() const
{
    node<T>* ptr = toptr;
    int count = 0;
    while (ptr != nullptr) {
        ptr = ptr->link;
        ++count;
    }
    return count;
}

template<typename T>
void linkedStack<T>::makeEmpty()
{
    node<T>* ptr;
    while (ptr->link != nullptr) {
        ptr = toptr;
        toptr = toptr->link;
        delete ptr;
    }
}

#endif
