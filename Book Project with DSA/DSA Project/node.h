#include"book.cpp"
template <class T>
class Node
{
	T data;
	Node<T> *next;
	public:
	Node(T&);
	void setData(T&);
	void setNext(Node<T>*);
	T& getData();
	Node<T>* getNext();
	
	
};