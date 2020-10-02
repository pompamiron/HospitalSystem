/*
    response.h

    Responsible Person Input
    This response.h will receive the information of responsible person
    such as name , relation and telephone number of responsible person.
    Created by     Group Little Banana (Hospital)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*#include "structure.h"*/

void responseName (RESPON_T response)
{
    char namebuffer[36];
    int count = 0;
    int re = 0;
    int check = 0;
    int lenght ;

    do
    {
        printf("First Name : ");
        fgets(namebuffer,sizeof(namebuffer),stdin);
        sscanf(namebuffer,"%s",response.name);

        lenght = strlen(response.name);

        do
        {
            if(isalpha(response.name[count])|| response.name[count]== '.' || response.name[count]=='\'' || response.name[count] =='-')
                {
                    check = 0;
                    re = 0;
                }
            else if(count < lenght)
                {
                    check = 0;
                    re = 0;
                }
            else
                {
                    printf("Error,Please enter name in correct form.\n");
                    check = 1;
                }
            count++;

        }while(count<lenght && check == 0);
        re = 1;
    }while(re == 0);

    re = 0 ;
    check = 0;
    count = 0;
    do
    {
        printf("Last Name : ");
        fgets(namebuffer,sizeof(namebuffer),stdin);
        sscanf(namebuffer,"%s",response.lastname);

        lenght = strlen(response.lastname);

        do
        {
            if(isalpha(response.lastname[count])|| response.lastname[count]== '.' || response.lastname[count]=='\'' || response.lastname[count] =='-')
                {
                    check = 0;
                    re = 0;
                }
            else if(count < lenght)
                {
                    check = 0;
                    re = 0;
                }
            else
                {
                    printf("Error,Please enter name in correct form.\n");
                    check = 1;
                }
            count++;

        }while(count<lenght && check == 0);
        re = 1;
    }while(re == 0);
}

void responseRelation (RESPON_T response)
{
    char relabuffer[36];

    printf("Relation : ");
    fgets(relabuffer,sizeof(relabuffer),stdin);
    sscanf(relabuffer,"%s",response.relation);
}

void responseTelephone (RESPON_T response)
{
    char telbuffer[21];
    char *token ;
    int count = 0;
    int re = 0;

    do
    {
        printf("Telephone : ");
        fgets(telbuffer,sizeof(telbuffer),stdin);
        token = strtok(telbuffer,"+-");
        while(token != NULL)
        {
            strcpy(response.tel[count],token);
            count++;
            token = strtok(NULL,"+-");
        }
        if(telbuffer[0]=='+')
        {

            if(count==3)
            {
                if(strlen(response.tel[0])<2 || strlen(response.tel[0])>3)
                {
                    printf("Errors,please enter telephone number in +ccc-aaaaaa-nnnnnnnn form must be 2 or 3 digit at front.\n");
                    re = 0;
                }
                if(strlen(response.tel[1]) != 6 )
                {
                    printf("Errors,please enter telephone number in +ccc-aaaaaa-nnnnnnnn form must be 6 digits and middle.\n");
                    re = 0;
                }
                if(strlen(response.tel[2]) != 9)
                {
                    printf("%d\n",strlen(response.tel[2]));
                    printf("Errors,please enter telephone number in +ccc-aaaaaa-nnnnnnnn form must ending with 8 digits.\n");
                    re = 0;
                }
                else{
                    re = 1;
                }
            }
            else
            {
                printf("Errors,please enter telephone number in +ccc-aaaaaa-nnnnnnnn\n");
                re = 0;
            }
        }
        else
        {
            printf("Errors,please enter telephone number must start with '+' .\n");
            re = 0;
        }
    }
    while(re == 0);

}

/*int main()
{
    RESPON_T response[256];
    int number = 0;
    int re = 0 ;

    while(re == 0)
    {
    responseName(response[number]);
    responseRelation(response[number]);
    responseTelephone(response[number]);
    }
}
*/
