/*
This is a Basic C++ Program to help maintain the Inventory of a Book Shop. 
It has the operations like :
1. Creating an Inventory
2. Displaying the Information about the Books in the Inventory
3. Adding a Book to the Inventory
4. Searching for a Book in the Inventory
5. Deleting a Book from the Inventory

There are two classes Book and Inventory.
The class Book is never accessed through the main() function but by creating another class called Inventory.
The objects of class Book are made in the class Inventory using the "new" operator.
An object of class Inventory is declared in main().
All aboove mentioned functions are done through the use of this Object.
*/
#include <iostream>
#include <string.h>
using namespace std;
class Book {
	int stock;
	float cost;
	char title[101], author[101], publisher[101];
	friend class Inventory;
	void display();
public :
	Book();
};
void Book::display() {
	cout<<"Title: "<<title<<endl;
	cout<<"Author: "<<author<<endl;
	cout<<"Publisher: "<<publisher<<endl;
	cout<<"Number of Books: "<<stock<<endl;
	cout<<"Cost of Book: "<<cost<<endl;
}
Book::Book() {
	stock = 0;
	cost = 0;
	strcpy(title,"C++");
	strcpy(author,"Balagurusamy");
	strcpy(publisher,"McGraw Hill");
}
class Inventory {
	int numberOfBooks;
	int j;
	Book *B;
	Book *workable;
	public :
	Inventory(int i);
	void create();
	void display();
	void add();
	void search(char []);
	void delBook(int);
	void modify(int i);
	Book *setPointer(int i) {
		int j;
		for(B = workable, j = 0;j<=i;j++) {
			B++;
		}
		return B;
	}
	Book *setPointer() {
		return workable;
	}
};
void Inventory::delBook(int i) {
	delete setPointer(i);
}
void Inventory::modify(int i) {
	B = setPointer(i);
	int opt;
	cout<<"What do you want change\n";
	cout<<"1.Title\n2.Author\n3.Publisher\n4.Number of Books\n5.Cost of Book\n";
	cin>>opt;
	cout<<"Enter the Changed ";
	switch(opt) {
	case 1 : {
		cout<<"Title\n";
		cin>>B->title;
		break;
	}
	case 2 : {
		cout<<"Author\n";
		cin>>B->author;
		break;
	}
	case 3 : {
		cout<<"Publisher\n";
		cin>>B->publisher;
		break;
	}
	case 4 : {
		cout<<"Number of Books\n";
		cin>>B->stock;
		break;
	}
	case 5 : {
		cout<<"Cost of Book\n";
		cin>>B->cost;
		break;
	}
	}
}
void Inventory::search(char a[]) {
	int k;
	for(k=0,B = setPointer();k<=j;k++,B++) {
		if(strcmp(a,B->author)==0||strcmp(a,B->publisher)==0||strcmp(a,B->title)==0) {
			B->display();
		}
	}
}
void Inventory::add() {
	char ans[10];
	do {
		j++;
		cout<<"Enter the Title of the Book\n";
		cin>>B->title;
		cout<<"Enter the Author of the Book\n";
		cin>>B->author;
		cout<<"Enter the Publisher of the Book\n";
		cin>>B->publisher;
		cout<<"Enter the Cost of the Book\n";
		cin>>B->cost;
		cout<<"Enter the Number of Books available\n";
		cin>>B->stock;
		B++;
		cout<<"Do you want to enter more Book Info\n";
		cin>>ans;
	}while(strcmp(ans,"Yes")==0||strcmp(ans,"yes")==0||strcmp(ans,"YES")==0||strcmp(ans,"y")==0);
}
void Inventory::display() {
	B = setPointer();
	int i;
	for(i=0;i<=j;i++,B++) {
		B->display();
	}
}
void Inventory::create() {
	char ans[10];
	j = -1;
	do {
		j++;
		cout<<"Enter the Title of the Book\n";
		cin>>B->title;
		cout<<"Enter the Author of the Book\n";
		cin>>B->author;
		cout<<"Enter the Publisher of the Book\n";
		cin>>B->publisher;
		cout<<"Enter the Cost of the Book\n";
		cin>>B->cost;
		cout<<"Enter the Number of Books available\n";
		cin>>B->stock;
		B++;
		cout<<"Do you want to enter more Book Info\n";
		cin>>ans;
	}while(strcmp(ans,"Yes")==0||strcmp(ans,"yes")==0||strcmp(ans,"YES")==0||strcmp(ans,"y")==0);
}
Inventory::Inventory(int i = 20) {
	B = new Book [i];
	workable = B;
	j = -100;
	numberOfBooks = i;
}
int main() {
	int opt, no;
	cout<<"Enter the Number of Books in your Inventory\n";
	cin>>no;
	char ans[101];
	Inventory I(no);
	do {
		cout<<"1.Create a Master Table\n2.Display Information of all the Books\n";
		cout<<"3.Add a Book\n4.Search a Book\n5.Delete a Book\n6.Modify Book Information\n7.Exit\n";
		cin>>opt;
		switch(opt) {
		case 1 : {
			I.create();
			break;
		}
		case 2 : {
			I.display();
			break;
		}
		case 3 : {
			I.add();
			break;
		}
		case 4 : {
			cout<<"Enter the Title\\Author\\Publisher\n";
			cin>>ans;
			I.search(ans);
			break;
		}
		case 5 : {
			cout<<"Enter the Book Number to be deleted\n";
			cin>>no;
			I.delBook(no);
			break;
		}
		case 6 : {
			cout<<"Enter the Book Number to be deleted\n";
			cin>>no;
			I.modify(no);
			break;
		}
		case 7 : {
			return 0;
		}
		}
	}while(true);
}
