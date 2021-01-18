/*************************************************************************
 @Author: 刘名轩
 @Created Time : 2021年01月17日 星期日 17时14分30秒
 @File Name: seqStack.hpp
 @Description:
 ************************************************************************/
#ifndef SEQSTACK_HPP
#define SEQSTACK_HPP

#include <iostream>
#include <cassert>
#include "stack.h"

const int stackIncreament = 20;

template<class T>
class seqStack : public stack<T> 
{
    private:
        T* data;
        int topSite;
        int maxsize;
        void overflowProcess(); //私有函数，扩充栈的存储空间
    public:
        seqStack(int sz = 50);
        ~seqStack() {delete []data;}
        void push(const T& x); //向栈中添加元素x
        void pop(); //取出顶部元素
        T top() const; //返回顶部元素
        int size() const { return topSite + 1; } //返回栈中元素的数量
        bool empty() const { return topSite == -1; } //是否为空
        bool full() const { return topSite == maxsize - 1; } //是否已满
        void mdkeEmpty() { topSite = -1; }
        friend std::ostream& operator<<(std::ostream& os, const seqStack<T>& S)
        {
            os << "top = " << S.topSite << std::endl;
            for (int i = 0; i <= S.topSite; ++i) {
                os << '#' << i << ':' << S.data[i] << std::endl;
            }
            return os;
        }
};

template<typename T>
void seqStack<T>::overflowProcess()
{
    T* newArray = new T[maxsize + stackIncreament];    
    if (newArray == nullptr) {
        std::cerr << "存储分配失败" << std::endl;
        exit(1);
    }
    for (int i = 0; i <= topSite; ++i) newArray[i] = data[i];
    maxsize = maxsize + stackIncreament;
    delete []data;
    data = newArray;
    return ;
}

template<typename T>
seqStack<T>::seqStack(int sz)
{
    if (sz <= 0) 
        exit(1);
    data = new T[maxsize];
    if (data == nullptr) {
        std::cerr << "存储错误" << std::endl;
        exit(1);
    }
    topSite = -1;
    maxsize = sz;
}

template<typename T>
void seqStack<T>::push(const T& x)
{
    // 如果栈已满
    if (topSite == maxsize - 1) 
        overflowProcess();
    data[++topSite] = x;
}

template<typename T>
void seqStack<T>::pop()
{
    if (topSite == -1) return ;
    --topSite;
}

template<typename T>
T seqStack<T>::top() const
{
    if (topSite == -1) 
        throw "error";
    return data[topSite];
}


#endif
