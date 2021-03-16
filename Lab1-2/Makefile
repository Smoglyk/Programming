main: main.c
   gcc -o main main.c

test: main.c main_test.c
   gcc  -o test -Dmain=_main main.c main_test.c
