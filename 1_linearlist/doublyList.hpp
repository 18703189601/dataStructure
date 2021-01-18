/*************************************************************************
 @Author: 刘名轩
 @Created Time : 2021年01月15日 星期五 20时41分57秒
 @File Name: doublyList.hpp
 @Description:
 ************************************************************************/
#ifndef DOUBLYLIST_HPP
#define DOUBLYLIST_HPP

#include <iostream>

template<class T>
struct node
{
    T data;
    node<T>* prior;
    node<T>* next;

    node(node<T>* p = nullptr, node<T>* n = nullptr) : prior(p), next(n) {}
    node(const T& value, node<T>* p = nullptr, node<T>* n = nullptr) : data(value), prior(p), next(n) {}
};

template<class T>
class doublyList
{
    private:
        node<T>* first;
        node<T>* last;
    public:
        //构造函数
        doublyList()
        {
            first = new node<T>;
            first->next = first;
            first->prior = first;
            last = first;
        }
        doublyList(const T& value)
        {
            first = new node<T>(value);
            first->next = first;
            first->prior = first;
            last = first;
        }
        ~doublyList() { makeEmpty(); delete first; }

        //功能函数
        node<T>* getHead() const { return this->first; }
        node<T>* getRear() const { return this->last; }
        int length() const; //链表长度
        void makeEmpty(); //将表置空，只保留头结点
        node<T>* locate(int i) const; //返回第i个数据的地址
        void getData(int i, T& value) const; //获取第i个数据
        void setData(int i, const T& value); //将第i个数据变为value
        node<T>* search(const T& x) const; //获取正向序列的和x相等的数值的地址
        void insert(int i, const T& x); //在第i个后面插入
        void remove(int i, T& x); //将第i个数据删除
        bool empty() const { return first == last; }

        void headInput();
        void rearInput();
        void forwardTra() const;
        void reverseTra() const;

        void push_front(const T& x);
        void push_back(const T& x);

        doublyList<T>& operator=(doublyList<T>& L);
};

template<typename T>
int doublyList<T>::length() const
{
    node<T>* ptr = first;
    int count = 0;
    while (ptr->next != first) {
        ptr = ptr->next;
        ++count;
    }
    return count;
}

template<typename T>
void doublyList<T>::makeEmpty()
{
    node<T>* ptr = first->next;
    while (ptr != first) {
        first->next = ptr->next;
        ptr->next->prior = first;
        delete ptr;
        ptr = first->next;
    } 
}

template<typename T>
node<T>* doublyList<T>::locate(int i) const
{
    if (i < 0 || i > this->length()) return nullptr;
    int count = 0;
    node<T>* ptr = first;
    while (count != i) {
        ptr = ptr->next;
        ++count;
    }
    return ptr;
}

template<typename T>
void doublyList<T>::getData(int i, T& value) const
{
    node<T>* ptr = this->locate(i);
    if (ptr == nullptr) return ;
    value = ptr->data;
    return ;
}

template<typename T>
void doublyList<T>::setData(int i, const T& value)
{
    node<T>* ptr = this->locate(i);
    if (ptr == nullptr) return ;
    ptr->data = value;
    return ;
}

template<typename T>
node<T>* doublyList<T>::search(const T& x) const
{
    node<T>* ptr = first->next;
    while (ptr != first) {
        if (ptr->data == x) break;
        ptr = ptr->next;
    }
    return ptr == first ? nullptr : ptr;
}

template<typename T>
void doublyList<T>::insert(int i, const T& x)
{
    node<T>* ptr = this->locate(i);
    if (ptr == nullptr) return ;
    node<T>* current = new node<T>(x, ptr, ptr->next);
    ptr->next->prior = current;
    ptr->next = current;
}

template<typename T>
void doublyList<T>::remove(int i, T& value)
{
    node<T>* ptr = this->locate(i);
    if (ptr == nullptr) return ;
    value = ptr->data;
    ptr->next->prior = ptr->prior;
    ptr->prior->next = ptr->next;
    delete ptr;
}

template<typename T>
void doublyList<T>::headInput()
{
    std::cout << "你想输入几个数据？" << std::endl;
    int num;
    std::cin >> num;
    if (num <= 0) return ;
    T value;
    std::cout << "Enter your datas: " << std::endl;
    std::cin >> value;
    last = new node<T>(value, first, first);
    first->next = last;
    first->prior = last;
    for (int i = 1; i <= num - 1; i++) {
        std::cin >> value;
        node<T>* current = new node<T>(value, first, first->next);
        first->next->prior = current;
        first->next = current;
    }
}

template<typename T>
void doublyList<T>::rearInput()
{
    std::cout << "你想输入几个数据？" << std::endl;
    int num;
    std::cin >> num;
    if (num <= 0) return ;
    T value;
    std::cout << "Enter your datas: " << std::endl;
    for (int i = 0; i < num; i++) {
        std::cin >> value;
        node<T>* current = new node<T>(value, last, first);
        last->next = current;
        first->prior = current;
        last = current;
    }
}

template<typename T>
void doublyList<T>::forwardTra() const
{
    node<T>* ptr = first->next;
    std::cout << std::endl << "Datas in list: " << std::endl;
    int count = 0;
    while (ptr != first) {
        std::cout << '#' << ++count << ": " << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

template<typename T>
void doublyList<T>::reverseTra() const
{
    node<T>* ptr = last;
    std::cout << std::endl << "Datas in list: " << std::endl;
    int count = this->length() + 1;
    while (ptr != first) {
        std::cout << '#' << --count << ": " << ptr->data << std::endl;
        ptr = ptr->prior;
    }
}

template<typename T>
void doublyList<T>::push_front(const T& x)
{
    node<T>* ptr = new node<T>(x);
    if (first == last) {
        last = ptr;
        last->next = first;
        last->prior = first;
        first->next = last;
        first->prior = last;
    } else {
        ptr->next = first->next;
        ptr->prior = first;
        first->next->prior = ptr;
        first->next = ptr;
    }
}

template<typename T>
void doublyList<T>::push_back(const T& x) 
{
    node<T>* ptr = new node<T>(x, last, first);
    last->next = ptr;
    first->prior = ptr;
    last = ptr;
}

template<typename T>
doublyList<T>& doublyList<T>::operator=(doublyList<T>& L)
{
    T value;
    node<T>* srcptr = L.getHead();
    node<T>* desptr = first = new node<T>(srcptr->data); //复制头结点
    srcptr = srcptr->next; //指向已知链表的第一个结点
    while (srcptr != L.getHead()) {
        value = srcptr->data;
        desptr->next = new node<T>(value, desptr);
        desptr = desptr->next;
        srcptr = srcptr->next;
    }
    last = desptr;
    first->prior = last;
    last->next = first;
    return *this;
}


#endif
