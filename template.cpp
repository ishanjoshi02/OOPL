#include <iostream>
#include <stdlib.h>
#define MAX 15
using namespace std;
template <class T>
void displayMatrix(T c[][MAX],int row, int col);
template <class T>
class Matrix {
	T v[MAX][MAX];
	int row, col;
public :
	void accept();
	void display();
	void operator +(Matrix);
	void operator *(Matrix);
	void transpose();
	void saddlePoint();
};
template <class T>
void Matrix<T>::saddlePoint() {
	T min[row], max;
	int i;
	for(i = 0 ; i < row ; i++ ) {
		min[i] = this->v[i][0];
		for(int j = 0 ; j < col ; j++ ) {
			if(min[i] > this->v[i][j]) {
				min[i] = v[i][j];
			}
		}
	}
	max = min[0];
	for(i = 0 ; i < row ; i++ ) {
		if(max < min[i]) {
			max = min[i];
		}
	}
	cout << "Saddle Point is " << max << endl;
}
template <class T>
void Matrix<T>::transpose() {
	T c[MAX][MAX];
	for(int i = 0 ; i < row ; i++ ) {
		for(int j = 0; j < col ; j++) {
			c[j][i]  = this->v[i][j];
		}
	}
	displayMatrix(c,row,col);
}
template <class T>
void displayMatrix(T c[][MAX],int row, int col) {
	for(int i = 0 ; i < row ; i++ ) {
		for(int j = 0 ; j < col ; j++ ) {
			cout << c[i][j] << "\t";
		}
		cout << endl;
	}
}
template <class T>
void Matrix<T>::operator *(Matrix b) {
	T c[MAX][MAX];
	/*if(row != b.row || col != b.col) {
		cout << "Invalid Values for Row and Column\nThey should be the Same\n";
		exit(1);
	}*/
	for(int i = 0 ; i < row ; i++ ) {
		for(int j = 0 ; j < col ; j++ ) {
			c[i][j] = 0;
			for(int k = 0 ; k < b.row ; k++ ) {
				c[i][j] += this->v[i][k] + b.v[k][j];
			}
		}
	}
	displayMatrix(c,row,col);
}
template <class T>
void Matrix<T>::operator +(Matrix b) {
	T c[MAX][MAX];
	if(row != b.row || col != b.col) {
		cout << "Invalid Values for Row and Column\nThey should be the Same\n";
		exit(1);
	}
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < b.col; j++) {
			c[i][j] = b.v[i][j] + this->v[i][j];
		}
	}
	displayMatrix(c,row,col);
}
template <class T>
void Matrix<T>::accept() {
	cout << "Enter the Number of Rows and Columns in the Matrix\n";
	cin >> row >> col;
	cout << "Enter the Elements now\n";
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cin >> v[i][j];
		}
	}
}
template <class T>
void Matrix<T>::display() {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cout << v[i][j] << "\t";
		}
		cout << "\n";
	}
}
int menu() {
	int opt;
	cout << "1.Accept the First Matrix\n2.Accept the Second Matrix\n"
			<< "3.Add the Two Matrices\n4.Multiply the Two Matrices\n"
			<< "5.Transpose of First Matrix\n6.Transpose of Second Matrix\n"
			<< "7.Saddle Point of First Matrix\n8.Saddle Point of Second Matrix\n"
			<<	"9. Exit\n";
	cin >> opt;
	return opt;
}
int main() {
	int opt;
	Matrix<int> a,b;
	Matrix<float> c,d;
	do {
		cout << "1.Integer Array Operations\n2.Float Array Operations\n";
		cin >> opt;
		switch(opt) {
		case 1 : {
			switch(menu()) {
			case 1 : {
				a.accept();
				a.display();
				break;
			}
			case 2 : {
				b.accept();
				b.display();
				break;
			}
			case 3 : {
				a + b;
				break;
			}
			case 4 : {
				a * b;
				break;
			}
			case 5 : {
				a.transpose();
				break;
			}
			case 6 : {
				b.transpose();
				break;
			}
			case 7 : {
				a.saddlePoint();
				break;
			}
			case 8 : {
				b.saddlePoint();
				break;
			}
			default : {
				return 0;
			}
			}
			break;
		}
		case 2 : {
			switch(menu()) {
			case 1 : {
				c.accept();
				c.display();
				break;
			}
			case 2 : {
				d.accept();
				d.display();
				break;
			}
			case 3 : {
				c + d;
				break;
			}
			case 4 : {
				c * d;
				break;
			}
			case 5 : {
				c.transpose();
				break;
			}
			case 6 : {
				d.transpose();
				break;
			}
			case 7 : {
				c.saddlePoint();
				break;
			}
			case 8 : {
				d.saddlePoint();
				break;
			}
			default : {
				return 0;
			}
			}
			break;
		}
		}
	}while(true);
}
