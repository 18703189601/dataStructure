/*************************************************************************
 @Author:
 @Created Time : 2021年01月18日 星期一 15时50分42秒
 @File Name: queue.h
 @Description:
 ************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class queue
{
    public:
        queue() {}
        ~queue() {}
        virtual void push(const T& x) = 0; //从尾部添加数据
        virtual T front() const = 0; //返回最前面的数据
        virtual T back() const = 0; //返回最后面的数据
        virtual void pop() = 0; //取出最前面的数据
        virtual int size() const = 0; //返回数组的大小
        virtual bool empty() const = 0; //判断是否为空
};



#endif
