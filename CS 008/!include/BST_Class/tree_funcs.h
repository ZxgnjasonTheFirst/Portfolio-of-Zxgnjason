#ifndef TREE_FUNCS_H
#define TREE_FUNCS_H
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
struct tree_node{
    T _item;
    tree_node *_left;
    tree_node *_right;
    int _height;
    int balance_factor(){
        //balance factor = height of the right subtree
        //                        - the height of the left subtree
        //a NULL child has a height of -1
        //a leaf has a height of 0
        int left_height, right_height;
        if(_left == NULL){
                left_height = -1;
        }
        else
            left_height = _left->_height;
        if(_right == NULL){
            right_height = -1;
        }
        else
            right_height = _right->_height;
        return abs(right_height - left_height);
    }
    int height(){
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)
        int left_height, right_height;
        if(_left == NULL){
            left_height = -1;
        }
        else
            left_height = _left->_height;
        if(_right == NULL){
            right_height = -1;
        }
        else
            right_height = _right->_height;
        _height = 1 + max(left_height, right_height);
        return _height;

    }
    int update_height(){
        //set the _height member variable (call height();)
        return height();
    }
    tree_node(T item=T(), tree_node* left=NULL, tree_node* right=NULL): _item(item), _left(left), _right(right){
        _height = 0;
    }
    friend ostream& operator <<(ostream& outs, const tree_node<T>& t_node){
        outs<<"|"<<t_node._item<<"|";
        return outs;
    }
};

template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me){
//    cout<<"here"<<endl;
    if(!root){
//        cout<<"what about here"<<endl;
        root = new tree_node<T>(insert_me);
        return;
    }
    else if(insert_me < root->_item){
//        cout<<"And here"<<endl;
        tree_insert(root->_left, insert_me);
    }
    else if(insert_me > root->_item){
//        cout<<"over here"<<endl;
        tree_insert(root->_right, insert_me);

    }
//    cout<<"at last here"<<endl;
    root->update_height();


};

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target){
    if(!root){
        return NULL;
    }
    else if(target < root->_item){
        return tree_search(root->_left, target);
    }
    else if(target > root->_item){
        return tree_search(root->_right, target);
    }
    else if(target == root->_item){
        return root;
    }
};

template <typename T>
bool tree_search(tree_node<T>* root, const T& target, tree_node<T>* &found_ptr){
    found_ptr = tree_search(root, target);
    if(!found_ptr){
        return false;
    }
    else{
        return true;
    }
};

template<typename T>
void tree_print(tree_node<T>* root, int level=0, ostream& outs=cout){
    if(root == NULL){
        return;
    }
    level++;

    tree_print(root->_right, level);
    outs<<endl;
    for(int i = 0; i < level-1; ++i){
        outs<<"     ";
    }
    outs<<*root<<endl;

    tree_print(root->_left, level);
};

template<typename T>       //prints details info about each node
void tree_print_debug(tree_node<T>* root, int level=0, ostream& outs=cout){
    if(root == NULL){
        return;
    }
    level++;

    tree_print_debug(root->_right, level);
    outs<<endl;
    for(int i = 0; i < level-1; ++i){
        outs<<"     ";
    }
    outs<<*root<<" h: "<<root->_height<<" bf: "<<root->balance_factor()<<endl;

    tree_print_debug(root->_left, level);

};

template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root){

    if(!root){
        return;
    }
    else{
        tree_clear(root->_left);
//        cout<<root->_item<<endl;
    }

    if(root->_right)
        tree_clear(root->_right);
//    cout<<"delete"<<endl;
//    cout<<*root<<endl;
    delete root;
    root = NULL;

};

template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target){
    tree_node<T> * discard;
    T _max;
    if(!root){
        return false;
    }
    else if(target > root->_item){
        tree_erase(root->_right, target);
        root->update_height();
    }
    else if(target < root->_item){
        tree_erase(root->_left, target);
        root->update_height();
    }
    else{
        if(!root->_left){
            discard = root;
            root = discard->_right;
            delete discard;
            return true;
        }
        else{
            tree_remove_max(root->_left, _max);
            root->update_height();
            root->_item = _max;
            return true;
        }

    }

};

template <typename T>       //erase rightmost node from the tree
                            // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value){
    tree_node<T>* discard;
    if(root->_right){
        tree_remove_max(root->_right, max_value);
        root->update_height();
    }
    else if(root->_left){
        max_value = root->_item;
        discard = root;
        root = root->_left;
        delete discard;
        return;
    }
    else{
        max_value = root->_item;
        delete root;
        root = NULL;
        return;
    }
};

template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root){
    tree_node<T>* cpy;
    if(root){
        cpy = new tree_node<T>(root->_item);
        cpy->_height = root->_height;
        if(root->_left)
            cpy->_left = tree_copy(root->_left);
        if(root->_right)
            cpy->_right = tree_copy(root->_right);
        return cpy;
    }


}
template <typename T>       //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src){
    if(!src){
        return;
    }
    else{
        tree_insert(dest, src->_item);
        tree_add(dest, src->_left);
    }

    if(src->_right)
        tree_add(dest, src->_right);

};


template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size){
    tree_node<T>* root = NULL;
    if(size/2 >= size){
        return NULL;
    }
    root = new tree_node<T>(a[size/2]);
    root->_left = tree_from_sorted_list(a, size/2);
    root->_right = tree_from_sorted_list(a + size/2 + 1, size/2);
    root->update_height();
    return root;
};





#endif // TREE_FUNCS_H

