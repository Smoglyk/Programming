Lab1: main.c
	gcc -o Lab1 main.c -lm
Lab1_Test: main_test.c main_test.c
	gcc main_test.c main.c -o main_test -D TESTING -lm
