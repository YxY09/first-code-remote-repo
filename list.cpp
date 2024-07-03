#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* prev;
	Node* next;
	Node(int value) :data(value), next(nullptr), prev(nullptr) {};
};
class List
{
private:
	Node* sentinel;// the sentinel which can make the code easier
public:
	List()
	{
		sentinel = new Node(0);
	}
	void insert_at_head(int data)
	{
		Node* temp = new Node(data);
		temp->next = sentinel->next;
		if(temp->next!=nullptr)
		{
		temp->next->prev=temp;
	    }
		sentinel->next = temp;
		temp->prev = sentinel;

	}
	void insert_at_tail(int data)
	{
		Node* temp = sentinel;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		Node* new_node = new Node(data);
		temp->next = new_node;
		new_node->prev = temp;
		new_node->next = nullptr;
		sentinel->prev=new_node;
	}
	Node* find_element(int key)const
	{
		Node*temp=sentinel;
		while(temp->next!=nullptr&&temp->data!=key)
		{
			temp=temp->next;
		}
		if(temp->data!=key)
		{
			return sentinel;
		}
		else
		{
			return temp;
		}
	}
	void display_from_head()const
	{
		Node* temp = sentinel->next;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void display_from_tail()const
	{
		Node* temp = sentinel->prev;
		while (temp != sentinel)
		{
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout << endl;
	}

};
int main() {
	List myList;

	// 在头部插入数据
	myList.insert_at_head(10);
	myList.insert_at_head(20);
	myList.insert_at_head(30);

	// 在尾部插入数据
	myList.insert_at_tail(5);
	myList.insert_at_tail(15);
	myList.insert_at_tail(25);

	cout << "Display from head: ";
	myList.display_from_head(); // 从头部打印链表

	cout << "Display from tail: ";
	myList.display_from_tail(); // 从尾部打印链表
	cout<<myList.find_element(15)->data;
	cout<<endl;
	return 0;
}
