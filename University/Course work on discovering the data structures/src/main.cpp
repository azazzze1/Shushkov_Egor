#include "BTree.h"
#include "AVLtree.h"
#include "gnuplot-iostream.h"

#include <time.h>

void test();
int main() {
    test();
}

void test(){
    BTree t;
    t.insert(8);
    t.insert(9);
    t.insert(10);
    t.insert(11);
    t.insert(15);
    t.insert(16);
    t.insert(17);
    t.insert(18);
    t.insert(20);
    t.insert(23);

    cout << "B-дерево: ";
    t.traverse();
    (t.search(17) != NULL) ? cout<<endl<<"17 найдено" : cout<<endl<<"17 не найдено";
    cout<<'\n';
    t.deletion(33);
    t.deletion(17);
    cout<<"Новое B-дерево: ";
    t.traverse();
    (t.search(17) != NULL) ? cout<<endl<<"17 найдено" : cout<<endl<<"17 не найдено";

    AVLtree tr;
    cout<<"\n\n\n"<<"AVL-дерево:";
    tr.root = tr.insert(tr.root, 10);
    tr.root =tr.insert(tr.root, 20);
    tr.root = tr.insert(tr.root, 12);
    tr.root =    tr.insert(tr.root, 36);
    tr.root =tr.insert(tr.root, 30);
    tr.root =tr.insert(tr.root, 40);
    tr.root = tr.insert(tr.root, 28);
    tr.root =  tr.insert(tr.root, 22);
    tr.root =  tr.insert(tr.root, 48);
    tr.root =  tr.insert(tr.root, 38);
    tr.inOrderPrint(tr.root);
    cout<<endl;

    tr.print(tr.root,0);

    (tr.search(tr.root,22) != NULL) ? cout<<endl<<"22 найдено" : cout<<endl<<"22 не найдено";
    tr.root = tr.deletion(tr.root, 22);
    (tr.search(tr.root,22) != NULL) ? cout<<endl<<"22 найдено" : cout<<endl<<"22 не найдено";
    (tr.search(tr.root,30) != NULL) ? cout<<endl<<"30 найдено" : cout<<endl<<"30 не найдено";
}