/*************************************************************************
 @Author: 刘名轩
 @Created Time : 2021年01月16日 星期六 17时10分55秒
 @File Name: doublyMain.cpp
 @Description:
 ************************************************************************/
#include <iostream>
#include "doublyList.hpp"

using namespace std;

int main()
{
    doublyList<int> L(0);
    int choice = 0;
    int i = 0, value = 0;
    do {
        cout << "***********************************************" << endl;
        cout << "1-头插法建表" << endl;
        cout << "2-尾插法建表" << endl;
        cout << "3-正向遍历" << endl;
        cout << "4-反向遍历" << endl;
        cout << "5-长度" << endl;
        cout << "6-将表置空" << endl;
        cout << "7-获取第i个数据" << endl;
        cout << "8-修改第i个数据" << endl;
        cout << "9-插入到第i个数据之后" << endl;
        cout << "10-push_front" << endl;
        cout << "11-push_back" << endl;
        cout << "1010-退出" << endl;
        cout << "***********************************************" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                L.makeEmpty();
                L.headInput();
                break;
            case 2:
                L.makeEmpty();
                L.rearInput();
                break;
            case 3:
                L.forwardTra();
                break;
            case 4:
                L.reverseTra();
                break;
            case 5:
                cout << "The length of list is " << L.length() << endl;
                break;
            case 6:
                L.makeEmpty();
                break;
            case 7:
                cout << "想要第几个数据？" << endl;
                cin >> i;
                L.getData(i, value);
                cout << "第" << i << "个数据是：" << value << endl;
                break;
            case 8:
                cout << "想要修改第几个数据？" << endl;
                cin >> i;
                cout << "想要修改成什么数？" << endl;
                cin >> value;
                L.setData(i, value);
                break;
            case 9:
                cout << "输入想插入的位置:";
                cin >> i;
                cout << "插入数据的值:" << endl;
                cin >> value;
                L.insert(i, value);
                break;
            case 10:
                cout << "输入想添加的数据" << ": ";
                cin >> value;
                L.push_front(value);
                break;
            case 11:
                cout << "输入想添加的数据：";
                cin >> value;
                L.push_back(value);
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
