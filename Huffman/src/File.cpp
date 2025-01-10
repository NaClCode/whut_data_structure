#include <File.hpp>
#include <string.h>
#include <iostream>
#include <string>
#include <Config.hpp>
#include <queue>
#include <Huffman.hpp>
#include <string>
#include <fstream>
#include <bitset>

using namespace std;
void fileopen(Config* config, int *weight){
    string pFilename = config->get_config();
	FILE *in = fopen(pFilename.c_str(), "rb");
	int ch = 0;
	while ((ch = fgetc(in)) != EOF){
		weight[ch]++;
	}
    cout << endl;
	fclose(in);
}


void zip(Config* config, Huffmantree &huffman, int* weight) {
    string pFilename = config->get_config();
    FILE *in = fopen(pFilename.c_str(), "rb");
    FILE *out = fopen((pFilename + ".huf").c_str(), "wb");

    if (!in || !out) {
        cerr << "Error opening file." << endl;
        if (in) fclose(in);
        if (out) fclose(out);
        return;
    }

    fwrite(weight, sizeof(int), 256, out);

    char buffer = 0; 
    int bitCount = 0;
    int count = 0; 

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        string temp = huffman.getCodebook()->getCode(ch);
        for (char bit : temp) {
            buffer = (buffer << 1) | (bit == '1');
            bitCount++;
            count++ ;
            if (bitCount == 8) {
                fwrite(&buffer, sizeof(char), 1, out);
                bitCount = 0;
                buffer = 0;
            }
        }
    }

    if (bitCount > 0) {
        buffer <<= (8 - bitCount);
        fwrite(&buffer, sizeof(char), 1, out);
    }

    fwrite(&count, sizeof(int), 1, out);

    long inFileLength = ftell(in);
    long outFileLength = ftell(out);
    cout << "Compression ratio: " << (outFileLength) * 1.0 / inFileLength << endl;

    fclose(in);
    fclose(out);

    cout << "Zip completed" << endl;
}




void unzip(Config* config){
    string pFilename = config->get_config();

    FILE *in = fopen((pFilename + ".huf").c_str(), "rb");
    FILE *out = fopen((pFilename + ".unzip").c_str(), "wb");
    int weight[256], count, ch, j = 0;

    if (!in || !out) {
        cerr << "Error opening files for compression." << endl;
        return;
    }

    fseek(in, -sizeof(int), SEEK_END);
    fread(&count, sizeof(int), 1, in);
    fseek(in, 0, SEEK_SET);
    fread(weight, sizeof(int), 256, in);

    Huffmantree huffmantree(weight);
    queue<bool> temp;
    int tree = huffmantree.root;
    
    while ((ch = fgetc(in)) != EOF){

        bitset<8> bits(ch);
        for (int i = 7; i >= 0 && count >= 0; i--, count--) {
            temp.push(bits[i]);
            j ++;
        }

        while(!temp.empty()){
            int left = huffmantree.tree[tree].left;
            int right = huffmantree.tree[tree].right;
            if(left == -1 && right == -1){
                fwrite(&huffmantree.tree[tree].data, sizeof(char), 1, out);
                tree = huffmantree.root;
            }
            if(temp.front()){
                tree = huffmantree.tree[tree].right;
            }else{
                tree = huffmantree.tree[tree].left;
            }

            temp.pop();

        }

	}

    fclose(in);
    fclose(out);

}