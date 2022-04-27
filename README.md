# CISC3142_CSVLab
This is a program for CISC3142 and is used to analyze certain csv files that are three courses each named 1115.csv, 3115.csv and 3130.csv. This program is partially incomplete due to compiler issues that increased the necessary time needed to do the project. At the bottom of the README file will include what needs to be added.
The main code is within a src folder and is named "main.cpp". The file makes use of functions taken from "testCalcFunc.cpp"
The two .cpp make use of a header file within a headers folder called "testCalcFunc.h" which helps build/link the code.

## Setup
This repo makes use of LinuxOs system and would be setup there along with makefile so it would be best to ssh or make use of your Linux machine. Clone this repo into your repository and you can build the program using this command in the terminal while in your repo copy:

```bash
make lab3
```
The user is then prompted to "Enter the course number. (1115, 3115, 3130)". The user then needs to enter the course number 1115, 3115 or 3130.
The file will then be produced in the same repository and will be in a directory called "outputFiles"

If the files need to be removed from the outputFiles directory the user can clear 1115.txt, 3115.txt and 3130.txt by typing ```bash make cleanOutput``` while in the CISC3142_CSVLab directory.

# The Problem

The program is to complete the task of reading a CSV file and then based off the information collected, we are to create a data analysis of what has been read in. This is to include the pass rate for the three courses, the pass rate for each professor, the w rate for the three courses, the w rate for each professor, the rate of passing for Spring, and the rate of passing for Fall.

# Functions used to solve

## findTotalStuProf & wPerProf

These two functions work very similarly in that they serve a certain purpose in the program and that is to create a map to hold key-value pairs. In findTotalStuProf case, the function will keep being reading lines and setting the string line to be the value in the CSV file with column itterating to help the program find which column is going to be what it is since we know what each column is meant for. For example, when it reaches column 3, the program will check since we know it is the professorId column and using the line we would check the map seeing if that professorId is within the map. The function uses professorId to keep track of how many students they had by reading each line and then checking if the professorId is in the map or not. If it is not in the map then professorId will be the key and a stuTotal variable set to 1 will be the value in the key-value for the map stuTotalProf. The file will keep being read line by line with column itterating to help the program find which column is going to be what helps identify the values separated by commas creating a map with the professorId and the amount of students they have.
Once the column iterates to 6 which is the grade, the program will create a substring of grade to fix having the issue of empliid and grade together as one string due to the getline() parameters. It will then iterate to a overallStudentTotal variable. It loops again and if the professorId is found again, the map float is iterated again. Overall student total is printed in a string at the end and a map containing the professorId's and stuTotal are returned

The function wPerProf does almost exactly the same thing as findTotalStuProf except when adding the professorId into the map when not finding it, it will change the value to 0 instead of 1 since we do not know whether this student has a W or not. Once we reach the point of checking the grade, we check for if(grade == "W" || grade == "WU" || grade == "WN" || grade == "WD"). We then create a variable to replace the value in the map with stuWithdrawal and add one to iterate it. We then replace the map with the new value and use the same key. Once the file is finished reading the function returns a map<string,float> called stuWProf.

## calcCoursePass

This function calculates the overall rate at which the students pass the course. This function mainly reads through a CSV file that is determined by the user's input. The function checks the CSV file value by value by using an int variable called column and is iterated when a value is read from the CSV file with getline(). When column reaches 6, the program adds to a int variable called stuTotal and then the program checks the string grade created from the substring and checks if grade isn't F, W, WU, WN , WD or FIN. If grade isn't any of those then the program iterates stuPassed. column is set to 1 again to allow the program to keep track of columns. After reading the file, the percentage of passing a course is set to a variable of float passRateCourse. This is done by dividing stuPassed by the stuTotal and then multiplying passRateCourse by 100. The data is written tot he output file and passRateCourse is returned to the function.

## calcSpringPass & calcFallPass

Both these functions are similar as well as they calculate the grade of overall course with the functions specifically looking for classes pertaining to certain seasons. Both has a bool variable respectively called isSpring and isFall and both are set to false. As the file is being read column by column the variable column is being iterated. Once it reaches collumn=4, the program then checks the value of line. If the value of line is the class value for Spring which are "T02", "T06", "T10", "T14", "T18", "T21" or Fall which are "T04", "T08", "T12", "T16", "T20", "T23". Depending on the function, if the value is the same, then isFall or isSpring will be set to true and the program will keep reading the CSV file. Once it reaches column=6, the program creates a substring of the value line and then checks the bool variable isFall and isSpring. If they are true that means the class being taken is in Fall or Spring and then another if statement checks if the grade is a passing grade or not. If it is, then the stuPassed variable will be iterated and stuTotal will be be iterated whether isFall or isSpring is true or not. column is set back to 1 to help keep track of the file and isFall/isSpring is set back to false to be used again by the while loop. At the end after the loop, the pass rate is calculated to a float called passRateCourse by dividing the stuPassed by the stuTotal and then multiplying passRateCourse by 100. Thius is then outputed to the outputfile and returns passRateCourse to the original functions.

# main.cpp

The program sets up the reading the file and the output file. This program then prompts the user to enter a course number. This input would be placed in courseNo string variable and then opens a file with the name courseNo + ".txt" to the outputFiles folder. The program then checks if the courseNo is 1115, 3115 or 3130 and opens their respective files to read. If the courseNo is none of the three then the cout will produce a string that says the string isn't valid.
Afterwards most of the functions appear here with printMap printing the key-value pairs to the outputFile and setting up other output using the calcSpringPass, calcFallPass, and calcCoursePass. All the information is placed into the outputFile with their respective courseNo.

# Additional features to be added

Currently the program is incomplete due to not containing the percentages of W rate and passing rate so I only have included number of people that have W and passing. There also isn't any form of printf to create a nicer report but that is to be added later.
