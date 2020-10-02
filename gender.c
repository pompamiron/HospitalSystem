/*******************************************************
 *   gender.c
 *
 *	program for input gender,nation and passport id
 *
 *   Created by     Group Little Banana (Hospital)
 *********************************************************/

#include<stdio.h>

#include<string.h>

#include<stdlib.h>
#include "structure.h"



void gender(int* number,PATIENT_T patient[])

{

	char input[255];

	while(1)

	{

		printf("Gender(M/F/N) : ");

		fgets(input,sizeof(input),stdin);

		sscanf(input,"%s",patient[*number].gender);



		if((strcasecmp(patient[*number].gender,"m")==0)||(strcasecmp(patient[*number].gender,"f")==0)||(strcasecmp(patient[*number].gender,"n")==0))

		{

			break;

		}



		else

		{

			printf("Please enter in form of M/F/N !.\n");

		}

	}





}



void nation(int* number,PATIENT_T patient[])

{

	char nat[245][4] = {"AC","AF","AL","DZ","AD","AO","AI","AQ","AG","AR",

						"AM","AW","AU","AT","AZ","BS","BH","BD","BB","BY",

						"BE","BZ","BJ","BM","BT","BO","BA","BW","BV","BR",

						"IO","VG","BN","BG","BF","BI","KH","CM","CA","CV",

						"KY","CF","TD","CL","CN","CX","CC","CO","KM","CG",

						"CD","CK","CR","CI","HR","CU","CY","CZ","DK","DJ",

						"DM","DO","TP","EC","EG","SV","GQ","EE","ET","FK",

						"FO","FJ","FI","FR","FX","GF","PF","TF","GA","GM",

						"GE","DE","GH","GI","GR","GL","GD","GP","GU","GT",

						"GN","GW","GY","HT","HM","HN","HK","HU","IS","IN",

						"ID","IR","IQ","IE","IM","IL","IT","JM","JP","JO",

						"KZ","KE","KI","KP","KR","KW","KG","LA","LV","LB",

						"LS","LR","LY","LI","LT","LU","MO","MK","MG","MW",

						"MY","MV","ML","MT","MH","MQ","MR","MU","YT","MX",

						"FM","MD","MC","MN","ME","MS","MA","MZ","MM","NA",

						"NR","NP","AN","NL","NC","NZ","NI","NE","NG","NU",

						"NF","MP","NO","OM","PK","PW","PA","PG","PY","PE",

						"PH","PN","PL","PT","PR","QA","RE","RO","RU","RW",

						"WS","SM","ST","SA","SN","SP","SC","SL","SG","SK",

						"SI","SB","SO","AS","ZA","GS","SU","ES","LK","SH",

						"KN","LC","PM","VC","SD","SR","SJ","SZ","SE","CH",

						"SY","TW","TJ","TZ","TH","TG","TK","TO","TT","TN",

						"TR","TM","TC","TV","UG","UA","AE","GB","UK","US",

						"UM","UY","UZ","VU","VA","VE","VN","VI","WF","EH",

						"YE","YU","ZR","ZM","ZW"};



	char input[32];

	int i=0;





	while(1)

	{

		printf("Nation : ");

		fgets(input,sizeof(input),stdin);

		sscanf(input,"%s",patient[*number].nation);



			for(i=0;i<=255;i++)

			{

				if(strcmp((patient[*number].nation),nat[i]) == 0)

				{

					return;

				}

			}



			printf("Please enter in form of 2 upper(ex.'TH') !.\n");







	}







}



void passport(int* number,PATIENT_T patient[])

{





	char input[32];

	char check[112];

	int length  = 0;

	int count1  = 0;

	int count2  = 0; /* check passnum is number */

	int count3  = 0;





	while(1)

	{



		printf("Identifition number / Passport number: ");

		fgets(input,sizeof(input),stdin);

		sscanf(input,"%s",patient[*number].passnum);



		length = strlen(patient[*number].passnum);







			if(strcmp(patient[*number].nation,"TH") != 0)

			{



				if((length >= 8 )&&(length <= 16))

				{

					return;

				}

				else

				{

					printf("Please enter in form of digit length 8-16\n");

				}

			}





			/* if nation is TH identifition is 13 digits */



			if(strcmp(patient[*number].nation,"TH") == 0)

			{



				if(length != 13)



				{

					printf("Please enter in form of digit length 13\n");

				}



				else if(length == 13)

				{



							for(count1=0;count1<13;count1++)

							{



								if((patient[*number].passnum[count1]>'0')&&(patient[*number].passnum[count1]<'9'))

								{

									count2++;

								}

							}



							if(count2 == 13)

							{

								return;

							}



				}





			}







		}





	}









