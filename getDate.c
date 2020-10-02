/*******************************************************************************
 *   getDate.c	
 *	
 *	This program will ask about birthday date and admission date. Then, check
 *      about condition of date and keep information.
 *
 *	   Created by     Group Little Banana (Hospital)
 *
 *******************************************************************************
 */

#include<stdio.h>
#include<string.h>

#include "dateFunctions.h"
#include "structure.h"

/* This function will get birthday date and check condition. */
void dateBirthday(PATIENT_T patient)
	{
	char input[256];		/* get data from the user */
	char birthString1[128];		/* keep information from the user */
	char birthString2[128];		/* keep information from the user */	
	int a=0;			/* variable for loop */
	int b=0;			/* variable for condition */
	
	DATE_T birthday;		/* structure for keep birthday date */
	DATE_T day;			/* structure for keep present date */
	
	/* loop while for get information from the user and compare date when the user put the date */
	while(a==0)
		{
		printf("Date of birth : ");
		fgets(input, sizeof(input), stdin);
		sscanf(input, "%d-%d-%d", &birthday.year, &birthday.month, &birthday.day);

		sprintf( birthString1, "%d-%d-%d", birthday.year, birthday.month, birthday.day);
		
		patient.birthyear=birthday.year;
		patient.birthmonth=birthday.month;
		patient.birthday=birthday.day;
				
		birthday.year = birthday.year-543;
	
		sprintf(birthString2, "%.2d/%.2d/%d", birthday.day, birthday.month, birthday.year);

		DATE_STATUS status = checkDate(birthString2,&birthday);	/* function for parses a date ('dateString')  in the form dd/mm/yyyy. */		
		/* condition if information is not valid date */
		if (status != DATE_OK)	
			{
			printf("ERROR : Your date is not correct in form (yyyy-mm-dd).\n");
			b++;
			}
		/* condition if information is valid date */
		else if(status == DATE_OK)
			{
			birthday.year = birthday.year+543;		
			b=0;
			}
		/* if date is correct */
		if(b==0)
			{
			dateToday(&day);	/* Sets the fields of 'pResult' to the correct values for today. */

			day.year=day.year+543;

			/* if date is future */
			if(birthday.year > day.year)
				{
				printf("ERROR : Your date is impossible(future).\n");
				}
			/* if date is correct */
			else
				{
				a++;
				}
			}
	
		}
	
	}

/* This function will get admission date and check condition. */
void dateAdmis(PATIENT_T patient)
	{
	char input[256];	/* get data from the user */
	char dateString1[128];	/* keep information from the user */
	char dateString2[128];	/* keep information from the user */
	int compare1;		/* variable for compare */
	int compare2;		/* variable for compare */
	int a=0;		/* variable for loop */
	int b=0;		/* variable for condition */
				
	DATE_T admis;		/* structure for keep admission date */
	DATE_T day;		/* structure for keep present date */
	
	/* loop while for get information from the user and compare date when the user put the date */
	while(a == 0)
		{
		printf("Admission date (yyyy-mm-dd): ");
		fgets(input, sizeof(input), stdin);
		sscanf(input,"%d-%d-%d", &admis.year, &admis.month, &admis.day);
		
		sprintf(dateString1,"%d-%d-%d", admis.year, admis.month, admis.day);

		patient.admisyear=admis.year;
		patient.admismonth=admis.month;
		patient.admisday=admis.day;
				
		admis.year = admis.year-543;

		sprintf(dateString2,"%.2d/%.2d/%d", admis.day, admis.month, admis.year);		

		DATE_STATUS status = checkDate(dateString2,&admis);	/* function for parses a date ('dateString')  in the form dd/mm/yyyy. */		

		/* condition if information is not valid date */
		if (status != DATE_OK)	
			{
			printf("ERROR : Your date is not correct in form (yyyy-mm-dd).\n");
			b++;
			}
		/* condition if information is valid date */
		else if(status == DATE_OK)
			{
			admis.year = admis.year+543;		
			b=0;
			}
		/* condition for compare each date */			
		if(b==0)
			{					
			dateToday(&day);	/* Sets the fields of 'pResult' to the correct values for today. */
			
			day.year=day.year+543;

			/* if date is future */
			if(day.year < patient.admisyear)
				{
				printf("ERROR : Your date is impossible(future).\n");
				}
			/* if date is past */
			else if(patient.admisyear < patient.birthyear)
				{
				printf("ERROR : Your date is impossible(past).\n");
				}
			/* if date is correct */
			else
				{
				a++;
				}
			
			}
		
		}
	
	}


int main()
	{
	PATIENT_T patient[365];
	
	int count=0;

	dateBirthday(patient[count]);

	dateAdmis(patient[count]);

	return 0;
	
	}
