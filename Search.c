/*******	************************************************
 *  Search.c
 *
 *		program for search data
 *
 *
 *     Created by     Group Little Banana (Hospital)
 *
 *******************************************************
 */
 
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<ctype.h>
 
 #include"structure.h"
 
 int main()
 {
 	
 	char input[1024];
 	char searchForm[32];
 	
 	int searchNo = 0;
 	int count = 0;
 	
 	FILE* patientIn = NULL;
 	
 	PATIENT_T patient[255];
 	RESPON_T respon[255];
 	
 	patientIn = fopen("patientdata.txt","r");
 	
 	if(patientIn==NULL)
 	{
 		printf("Patient data file is NULL!! \n'");
 		exit(0);
	 }
 	
		printf("-------------------------------------\n");
 		printf("    Search from !                    \n");
 		printf("-------------------------------------\n");
 		printf(" 1.Name                              \n");
 		printf(" 2.Nationality                       \n");
 		printf(" 3.Diagnosis                         \n");
 		printf("-------------------------------------\n");
 		
 		
 		while(1)
 		{
		 
			printf(" Choose (1-4):  ");
 			fgets(input,sizeof(input),stdin);
 			sscanf(input,"%d",&searchNo);
 		
		 	if((searchNo >= 1)&&(searchNo <= 4))
				{
					break; 	
				}
			 
			 else
			 	{
			 		printf("Please enter 1-4 !! \n");
				}
				
 		}

		/*if(searchNo == 1)
		{
			strcpy(searchForm,)
		}*/
		
	while(fgets(input,sizeof(input),patientIn) != NULL)
		{
			
			sscanf(input,"%d %d %s %s %d %d %d %s %s %s %s %s %s %s %s",&patient[count].firstID,
																		&patient[count].ID,
																		patient[count].name,
																		patient[count].lastname,
																		&patient[count].birthday,
																		&patient[count].birthmonth,
																		&patient[count].birthyear,
																		patient[count].gender,
																		patient[count].nation,
																		patient[count].passnum,
																		patient[count].diagnosis,
																		respon[count].name,
																		respon[count].lastname,
																		respon[count].relation,
																		respon[count].tel);
																		
				

																		
			count++;
																		
		}
		
		
				
					count = 0;
					printf("%s-%s %s %s %d/%d/%d %s %s %s %s %s %s %s %s",patient[count].firstID
																		,patient[count].ID
																		,patient[count].name
																		,patient[count].lastname
																		,patient[count].birthday
																		,patient[count].birthmonth
																		,patient[count].birthyear
																		,patient[count].gender
																		,patient[count].nation
																		,patient[count].passnum
																		,patient[count].diagnosis
																		,respon[count].name
																		,respon[count].lastname
																		,respon[count].relation
																		,respon[count].tel);
	
	fclose(patientIn);
	
	return 0;
}
 
