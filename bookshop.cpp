#include <iostream>
#include <string>
using namespace std;
class Book {
public:
	string name, author, publication;
	int cost, stock;
	bool statusOfBook();
};
class Shop : Book {
	Book *B[20];
	int numberOfBooks;
public:
	Shop(int);
	void create();
	void display();
	void deleteBook();
	void transaction();
	void modify();
	void addBook();
	void updateStock() {
		string element;
		cout << "Enter the Name/Author/Publication of Book\n";
		cin >> element;
		for(int i = 0;i<numberOfBooks;i++) {
			if(element == B[i]->name ||
					element == B[i]->author ||
					element == B[i]->publication) {
				cout << "Enter Updated Stock of Book\n";
				cin >> B[i]->stock;
				return;
		}
	}
}
};
Shop::Shop(int i = 10) {
	numberOfBooks = i;
}
void Shop::create() {
	int i;
	for(i=0;i<numberOfBooks;i++) {
		cout << "Enter the Name of Book\n";
		cin >> noskipws >> B[i]->name;
		cout << "Enter the Author of Book\n";
		cin >> noskipws >> B[i]->author;
		cout << "Enter the Publication of Book\n";
		cin >> noskipws >> B[i]->publication;
		cout << "Enter the cost of Book\n";
		while(!cin >> B[i]->stock) {
			cout << "Please enter an Integer Value for Cost\n";
		}
		cout << "Enter the Amount of Copies\n";
		while(!cin >> B[i]->stock) {
			cout << "Please enter an Integer Value for Amount of Copies\n";
		}
	}
	cout << "Book Shop Created Successfully\n";
}
void Shop::display() {
	for(int i = 0;i<numberOfBooks;i++) {
		cout << "Name : " << B[i]->name << endl
				<< "Author : " << B[i]->author << endl
				<< "Publication : " << B[i]->publication << endl
				<< "Cost of Book : " << B[i]->cost << endl
				<< "Copies of Book : " << B[i]->stock << endl;
	}
}
void Shop::modify() {
	string element;
	cout << "Enter the Name/Author/Publication of Book\n";
	cin >> element;
	for(int i = 0;i<numberOfBooks;i++) {
		if(element == B[i]->name ||
				element == B[i]->author ||
				element == B[i]->publication) {
			cout << "Enter the Name of Book\n";
			cin >> noskipws >> B[i]->name;
			cout << "Enter the Author of Book\n";
			cin >> noskipws >> B[i]->author;
			cout << "Enter the Publication of Book\n";
			cin >> noskipws >> B[i]->publication;
			cout << "Enter the cost of Book\n";
			while(!cin >> B[i]->stock) {
				cout << "Please enter an Integer Value for Cost\n";
			}
			cout << "Enter the Amount of Copies\n";
			while(!cin >> B[i]->stock) {
				cout << "Please enter an Integer Value for Amount of Copies\n";
			}
			return;
		}

	}
}
void Shop::deleteBook() {
	string element;
	cout << "Enter the Name/Author/Publication of Book\n";
	cin >> element;
	for(int i = 0;i<numberOfBooks;i++) {
		if(element == B[i]->name ||
				element == B[i]->author ||
				element == B[i]->publication) {
			Book *dPointer = B[i];
			for(int j=i;j<numberOfBooks;j++) {
				B[j] = B[j+1];
			}
			delete dPointer;
		}
	}
}
void Shop::transaction() {
	string element;
		cout << "Enter the Name/Author/Publication of Book\n";
		cin >> element;
		for(int i = 0;i<numberOfBooks;i++) {
			if(element == B[i]->name ||
					element == B[i]->author ||
					element == B[i]->publication) {
				if(!B[i]->statusOfBook()) {
					cout << "Book not in Stock\n";
					return;
				}
				else {
					cout << "Transaction Successful\n";
					B[i]->stock--;
				}
			}
		}
}
bool Book::statusOfBook() {
	if(this->stock > 0) {
		return true;
	}
	return false;
}
void Shop::addBook() {
	int i = numberOfBooks;
	B[i] = new Book();
	cout << "Enter the Name of Book\n";
	cin >> noskipws >> B[i]->name;
	cout << "Enter the Author of Book\n";
	cin >> noskipws >> B[i]->author;
	cout << "Enter the Publication of Book\n";
	cin >> noskipws >> B[i]->publication;
	cout << "Enter the cost of Book\n";
	while(!cin >> B[i]->stock) {
		cout << "Please enter an Integer Value for Cost\n";
	}
	cout << "Enter the Amount of Copies\n";
	while(!cin >> B[i]->stock) {
		cout << "Please enter an Integer Value for Amount of Copies\n";
	}
	numberOfBooks++;
}
int main(int argc, char **argv) {
	short int option;
	Shop obj;
	do {
		cout << "1. Create Shop\n"
				"2. Display Shop\n"
				"3. Remove a Book\n"
				"4. Sell a Book\n"
				"5. Update Stock\n"
				"6. Modify Book Information\n"
				"7. Add a Book\n"
				"8. Exit\n";
		cin >> option;
		switch(option) {
		case 1 : {
			cout <<"Enter the Number of Books in Shop\n";
			cin >> option;
			obj = Shop(option);
			obj.create();
			break;
		}
		case 2 : {
			obj.display();
			break;
		}
		case 3 : {
			obj.deleteBook();
			break;
		}
		case 4 : {
			obj.transaction();
			break;
		}
		case 5 : {
			obj.updateStock();
			break;
		}
		case 6 : {
			obj.modify();
			break;
		}
		case 7 : {
			obj.addBook();
			break;
		}
		case 8 : {
			return 0;
		}
		}
	}while(true);
}
