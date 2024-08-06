#include "node.cpp"
template <class T>
class LinkedList
{
	Node<T>* start;
	public:
	LinkedList();
	LinkedList(LinkedList&);//copy constructor
	void insertPos(T&,int);
	void insertEnd(T&);
	void deletePosition(int);
	void deleteDataById(int );
	void updateById(Node<T>*);
	Node<T>* searchById(int);
	void searchByName(char*);
	void sortRating();
	void sortPrice();
	void display();
	void display1(int);
	void topRating(int);
	void topPrice(int);
	~LinkedList();
};