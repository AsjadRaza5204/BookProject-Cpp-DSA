
#include "linkedlist.cpp"

int main(int argc, char** argv)
{
LinkedList <Book>l;
int choice= 0; 
while(choice!=10)
{

cout<<"\n\t\t1.Insert at Specific Position";
cout<<"\n\t\t2.Delete Book By BookId";
cout<<"\n\t\t3.Display";
cout<<"\n\t\t4.Sort";
cout<<"\n\t\t5.Search";
cout<<"\n\t\t6.Update";
cout<<"\n\t\t7.Top  Books";
cout<<"\n\t\t10.Exit";


cout<<"\nEnter your choice : ";
cin>>choice;
switch(choice)
{
case 1:
{
int id,rating,pos;
double price;
char name[200];
char author[200];
char category[200];
cout<<"\nEnter Position to insert ";
cin>>pos;
cout<<"\nEnter Book ID,Book Name,Author Name,Category,Price,Rating \n";
cin>>id;
Node<Book>* a=l.searchById(id);
if(a!=NULL)
{
cout<<"Already Book Record in Present";
a->getData().display();

}
else
{

fflush(stdin);
cin.clear();
cin.getline(name, 200);
fflush(stdin);
cin.clear();
cin.getline(author, 200);
fflush(stdin);
cin.clear();
cin.getline(category, 200);
fflush(stdin);
cin.clear();
cin>>price>>rating;

Book b1(id,name,author,category,price,rating);
l.insertPos(b1,pos);
}
}
break;
case 2:
{
int id;
cout<<"\nEnter  Book Id to delete Book Record";
cin>>id;
l.deleteDataById(id);
}
break;
case 3:
l.display();
break;
case 4:
{
int ch;
cout<<"\n1.Sort By Rating in Ascending Order\n2.Sort by Price Ascending Order ";
cin>>ch;
switch(ch)
{
case 1:
l.sortRating();
break;
case 2:
l.sortPrice();
break;
}
}
break;
case 5:
{
int ch;
cout<<"\n1.Search By Book ID\n2.Search By Others";
cin>>ch;
switch(ch)
{
case 1:
{
int id;
cout<<"\nEnter ID to Search Book";
cin>>id;
Node<Book>* r=l.searchById(id);
if(r==NULL)
{
cout<<"\nNo Book Data is Found ";
}
else
{
cout<<"\nBook Found ";
r->getData().display();
}
}

break;
case 2:
{

char name[200];
cout<<"\nEnter which Value you want to search \nBy Book Name or By Author Name or By Category ";
cin>>name;
l.searchByName(name);

}
break;

}
}
break;
case 6:
{

int id;
cout<<"\nEnter Book Id ";
cin>>id;
Node<Book>* a=l.searchById(id);
if(a!=NULL)
{
l.updateById(a);
}
else
{
cout<<"\nNo Book Id is present to update ";
}

}
break;
case 7:
{

int ch;
cout<<"\n1.Top Books By Rating\n2.Top Books By Price ";
cin>>ch;
switch(ch)
{
case 1:
{
int c;
cout<<"\nHow Many Top Books you want Accorting to Rating ";
cin>>c;
l.topRating(c);
}
break;
case 2:
{
int c;
cout<<"\nHow Many Top Books you want Accorting to Price ";
cin>>c;
l.topPrice(c);	
}
break;
}

}
break;
case 10:
cout<<"\nEnd of program-----";
break;
default:
cout<<"\nInvalid choice";

}
}
}


