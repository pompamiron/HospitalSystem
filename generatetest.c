/*

    Created by     Group Little Banana (Hospital)

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "dateFunctions.h"

int main()
{
    char buffer[360];
    int count = 0 ;
    int idcount = 1;
    int re = 0;
    DATE_T newfirst;
    DATE_T nowfirst;
    dateToday(&newfirst);


    PATIENT_T patient [360] ;

    do
    {
        printf("Please enter patient name : ");
        fgets(buffer,sizeof(buffer),stdin);
        sscanf(buffer,"%s",patient[count].name);

        if(strcasecmp(patient[count].name,"end")==0)
        {
            re = 1 ;
        }
        else
        {
            printf("Please enter Birth day (yyy-mm-dd) : ");
            fgets(buffer,sizeof(buffer),stdin);
            sscanf(buffer,"%d-%d-%d",&patient[count].birthyear,&patient[count].birthmonth,&patient[count].birthday);

            if(newfirst.year != nowfirst.year)
            {
                nowfirst.year = newfirst.year ;
                patient[count].firstID = nowfirst.year;
                patient[count].id = idcount;
            }
            else if(newfirst.year == nowfirst.year)
            {
                patient[count].firstID = nowfirst.year;
                patient[count].id = idcount++;
            }
            re = 0;
        }
    }while(re == 0 );
}
