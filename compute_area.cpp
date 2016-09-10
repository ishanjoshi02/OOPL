#include <iostream>
using namespace std;
class Shape {
	protected :
	double dimension1,dimension2;
	virtual void getData() {}
	virtual double compute_Area() {}
};
class Triangle : public Shape {
public :
	double compute_Area();
	void getData();
};
void Triangle::getData() {
	cout << "Enter the length of Base of Triangle\n";
	cin >> dimension1;
	cout << "Enter the height of the Triangle\n";
	cin >> dimension2;
}
double Triangle::compute_Area() {
	return (dimension1*dimension2)/2;
}
class Rectangle : public Shape {
public :
	double compute_Area();
	void getData();
};
void Rectangle::getData() {
	cout << "Enter the length of Rectangle\n";
	cin >> dimension1;
	cout << "Enter the height of Rectangle\n";
	cin >> dimension2;
}
double Rectangle::compute_Area() {
	return dimension1*dimension2;
}
int main() {
	short int opt1;
	Triangle T;
	Rectangle R;
	do {
		cout << "1.Triangle Operations\n2.Rectangle Operations\n3.Exit\n";
		cin >> opt1;
		switch (opt1) {
		case 1 : {
			T.getData();
			cout << "The Area for the Triangle is : \n"<<T.compute_Area()<<endl;
			break;
		}
		case 2 : {
			R.getData();
			cout << "The Area for the Rectangle is : \n"<<R.compute_Area()<<endl;
			break;
		}
		case 3 : {
			return 0;
		}
		}
	}while(true);
}
