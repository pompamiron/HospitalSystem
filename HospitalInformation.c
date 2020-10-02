/*

    Created by     Group Little Banana (Hospital)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dateFunctions.c"
#include "gender.c"
#include "getDate.h"
#include "record.h"
#include "menu.h"
#include "response.h"
#include "getData.h"
/*
#include "getDate.h"
#include "record.h"
#include "menu.h"

*/
int main()
{
    DATE_T admis;		/* structure for keep admission date */
	DATE_T day;		/* structure for keep present date */
    PATIENT_T patient[500];
    RESPON_T response[500];

    int choose = 0;
    int count=0;
    int status = 0 ;
    int re = 0 ;
    int number = 0;
    char buffer[360];

    printf("**********************************\n");
    printf("******                      ******\n");
    printf("****                          ****\n");
    printf("**    Welcome to CPE Hospital   **\n");
    printf("****                          ****\n");
    printf("******                      ******\n");
    printf("**********************************\n\n");
    do
    {
        printmenu();
        do
        {
            printf("Select : ");
            fgets(buffer,sizeof(buffer),stdin);
            sscanf(buffer,"%d",&choose);
            switch(choose)
            {
            case 1 :
                recordFunction(patient[count]);
                getName(patient,number);
                dateBirthday(patient[count]);
                gender(&number,patient);
                nation(&number,patient);
                passport(&number,patient);
                getDiagnosis(patient,number);
                responseName(response[number]);
                responseRelation(response[number]);
                responseTelephone(response[number]);
                dateAdmis(patient[count]);
                number++;
                count++;
                re = 1;
                status = 0 ;
                break;
            case 2 :
                printsearchmenu();
                status = 0;
                re = 1;
                break;
            case 3 :
                status = 1;
                break;
            default :
                re = 0;
                break;
            }
        }while(re == 0);

    }while(status = 0);
}
