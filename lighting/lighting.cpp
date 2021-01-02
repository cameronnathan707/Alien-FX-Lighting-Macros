
//Lighting_Editor
//This is a code to recive input from autohotkey
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
string colour;
void choices(int a){

	if (a == 1) {
		//purple blue
		colour = "purple/blue";
	}
	else if (a == 2) {
		//green blue
		colour = "green/blue";
	}
	else if (a == 3) {   
		//red purple
		colour = "red/purple";
	}
	else if (a == 4) {
		//white
		colour = "white";
	}
	else if (a == 5) {
		//rainbow wave
		colour = "rainbow wave";
	}
}
int main( int argc, char* argv[]) {
	string arg1 = argv[1];
	string arg2 = argv[2];
	ofstream myfile;
    choices(stoi(arg2));
	myfile.open("C:/Users/camer/Desktop/test.txt");
	myfile << "Write variable to file: " + arg1 + " " + arg2+"\n"+colour;
	myfile.close();
	cout << colour;
    return 0;
}
