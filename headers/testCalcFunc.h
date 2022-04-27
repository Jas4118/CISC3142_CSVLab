#ifndef TESTCALCFUNC_H
#define TESTCALCFUNC_H
#include <iostream>
#include <string>
#include <map>

map<string,float> findTotalStuProf(string docNum);
float calcCoursePass(string docNum,std::ofstream& outputFile);
float calcSpringPass(string docNum,std::ofstream& outputFile);
void printMap(map<string,float> newMap,std::ofstream& outputFile);

#endif
