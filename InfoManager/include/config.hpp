#ifndef CONFIG_H
#define CONFIG_H
#include <string>
using namespace std;
class Config{
private:
    string datadir;
public:
    Config(string datadir);
    string get_datadir();
    string get_vexfile();
    string get_edgefile();

};
#endif
