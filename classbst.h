 #ifndef CLASSBST_H
#define CLASSBST_H

#include <iostream>
#include <fstream>
#include "../../../Documents/CS8(assignment)/BSTFunctions/tree_node.h"

using namespace std;

template<typename T>
class classBST{
public:
    classBST();
    classBST(const T* sorted_list, int size =-1);

    classBST(const classBST<T> *copy_me);
    classBST<T> & operator = (const classBST<T> &rhs);
    ~classBST();

    void insert(const T& insert_me);
    void erase(const T& target);
    bool search(const T target, tree_node<T> *& found_ptr);
    void clearall();
    friend ostream& operator<<(ostream & outs, const classBST<T> &tree)
    {
        tree_print_debug(tree.root,0,outs);
        return outs;

    }
    classBST<T>& operator += (const classBST<T> &rhs);

private:
    tree_node<T> *root;
};

template<typename T>
void classBST<T>::clearall()
{
    tree_clear(root);
}
template<typename T>
classBST<T>::classBST()
{
    root=NULL;
}

template<typename T>
classBST<T>::classBST(const T* sorted_list, int size)
{
    root = tree_from_sorted_list(sorted_list,size);
}

template<typename T>
classBST<T>::classBST(const classBST<T> *copy_me)
{
    root = tree_copy(copy_me);
}

template<typename T>
classBST<T> &classBST<T>:: operator = (const classBST<T> &rhs)
{
    if(this == &rhs)
        return *this;
    tree_clear(root);
    root = tree_copy(rhs.root);
    return *this;
}

template<typename T>
classBST<T>::~classBST()
{
    tree_clear(root);
}

template<typename T>
void classBST<T>::insert(const T &insert_me)
{
    tree_insert(root, insert_me);
}

template<typename T>
void classBST<T>::erase(const T& target)
{
    tree_erase(root, target);
}

template<typename T>
bool classBST<T>::search(const T target, tree_node<T> *& found_ptr)
{
    return tree_search(root,target,found_ptr);
}

template<typename T>
classBST<T>& classBST<T>::operator += (const classBST<T> &rhs)
{
    tree_add(root,rhs.root);
    return *this;
}

#endif // CLASSBST_H
