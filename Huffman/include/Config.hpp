# ifndef __CONFIG__
# define __CONFIG__
# include <string>
using namespace std;

class Config{
private:
    string file;
public:
    Config(char * str);
    string get_config();
    ~Config();
};


# endif