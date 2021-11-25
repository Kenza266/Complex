all: clean project
	./Project

project: 	Project.cpp $(addprefix MyLib/src/,functions.c treePrint.c occTab.c matSum.c mergeSort.c)
	gcc Project.cpp $(addprefix MyLib/src/,functions.c treePrint.c occTab.c matSum.c mergeSort.c) -o Project

clean: 
	rm -f Project.exe