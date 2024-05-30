#ifndef ALG_CW_BTREE_H
#define ALG_CW_BTREE_H

#include <iostream>

#define BTreeOrder 3
using namespace std;

struct BtreeNode{
    BtreeNode(bool _leaf): leaf(_leaf){}
    int keys [2*BTreeOrder-1];
    BtreeNode* childrens[2*BTreeOrder];
    int size = 0;
    bool leaf;

    void splitChild(int idx, BtreeNode* node);
    void insertNonFull(int k);
    BtreeNode* search(int key);
    void deletion(int key);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPredecessor(int idx);
    int getSuccessor(int idx);
    int findIdxKeyInNode(int key);
    void merge(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void traverse();
};

class BTree{
private:
    BtreeNode* root;
public:
    BTree(){root = NULL;}
    void insert(int key);
    void traverse();
    void deletion(int key);
    BtreeNode* search(int key);
};


#endif
