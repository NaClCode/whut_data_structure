#include <Config.hpp>
#include <stdlib.h>
#include <string>
using namespace std;
Config::Config(char* str){
    this->file = string(str);
}

string Config::get_config(){
    return this->file;
}

Config::~Config(){
}


