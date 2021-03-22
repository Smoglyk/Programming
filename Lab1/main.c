
#include "main.h"

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
int checkDigital(double xt)
{
    if(xt < 0)
    {
        return 0;
    }
 return 1;
}

int fact(int a)
{
    int f = 1, i = 0;
    while(i < a)
    {
      i++;
      f *= i;
    }
    return f;
}

int main()
{
int i = 1, j = 1, n, resultSum = 0, resultMulti = 1;
n = Correctinput();
checkDigital(n);
    while(i <= n)
   {
       while(j <= i)
      {
          int copy_p = resultMulti;
          resultMulti = fact(j+i)/ fact(i);
          resultMulti *= copy_p;
          j++;
      }
    resultSum += resultMulti;
    resultMulti = 1;
    i++;
    j = 1; 
   }  

   printf("Answer : %d", resultSum);

}
