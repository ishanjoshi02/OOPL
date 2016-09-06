/*
 *Create a  class  named  weather  report  that  holds  a daily  weather
 *report  with  data  membersday_of_month, hightemp, lowtemp,a mount_rain and
 *amount_snow.Use different types of constructors to initialize the objects.
 *Also include a function that prompts the user and sets values for each field
 *so that you can override the default values.
 *Write  a  menu  driven  program  in  C++  with  options  to  enter
 *data  and  generate  monthly report that displays average of each attribute.
 *Author : Ishan Joshi
 *Roll Number : 3154166
 */

#include <iostream>
#include <string.h>
using namespace std;
class Weather {
	char dayOfMonth[21];
	short int highTemp,lowTemp, amountRain, amountSnow;
public:
	Weather();
	void getData();
	void display();
};
Weather::Weather() {
	strcpy(dayOfMonth,"01/01/2016");
	highTemp = 99;
	lowTemp = 0;
	amountRain = 0;
	amountSnow = 0;
}
void Weather::getData() {
	cout<<"Enter the Date\n";
	cin>>dayOfMonth;
	cout<<"Enter the Highest Temperature Recorded\n";
	cin>>highTemp;
	cout<<"Enter the Lowest Temperature Recorded\n";
	cin>>lowTemp;
	cout<<"Enter the Amount of Rain today\n";
	cin>>amountRain;
	cout<<"Enter the Amount of Snow today\n";
	cin>>amountSnow;
}
void Weather::display() {
	cout<<"Date :"<<dayOfMonth<<endl;
	cout<<"Highest Temperature Recorded: "<<highTemp<<endl;
	cout<<"Lowest Temperature Recorded: "<<lowTemp<<endl;
	cout<<"Amount of Rainfall : "<<amountRain<<endl;
	cout<<"Amount of Snowfall :"<<amountSnow<<endl;
}
int main() {
	Weather obj[30];
	short int opt,j = -99,i;
	char ans[10];
	do {
		cout<<"1. Create a Master Table\n2. Display the Weather Report\n3. Exit\n";
		cin>>opt;
		switch(opt) {
		case 1 : {
			j = -1;
			do {
				j++;
				obj[j].getData();
				cout<<"Do you to continue adding\n";
				cin>>ans;
			}while(strcmp(ans,"yes")==0);
			break;
		}
		case 2 : {
			if(j == -99) {
				cout<<"Please create a Master Table beforing displaying it\n";
			break;
			}
			for(i=0;i<j+1;i++) {
				obj[i].display();
			}
		break;
		}
		case 3 : {
			return 0;
		}
		}
	}while(true);
}

