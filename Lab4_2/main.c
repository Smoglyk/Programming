#include "main.h"

int isEmpty(char* p)
{
    if(!p)
    {
        return 0;
    }
    return 1;
}
void Change(char *c, int size)
{
    int a;
    int result = (80 - size) / 2;
    char newArr[80];
    for(a = 0; a < 80; a++)
        newArr[a] = c[a];
    for(a = 0; a < result; a++)
        c[a] = ' ';
    for(a = result; a < 80; a++)
       c[a] = newArr[a - result];
}
int main()
{
    char *filename = "text.txt";
    int i = 0, k = 0, count = 0, sizeX = 80;
    FILE *fp, *fp2;

    char*arr = (char*)malloc(sizeX * sizeof(char));
    
    
    isEmpty(arr);

    if((fp = fopen(filename, "r"))==NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    
    while(fgets(arr, 80, fp) != NULL);
    
    

    for(i = 0; i < 80; i++) 
    {
        
            count++;
            if(arr[i] == 0)
            {
                Change(arr, count);
                break;
            }
    } 

    for(i = 0; i < 80; i++) 
    {
            printf("%c",arr[i]);
    }  
    fclose(fp);

    if( (fp2 = fopen(filename, "w")) == NULL)
    {
        printf("Error");
        return 1;
    }
    fputs(arr, fp2);
    fclose(fp2);
   
    free(arr);
    
}