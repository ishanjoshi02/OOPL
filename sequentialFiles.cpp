#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;
class Error {
	int code;
	string description;
public :
	Error(int a, string b) {
		code = a;
		description = b;
	}
	void displayError() {
		cout << "Error " << code << endl
				<< description << endl;
	}
};
class Database {
	char nameOfFile[21];
	ofstream ofile;
	ifstream ifile;
	int numberOfStudents;
public:
	void getData();
	void display();
	void addRecord();
	void deleteRecord();
	void modifyRecord();
	void searchRecord();
	void deleteFile();
};
void Database::getData() {
	string a,b;
	cout << "Enter the Name of File\n";
	cin >> nameOfFile;
	strcat(nameOfFile,".dat");
	ofile.open(nameOfFile,ios::binary);
	try{
		if(ofile.eof()) {
			throw Error (404,"File Not Found\n");
		}
		else {
			string onceMore;
			do {
				cout << "Enter the Name of Student followed by his/her Roll Number\n";
				cin >> a >> b;
				ofile << a << endl
						<< b << endl;
				cout << "Do you want to Enter again\n";
				cin >> onceMore;
			}while((onceMore == "Yes" || onceMore == "yes"
					|| onceMore == "y" || onceMore == "Y")
					&& numberOfStudents++);
		}
	}
	catch (Error &e) {
		e.displayError();
	}
}
void Database::display() {
	int i;
	string a,b;
	ifile.open(nameOfFile,ios::binary);
	try {
		if(ifile.eof()) {
			throw Error(123,"No such File exists\n"
					"Please create a File first\n");
			for(i=1;i<=numberOfStudents;i++) {
				ifile >> a >> b;
				cout << "Name : " << i << " is " << a << endl
						<< "Roll Number : " << b << endl;
			}
		}
	}
	catch(Error &r) {
		r.displayError();
		this->getData();
	}
}
void Database::addRecord() {
	string a,b;
	ofile.open(nameOfFile,ios::binary);
	try{
		if(ofile.eof()) {
			throw Error (404,"File Not Found\n");
		}
		else {
			string onceMore;
			do {
				cout << "Enter the Name of Student followed by his/her Roll Number\n";
				cin >> a >> b;
				ofile << a << endl
						<< b << endl;
				cout << "Do you want to Enter again\n";
				cin >> onceMore;
			}while((onceMore == "Yes" || onceMore == "yes"
					|| onceMore == "y" || onceMore == "Y")
					&& numberOfStudents++);
		}
	}
	catch (Error &e) {
		e.displayError();
	}
}
void Database::deleteRecord() {
	string a,b,searcher;
	cout << "Enter the Name of Student or Roll Number of Student\n";
	cin >> searcher;
	ofile.open("temp.dat",ios::binary);
	ifile.open(nameOfFile,ios::binary);
	try {
		if(ifile.eof() || ofile.eof()) {
			throw Error(456,"No such file exists\nPlease create Database first\n");
		}
		else {
			for(int i = 0;i<numberOfStudents;i++) {
				ifile >> a >> b;
				if(a!=searcher && b != searcher) {
					ofile << a << endl << b << endl;
				}
			}
		}
		numberOfStudents --;
		remove(nameOfFile);
		rename("temp.dat",nameOfFile);
	}
	catch (Error &o) {
		o.displayError();
		this->getData();
	}
}
void Database::modifyRecord() {
	string a,b,searcher;
	cout << "Enter the Name of Student or Roll Number of Student\n";
	cin >> searcher;
	ofile.open("temp.dat",ios::binary);
	ifile.open(nameOfFile,ios::binary);
	try {
		if(ifile.eof() || ofile.eof()) {
			throw Error(456,"No such file exists\nPlease create Database first\n");
		}
		else {
			for(int i = 0;i<numberOfStudents;i++) {
				ifile >> a >> b;
				if(a!=searcher && b != searcher) {
					ofile << a << endl << b << endl;
				}
				else {
					cout << "Enter the Name and Roll Number of Student\n";
					cin >> a >> b;
					ofile << a << endl << b << endl;
				}
			}
		}
			remove(nameOfFile);
			rename("temp.dat",nameOfFile);
		}
		catch (Error &o) {
			o.displayError();
			this->getData();
		}
}
void Database::searchRecord() {
	string a,b,searcher;
		cout << "Enter the Name of Student or Roll Number of Student\n";
		cin >> searcher;
		ifile.open(nameOfFile,ios::binary);
		try {
			if(ifile.eof()) {
				throw Error(456,"No such file exists\nPlease create Database first\n");
			}
			else {
				for(int i = 0;i<numberOfStudents;i++) {
					ifile >> a >> b;
					if(a==searcher && b == searcher) {
						cout << a << endl << b << endl;
					}
				}
			}
		}
		catch (Error &o) {
			o.displayError();
			this->getData();
		}
}
void Database::deleteFile() {
	remove(nameOfFile);
}
int main(int argc, char **argv) {
	Database dat;
	string saveFile;
	int option;
	do {
		cout << "1. Create Database\n"
				"2. Display Database\n"
				"3. Add a Record\n"
				"4. Delete a Record\n"
				"5. Modify a Record\n"
				"6. Search a Record\n"
				"7. Exit\n";
		cin >> option;
		switch(option) {
		case 1 : {
			dat.getData();
			break;
		}
		case 2 : {
			dat.display();
			break;
		}
		case 3 : {
			dat.addRecord();
			break;
		}
		case 4 : {
			dat.deleteRecord();
			break;
		}
		case 5 : {
			dat.modifyRecord();
			break;
		}
		case 6 : {
			dat.searchRecord();
			break;
		}
		case 7 : {
			cout << "Do you want to save the file\n";
			cin >> saveFile;
			if(saveFile == "y" || saveFile == "Y"
					|| saveFile == "yes" || saveFile == "Yes") {
				dat.deleteFile();
			}
			return 0;
		}
		}
	}while(true);
}
