#include<Node.hpp>
#include<iostream>
Node::Node(int data, int weight){
    this->data = data;
    this->left = this->right = this->parent = -1;
    this->weight = weight;
}

Node::Node(){
    this->weight = this->data = this->left = this->right = this->parent = -1;
}

void Node::setNode(int data, int weight){
    this->data = data;
    this->weight = weight;
}

void Node::setNode(int weight, int left, int right){
    this->weight = weight;
    this->left = left;
    this->right = right;
}

void Node::print(){
    std::cout<<"Data: "<<this->data<<" Weight: "<<this->weight<<
            " Left: "<<this->left<<" Right: "<<this->right<<
            " Parent: "<<this->parent<<std::endl;
}