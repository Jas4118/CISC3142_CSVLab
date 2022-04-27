lab3:
	cd src && g++ main.cpp -o main && ./main
cleanOutput:
	cd outputFiles && rm 1115.txt && rm 3115.txt && rm 3130.txt
