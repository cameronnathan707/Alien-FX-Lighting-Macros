// lighting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Lighting_Editor
//This is a code to recive input from autohotkey
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void choices(int a){

	if (a == 1) { cout << "thats a one"; }
	else {
		cout << "thats not";
	}
}
int main( int argc, char* argv[]) {
	string temp = argv[2];
	string te = argv[1];
	ofstream myfile;
	myfile.open("C:/Users/camer/Desktop/test.txt");
	myfile << "Write variable to file: " + te + " " + temp;
	myfile.close();
	
    choices(stoi(temp));
    return 0;
}
