#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ofstream ofile;
	ifstream ifile;
	string h;
	ofile.open("abc.txt",ios::binary);
	ofile << "Hi there,\nI am a Computer\n";
	ofile.close();
	ifile.open("abc.txt",ios::binary);
	while(!ifile.eof()) {
		ifile >> h;
		cout << h << " ";
	}
	ifile.close();
}
