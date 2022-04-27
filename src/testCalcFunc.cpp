#include <string>
#include <iostream>
#include <map>

#include "../headers/testCalcFunc.h"

map<string,float> findTotalStuProf(string docNum,std::ofstream& outputFile){
	string str, professorId;
	int column = 0, stuTotal = 0, overallStudentTotal=0;
	ifstream readFile("./data/" + docNum + ".csv"); // file to read from
	map<string,float> stuTotalProf;
	getline(readFile,str);

	while(readFile.good()){
		string line;
		getline(readFile, line, ',');
		column++;

		if(column == 3) {
			professorId = line;
			if(stuTotalProf.find(professorId) == stuTotalProf.end()){
				stuTotal = 1;
				stuTotalProf.insert({professorId, stuTotal});
			}
			else {
				stuTotal = stuTotalProf.at(professorId)+1; //itterating value of key-value pair
				stuTotalProf.erase(professorId);
				stuTotalProf.insert({professorId, stuTotal}); //replacing

			}
		}
		else if(column == 6) {
			string grade = line.substr(0,1); //grade is substring of line since line is seperated by comma
			column = 1;
			overallStudentTotal++;
		}
		
	}
	outputFile << "Overall student total in " <<docNum << " is: " << overallStudentTotal << endl;
	return stuTotalProf;
}

float calcCoursePass(string docNum,std::ofstream& outputFile){
	string str;
        int column = 0, stuTotal = 0, stuPassed = 0;
        ifstream readFile("./data/" + docNum + ".csv"); //file to read from 
        getline(readFile,str);

        while(readFile.good()){
                string line;
                getline(readFile, line, ','); //reading value and setting line to the string before comma
                column++;

                if(column == 6) {
                        string grade = line.substr(0,1); //grade is substring of line since line is seperated by comma
			stuTotal++; //stuTotal iterates when grade is determined meaning a student took the course and received grade
			if(grade != "F" && grade != "W" && grade != "WU" && grade != "WN" && grade != "WD" && grade != "FIN"){
				stuPassed++;
			}
                        column = 1;
                }
        }
	float passRateCourse = (float) stuPassed / (float) stuTotal;
	passRateCourse = passRateCourse*100;
	outputFile <<"Overall pass rate for " << docNum << " is " << passRateCourse <<"%"<<endl;
        return passRateCourse;

}

float calcSpringPass(string docNum,std::ofstream& outputFile){
        string str,termId;
	bool flag=false;
        int column = 0, stuTotal = 0, stuPassed = 0;
        ifstream readFile("./data/" + docNum + ".csv");
        getline(readFile,str);

        while(readFile.good()){
                string line;
                getline(readFile, line, ',');
                column++;
		if(column == 4){
			if(line == "T04" || line == "T08" || line == "T12" || line == "T16" || line == "T20" || line == "T23"){
				flag=true;
			}
		}	

                if(column == 6 && flag==true) {
                        string grade = line.substr(0,1); //grade is substring of line since line is seperated by comma
                        stuTotal++; //stuTotal iterates when grade is determined meaning a student took the course and received grade
                        if(grade != "F" && grade != "W" && grade != "WU" && grade != "WN" && grade != "WD" && grade != "FIN"){
                                stuPassed++;
                        }
                        column = 1;
			flag=false;
                }
        }
        float passRateCourse = (float) stuPassed / (float) stuTotal;
        passRateCourse = passRateCourse*100;
        outputFile <<"Spring pass rate for " << docNum << " is " << passRateCourse <<"%"<<endl;
        return passRateCourse;

}


map<string,float> wPerProf(string docNum){
	string str, professorId;
        int column = 0, stuWTotal = 0;
        ifstream readFile("./data/" + docNum + ".csv");
        map<string,float> stuWProf;
        getline(readFile,str);

        while(readFile.good()){
                string line;
                getline(readFile, line, ',');
                column++;

                if(column == 3) {
                        professorId = line;
                        if(stuWProf.find(professorId) == stuWProf.end()){ //adding professor if id was not recognized from csv
         
                                stuWProf.insert({professorId, 0});

                        }
                }
                else if(column == 6) {
                        string grade = line.substr(0,1); //grade is substring of line since line is seperated by comma
			if(grade == "W" || grade == "WU" || grade == "WN" || grade == "WD"){
				int stuWithdrawal = stuWProf.at(professorId);
				stuWithdrawal++;
				stuWProf.erase(professorId);
				stuWProf.insert({professorId,stuWithdrawal});
			}
                        column = 1;
                }

        }
        return stuWProf;
}
void printMap(map<string,float> newMap,std::ofstream& outputFile){
	for(auto it = newMap.cbegin(); it != newMap.cend(); it++){
                outputFile << it->first << " " << it->second << "\n";
	}
}

