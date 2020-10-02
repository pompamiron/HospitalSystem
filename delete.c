/*

    Created by     Group Little Banana (Hospital)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"

void reading(PATIENT_T patient,RESPON_T response,FILE *pIn)
{
    char filebuffer[360];

    fgets(filebuffer,sizeof(filebuffer),pIn);
    sscanf(filebuffer,"%d-%ld %s %s %d/%d/%d %s %s %s %s %s %s %s %s",&patient.firstID,&patient.id,&patient.name,&patient.lastname,&patient.birthday,&patient.birthmonth,&patient.birthyear,&patient.gender,&patient.nation,&patient.passnum,&patient.diagnosis,&response.name,&response.lastname,&response.tel);
}
void deleting()
{
    int time=0;
}
int main()
{
    FILE* pIn = NULL;

    int count = 0;
    int recount = 0;
    char buffer[128];
    char filebuffer[360];
    char name[128];
    PATIENT_T patient[360];
    RESPON_T response[360];

    pIn = fopen("patientdata.txt","r");

    if(pIn == NULL)
    {
        printf("Error can't open file.\n");
    }
    else
    {
        fscanf(pIn,"%d",&count);
        do
        {
            reading(patient[recount],response[recount],pIn);
            recount++;
        }while(recount < count);

        fclose(pIn);

        recount = 0;

        do
        {
            printf("%d-%06ld %s %s %d/%d/%d %s %s %s %s %s %s %s %s",patient[recount].firstID,patient[recount].id,patient[recount].name,patient[recount].lastname,patient[recount].birthday,patient[recount].birthmonth,patient[recount].birthyear,patient[recount].gender,patient[recount].nation,patient[recount].passnum,patient[recount].diagnosis,response[recount].name,response[recount].lastname,response[recount].tel);
            recount++;
        }while(recount < count);

        /*do
        {
            printf("do")
        }*/
    }
}
