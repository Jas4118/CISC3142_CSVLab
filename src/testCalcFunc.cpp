#include <string>
#include <iostream>
#include <map>

#include "../headers/testCalcFunc.h"

map<string,float> findTotalStuProf(string docNum,std::ofstream& outputFile){
	string str, professorId;
	int column = 0, stuTotal = 0, overallStudentTotal = 0, studentPassed = 0;
	ifstream readFile("./csvFiles/" + docNum + ".csv"); // file to read from
	map<string,float> stuTotalProf; //map containing number of students to each prof
	getline(readFile,str); //skip heading

	while(readFile.good()){ // reading file
		string line;
		getline(readFile, line, ','); // reading file by comma and setting value to line
		column++; // iterating to keep track of value

		if(column == 3) { // checks column 3 which is profId
			professorId = line;
			if(stuTotalProf.find(professorId) == stuTotalProf.end()){ // if professorId wasn't found as key then it will be inserted
				stuTotal = 1;
				stuTotalProf.insert({professorId, stuTotal});
			}
			else {
				stuTotal = stuTotalProf.at(professorId)+1; //itterating value of key-value pair
				stuTotalProf.erase(professorId);
				stuTotalProf.insert({professorId, stuTotal}); //replacing key-value pair

			}
		}
		else if(column == 6) { // grade column
                        string grade = line.substr(0,1); //grade is substring of line since line is seperated by comma
			stuTotal++;
                        column = 1; // setting back to 1 to help keep track
			overallStudentTotal++;
		}
		
	}
	outputFile << "Overall student total in " <<docNum << " is: " << overallStudentTotal << endl;

	return stuTotalProf; //returns map to be printed by printMap
}

float calcCoursePass(string docNum,std::ofstream& outputFile){
	string str;
        int column = 0, stuTotal = 0, stuPassed = 0;
        ifstream readFile("./csvFiles/" + docNum + ".csv"); // file to read from 
        getline(readFile,str); // skip title

        while(readFile.good()){ // reading file
                string line;
                getline(readFile, line, ','); //reading value and setting line to the string before comma
                column++; //iterating to keep track of value

                if(column == 6) {
                        string grade = line.substr(0,1); //grade is substring of line since line is seperated by comma
			stuTotal++; //stuTotal iterates when grade is determined meaning a student took the course and received grade
			if(grade != "F" && grade != "W" && grade != "WU" && grade != "WN" && grade != "WD" && grade != "FIN"){ // checking for failing grades/withdrawal grades
				stuPassed++;
			}
                        column = 1; // setting back to 1 to help keep track
                }
        }
	float passRateCourse = (float) stuPassed / (float) stuTotal; //decimal percentage
	passRateCourse = passRateCourse*100;
	outputFile <<"Overall pass rate for " << docNum << " is " << passRateCourse <<"%"<<endl;
        return passRateCourse; // return float to print

}

float calcSpringPass(string docNum,std::ofstream& outputFile){
        string str,termId;
        bool isSpring=false; // flag changed when checking for Spring classes
        int column = 0, stuTotal = 0, stuPassed = 0;
        ifstream readFile("./csvFiles/" +docNum + ".csv"); // file to read from
        getline(readFile,str); // skip title

        while(readFile.good()){ // reading file
                string line;
                getline(readFile, line, ','); //reading value and setting line to the string before comma
                column++; //iterating to keep track of value

                if(column == 4){ // termIds
                        if(line == "T02" || line == "T06" || line == "T10" || line == "T14" || line == "T18" || line == "T21"){ //checking for Spring classes
                                isSpring=true;
                        }

                }

                if(column == 6) { // grades
                        string grade = line.substr(0,1); //grade is substring of line since line is seperated by comma
                        if(isSpring==true){
                                if(grade != "F" && grade != "W" && grade != "WU" && grade != "WN" && grade != "WD" && grade != "FIN"){ // checking for failing grades/withdrawal grades
                                        stuPassed++;
                                }
                                stuTotal++;
                        }
                        column = 1; // setting back to 1 to help keep track
                        isSpring=false; // setting isSpring back to false to prep for next line
                }

        }

        float passRateCourse = (float) stuPassed / (float) stuTotal; //decimal percentage
        cout << stuPassed << " passed " << stuTotal << " Total Spring" << endl;
        passRateCourse = passRateCourse*100;
        outputFile <<"Spring pass rate for " << docNum << " is " << passRateCourse <<"%"<<endl;
        return passRateCourse; // return float to print
 
}


float calcFallPass(string docNum,std::ofstream& outputFile){
        string str,termId;
        bool isFall=false; // flag changed when checking for Fall classes
        int column = 0, stuTotal = 0, stuPassed = 0;
        ifstream readFile("./csvFiles/" +docNum + ".csv"); // file to read from
        getline(readFile,str); // skip title

        while(readFile.good()){ // reading file
                string line;
                getline(readFile, line, ','); //reading value and setting line to the string before comma
                column++; //iterating to keep track of value

                if(column == 4){ // termIds
                        if(line == "T04" || line == "T08" || line == "T12" || line == "T16" || line == "T20" || line == "T23"){
                                isFall=true;
                      	}

                }

                if(column == 6) {
                        string grade = line.substr(0,1); //grade is substring of line since line is seperated by comma
			if(isFall==true){
                        	if(grade != "F" && grade != "W" && grade != "WU" && grade != "WN" && grade != "WD" && grade != "FIN"){ //checking for Fall classes
                                	stuPassed++;
                        	}
				stuTotal++;
			}
                        column = 1; // setting back to 1 to help keep track
                        isFall=false; // setting isFall back to false to prep for next line
                }

        }

        float passRateCourse = (float) stuPassed / (float) stuTotal; //decimal percentage
	cout << stuPassed << " passed " << stuTotal << " Total Fall" << endl;
        passRateCourse = passRateCourse*100;
        outputFile <<"Fall pass rate for " << docNum << " is " << passRateCourse <<"%"<<endl;
        return passRateCourse;

}


map<string,float> wPerProf(string docNum){
	string str, professorId;
        int column = 0, stuWTotal = 0;
        ifstream readFile("./csvFiles/" + docNum + ".csv"); // file to read from
        map<string,float> stuWProf; // map containing number of w to each prof
        getline(readFile,str); // skip heading

        while(readFile.good()){ // reading file
                string line;
                getline(readFile, line, ','); //reading value and setting line to the string before comma
                column++; // iterating to keep track of value

                if(column == 3) { // professorIds
                        professorId = line;
                        if(stuWProf.find(professorId) == stuWProf.end()){ //adding professor if id was not recognized from csv
                                stuWProf.insert({professorId, 0});
                        }
                }
                else if(column == 6) {
                        string grade = line.substr(0,1); //grade is substring of line since line is seperated by comma
			if(grade == "W" || grade == "WU" || grade == "WN" || grade == "WD"){ //checking for withdrawal from classes
				int stuWithdrawal = stuWProf.at(professorId)+1;
				stuWProf.erase(professorId);
				stuWProf.insert({professorId,stuWithdrawal}); // replacing
			}
                        column = 1; // setting back to 1 to help keep track
                }

        }
        return stuWProf; // returning map
}
void printMap(map<string,float> newMap,std::ofstream& outputFile){ // prints map keys and values
	for(auto it = newMap.cbegin(); it != newMap.cend(); it++){
                outputFile << it->first << "\t" << it->second << "\n";
	}
}

