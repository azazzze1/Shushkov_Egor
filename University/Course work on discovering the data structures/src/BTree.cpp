#include "BTree.h"

void BtreeNode::splitChild(int idx, BtreeNode *node) {
    BtreeNode* NewNode = new BtreeNode(node->leaf);
    NewNode -> size = BTreeOrder-1;

    for(int i = 0; i < BTreeOrder - 1; ++i)
        NewNode->keys[i] = node->keys[i+BTreeOrder];

    if(node->leaf == false)
        for(int i = 0; i < BTreeOrder; ++i)
            NewNode->childrens[i] = node->childrens[i + BTreeOrder];

    node->size = BTreeOrder - 1;
    for(int i = size; i >= idx + 1; --i)
        childrens[i+1] = childrens[i];

    childrens[idx + 1] = NewNode;

    for(int i = size - 1; i >= idx; --i)
        keys[i+1] = keys[i];

    keys[idx] = node->keys[BTreeOrder - 1];
    ++size;
}

void BtreeNode::insertNonFull(int key) {
    int i = size - 1;
    if(leaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            --i;
        }
        keys[i + 1] = key;
        ++size;
    }else{
        while (i>=0 && keys[i] > key)
            --i;

        if(childrens[i+1]->size == 2 * BTreeOrder - 1){
            splitChild(i+1, childrens[i+1]);
            if(keys[i+1] < key)
                ++i;
        }
        childrens[i+1]->insertNonFull(key);
    }
}

BtreeNode *BtreeNode::search(int key){
    int i = 0;
    while(i < size && key > keys[i])
        ++i;

    if(keys[i]==key)
        return this;

    if(leaf)
        return NULL;

    return childrens[i]->search(key);
}


void BtreeNode::traverse() {
    int i;
    for (i = 0; i < size; i++) {
        if (leaf == false)
            childrens[i]->traverse();
        cout << " " << keys[i];
    }

    if (leaf == false)
        childrens[i]->traverse();
}

int BtreeNode::findIdxKeyInNode(int key) {
    int idx = 0;
    while(idx < size && keys[idx] < key)
        ++idx;
    return idx;
}

int BtreeNode::getPredecessor(int idx) {
    BtreeNode* cur = childrens[idx];
    while (!cur->leaf)
        cur = cur->childrens[cur->size];

    return cur->keys[cur->size -1];
}
int BtreeNode::getSuccessor(int idx) {
    BtreeNode* cur = childrens[idx+1];
    while (!cur->leaf)
        cur = cur->childrens[0];
    return cur->keys[0];
}

void BtreeNode::removeFromLeaf(int idx) {
    for(int i = idx + 1; i < size; ++i)
        keys[i-1] = keys[i];
    --size;
}

void BtreeNode::merge(int idx) {
    BtreeNode* child = childrens[idx];
    BtreeNode* sibling = childrens[idx+1];

    child->keys[BTreeOrder-1] = keys[idx];

    for(int i = 0; i < sibling->size; ++i)
        child->keys[i+BTreeOrder] = sibling->keys[i];

    if(!child->leaf)
        for(int i = 0; i <= sibling->size; ++i)
            child -> childrens[i+BTreeOrder] = sibling -> childrens[i];

    for(int i = idx + 1; i < size; ++i)
        keys[i-1] = keys[i];

    for(int i = idx + 2; i<=size; ++i)
        childrens[i-1] = childrens[i];

    child->size += sibling->size + 1;
    --size;

    delete(sibling);
}

void BtreeNode::removeFromNonLeaf(int idx) {
    int key = keys[idx];
    if(childrens[idx]->size >= BTreeOrder){
        int pred = getPredecessor(idx);
        keys[idx] = pred;
        childrens[idx]->deletion(pred);
    }
    else if(childrens[idx + 1]->size >= BTreeOrder){
        int succ = getSuccessor(idx);
        keys[idx] = succ;
        childrens[idx + 1]->deletion(succ);
    }
    else{
        merge(idx);
        childrens[idx]->deletion(key);
    }
}

void BtreeNode::borrowFromPrev(int idx) {
    BtreeNode* child = childrens[idx];
    BtreeNode* sibiling = childrens[idx - 1];

    for(int i = child->size - 1; i >= 0; --i)
        child -> keys[i+1] = child -> keys[i];

    if(!child->leaf){
        for(int i = child -> size; i>=0; --i)
            child->childrens[i+1] = child->childrens[i];
    }

    child -> keys[0] = keys[idx - 1];

    if(!child->leaf)
        child->childrens[0] = sibiling->childrens[sibiling->size];

    keys[idx - 1] = sibiling->keys[sibiling->size-1];

    ++child->size;
    --sibiling->size;
}

void BtreeNode::borrowFromNext(int idx) {
    BtreeNode* child = childrens[idx];
    BtreeNode* sibiling = childrens[idx + 1];

    child->keys[child->size] = keys[idx];

    if(!child->leaf)
        child->childrens[child->size + 1] = sibiling->childrens[0];

    keys[idx] = sibiling -> keys[0];

    if(!sibiling->leaf)
        for(int i = 1; i <= sibiling->size; ++i)
            sibiling -> childrens[i-1] = sibiling->childrens[i];

    ++child->size;
    --sibiling->size;
}

void BtreeNode::fill(int idx) {
    if(idx != 0  && childrens[idx - 1]->size >= BTreeOrder)
        borrowFromPrev(idx);
    else if(idx != size  && childrens[idx + 1]->size >= BTreeOrder)
        borrowFromNext(idx);

    else if(idx != size)
        merge(idx);
    else
        merge(idx-1);
}

void BtreeNode::deletion(int key) {
    int idx = findIdxKeyInNode(key);

    if(idx < size && keys[idx] == key){
        if(leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    }else{
        if(leaf){
            cout<<"Данный ключ "<<key<<" не существует в дереве\n";
            return;
        }

        bool flag =((idx == size) ? true : false);

        if(childrens[idx]->size < BTreeOrder)
            fill(idx);

        if(flag && idx > size)
            childrens[idx - 1]->deletion(key);
        else
            childrens[idx]->deletion(key);
    }
}

BtreeNode *BTree::search(int key) {
    return (root == NULL) ? NULL : root->search(key);
}

void BTree::insert(int key){
    if(root == NULL){
        root = new BtreeNode(true);
        root->keys[0] = key;
        root->size = 1;
    }else if(root->size == 2*BTreeOrder - 1){
        BtreeNode* NewRoot = new BtreeNode(false);
        NewRoot -> childrens[0] = root;
        NewRoot ->splitChild(0,root);

        int i = NewRoot->keys[0] < key ? 1 : 0;
        NewRoot->childrens[i]->insertNonFull(key);

        root = NewRoot;
    }else
        root->insertNonFull(key);
}

void BTree::deletion(int key) {
    if(!root){
        cout<<"Это дерево пустое!\n";
        return;
    }
    root->deletion(key);

    if(root->size == 0){
        BtreeNode* tmp = root;
        if(root->leaf)
            root=NULL;
        else
            root=root->childrens[0];
        delete tmp;
    }
}

void BTree::traverse() {
    if(root != NULL)
        root -> traverse();
}