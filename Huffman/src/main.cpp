#include<File.hpp>
#include<Huffman.hpp>
#include<Config.hpp>
using namespace std;
int weight[SIZE];// = {8, 6, 2, 5, 13, 25, 19, 36};
int main(int argc, char *argv[]){

	if(argc <= 1){
		cout << "Please Enter FileName!" << endl;
	}else{
		Config* config = new Config(argv[1]);
		string is_zip(argv[2]);
		cout << config->get_config() << endl;
		if(is_zip == "zip"){
			fileopen(config, weight);
			Huffmantree huffmantree(weight);
			zip(config, huffmantree, weight);
		}else if(is_zip == "unzip"){
			unzip(config);
		}else{
			cout << "Invalid parameter, please enter \"zip\" or \"unzip\"" << endl;
		}
		
	}
	
	return 0;
}




