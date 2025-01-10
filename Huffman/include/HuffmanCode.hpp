# ifndef __HUFFMANCODE__
# define __HUFFMANCODE__
# include <string>
using namespace std;
class HuffmanCode
{
private:
    string* code;
    const int n = 256;
public:
    HuffmanCode();
    ~HuffmanCode();
    void set(int index, string code);
    void print();
    string getCode(int data);
};

# endif