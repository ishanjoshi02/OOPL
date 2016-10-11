#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Database {
	fstream file;
	int numberOfStudents;
public :
	void create();
	void display();
	void addRecord();
	void deleteRecord();
	void modifyRecord();
	void deleteFile();
};
void Database::create() {
	static int i;
	char another;
	string a,b;
	file.open("abc.txt",ios::out);
	if(file.eof()) {
		cout << "File not created\n";
		if(i==1) {
			cout << "Trying again\n";
			return;
		}
		i = 1;
		this->create();
	}
	do {
		cout << "Enter Name and Roll Number\n";
		cin >> a >> b;
		file << a << endl << b << endl;
		cout << "Do you want to add another\n";
		cin >> another;
	}while(another=='Y'||another=='y');
	file.close();
}
void Database::display() {
	string a,b;
	file.open("abc.txt",ios::in);
	if(file.eof()) {
		cout << "File doesn't exist\n";
		this->create();
	}
	while(!file.eof()) {
		file >> a >> b;
		cout << "Name :" << a << endl
				<<"Roll Number : " << b << endl;
	}
	file.close();
}
void Database::addRecord() {
	char another;
	string a,b;
	file.open("abc.txt",ios::app);
	if(file.eof()) {
		cout << "File doesn't exist\n";
		this->create();
	}
	do {
			cout << "Enter Name and Roll Number\n";
			cin >> a >> b;
			file << a << endl << b << endl;
			cout << "Do you want to add another\n";
			cin >> another;
		}while(another=='Y'||another=='y');
		file.close();
}
void Database::deleteRecord() {
	fstream temp;
	temp.open("temp.txt",ios::out);
	file.open("abc.txt",ios::in);
	if(file.eof()) {
		cout << "File doesn't exist\n";
		this->create();
	}
	string a,b,element;
	cout <<  "Enter the Roll Number or Name of Student\n";
	cin >> element;
	while(!file.eof()) {
		file >> a >> b;
		if(a==element || b==element) {
			continue;
		}
		temp << a << endl
				<< b << endl;
	}
	remove("abc.txt");
	rename("temp.txt","abc.txt");
	file.close();
	temp.close();
}
void Database::modifyRecord() {
	ofstream temp;
	temp.open("temp.txt",ios::out);
	file.open("abc.txt",ios::in);
	if(file.eof()) {
		cout << "File not created\n";
		this->create();
	}
	string a,b,element;
	cout << "Enter the Roll Number or Name of Student\n";
	cin >> element;
	while(!file.eof()) {
		file >> a >> b;
		if(a==element || b==element) {
			cout << "Enter the Changed Name and Roll Number of Student";
			cin >> a >> b;
		}
		temp << a << endl
				<< b << endl;
	}
	remove("abc.txt");
	rename("temp.txt","abc.txt");
	file.close();
	temp.close();
}
void Database::deleteFile() {
	remove("abc.txt");
}
int main(int argc, char **argv) {
	Database dat;
	short int option;
	do {
		cout << "1. Create a Database\n"
				"2. Display the Database\n"
				"3. Add a Record\n"
				"4. Delete a Record\n"
				"5. Modify a Record\n"
				"6. Exit\n";
		cin >> option;
		switch(option) {
		case 1 : {
			dat.create();
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
			string save;
			cout << "Want to save the File?\n";
			cin >> save;
			if(save == "No"||save == "no"
					|| save == "n" || save == "N") {
				dat.deleteFile();
			}
			return 0;
		}
		}
	}while(true);
}

