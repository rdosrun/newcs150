#include "node.h"
class tree
{
public:
	node * root = NULL,*current=NULL;
	tree();
	void add_node(node *x,node *tmp);
	void delete_node(node & tmp);
	int lookup_node(node *x, string tmp);
};
tree::tree(){
	this->root = new node();
	this->current = new node();
}

void tree::add_node(node *x, node *tmp){
	current = x;
	cout<<tmp->info_string<<":"<<tmp->info_num<<endl;
	if(root == NULL)
	{
		cout<<"intializing index list..."<<endl;
		root =tmp;
		current = tmp;
		cout<<"done"<<endl;
	}else if (tmp->info_string < current->info_string)
    {
        if (current->next_left)
            add_node(current->next_left, tmp);
        else
            current->next_left = tmp;
    }
    else if (tmp->info_string > current->info_string)
    {
        if (current->next_right)
            add_node(current->next_right, tmp);
        else
            current->next_right = tmp;
    }
}
int tree::lookup_node(node *x, string tmp){
	current = x;
	if(root == NULL)
	{
		cout<<"list empty";
	}else if(tmp == current->info_string){
		return current->info_num; 
	}else if (tmp< current->info_string)
    {
        if (current->next_left!=NULL)
            return lookup_node(current->next_left, tmp);
        else
        	return -1;
    }
    else if (tmp > current->info_string)
    {
        if (current->next_right!=NULL)
            return lookup_node(current->next_right, tmp);
        else
        	return -1;
    }
}
