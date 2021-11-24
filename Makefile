all: clean project
	./Project

project: 	Project.cpp functions.cpp treePrint.h occTab.h matSum.h mergeSort.h
	gcc Project.cpp functions.cpp treePrint.h occTab.h matSum.h mergeSort.h -o Project

clean: 
	rm -f Project.exe