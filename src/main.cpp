#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#include "../headers/testCalcFunc.h"
#include "testCalcFunc.cpp"

struct student {
	string id, courseNo, Grade;
};

struct instructor {
	string id, courseNo, TermId;
};

struct term{
	string id, displayName;
};

struct course{
	string id, courseNo, sectionNo, term;
};

int main() {

	std::ifstream readFile;
	std::ofstream outputFile;
	
	string courseNo, docNum;
	cout << "Enter the course number. (1115, 3115, 3130)"<< endl;
	cin >> courseNo; // user input
	string skipLine, used;
	outputFile.open("../outputFiles/"+ courseNo+ ".txt");

	if ( courseNo == "1115" || courseNo == "3115" || courseNo == "3130"){ //check input
		if(courseNo == "1115"){
			docNum = "1115";
			readFile.open("./csvFiles/1115.csv");
		}
		if(courseNo == "3115"){
			docNum = "3115";
			readFile.open("./csvFiles/3115.csv");
		}
		if(courseNo == "3130"){
			docNum = "3130";
			readFile.open("./csvFiles/3130.csv");
		}
	} else {
		cout << "Entered string is not valid" << endl;
	}
	outputFile << "Total student per prof \n\n";
	printMap(findTotalStuProf(docNum,outputFile),outputFile); // prints map first and second
	outputFile << '\n';

	outputFile << "Number of W(ithdrawals) per prof \n\n";
	printMap(wPerProf(docNum), outputFile); //prints wmap first and second
	outputFile << '\n';

	calcSpringPass(docNum, outputFile); //calculates rate of passing in Spring
	calcFallPass(docNum, outputFile); //calculates rate of passing in Fall
	calcCoursePass(docNum, outputFile); //calculates rate of passing overall
}


