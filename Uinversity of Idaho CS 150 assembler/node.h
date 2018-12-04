#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;
class node{
public:
	int info_num,info_num2;
	double info_double;
	char info_char;
	bool info_bool;
	string info_string;
	node* next_right = NULL;
	node* next_left = NULL;
	string list [100];
	node(string info_string,int info_num);
	node();
};
node::node(){
	this->next_right = NULL;
	this->next_left = NULL;
}
node::node(string info_string, int info_num){
	this->info_string = info_string;
	this->info_num = info_num;
	this->next_right = NULL;
	this->next_left = NULL;
}