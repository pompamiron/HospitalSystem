/*******************************************************************************
 *   record.c	
 *	
 *	This program will show about medical record number when the user want to created member.
 *
 *		  Created by     Group Little Banana (Hospital)
 *	02 December 2016
 *
 *******************************************************************************
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "structure.h"
#include "dateFunctions.h"

/* This function will show the number of member when the user create new record 
 * 'PATIENT_T patient' is structure for keep information of the patient
 */
void recordFunction(PATIENT_T patient)
	{	
	char input[365];	/* get data from the user */ 
	//int count=0;		/* variable for count the patient */
	int a=0;		/* variable for loop */	
	int idcount=1;		/* variable for count the patient number */

	DATE_T newRecord;	/* structure for keep record day */
	DATE_T today;		/* structure for keep present day */

	dateToday(&today);
	
	today.year=today.year+543;

	/* condition if year of both date not the same */
	if(today.year != newRecord.year)
            	{
                newRecord.year = today.year ;
               	patient.firstID = newRecord.year;
               	patient.ID = idcount;									
            	}
	/* condition if year of both date the same */
        else if(today.year == newRecord.year)
            	{
               	patient.firstID = newRecord.year;
		idcount+=1;
                patient.ID = idcount;						
		}	

	printf("Medical record number : %d-%.6d\n", patient.firstID, patient.ID);
				
	}

int main()
	{
	PATIENT_T patient[365];
	
	int count=0;
	
		
	recordFunction(patient[count]);
	count++;
	

	return 0;

	}
