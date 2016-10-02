#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student {
public:
	string name,rollNumber,contactAddress;
};
class Files : protected  Student {
	fstream file;
	Student s[15];
	int numberOfStudent;
	char nameOfFile[20] = "Ishan.txt";
public :
	void create();
	void display();
	void insert();
	void deleteRecord();
	void modifyRecord();
	void removeFile();
};
void Files::removeFile() {
	remove(nameOfFile);
}
void Files::create() {
	cout << "Enter the Number of Student in Database\n";
	cin >> numberOfStudent;
	file.open(nameOfFile,ios::out|ios::in);
	for(int i=0;i<numberOfStudent;i++) {
		cout << "Enter the Name, Roll Number and Contact Address of Student " << i + 1
				<< endl ;
		cin >> s[i].name >> s[i].rollNumber >> s[i].contactAddress ;
		file << s[i].rollNumber <<endl<< s[i].name << endl <<s[i].contactAddress << endl;
	}
	file.close();
}
void Files::display() {
	file.open(nameOfFile,ios::out|ios::in);
	for(int i=0;i<numberOfStudent;i++) {
		file >> s[i].rollNumber >> s[i].name >> s[i].contactAddress;
		cout << "Name : " << s[i].name << endl
				<< "Roll Number : " << s[i].rollNumber << endl
				<< "Contact Address : " << s[i].contactAddress << endl;
	}
	file.close();
}
void Files::insert() {
	file.open(nameOfFile,ios::app|ios::out);
	numberOfStudent++;
	int i = numberOfStudent - 1;
	cout << "Enter the Name, Roll Number and Contact Address of Student " << numberOfStudent
			<< endl ;
	cin >> s[i].name >> s[i].rollNumber >> s[i].contactAddress ;
	file << s[i].rollNumber <<endl << s[i].name <<endl<<s[i].contactAddress << endl;
	file.close();
}
void Files::modifyRecord() {
	string answer;
	cout << "Enter the Roll Number of Student\n";
	cin >> answer;
	for(int i=0;i<numberOfStudent;i++) {
		file >> s[i].rollNumber;
		if(s[i].rollNumber == answer) {

			cout << "Enter the Name, Roll Number and Contact Address of Student " << i + 1
					<< endl ;
			cin >> s[i].name >> s[i].rollNumber >> s[i].contactAddress ;
			file << s[i].rollNumber <<endl<< s[i].name << endl <<s[i].contactAddress << endl;
			break;
		}
	}
	file.close();
}
void Files::deleteRecord() {
	string answer;
	fstream temp;
	cout << "Enter the Roll Number of Student\n";
	cin >> answer;
	file.open(nameOfFile);
	temp.open("temp.txt");
	for(int i = 0; i < numberOfStudent ;i++) {
		if(s[i].rollNumber != answer) {
			temp << s[i].rollNumber <<endl<< s[i].name << endl <<s[i].contactAddress << endl;
		}
	}
	file.close();
	remove(nameOfFile);
	rename("temp.txt",nameOfFile);
}
int main(int argc, char **argv) {
	Files fp;
	int opt;
	do {
		cout << "1. Create a Database\n"
				<< "2. Display the Database\n"
				<< "3. Add a Record\n"
				<< "4. Delete a Record\n"
				<< "5. Modify a Record\n"
				<< "6. Exit\n";
		cin >> opt;
		switch(opt) {
		case 1 : {
			fp.create();
			break;
		}
		case 2 : {
			fp.display();
			break;
		}
		case 3 : {
			fp.insert();
			break;
		}
		case 4 : {
			fp.deleteRecord();
			break;
		}
		case 5 : {
			fp.modifyRecord();
			break;
		}
		}
	}while(true);
	cout << "Do you want to save the File?\n1.Yes\n2.No\n";
	cin >> opt;
	if(opt == 2) {
		fp.removeFile();
	}
}
