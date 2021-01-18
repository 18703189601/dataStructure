/*************************************************************************
 @Author: 刘名轩
 @Created Time : 2021年01月15日 星期五 11时51分52秒
 @File Name: seqList.hpp
 @Description:
 ************************************************************************/
#ifndef SEQLIST_HPP
#define SEQLIST_HPP

const int defaultSize = 100;

template<class T> 
class seqList
{
    private:
        int maxsize;
        int last;
        T* data;
    public:
        seqList(int sz = defaultSize);
        seqList(seqList<T>& L);
        ~seqList() { delete[] data; }

        int size() const { return this->maxsize; }
        int length() const { return this->last + 1; } 
        void getData(int i, T& value) const; //返回第i个数据
        void setData(int i, const T& value); //将第i个数据修改为x
        int search(const T& x) const; //返回第一个值为x的位置
        void insert(int i, const T& x); // 在第i个数据后插入x
        void remove(int i, T& x); // 删除第i个数据，由x返回被删除数值
        bool empty() const { return last == -1; }
        bool full() const { return last == maxsize - 1; }
        void input();
        void output() const;
        seqList<T>& operator=(seqList<T>& L); //符号重载，表整体赋值
};

template<typename T>
seqList<T>::seqList(int sz)
{
    if (sz > 0) {
        this->maxsize = sz;
        this->last = -1;
        data = new T[sz];
    }
}

template<typename T>
seqList<T>::seqList(seqList<T>& L)
{
    maxsize = L.size();
    last = L.length() - 1;
    this->data = new T[this->maxsize];
    T value;
    for (int i = 0; i <= last; i++) {
        L.getData(i + 1, value);
        data[i] = value;
    }
}

template<typename T>
void seqList<T>::getData(int i, T& value) const
{
    if (i < 1 || i > this->length()) return ;
    value = this->data[i - 1];
    return ;
}

template<typename T>
void seqList<T>::setData(int i, const T& value)
{
    if (i < 1 || i > this->length()) return ;
    this->data[i - 1] = value;
    return ;
}

template<typename T>
int seqList<T>::search(const T& value) const
{
    int i = 0;
    for (; i <= this->last; ++i) {
        if (this->data[i] == value)
            break;
    }
    return i == this->last + 1 ? 0 : i + 1; 
}

template<typename T>
void seqList<T>::insert(int i, const T& x)
{
    if (i < 1 || i > this->last + 1) return ;
    if (last == maxsize - 1) return ;
    for (int ix = last + 1; ix >= i + 1; --ix) {
        this->data[ix] = this->data[ix - 1];
    }
    ++last;
    this->data[i] = x;
    return ;
}

template<typename T>
void seqList<T>::remove(int i, T& x) 
{
    if (i < 1 || i > this->last + 1) return ;
    for (int ix = i - 1; ix < last; ++ix) {
        this->data[ix] = this->data[ix + 1];
    }
    --last;
    return ; 
}

template<typename T>
void seqList<T>::input()
{
    int n;
    std::cout << "Enter the length of the seqList: ";
    std::cin >> n;
    if (n > maxsize) {
        std::cout << "The length should be less than " << maxsize << std::endl;
        return ;
    }
    last = n - 1;
    std::cout << "Enter datas:" << std::endl;
    for (int i = 0; i <= last; i++) {
        std::cout << '#' << i + 1 << ':';
        std::cin >> data[i];
    }
}

template<typename T>
void seqList<T>::output() const 
{
    if (last == -1) {
        std::cout << "The seqList is empty!" << std::endl;
        return ;
    } else {
        std::cout << "List of seqList:" << std::endl;
        for (int i = 0; i <= last; ++i) {
            std::cout << '#' << i + 1 << ':' << data[i] << std::endl;
        }
        return ;
    }    
}

template<typename T>
seqList<T>& seqList<T>::operator=(seqList<T>& L)
{
    maxsize = L.size();
    last = L.length() - 1;
    data = new T[maxsize];
    T value;
    for (int i = 0; i <= last; ++i) {
        L.getData(i + 1, value);
        data[i] = value;
    }
    return *this;
}


#endif
