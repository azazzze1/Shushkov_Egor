#ifndef ALG_CW_AVLTREE_H
#define ALG_CW_AVLTREE_H
#include <iostream>
using namespace std;

struct AVLnode{
    int key;
    AVLnode* left = NULL;
    AVLnode* right = NULL;
    int height = 0;
    AVLnode(int _key): key(_key){}
};

class AVLtree{
public:
    AVLtree(){
        root = NULL;
    }

    AVLnode* root;
    int depth(AVLnode* node);
    int getBalance(AVLnode* node);
    AVLnode* rightRotate(AVLnode* y_node);
    AVLnode* leftRotate(AVLnode* x_node);
    AVLnode* minValueNode(AVLnode* node);

    AVLnode* insert(AVLnode* node, int key);
    AVLnode* search(AVLnode* node, int key);
    AVLnode* deletion(AVLnode* root, int key);


    void inOrderPrint(AVLnode* root);
    void print(AVLnode* root, int lvl);
};


#endif
