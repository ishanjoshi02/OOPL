/*
 * Create employee bio-data using following classes i) Personal record

ii))Professional record iii) Academic record Assume appropriate

data members and member function to accept required data &amp;

print bio-data. Create bio-data using multiple inheritance using C++.
 */
#include <iostream>
#include <string>
using namespace std;
class Personal {
	string address, number;
public :
	void getData();
	void display();
};
void Personal::getData() {
	cout << "Enter the Contact Address of Employee\n";
	getline(cin,address);
	cout << "Enter the Home Number of Employee\n";
	getline(cin,number);
}
void Personal::display() {
	cout << "Contact Address : "
			<< address << endl
			<< "Home Number : "
			<< number << endl;
}
class Professional {
	string currentCompany, employeeID;
public :
	void getData();
	void display();
};
void Professional::getData() {
	cout << "Enter Company Name : \n";
	getline(cin,currentCompany);
	cout << "Enter the Employee ID :\n";
	getline(cin,employeeID);
}
void Professional::display() {
	cout << "Company Name : " << currentCompany
			<< endl << "Employee ID : "
			<< employeeID <<endl;
}
class Academic {
	float mark1,mark2;
public :
	void getData();
	void display();
};
void Academic::getData() {
	cout << "Enter the 10th Percentage :\n";
	cin >> mark1;
	cout << "Enter the 12th Percentage :\n";
	cin >> mark2;
}
void Academic::display() {
	cout << "10th Percentage :" << mark1
			<< endl << "12th Percentage :"
			<< mark2 << endl;
}
class All : private Personal, private Professional, private Academic{
public :
	void getData();
	void display();
};
void All::getData() {
	Personal::getData();
	Professional::getData();
	Academic::getData();
}
void All::display() {
	Personal::display();
	Professional::display();
	Academic::display();
}
int main() {
	All a;
	short int opt;
	do {
		cout << "1. Enter the Data \n"
					"2. Display the Data\n"
						"3. Exit\n";
		cin >> opt;
		switch(opt) {
		case 1 : {
			a.getData();
			break;
		}
		case 2 : {
			a.display();
			break;
		}
		default : {
			return 0;
		}
		}
	}while(true);
}
