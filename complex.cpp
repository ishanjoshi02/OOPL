/*
 * Design a class ‘Complex ‘with data members for real and imaginary part.
 * Provide default and parameterized  constructors.
 * Write  a  program  to  perform  arithmetic  operations of two Complex Numbers
 *
 * i. Addition and Subtraction using friend functions
 * ii. Multiplication and DIvisiom using Member functions
 */
#include <iostream>
using namespace std;
class Complex {
	int real,imaginary;
public:
	friend Complex getData(Complex);
	Complex multiply(Complex);
	Complex divide(Complex);
	friend Complex addition(Complex, Complex);
	friend Complex subtraction(Complex, Complex);
	friend void display(Complex);
};
Complex getData(Complex t) {
	cout<<"Enter the Real Part\n";
	cin>>t.real;
	cout<<"Enter the Imaginary Part\n";
	cin>>t.imaginary;
	return t;
}
Complex Complex::multiply(Complex t2) {
	Complex t;
	t.real = real*t2.real + real*t2.imaginary;
	t.imaginary = imaginary*t2.real + imaginary*t2.imaginary;
	return t;
}
void display(Complex t1) {
	if(t1.imaginary==0) {
		cout<<t1.real<<endl;
	}
	if(t1.imaginary<0) {
		cout<<t1.real<<"-"<<t1.imaginary<<"i"<<endl;
	}
	if(t1.imaginary>0) {
		cout<<t1.real<<"+"<<t1.imaginary<<"i"<<endl;
	}
}
Complex Complex::divide(Complex t2) {
	Complex t;
	t.real = (real*t2.real - real*t2.imaginary)/(((t2.real)^2) + ((t2.imaginary)^2));
	t.imaginary = (imaginary*t2.real - imaginary*t2.imaginary)/(((t2.real)^2) + ((t2.imaginary)^2));
	return t;
}
Complex addition(Complex t1,Complex t2) {
	Complex t;
	t.real = t1.real + t2.real;
	t.imaginary = t1.imaginary + t2.imaginary;
	return t;
}
Complex subtraction(Complex t1,Complex t2) {
	Complex t;
	t.real = t2.real - t1.real;
	t.imaginary = t2.imaginary - t1.imaginary;
	return t;
}
int main(int argc, char **argv) {
	Complex t1,t2;
	short int opt;
	do {
		cout<<"1. Add Two Complex Numbers\n2. Subtract Two Complex Numbers\n";
		cout<<"3. Divide Two Complex Numbers\n4. Multiply Two Complex Numbers\n5. Exit\n";
		cin>>opt;
		switch(opt) {
		case 1 : {
			display(addition(getData(t1),getData(t2)));
			break;
		}
		case 2 : {
			display(subtraction(getData(t1),getData(t2)));
			break;
		}
		case 4 : {
			display(getData(t1).multiply(getData(t2)));
			break;
		}
		case 3 : {
			display(getData(t1).divide(getData(t2)));
			break;
		}
		case 5 : {
			return 0;
		}
		}
	}while(true);
}

