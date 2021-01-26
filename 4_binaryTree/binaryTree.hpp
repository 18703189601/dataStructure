/*************************************************************************
 @Author: 
 @Created Time : 2021年01月21日 星期四 19时37分28秒
 @File Name: binaryTree.hpp
 @Description:
 ************************************************************************/
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
#include <fstream>

template<typename T>
struct node
{
    T data;
    node<T>* lChild;
    node<T>* rChild;

    node() : lChild(nullptr), rChild(nullptr) {}
    node(const T& d, node<T>* l = nullptr, node<T>* r = nullptr) : data(d), lChild(l), rChild(r) {}
};

template<typename T>
class binaryTree
{
    private:
        node<T>* root;
        T refValue; //数据输入停止标志
        void createBTree(std::istream& in, node<T>* &subTree); //从文件中读入数据
        bool insert(node<T>* &subTree, const T& x); //插入
        void destroy(node<T>* &subTree); //删除
        bool find(node<T>* subTree, const T& x) const; //查找
        node<T>* find(node<T>* subTree, const T& x) const; //查找
        node<T>* copy(node<T>* orignode); //复制
        int height(node<T>* subTree); //返回树高度
        int size(node<T>* subTree); //返回结点树
        node<T>* parent(node<T>* subTree, node<T>* current); //返回父结点
        void traverse(node<T>* subTree, std::ostream& out); //前序遍历输出
        void preOrder(node<T>* subTree, void(*visit)(node<T>* ptr)); //前序遍历
        void inOrder(node<T>* subTree, void(*visit)(node<T>* ptr)); //中序遍历
        void postOrder(node<T>* subTree, void(*visit)(node<T>* ptr)); //后序遍历
        friend std::istream& operator>>(std::istream& in, binaryTree<T>& tree)
        {
            createBTree(in, tree.root);
            return in;
        }
        friend std::ostream& operator<<(std::ostream& out, binaryTree<T>& tree)
        {
            out << "二叉树前序遍历\n";
            tree.traverse(tree.root, out);
            out << std::endl;
            return out;
        }

    public:
        binaryTree() : root(nullptr) {}
        binaryTree(const T& value) : refValue(value), root(nullptr) {}
        binaryTree(binaryTree<T>& tree);
        ~binaryTree() { destroy(root); }

        bool empty() const { return root == nullptr; }
        node<T>* parent(node<T>* current) const; //返回父结点
        { return (root == nullptr || root == current) ? nullptr : parent(root, current); }
        node<T>* leftChild(node<T>* current) const //返回左孩子
        { return current != nullptr ? current->lChild : nullptr; }
        node<T>* rightChild(node<T>* current) const //返回右孩子
        { return current != nullptr ? current->rChild : nullptr; }
        int height() { return height(root); }
        int size() { return size(root); }
        node<T>* getRoot() const { return root; }
        void preOrder(void(*visit)(node<T>* ptr)) { preOrder(root, visit); }
        void inOrder(void(*visit)(node<T>* ptr)) { inOrder(root, visit); }
        void postOrder(void(*visit)(node<T>* ptr)) { postOrder(root, visit); }
        void levelOrder(void(*visit)(node<T>* ptr)); //层序遍历
        int insert(const T& x); //插入新元素
        node<T>* find(const T& x) const; //搜索
};

template<typename T>
void binaryTree<T>::createBTree(std::istream& in, node<T>* &subTree)
{//从文件中读入数据

}

/**
 * 1. Description: 在二叉树第一个空闲的地方插入新树
 **/
template<typename T>
bool binaryTree<T>::insert(node<T>* &subTree, const T& x)
{
    
}

/**
 * 1. Description: 将以subTree为结点的树删除
 * 2. Method: 递归
 * 3. In addition: node<T>* &subTree
 *  (1) 以node<T>* subTree 为参: 只会修改subTree所指数据，无法修改subTree本身
 *  (2) 以node<T>* &subTree 为参：可以修改subTree本身
 **/
template<typename T>
void binaryTree<T>::destroy(node<T>* &subTree)
{
    if (subTree != nullptr) {
        destroy(subTree->lChild);
        destroy(subTree->rChild);
        delete subTree;
    }    
}

template<typename T>
bool binaryTree<T>::find(node<T>* subTree, const T& x) const
{

}

template<typename T>
node<T>* binaryTree<T>::find(node<T>* subTree, const T& x) const
{

}

template<typename T>
node<T>* binaryTree<T>::copy(node<T>* orignode)
{
    
}

template<typename T>
int binaryTree<T>::height(node<T>* subTree)
{

}

template<typename T>
int binaryTree<T>::size(node<T>* subTree)
{

}

/**
 * 1. Description: 私有函数
 * 2. Method: 从subTree结点开始, 寻找current的父结点
 **/
template<typename T>
node<T>* binaryTree<T>:: parent(node<T>* subTree, node<T>* current)
{
    if (subTree == nullptr) return nullptr;
    if (subTree->lChild == current || subTree->rChild == current) return subTree;
    //设置ptr原因：防止左遍历时时的重复计算
    node<T>* ptr;
    //左递归
    if ((ptr = parent(subTree->lChild, current)) != nullptr) return ptr;
    //右递归
    else return parent(subTree->rChild, current);
}

/**
 * 1. Description: 前序遍历输出各个结点数据
 **/
template<typename T>
void binaryTree<T>::traverse(node<T>* subTree, std::ostream& out)
{
    if (subTree != nullptr) {
        out << subTree->data << ' ';
        traverse(subTree->lChild, out);
        traverse(subTree->rChild, out);
    }
}

template<typename T>
void binaryTree<T>::preOrder(node<T>* subTree, void(*visit)(node<T>* ptr))
{

}

template<typename T>
void binaryTree<T>::inOrder(node<T>* subTree, void(*visit)(node<T>* ptr))
{

}

template<typename T>
void binaryTree<T>::postOrder(node<T>* subTree, void(*visit)(node<T>* ptr))
{

}

/**
 * 以下是public函数
 **/

template<typename T>
binaryTree<T>::binaryTree(binaryTree<T>& tree)
{

}

template<typename T>
void binaryTree<T>::levelOrder(void(*visit)(node<T>* ptr))
{

}

template<typename T>
int binaryTree<T>::insert(const T& x)
{

}

template<typename T>
node<T>* find(const T& x) const
{

}

















#endif
