#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node*left_child;
	Node* brother;
	Node(int value):data(value),left_child(nullptr),brother(nullptr){};
};
class Tree
{
private:
	Node*root;
public:
	//build the tree
	Tree(int value)
	{
		root=new Node(value);
	}
	T

};