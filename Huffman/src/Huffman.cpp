#include <Huffman.hpp>
#include <iostream>
#include <HuffmanCode.hpp>
using namespace std;

Huffmantree::Huffmantree(int weight[]){
    this->code = new HuffmanCode();
    this->tree = new Node[this->treesize];
    for(int i = 0; i < SIZE; i++){
        this->tree[i].setNode(i, weight[i]);
    }
    create(SIZE);
    encode(root, "");

};


int Huffmantree::getMinIndex(){
    int flag = 1, index = -1;
    for(int i = 0; i < this->treesize; i++){
        if(this->tree[i].weight > 0 && this->tree[i].parent == -1){
            if(flag) index = i;
            if(this->tree[i].weight <= this->tree[index].weight){
                flag = 0;
                index = i;
            }
        }
    }
    return index;
}

void Huffmantree::create(int n){
    int next = n;
    int minIndex1, minIndex2;
    
    for(;;){
        minIndex1 = getMinIndex();
        this->tree[minIndex1].parent = next;
        minIndex2 = getMinIndex();
        this->tree[minIndex2].parent = next;
        if(minIndex1 == -1 || minIndex2 == -1){
            break;
        }
        this->tree[next].setNode(this->tree[minIndex1].weight + this->tree[minIndex2].weight, minIndex1, minIndex2);
        next ++;
    }

    if(minIndex1 == -1) root = minIndex2;
    else root = minIndex1;
    
}

void Huffmantree::encode(int i, string s){
    if(this->tree[i].data != -1){
        
        this->code->set(this->tree[i].data, s);
    }else{
        encode(this->tree[i].left, s + "0");
        encode(this->tree[i].right, s + "1");
    }
    
}

void Huffmantree::print(){
    for(int i = 0;i < this->treesize;i++){
        this->tree[i].print();
    }
}

HuffmanCode* Huffmantree::getCodebook(){
    return this->code;
}

Huffmantree::~Huffmantree(){
    delete[] this->tree;
};
