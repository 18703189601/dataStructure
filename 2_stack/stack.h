/*************************************************************************
 @Author: 刘名轩
 @Created Time : 2021年01月17日 星期日 17时03分19秒
 @File Name: stack.h
 @Description:
 ************************************************************************/
#ifndef STACK_H
#define STACK_H

template<class T>
class stack
{
    public:
        stack(){}
        virtual void push(const T& x) = 0; //向栈中添加元素e
        virtual void pop() = 0; //取出顶部元素
        virtual T top() const = 0; //返回顶部元素
        virtual int size() const = 0; //返回栈中元素的数量
        virtual bool empty() const = 0; //是否为空
        virtual bool full() const = 0; //是否已满
};


#endif
