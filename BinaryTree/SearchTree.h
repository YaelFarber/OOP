/* Author: Yael Farber 
Course: Advanced Programming
Exercise 10 Question 1+2+3
Program doc: implemnting a BST tree, with options to:
add, remove, reflect, sort get the height of the tree, number of leaves, number of left leaves,and a level of asked node. */

#include "Tree.h"

template <class T>
class SearchTree : public Tree<T>
{
public:
    // protocol for search trees
    void add(T value);
    bool search(T value);

    /*wrapper functions*/

    /*entry: by BST tree + gets a value , exit: remove (delete) the first node in the tree that contain that value*/
    void remove(T value);

    /*entry: by BST tree + gets a value , exit: retrun on which level in the tree the node with that value is*/
    int level(T val);

private:
    /*recursion functions*/

    void add(class Tree<T>::Node *current, T val);
    bool search(class Tree<T>::Node *current, T val);

    /*entry: by BST tree + gets a value and the tree root, exit: remove (delete) the first node in the tree that contain that value*/
    void remove(class Tree<T>::Node *&current, T val);

    /*entry: by BST tree + gets a value and the tree root, exit: retrun on which level in the tree the node with that value is*/
    int levelCount(class Tree<T>::Node *current, T val, int count = 0);

    /*entry:  get a value ,exit: return a node that contain the asked val (same as search ,but return the node)*/
    typename Tree<T>::Node *searchNode(class Tree<T>::Node *&current, T val)
    {
        if (current)
        {
            if (current->value == val)
            {
                return current;
            }

            else if (current->value > val)
            {
                return searchNode(current->left, val);
            }
            else
            {
                return searchNode(current->right, val);
            }
        }
        return nullptr;
    }

    /*entry:get tree root + a value ,exit: return a pointer to the node of the successoer of asked value*/
    typename Tree<T>::Node *findSuccessor(class Tree<T>::Node *current, T val)
    {
        current = searchNode(current, val);
        if (current->right)           /*go right*/
            current = current->right; /*then go to the left leaf => the successor would be there*/
        if (current)
            while (current->left)
                current = current->left;
        return current;
    }
};

template <class T>
void SearchTree<T>::add(T value)
{
    if (this->root == nullptr)
        this->root = new class Tree<T>::Node(value);
    else
        add(this->root, value);
}
template <class T>
void SearchTree<T>::add(class Tree<T>::Node *current, T val)
{
    if (current->value <= val) // Add to right subtree
    {

        if (current->right == nullptr)
        {
            current->right = new class Tree<T>::Node(val);
            class Tree<T>::Node *temp = current;
            current = current->right;
            current->parent = temp;
        }
        else
            add(current->right, val);
    }
    else
    {
        if (current->left == nullptr)
        {
            current->left = new class Tree<T>::Node(val);
            class Tree<T>::Node *temp = current;
            current = current->left;
            current->parent = temp;
        }
        else
            add(current->left, val);
    }
}

template <class T>
bool SearchTree<T>::search(T value)
{
    if (this->isEmpty())
        return false;
    else
        return search(this->root, value);
}

template <class T>
bool SearchTree<T>::search(class Tree<T>::Node *current, T val)
{
    // see if argument value occurs in tree
    if (!current)
        return false; // not found
    if (current->value == val)
        return true;

    if (current->value > val)
    {
        return (current->value != val) && search(current->left, val);
    }
    else
    {
        return (current->value != val) && search(current->right, val);
    }
}

/*entry: by BST tree + gets a value , exit: remove (delete) the first node in the tree that contain that value*/
template <class T>
void SearchTree<T>::remove(T value)
{
    if (search(this->root, value))
        remove(this->root, value);
}

template <class T>
void SearchTree<T>::remove(class Tree<T>::Node *&current, T val)
{
    if (current)
    {
        class Tree<T>::Node *p = searchNode(current, val);
        if (p == nullptr)
            return;

        /*leaf*/
        if (!p->left && !p->right)
        {
            if (p->parent->right == p)
                p->parent->right = nullptr;
            else
                p->parent->left = nullptr;

            delete p;
        }
        else
        {
            /*has one son (grandfather points on grandson) */
            if (p->left && !p->right)
            {

                /*update grandfather*/
                if (p->parent->left == p)
                    p->parent->left = p->left;
                else
                    p->parent->right = p->left;

                /*update grandson*/
                p->left->parent = p->parent;

                delete p;
            }
            else
            {
                if (!p->left && p->right)
                {

                    /*update grandfather*/
                    if (p->parent->left == p)
                        p->parent->left = p->right;
                    else
                        p->parent->right = p->right;

                    /*update grandson*/
                    p->right->parent = p->parent;

                    delete p;
                }
                else
                    /*has 2 sons*/
                    if (p->left && p->right)
                    {
                        class Tree<T>::Node *suc = findSuccessor(current, val);
                        p->value = suc->value;
                        remove(p->right, suc->value);
                    }
            }
        }
    }
}

/*entry: by BST tree + gets a value , exit: retrun on which level in the tree the node with that value is*/
template <class T>
int SearchTree<T>::level(T val)
{
    if (!search(val))
        return -1;
    return levelCount(this->root, val);
}

template <class T>
int SearchTree<T>::levelCount(class Tree<T>::Node *current, T val, int count)
{
    if (current)
    {

        if (current->value != val)
        {

            if (!current->left && !current->right) /*is leaf*/
                return 1;

            if (current->left && !current->right) /*has only left son*/
            {
                return levelCount(current->left, val) + 1;
            }

            else if (current->right && !current->left) /*has only right son*/
            {
                return levelCount(current->right, val) + 1;
            }

            if (current->left && current->right) /*has 2 sons*/
            {
                if (current->value > val)
                    return levelCount(current->left, val) + 1;
                else
                    return levelCount(current->right, val) + 1;
            }
        }
        return count;
    }
    return count;
}
