/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Exercise 10 Question 1+2+3
Program doc: implemnting a BST tree, with options to:
add, remove, reflect, sort get the height of the tree, number of leaves, number of left leaves,and a level of asked node. */
#pragma once
#include <iostream>
using namespace std;

template <class T>
class Tree
{
protected:
    class Node // inner class
    {
    public:
        Node *left;
        Node *right;
        Node *parent;
        T value;

        Node(T val) : value(val), left(nullptr), right(nullptr), parent(this) {}

        Node(T val, Node *l, Node *r, Node *p)
            : value(val), left(l), right(r), parent(p) {}
    }; // end of Node class

    Node *root;

public:
    Tree() { root = nullptr; } // initialize tree
    virtual ~Tree();
    bool isEmpty() const;
    void clear()
    {
        clear(root);
        root = nullptr;
    }
    void preOrder() { preOrder(root); }
    void inOrder() { inOrder(root); }
    void postOrder() { postOrder(root); }

    virtual void process(T &val) { cout << val << " "; }
    virtual void add(T val) = 0;
    virtual bool search(T val) = 0;
    virtual void remove(T val) = 0;

    /*wrapper functions*/

    /*entry: by a tree structor, exit: return the number of leaves in that tree*/
    int leaves();

    /*entry: by a tree structor, exit: return the height of that tree*/
    int height();

    /*entry: by a tree structor, exit: return the mirror reflection of that tree*/
    void reflect();

    /*entry: by a tree structor, exit: return the number of left leaves in that tree */
    int onlyLeftSon();

private:
    void clear(Node *current);
    void preOrder(Node *current);
    void inOrder(Node *current);
    void postOrder(Node *current);

    /*recursion functions*/

    /*entry: by a tree structor, exit: return the number of leaves in that tree*/
    int leavesCount(Node *current, int count = 0);

    /*entry: by a tree structor, exit: return the height of that tree*/
    int heightCount(Node *current, int count_l = 0, int count_r = 0);

    /*entry: by a tree structor, exit: return the mirror reflection of that tree*/
    void creatReflect(Node *current);

    /*entry: by a tree structor, exit: return the number of left leaves in that tree */
    int onlyLeftSonCount(Node *current, int count = 0);
};

/*implimention*/

template <class T>
Tree<T>::~Tree() // deallocate tree
{
    if (root != nullptr)
        clear(root);
}

template <class T>
void Tree<T>::clear(Node *current)
{
    if (current)
    { // Release memory associated with children
        if (current->left)
            clear(current->left);
        if (current->right)
            clear(current->right);
        delete current;
        current->parent = nullptr;
    }
}

template <class T>
bool Tree<T>::isEmpty() const
{
    return root == nullptr;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(class Tree<T>::Node *current)
{ // visit Node, left child, right child
    if (current)
    {
        // process current Node
        process(current->value);
        // then visit children
        preOrder(current->left);
        preOrder(current->right);
    }
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(class Tree<T>::Node *current)
{ // visit left child, right child, node
    if (current)
    {

        postOrder(current->left);
        postOrder(current->right);
        process(current->value);
    }
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(class Tree<T>::Node *current)
{ // visit left child, Node, right child
    if (current)
    {
        inOrder(current->left);
        process(current->value);
        inOrder(current->right);
    }
}

// number of leaves in a tree rooted at current
template <class T>
int Tree<T>::leaves()
{
    if (this->isEmpty())
        return 0;
    return leavesCount(this->root);
}

/*entry: by a tree structor, exit: return the number of leaves in that tree*/
template <class T>
int Tree<T>::leavesCount(class Tree<T>::Node *current, int count)
{
    if (current)
    {
        if (!current->left && !current->right) /*leaf*/
            return 1;
        count += leavesCount(current->left);
        count += leavesCount(current->right);
        return count;
    }
    return count;
}

/*entry: by a tree structor, exit: return the height of that tree*/
template <class T>
int Tree<T>::height()
{
    if (this->isEmpty())
        return 0;
    return heightCount(this->root) + 1;
}

template <class T>
int Tree<T>::heightCount(class Tree<T>::Node *current, int count_l, int count_r)
{
    if (current)
    {
        if (current->left) /*height of left sub tree*/
        {
            count_l++;
            count_l += heightCount(current->left);
        }

        if (current->right) /*height of right sub tree*/
        {
            count_r++;
            count_r += heightCount(current->right);
        }

        return max(count_l, count_r); /*the maximum sub tree height is the root height*/
    }
    return 0;
}

/*entry: by a tree structor, exit: return the mirror reflection of that tree*/
template <class T>
void Tree<T>::reflect()
{
    if (!this->isEmpty())
        creatReflect(this->root);
}

template <class T>
void Tree<T>::creatReflect(class Tree<T>::Node *current)
{
    if (current)
    {
        /* swap: right<->left */
        class Tree<T>::Node *temp;
        temp = current->left;
        current->left = current->right;
        current->right = temp;
        /*parent stay the same*/

        creatReflect(current->left);
        creatReflect(current->right);
    }
}

/*entry: by a tree structor, exit: return the number of left leaves in that tree */
template <class T>
int Tree<T>::onlyLeftSon()
{
    if (this->isEmpty())
        return 0;
    return onlyLeftSonCount(this->root);
}

template <class T>
int Tree<T>::onlyLeftSonCount(class Tree<T>::Node *current, int count)
{
    if (current)
    {
        if (current->left) /*only left son*/
        {
            count++;
            count += onlyLeftSonCount(current->left);
        }
        return count;
    }
    return count;
}
