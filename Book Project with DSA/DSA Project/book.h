#include <iostream>
#include <string.h>
using namespace std;
class Book
{
	int id;
	char name[20];
	char author[20];
	char category[20];
	double price;
	int rating;
	
	public:
	Book();
	Book(int,char*,char*,char*,double,int);	
	
	void setId(int);
	void setName(char*);
	void setAuthor(char*);
	void setCategory(char*);
	void setPrice(double);
	void setRating(int);
	
	
	
	int getId();
	char* getName();
	char* getAuthor();
	char* getCategory();
	double getPrice();
	int getRating();
	
	
	void display();

	
 	
};