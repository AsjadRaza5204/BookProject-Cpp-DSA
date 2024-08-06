 #include "book.h"
    Book::Book()
    {
    	this->id=0;
    	strcpy(this->name,"NULL");
    	strcpy(this->author,"NULL");
    	strcpy(this->category,"NULL");
    	this->price=0;
    	this->rating=0;
	}
	Book::Book(int id,char* name,char* author,char* category,double price,int rating)
	{
		this->id=id;

        strcpy(this->name,name);
    	strcpy(this->author,author);
    	strcpy(this->category,category);
    	this->price=price;
    	this->rating=rating;
	}	
	
	void Book::setId(int id)
	{
		this->id=id;
	}
	void Book::setName(char* name)
	{

		strcpy(this->name,name);
    	
	}
	void Book::setAuthor(char* author)
	{

		strcpy(this->author,author);
    	
	}
	void Book::setCategory(char* category)
	{

		strcpy(this->category,category);
	}
	void Book::setPrice(double price)
	{
		this->price=price;
	}
	void Book::setRating(int rating)
	{
		this->rating=rating;
	}
	
	
	
	int Book::getId()
	{
		return this->id;
    	
	}
	char* Book::getName()
	{
		return this->name;
    	
	}
	char* Book::getAuthor()
	{
		return this->author;
    	
	}
	char* Book::getCategory()
	{
		return this->category;
    	
	}
	double Book::getPrice()
	{
		return this->price;
    	
	}
	int Book::getRating()
	{
		return this->rating;
	}
	
	
	void Book::display()
	{
	
    	cout<<"\nBook Id :"<<this->id;
    	cout<<"\nBook Name :"<<this->name;
    	cout<<"\nBook Author :"<<this->author;
    	cout<<"\nBook Category :"<<this->category;
    	cout<<"\nBook Price :"<<this->price;
    	cout<<"\nBook Rating :"<<this->rating;	
	}
