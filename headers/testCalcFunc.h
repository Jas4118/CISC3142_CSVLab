#ifndef TESTCALCFUNC_H
#define TESTCALCFUNC_H
#include <iostream> 
#include <string>
#include <map>
//functions used in main.cpp and testCalcFunc.cpp
map<string,float> findTotalStuProf(string docNum);
float calcCoursePass(string docNum,std::ofstream& outputFile);
float calcSpringPass(string docNum,std::ofstream& outputFile);
void printMap(map<string,float> newMap,std::ofstream& outputFile);

#endif
