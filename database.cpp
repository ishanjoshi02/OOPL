/*
 * Design a base class with name, Date of Birth, Blood group and another base containing data members height and weight
design 1 more base class containing insurance policy no and contact address
the derived class containing data ember Telephone Number and Driving license no
 */
#include <iostream>
#include <stdio.h>
using namespace std;
class base1 {
	char dob[11];
	char bloodgroup[7];
public:
	char name[101];
	void getData();
	void display();
};
class base2 {
	short int height;
	short int weight;
public:
	void getData1();
	void display1();
};
class base3 {
	int policy;
	char address[501];
public:
	void getData2();
	void display2();
};
class derived : public base1,public base2,public base3 {
	int telephoneNumber;
	int drivingLicenseNumber;
public:
	short int present;
	derived();
	void get();
	void show();
};
derived::derived() {
	present = 0;
	telephoneNumber = 0;
	drivingLicenseNumber = telephoneNumber;
}
void base1::getData() {
	cout<<"Enter Name of Employee\n";
	cin>>name;
	cout<<"Enter the Employee's Date of Birth\n";
	cin>>dob;
	cout<<"Enter Blood Group of Employee\n";
	cin>>bloodgroup;
}
void base1::display() {
	cout<<"Name : "<<name<<endl;
	cout<<"Date of Birth : "<<dob<<endl;
	cout<<"Blood Group : "<<bloodgroup<<endl;
}
void base2::getData1() {
	cout<<"Enter the Height of Employee\n";
	cin>>height;
	cout<<"Enter the Weight of Employee\n";
	cin>>weight;
}
void base2::display1() {
	cout<<"Height : "<<height<<endl;
	cout<<"Weight : "<<weight<<endl;
}
void base3::getData2() {
	cout<<"Enter the Policy Number of Employee\n";
	cin>>policy;
	cout<<"Enter the Contact Address of Employee\n";
	cin>>address;
}
void base3::display2() {
	cout<<"Insurance Policy Number : " <<policy<<endl;
	cout<<"Contact Address : "<<address<<endl;
}
void derived::get() {
	base1::getData();
	base2::getData1();
	base3::getData2();
	cout<<"Enter the Employee's Telephone Number\n";
	cin>>telephoneNumber;
	cout<<"Enter the Driving License Number of Employee\n";
	cin>>drivingLicenseNumber;
}
void derived::show() {
	base1::display();
	base2::display1();
	base3::display2();
	cout<<"Telephone Number : "<<telephoneNumber<<endl;
	cout<<"Driving License Number : "<<drivingLicenseNumber<<endl;
}
int main() {
	derived obj[50],temp;
	char ans,name[101];
	short int opt,i,j=-1,no,flag,k;
	while(true) {
		cout<<"1.Build a Master Table\n2.Display all Records\n3.Insert a new entry\n4.Delete an Entry\n5.Modify a record\n6.Search a Record\n";
		cin>>opt;
		switch(opt) {
			case 1 : {
				do {
					j++;
					obj[j].get();
					obj[j].present = 1;
					cout<<"\nAdd Another Record"<<"y\\n\n";
					cin>>ans;
				}while(ans == 'Y' || ans == 'y');
			break;
			}
			case 2 : {
			for(i=0;i<=j;i++) {
				flag = 0;
				for(k=0;k<=50;k++) {
					if(obj[i].present != 0)
					obj[i].show();
				}
			}
			break;
			}
			case 5: {
			cout<<"Enter the Existing Record Number\n";
			cin>>no;
			if(no<=j) {
				for(i=no;i<=j;i++) {
				temp = obj[i];
				obj[i+1] = temp;
				}
				obj[no].get();
				j++;
				cout<<"Record Inserted Successfully\n";
			}
			break;
			}
			case 4: {
				if(j == -1) {
					cout<<"No Records exist!\nCreate a Database to Delete it\n";
					break;
				}
				cout<<"Enter the Record Number to deleted\n";
				cin>>no;
				obj[no].present = 0;
			break;
			}
			case 3: {
				j++;
				obj[j].get();
				obj[j].present = 1;
				break;
			}
			case 6: {
				cout<<"Enter the Name of Employee\n";
				cin>>name;
				for(i=0;i<=j;i++) {
					if(name == obj[i].name) {
						obj[i].show();
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					cout<<"Did not find record of Person\n";
				}
				break;
			}
		}
	}
}
