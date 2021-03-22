
#include "main.h"
#include <math.h>

int Correctinput()
{
    int temp;
    char goodCheck;
    while(!scanf("%d", &temp) || !scanf("%c", &goodCheck) || goodCheck != '\n')
    {
       printf("Wrong input! Please, try again: ");
       fflush(stdin);
    }
    return temp;
}

int cheakInput(int anw)
{
    if(anw == 1 || anw == 2 || anw == 3 || anw == 4 || anw == 5)
    {    
    return 1;
    }
    else 
    {
        printf("Pls, input a data correct\n");
        return 0;
    }
}

double round(double x)
{ 
    double integer; 
    int clon = x, clon2 = x + 0.5;
    if( clon == clon2)
    {
       integer = clon;
       return integer;
    } 
    else
    {
       integer = clon2;
       return clon2;
    }
}
void input(float  *a, float *b)
{
    printf("Input namerator\n");
    scanf("%f", a);
    printf("Input denominator\n");
    scanf("%f", b);
}

void me()
{
    printf("Author program Dmitry Smoglyk, version program 1.0\n");
}

void reverse(float a, float b)
{
    int a1 = 1, b1 = b;
    printf("Reverse number stork : %d / %d\n", b1, a1);
}

void shortForm(float a, float b)
{
    float remainder  = a / b;
    printf("short digital : %f\n", round(remainder));

}

void output(float a, float b)
{
    int answer;
    printf("What output you want: decimal(1), namerator(2), since form(3)\n");
    answer = Correctinput();
    if(answer == 1)
    {
        int declimal = a / b;
        printf("Declimal answer: %d\n", declimal);
    }
    if(answer == 2)
    {
        printf("Namerator answer: %f / %f\n", a, b);
    }
    if(answer == 3)
    {
        float declimal = (a / b);
        printf("%e\n", declimal);
        
    }
}

int main()
{
    int answ;
    float a,b;
    input(&a, &b);
    while(1)
    {
    printf("What is fuction you want apply\n: output(1), reverse(2),  shortForm(3), me(4), exit(5)\n");
    answ = Correctinput();
    cheakInput(answ);
   
   switch (answ)
   {
     case 1:  output(a,b);
     break;
     case 2:  reverse(a,b);
     break;
     case 3:  shortForm(a, b);
     break;
     case 4:  me();
     break;
     case 5:   exit(0);
     break;
     default:
       break;
   }

    }
}
