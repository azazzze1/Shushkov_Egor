#include "AVLtree.h"

void AVLtree::inOrderPrint(AVLnode *root) {
    if(root != NULL){
        inOrderPrint(root->left);
        cout << root->key << " ";
        inOrderPrint(root->right);
    }
}

int AVLtree::depth(AVLnode* node){
    if(!node)
        return 0;
    return node->height;
}

int AVLtree::getBalance(AVLnode *node) {
    if(!node)
        return 0;
    return depth(node->left) - depth(node->right);
}

AVLnode* AVLtree::rightRotate(AVLnode* y_node) {
    AVLnode* x_node = y_node->left;
    AVLnode* tmp = x_node->right;

    x_node->right = y_node;
    y_node->left = tmp;

    y_node->height = max(depth(y_node->left), depth(y_node->right)+1);
    x_node->height = max(depth(x_node->left), depth(x_node->right)+1);

    return x_node;
}

AVLnode* AVLtree::leftRotate(AVLnode* x_node) {
    AVLnode* y_node = x_node->right;
    AVLnode* tmp = y_node->left;

    y_node->left = x_node;
    x_node->right = tmp;

    y_node->height = max(depth(y_node->left), depth(y_node->right)+1);
    x_node->height = max(depth(x_node->left), depth(x_node->right)+1);

    return y_node;
}

AVLnode* AVLtree::insert(AVLnode* node, int key){
    if(node == NULL){
        return new AVLnode(key);
    }
    if(key<node->key)
        node->left = insert(node->left, key);
    else if(key>node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(depth(node->left), depth(node->right));

    int balance = getBalance(node);

    if(balance > 1 && key < node->left->key)
        return rightRotate(node);

    if(balance < -1 && key > node->right->key)
        return leftRotate(node);

    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

AVLnode *AVLtree::search(AVLnode *node, int key) {
    if (node == NULL) return NULL;
    if (node->key == key) return node;

    if (node->key > key) return search(node->left, key);
    return search( node->right, key);
}


AVLnode *AVLtree::minValueNode(AVLnode *node) {
    AVLnode* cur = node;
    while(cur->left != NULL)
        cur = cur->left;
    return cur;
}


AVLnode* AVLtree::deletion(AVLnode* node, int key) {
    if(node == NULL)
        return node;

    if(key < node->key)
        node->left = deletion(node->left, key);
    else if(key > node->key)
        node->right = deletion(node->right,key);
    else{
        if(node->left == NULL || node->right == NULL){
            AVLnode* tmp = node->left ? node->left : node->right;
            if(tmp == NULL){
                tmp = node;
                node = NULL;
            }else{
                *node = *tmp;
                delete tmp;
            }
        }else{
            AVLnode* tmp = minValueNode(node->right);
            node->key = tmp->key;
            node->right = deletion(node->right, tmp->key);
        }
    }

    if(node == NULL)
        return node;

    node->height = 1 + max(depth(node->left), depth(node->right));

    int balance = getBalance(node);

    if(balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if(balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if(balance > 1 && getBalance(node->left) < 0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance < -1 && getBalance(node->right) > 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLtree::print(AVLnode *root, int lvl) {
    if(root != NULL)
    {
        print(root->right,lvl + 1);
        for(int i = 0;i < lvl;i++) cout<<"   ";
        cout << root->key << endl;
        print(root->left,lvl + 1);
    }
}