Lab2-2: main.c
	gcc -o main main.c
main_test: main.c main_test.c
	gcc  -o main_test -Dmain=_main main.c main_test.c
