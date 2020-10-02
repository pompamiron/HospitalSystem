/*   dateFunctions.c
 *
 *   This module provides the implementation of some functions that
 *   parse, check and manipulate dates.
 *
  	  Created by     Group Little Banana (Hospital)
 *   Updated 1 September 2010
 *   Updated 14 November 2012 to use an enum for error codes
 *   Updated 30 October 2013 to fix problem in error checking
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "dateFunctions.h"
/* We must include our header file so that we will have the definitions
 * of the DATE_T structure and the enum for error codes
 */

/* Number of days in each month. */
int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


/* Local function. , not exposed in the header file.
 * Returns true (1) if 'year' is leap year, else false (0)
 */
int isLeapYear(int year)
{
   if ((year % 4 == 0) && (year % 100 != 0))
       return 1;
   else
       return 0;
}

/* Local function, not exposed in the header file.
 * calculates the difference in days between Jan 1 of
 * two different years (year1 and year2), and returns that value.
 */
long yearDayDifference(int year1, int year2)
{
    int y1, y2, yr;
    long totalDays = 0;
    if (year1 > year2)
       {
       y1 = year2;
       y2 = year1;
       }
    else
       {
       y1 = year1;
       y2 = year2;
       }
    for (yr = y1; yr < y2; yr++)
       {
       if (isLeapYear(yr))
	   totalDays += 366;
       else
           totalDays += 365;
       }
    return totalDays;
}

/* Local function, not exposed in the header file.
 * Given a DATE_T, calculates the day in the year
 * of the date (1 to 366)
 */
int yearDay(DATE_T date)
{
    int days = 0;
    int m = 0; /* month counter */
     for (m = 0; m < (date.month - 1); m++)
       {
       days += monthDays[m];
       }
    days += date.day;
    if ((isLeapYear(date.year)) && (date.month > 2))
       days += 1; /* adjust for leap year */
    return days;
}

/***** PUBLIC FUNCTIONS, included in dateFunctions.h ******/

/* Parses a date ('dateString')  in the form dd/mm/yyyy.
 * If the date is valid, returns DATE_OK and sets the values of the
 * fields in 'pResult' to match the information in the string.
 * If the date is not valid, returns an enum value indicating
 * what type of error. See enum above for more information
 */
DATE_STATUS checkDate(char* dateString, DATE_T * pResult)
{
    int d, m, y;   /* temp variables for day, month, year */
    DATE_STATUS status = DATE_OK;
    int i = 0;
    if (strlen(dateString) != 10)
       {
       status = ERR_BADFORMAT;
       }
    else if ((dateString[2] != '/') || (dateString[5] != '/'))
       {
       status = ERR_BADFORMAT;
       }
    else
       {
       /* check that all other chars are digits */
       for (i = 0; (i < 10) && (status == DATE_OK); i++)
           {
	   if ((i == 2) || (i == 5))
               continue; /* skip the slashes */
           else if (!isdigit(dateString[i]))
               status = ERR_BADFORMAT;
           }
       /* If the status is still positive, then we know the format is good */
       if (status == DATE_OK)
           {
	   sscanf(dateString,"%d/%d/%d",&d,&m,&y);
           if ((y > 2100) || (y < 1900))
               status = ERR_BADYEAR;
	   else if ((m>12) || (m < 1))
               status = ERR_BADMONTH;
           else
	       {
	       int maxDay = monthDays[m-1];
               if ((m == 2) && (isLeapYear(y)))
                   maxDay = 29;
	       if ((d < 1) || (d > maxDay))
                   status = ERR_BADDAY;
	       }
           }
       /* if we get to this point and status is still DATE_OK
        * we know that the date is good.
        */
       if (status == DATE_OK)
           {
	   pResult->year = y;
	   pResult->month = m;
	   pResult->day = d;
           }
       }
    return status;
}


/* Calculates and returns the absolute difference in days
 * between the first and the second date. The code is designed
 * to work correctly where the second date is later than the
 * first date. If this is not the case, the function calls
 * itself, with the arguments reversed.
 */
long dateDifference(DATE_T firstDate, DATE_T secondDate)
{
    long difference = 0;
    int compareResult = dateCompare(firstDate,secondDate);
    if (compareResult > 0)
       {
       difference = dateDifference(secondDate,firstDate);
       }
    else if (compareResult < 0)
       {
       difference = yearDayDifference(firstDate.year,secondDate.year);
       difference -= yearDay(firstDate);
       difference += yearDay(secondDate);
       }
    return difference;  /* will return zero if the dates are the same */
}


/* Sets the fields of 'pResult' to the correct values for today. */
void dateToday(DATE_T* pResult)
{
    time_t seconds = 0;
    struct tm * pTimeStruct;

    seconds = time(&seconds);
    pTimeStruct = localtime(&seconds);
    pResult->day = pTimeStruct->tm_mday;
    pResult->month = pTimeStruct->tm_mon + 1;
    pResult->year = pTimeStruct->tm_year + 1900;
}


/* Compares two DATE_T structures. Returns 1 if the
 * first date is later than the second, -1 if the
 * first date is earlier than the second, and 0 if
 * they are the same.
 */
int dateCompare(DATE_T firstDate, DATE_T secondDate)
{
    int compareValue = 0;
    if (firstDate.year > secondDate.year)
       {
       compareValue = 1;
       }
    else if (firstDate.year < secondDate.year)
       {
       compareValue = -1;
       }
    else if (firstDate.month > secondDate.month)
       {
       compareValue = 1;
       }
    else if (firstDate.month < secondDate.month)
       {
       compareValue = -1;
       }
    else if (firstDate.day > secondDate.day)
       {
       compareValue = 1;
       }
    else if (firstDate.day < secondDate.day)
       {
       compareValue = -1;
       }
    /* otherwise they are the same */

    return compareValue;
}

