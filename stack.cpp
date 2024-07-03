#include<iostream>
#include<exception>
using namespace std;
template<typename T>
class Stack{
private:
	T*arr;
	int capacity;
	int size;
public:
	Stack(int capacity_):capacity(capacity_),size(0){
		arr=new T[capacity];
	}
	~Stack(){
		delete []arr;
	}
	bool empty()const 
	{
		return size==0;
	}
	void push(const T&value)
	{
		if(size==capacity){
			throw runtime_error("stack overflow");
		}
		arr[size++]=value;
	}
	void pop(){
		if(empty())
		{
			throw runtime_error("stack underflow");
		}
		--size;
	}
	const T&top()const{
		if(empty())
			throw runtime_error("stack is empty");
		return arr[size-1];
	}
};
int main() {
    Stack<int> intStack(100);
    intStack.push(10);
    intStack.push(20);
    cout << "Top element: " << intStack.top() << endl;
    intStack.pop();
    cout << "Top element after pop: " << intStack.top() << endl;

    Stack<string> stringStack(100);
    stringStack.push("hello");
    stringStack.push("world");
    cout << "Top element: " << stringStack.top() << endl;
    stringStack.pop();
    cout << "Top element after pop: " << stringStack.top() << endl;

    return 0;
}
