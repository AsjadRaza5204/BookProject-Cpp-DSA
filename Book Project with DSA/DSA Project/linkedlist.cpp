#include "linkedlist.h"
#include<fstream>
template <class T>
	LinkedList<T>::LinkedList()
	{
		start=NULL;
		ifstream in("myfile.bin",ios_base::binary);
		T obj;
		while(!in.eof())
		{
	
			in.read((char*)&obj,sizeof(obj));
			if(!in.eof())
			{
			
				this->insertEnd(obj);
				
		    }
		}

	}
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
	LinkedList<T>::LinkedList(LinkedList& c)
	{
		this->start=NULL;
		Node<T>* p=c.start;
		while(p!=NULL)
		{
			this->insertEnd(p->getData());
			p=p->getNext();
		}
	}	
//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
	void LinkedList<T>::insertEnd(T& data)
	{
		Node<T>* temp=new Node<T>(data);
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			
		Node<T>* p=start;
		while(p->getNext()!=NULL)
		{
			p=p->getNext();
		}
		
		p->setNext(temp);
		}
		
		
	}
//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
	void LinkedList<T>::insertPos(T& data,int pos)
	{
		Node<T>* temp=new Node<T>(data);
		//no node temp is first node
		if(start==NULL)
		{
			start=temp;
			return;
		}
		if(pos==1)
		{
			temp->setNext(start);
			start=temp;
			return;
		}
		//any position
		int i=1;
		Node<T>* p=start;
		while(i<pos-1 && p->getNext()!=NULL)
		{
			p=p->getNext();
			i++;
		}
		temp->setNext(p->getNext());
		p->setNext(temp);
	}

//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void LinkedList<T>::deleteDataById(int id) {
	if (start == NULL) {
		cout << "\nNo Player to delete";
		return;
	}

	Node <T>*current = start;
	Node <T>*previous = NULL;

	
	//first position
	if (current != NULL && current->getData().getId() == id) {
		start = current->getNext();
		delete current;
		cout << "Book with id " << id << " deleted.\n";
		return;
	}


	while (current != NULL && current->getData().getId() != id) {
		previous = current;
		current = current->getNext();
	}

	//if no id is found 
	if (current == NULL) {
		cout << "Book not found..";
		return;
	}

	
	previous->setNext(current->getNext());

	delete current;
	cout << "Book with id " << id << " deleted.\n";
}

//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
Node <T>* LinkedList<T>::searchById(int id)
{
	if(start==NULL)
	{
		cout<<"\nNo data to search";
		
	}
	else
	{
	Node <T>* p=start;
	while(p!=NULL)
	{
		
		if(p->getData().getId()==id)
		{
			return p;
		}
		p=p->getNext();
	}
	}
	
	return NULL;
}
//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void LinkedList<T>::searchByName(char* name)
{
	if(start==NULL)
	{
		cout<<"\nNo data to search";
		
	}
	else
	{
		Node <T>* p=start;
	   while(p!=NULL)
	   {
		
		if(strcasecmp(p->getData().getName(),name)==0)
		{
			 p->getData().display();
		}
		else if(strcasecmp(p->getData().getCategory(),name)==0)
		{
			p->getData().display();
		}
		else if(strcasecmp(p->getData().getAuthor(),name)==0)
		{
			p->getData().display();
		}
		p=p->getNext();
	   }
	}
	

}

//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
	void LinkedList<T>::display()
	{
		if(start==NULL)
		{
			cout<<"\nNo Element to display";
		}
		else
		{
			int no=0;
			Node<T>* p=start;
		while(p!=NULL)
		{
			cout<<"\n_____________________________________________________________________\n";
			cout<<++no<<" Record ";
			cout<<"\n_____________________________________________________________________\n";
			p->getData().display();
			
			cout<<"\n";
			p=p->getNext();
		}
		}	
	}	
	
//////////////////////////////////////////////////////////////////////////////////////////	
template <class T>
void LinkedList<T>::display1(int c)// sort in top 3 element and get same as
{
		if(start==NULL)
		{
			cout<<"\nNo Element to display";
		}
		else
		{
			
			Node<T>* p=start;
			int p1=0;
		while(p1!=c)
		{
			p->getData().display();
			cout<<"\n";
			p=p->getNext();
			p1++;
		}
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
	void LinkedList<T>::updateById(Node<T>* a)
	{
		int ch;
		int rating;
		double price;
		cout<<"\n1.Update by Rating \n2.Price by Rating";
		cout<<"\nEnter choice ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					cout<<"\nEnter Rating ";
					cin>>rating;
					a->getData().setRating(rating);
					cout<<"Book Rating of Id"<<a<<" Successfully updated\n";
					a->getData().display();
				}
				break;
			case 2:
				{
					cout<<"\nEnter Price ";
					cin>>price;
					a->getData().setPrice(price);
					cout<<"Book Price of Id"<<a<<" Successfully updated\n";
					a->getData().display();
				}
				break;
		}
		
 }
//////////////////////////////////////////////////////////////////////////////////////////


	template <class T>	
	void LinkedList<T>::sortPrice()
	{
		if(start==NULL)
	    {
	      cout<<"\nNo Book Data to Sort";
		  return;
		  	
		}
		LinkedList<T> a(*this);
		Node<T>* p=a.start;
		while(p!=NULL)
		{
			Node<T>* q=p->getNext();
			while(q!=NULL)
			{
				if(p->getData().getPrice()>q->getData().getPrice())
				{
					T temp=p->getData();
					p->setData(q->getData());
					q->setData(temp);
				}
				q=q->getNext();
			}
			p=p->getNext();
		}
		a.display();
	}

//////////////////////////////////////////////////////////////////////////////////////////
	
	template <class T>
	void LinkedList<T>::sortRating()
	{
	    if(start==NULL)
	    {
	      cout<<"\nNo Book Data to Sort";
		  return;
		  	
		}
		LinkedList<T> a(*this);
		Node<T>* p=a.start;
		while(p!=NULL)
		{
			Node<T>* q=p->getNext();
			while(q!=NULL)
			{
				if(p->getData().getRating()>q->getData().getRating())
				{
					T temp=p->getData();
					p->setData(q->getData());
					q->setData(temp);
				}
				q=q->getNext();
			}
			p=p->getNext();
		}
		a.display();
	}
//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void  LinkedList<T>::topRating(int c)//max...min
{
	if(start==NULL)
	    {
	      cout<<"\nNo Book Data to Sort";
		  return;
		  	
		}
		LinkedList<T> a(*this);
		Node<T>* p=a.start;
		while(p!=NULL)
		{
			Node<T>* q=p->getNext();
			while(q!=NULL)
			{
				if(p->getData().getRating()<q->getData().getRating())
				{
					T temp=p->getData();
					p->setData(q->getData());
					q->setData(temp);
				}
				q=q->getNext();
			}
			p=p->getNext();
		}
		a.display1(c);
}

//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void  LinkedList<T>::topPrice(int c)//max...min
{
	if(start==NULL)
	    {
	      cout<<"\nNo Book Data to Sort";
		  return;
		  	
		}
		LinkedList<T> a(*this);
		Node<T>* p=a.start;
		while(p!=NULL)
		{
			Node<T>* q=p->getNext();
			while(q!=NULL)
			{
				if(p->getData().getPrice()<q->getData().getPrice())
				{
					T temp=p->getData();
					p->setData(q->getData());
					q->setData(temp);
				}
				q=q->getNext();
			}
			p=p->getNext();
		}
		a.display1(c);
}

//////////////////////////////////////////////////////////////////////////////////////////
template <class T>
	LinkedList<T>::~LinkedList()
	{
		cout<<"Destructor called\n";
		Node<T>* p;
		ofstream out("myfile.bin",ios_base::binary);
		while(start!=NULL)
		{
			p=start;
			cout<<"\nHere Object Destroyed\n";
			out.write((char*)&(start->getData()),sizeof(start->getData()) );
			start=start->getNext();
			delete p;

		}
		out.close();
	}
	
//////////////////////////////////////////////////////////////////////////////////////////	
	
	
	
