#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T>
class Matrix {
	T v[10][10];
	int row,col;
public :
	Matrix(int,int);
	Matrix();
	void accept();
	void display();
	void add(Matrix<T>);
};
template<class T>
void Matrix<T>::add(Matrix<T> b) {
	Matrix<T> c;
	if(row != b.row || col != b.col) {
		cout << "Invalid Values for Row and Column\nThey should be the Same\n";
		exit(0);
	}
	for(int i = 0;i < row;i++) {
		for(int j = 0; j < col;j++) {
			c.v[i][j] = v[i][j] + b.v[i][j];
		}
	}
	c.display();
}
template<class T>
Matrix<T>::Matrix(int a,int b) {
	row = a;
	col = b;
}
template<class T>
Matrix<T>::Matrix() {
	row = 10;
	col = 10;
}
template<class T>
void Matrix<T>::accept(){
	cout<<"Enter the Elements Now\n";
	for(int i=0;i<=row;i++) {
		for(int j=0;j<row;j++) {
			cin >> v[i][j];
		}
	}
}
template<class T>
void Matrix<T>::display() {
	cout<<"Displaying the Elements now\n";
	for(int i=0;i<=row;i++) {
		for(int j=0;j<row;j++) {
			cout << v[i][j] << "\t";
		}
		cout << endl;
	}
}
int menu() {
	int opt;
	cout << "1.Accept the First Matrix\n2.Accept the Second Matrix\n"
		 << "3.Add the Two Matrices\n4.Multiply the Two Matrices\n"
		 << "5.Transpose of First Matrix\n6.Transpose of Second Matrix\n"
		 << "7.Saddle Point of First Matrix\n8.Saddle Point of Second Matrix\n";
	cin >> opt;
	return opt;
}
int main() {
	Matrix<int> a,b;
	Matrix<float>c,d;
	int row,col,opt;
	do {
		cout << "1.Integer Array Operations\n2.Float Array Operations\n";
		cin >> opt;
		switch(opt) {
		case 1 : {
			switch(menu()) {
			case 1 : {
				cout << "Enter the Number of Rows and Columns\n";
				cin >> row >> col;
				a = Matrix<int>(row,col);
				a.accept();
				break;
			}
			case 2 : {
				cout << "Enter the Number of Rows and Columns\n";
				cin >> row >> col;
				b = Matrix<int>(row,col);
				b.accept();
				break;
			}
			case 3 : {
				a.add(b);
				break;
			}
			}
		}
		break;
		}
	}while(true);
}
