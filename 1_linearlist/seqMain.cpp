/*************************************************************************
 @Author: 刘名轩
 @Created Time : 2021年01月15日 星期五 19时47分35秒
 @File Name: main.cpp
 @Description:
 ************************************************************************/
#include <iostream>
#include "seqList.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    seqList<int>* L = new seqList<int>(20);
    int choice = 0;
    int i = 0;
    int value = 0;
    do {
        cout << "********************************************" << endl;
        cout << "1-初始化(input())" << endl;
        cout << "2-遍历(output())" << endl;
        cout << "3-数据长度(length())" << endl;
        cout << "4-数组大小(size())" << endl;
        cout << "5-获取第i个数据(void, int, T&)" << endl;
        cout << "6-重置第i个数据(void, int, const T&)" << endl;
        cout << "7-插入到第i个数据后(void, int, const T&)" << endl;
        cout << "8-删除第i个数据(void, int, T& x)" << endl;
        cout << "9-赋值重载" << endl;
        cout << "1010-退出！" << endl;
        cout << "********************************************" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                L->input();
                break;
            case 2:
                L->output();
                break;
            case 3:
                cout << "The length of list: " << L->length() << endl;
                break;
            case 4:
                cout << "The size of list: " << L->size() << endl;
                break;
            case 5:
                cout << "想要知道第几个数据？" << endl;
                cin >> i;
                L->getData(i, value);
                cout << "第i个数据是" << value << endl;
                break;
            case 6:
                cout << "想要重置第几个数据？" << endl;
                cin >> i;
                cout << "输入想要重置的数据大小: " << endl;
                cin >> value;
                L->setData(i, value);
                cout << "充值完毕！" << endl;
                break;
            case 7:
                cout << "在那个位置插入？" << endl;
                cin >> i;
                cout << "插入位置的数据是：" << endl;
                cin >> value;
                L->insert(i, value);
                cout << "插入完毕" << endl;
                break;
            case 8:
                cout << "删除第几个数据？" << endl;
                cin >> i;
                L->remove(i, value);
                cout << "删除完毕！" << endl;
                break;
            case 9:
                //seqList<int> L1 = *L;
                //cout << "验证赋值构造函数" << endl;
                //L1.output();
                break;
            case 1010:
                break;
            default:
                cout << "输入错误" << endl;
                break;
        }
    } while (choice != 1010);
    return 0;
}

