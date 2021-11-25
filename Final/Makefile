all: clean project
	./Project

project: 	Project.c
	gcc Project.c .\MyLib\headers\* .\MyLib\src\* -o Project

clean: 
	rm -f *.o Project.exe