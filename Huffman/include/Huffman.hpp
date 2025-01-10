# ifndef __HUFFMAN__
# define __HUFFMAN__
# include "Node.hpp"
# include <map>
# include <string>
# include <HuffmanCode.hpp>
const int SIZE = 256;
using namespace std;
class Huffmantree{
private:
    
    const int treesize = SIZE * 2 - 1;
    HuffmanCode* code;
    
    int getMinIndex();
    void create(int n);
    void encode(int i, string s);

public:
    int root;
    Node* tree;

    Huffmantree(int weight[]);
    HuffmanCode* getCodebook();
    ~Huffmantree();
    void print();
};
# endif 