/*
    Menu.h

    Hospital Menu
    Menu.h will do the menu process for what user want to do.
    In this menu will have 2 Functions such as
    1.Add Information 2.Search 2.1.Delete Information 2.2.Modify Information

    Created by 
    Group Little Banana (Hospital)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"

void printmenu ()
{
    printf("**********************************\n");
    printf("*               MENU             *\n");
    printf("*                                *\n");
    printf("*     1. Add New Patient         *\n");
    printf("*     2. Search                  *\n");
    printf("*     3. End Program             *\n");
    printf("*                                *\n");
    printf("**********************************\n\n");

}
void printsearchmenu ()
{
    printf("**********************************\n");
    printf("*           Search From          *\n");
    printf("*                                *\n");
    printf("*     1. Name                    *\n");
    printf("*     2. Nationality             *\n");
    printf("*     3. Diagnosis               *\n");
    printf("*                                *\n");
    printf("**********************************\n\n");
}
int main()
{
    int choose = 0;
    int re = 0 ;
    char buffer[8];

    printf("**********************************\n");
    printf("******                      ******\n");
    printf("****                          ****\n");
    printf("**    Welcome to CPE Hospital   **\n");
    printf("****                          ****\n");
    printf("******                      ******\n");
    printf("**********************************\n\n");
    printmenu();
    do
    {
        printf("Select : ");
        fgets(buffer,sizeof(buffer),stdin);
        sscanf(buffer,"%d",&choose);
        switch(choose)
        {
        case 1 :
            re = 1;
            break;
        case 2 :
            printsearchmenu();
            re = 1;
            break;
        case 3 :
            re = 1;
            break;
        default :
            re = 0;
            break;
        }
    }while(re == 0);
}
