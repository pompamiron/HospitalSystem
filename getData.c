/*
 * getData
 *
 *   Created by     Group Little Banana (Hospital)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*#include "structure.h"*/

#define MAXPATIENT 120

int getName(PATIENT_T patient[],int number)
    {
    char input[128];
	int check1 = 0;
	int check2 = 0;
	int i = 0;

    /* loop, get patient's name from user */
    while (check1 == 0 || check2 == 0)
        {
        printf("Name: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%[^\n]s %[^\n]s",patient[number].name,patient[number].lastname);

		if (strcmp(patient[number].name,"") == 0)
			{
			check1 = 0;
			}
		else
			{
			for(i= 0; i< strlen(patient[number].name); i++)
				{
				switch (patient[number].name[i])
					{
					case '!' :
							check1=0;
							break;
					case '/' :
							check1=0;
							break;
					case '?' :
							check1=0;
							break;
					case '*' :
							check1=0;
							break;
					case '%' :
							check1=0;
							break;
					case '&' :
							check1=0;
							break;
					case '@' :
							check1=0;
							break;
					case ';' :
							check1=0;
							break;
					case ',' :
							check1=0;
							break;
					case ':' :
							check1=0;
							break;
					case '~' :
							check1=0;
							break;
					case '_' :
							check1=0;
							break;
					case '#' :
							check1=0;
							break;
					case '(' :
							check1=0;
							break;
					case ')' :
							check1=0;
							break;
					case '[' :
							check1=0;
							break;
					case ']' :
							check1=0;
							break;
					case '{' :
							check1=0;
							break;
					case '}' :
							check1=0;
							break;
					case '"' :
							check1=0;
							break;
					default :
							check1=1;
							break;
					}

				switch (patient[number].lastname[i])
					{
					case '!' :
							//printf("\tError : You cannot use exclamation mark(!).\n");
							check2=0;
							//return check;
							break;
					case '/' :
							//printf("\tError : You cannot use slash(/).\n");
							check2=0;
							//return check;
							break;
					case '?' :
							//printf("\tError : You cannot use question mark(?).\n");
							check2=0;
							//return check;
							break;
					case '*' :
							//printf("\tError : You cannot use asterisk(*).\n");
							check2=0;
							//return check;
							break;
					case '%' :
							//printf("\tError : You cannot use percent.\n");
							check2=0;
							//return check;
							break;
					case '&' :
							//printf("\tError : You cannot use ampersand(*).\n");
							check2=0;
							//return check;
							break;
					case '@' :
							//printf("\tError : You cannot use at sign (*).\n");
							check2=0;
							//return check;
							break;
					case ';' :
							//printf("\tError : You cannot use semicolon(;).\n");
							check2=0;
							//return check;
							break;
					case ',' :
							//printf("\tError : You cannot use comma(,).\n");
							check2=0;
							//return check;
							break;
					case ':' :
							//printf("\tError : You cannot use colon(:).\n");
							check2=0;
							//return check;
							break;
					case '~' :
							//printf("\tError : You cannot use tilde(~).\n");
							check2=0;
							//return check;
							break;
					case '_' :
							//printf("\tError : You cannot use underscore(_).\n");
							check2=0;
							//return check;
							break;
					case '(' :
							//printf("\tError : You cannot use round brackets(()).\n");
							check2=0;
							//return check;
							break;
					case '[' :
							//printf("\tError : You cannot use square brackets([]).\n");
							check2=0;
							//return check;
							break;
					case '{' :
							//printf("\tError : You cannot use curly brackets({}).\n");
							check2=0;
							//return check;
							break;
					case '"' :
							//printf("\tError : You cannot use quotation marks("").\n");
							check2=0;
							//return check;
							break;
					default :
							check2=1;
							//return check;
							break;
					}
				}
			if (check1 == 0 || check2 == 0)
				printf("\tError: Can't enter special character.\n");
			else
				break;
			}
        }
    }

int getDiagnosis(PATIENT_T patient[],int number)
    {
    char input[256];

    do
        {
        printf("Diagnosis: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%[^\n]s",patient[number].diagnosis);
        }
    while (strcmp(patient[number].diagnosis,"") == 0);
    }

/*int main()
    {
    char input[128];
    int number = 0;
    char dateBirth[64];
    PATIENT_T patient[MAXPATIENT];

    getName(patient,number);
    getDiagnosis(patient,number);
	printf("%s\n",patient[number].name);
	printf("%s\n",patient[number].diagnosis);
    }*/
