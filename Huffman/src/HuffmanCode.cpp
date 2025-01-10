#include <HuffmanCode.hpp>
#include <iostream>

using namespace std;
HuffmanCode::HuffmanCode(){
    code = new string[n];
}

void HuffmanCode::set(int data, string code){
    this->code[data] = code;
}

string HuffmanCode::getCode(int data){
    return this->code[data];
}

HuffmanCode::~HuffmanCode(){
    delete[] code;
}

void HuffmanCode::print(){
    for(int i = 0; i < n; i++){
        cout<<i<<" "<<code[i]<<endl;
    }
}
