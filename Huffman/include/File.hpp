#ifndef __FILEHPP__
#define __FILEHPP__

#include <iostream>
#include <Huffman.hpp>
#include <Config.hpp>
void fileopen(Config* config, int *weight);
void zip(Config* config, Huffmantree &huffman, int* weight);
void unzip(Config* config);
#endif