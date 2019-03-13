#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


using namespace std;


void getName(ifstream& in, ofstream& out){
	string Name;
	char read;
	while(!in.eof()){
		in.get(read);
		out.put(read);
		if (read == '#N#'){
			in.putback(read);
			cout << "Enter the name of the recipient: ";
			cin >> Name;
			out << Name;
		}
	}
}

int main(){
	ifstream infile;
	ofstream outfile;
	
	cout << "Welcome to junk mail generator!" << endl;
	cout << endl;
	
	
	
	infile.open("junk.txt");
	if(infile.fail()){
		cout << "Failed!\n";
		exit(1);
	}
	
	outfile.open("p.txt");
	if(outfile.fail()){
		cout << "Failed!\n";
		exit(1);
	}
	
	getName(infile, outfile);
	
	infile.close();
	outfile.close();
	
	return 0;
}