/**********************************************************************/
/*																	                   */
/* Program Name:   program5 - Recursively Calculate the Sum of Even   */
/*                            Numbers in a Range                      */
/* Author:		    Ethan Pinto										          */
/* Installation:   Pensacola Christian College, Pensacola, Florida    */
/* Course:		    CS227, Data Structures and Algorithms			       */
/* Date Written:   November 10, 2016						    		       */
/*																	                   */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge  all of the lines  in this C program  are my own original */
/* work and that none of the lines in this C program have been copied */
/* from anyone else, unless I was specifically authorized to do so by */
/*                        my CS227 instructor.                        */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                           (signature)              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program reads in a range, swaps the range boundaries if they  */
/* are out of order, checks if the number is even, and recursively    */
/* calculates the sum of the even numbers in the range.               */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <ctype.h>

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define PROGRAM_NUMBER  5       /* Teacher assigned program number    */
#define LAST_NAME       "Pinto" /* The programmer's last name         */  
#define COURSE_NUMBER   "CS227" /* PCC assigned course number         */
#define MIN_RANGE_VALUE -5000   /* Minimum range boundary             */ 
#define MAX_RANGE_VALUE  5000   /* Maximum range boundary             */

/**********************************************************************/
/*                       Function Prototypes                          */
/**********************************************************************/
void print_heading();
   /* Print the program heading                                       */
void print_instructions();
   /* Print the program instructions                                  */
char get_response();
   /* Get the response                                                */
void get_range_value();
   /* Get the boundaries of the range                                 */
void swap_range_boundaries(int *p_first_user_range, 
                           int *p_last_user_range);
   /* Swap the range boundaries                                       */
int is_even(int first_user_range);
   /* Check if the number is even                                     */
int sum_evens(int first_user_name, int last_user_name);
   /* Recursively calculate the sum of the evens in a range           */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
	int first_user_range, /* Beginning boundary of the range           */
	    last_user_range;  /* Ending boundary of the range              */   
		   
	/* Print the program heading and instructions                      */
   printf("\n\n\n\n\n\n\n");
   print_heading();
   print_instructions();
   
   /* Loop processing whole numbers in a range until the user quits   */
   while(get_response() == 'y')
   {
   	/* Get the boundaries of the whole number range                 */
   	get_range_value(&first_user_range, &last_user_range);

      /* Swap the range boundaries if they are out of order,          */
      /* recursively calculate the sum of the evens in the range      */
      /* inclusively, and print the sum                               */
   	if(first_user_range > last_user_range)
		   swap_range_boundaries(&first_user_range, &last_user_range); 
		printf("\nProcessing the range %d to %d: ", 
		   first_user_range, last_user_range);
		sum_evens(first_user_range, last_user_range);
	}
	
   /* Print a goodbye message and terminates the program              */
   printf("\n\nThanks for \"even summing\".  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Print the Program Heading                      */
/**********************************************************************/
void print_heading()
{
   printf("\n======================================================");
   printf("\n               Program Number: %d",    PROGRAM_NUMBER);
   printf("\n               Programmer: %s",        LAST_NAME);
   printf("\n               PCC Course Number: %s", COURSE_NUMBER);
   printf("\n======================================================");
   return;
}

/**********************************************************************/
/*                       Print the Instructions                       */
/**********************************************************************/
void print_instructions()
{
	printf("\nThis program recursively calculates the sum of all");
	printf("\neven whole numbers between two numbers inclusively.");
	printf("\nYou are repeatedly asked to enter in the start and");
	printf("\nend of a range, and the sum of all even numbers in");
	printf("\nthat range is calculated and printed.  Information");
	printf("\nabout the recursive action of the function is also");
	printf("\nprinted so the recursive nature of the calculation");
	printf("\n                 may be observed");
	return;
}

/**********************************************************************/
/*                          Get the Response                          */
/**********************************************************************/
char get_response()
{
	char user_response[2]; /* Response from the user                   */
	
	do
	{
		printf("\n\nDo you want to process another range (y or n): ");
		scanf ("%1s", user_response);
		user_response[0] = tolower(user_response[0]);
	}
	while (user_response[0] != 'y' && user_response[0] != 'n');
	return user_response[0];
}

/**********************************************************************/
/*                           Get the Range                            */
/**********************************************************************/
void get_range_value(int *p_first_user_range, int *p_last_user_range)
{
	do
	{
		printf("\nEnter in the first number (from %d to %d): ", 
		   MIN_RANGE_VALUE, MAX_RANGE_VALUE);		
      scanf ("%d", p_first_user_range);
	}
	while(*p_first_user_range >= MAX_RANGE_VALUE && 
         *p_first_user_range < MIN_RANGE_VALUE);
	
	do
	{
		printf("\nEnter in the last number (from %d to %d): ",
		   MIN_RANGE_VALUE, MAX_RANGE_VALUE);
      scanf ("%d", p_last_user_range);
	}
	while(*p_last_user_range >= MAX_RANGE_VALUE && 
         *p_last_user_range < MIN_RANGE_VALUE);
	return;
}

/**********************************************************************/
/*                  Swap the Boundaries of the Range                  */
/**********************************************************************/
void swap_range_boundaries(int *p_first_number, int *p_last_number)
{
	*p_first_number  += *p_last_number;
	*p_last_number    = *p_first_number - *p_last_number;
	*p_first_number  -= *p_last_number;
   return;
}

/**********************************************************************/
/*             Recursively Calculate the Sum of the Evens             */
/**********************************************************************/
int sum_evens(int first_user_range, int last_user_range)
{
   int sum = 0; /* Inclusive sum of the evens in the range            */

	printf("\n    Entering sum functon for range %d to %d", 
      first_user_range, last_user_range); 
   if(first_user_range <= last_user_range)
   {
	   if (is_even(first_user_range) == 0)
	   {
	      printf("\n        Adding: %d", first_user_range);
         sum = first_user_range + sum_evens(first_user_range + 1, 
                                            last_user_range);
	   }
	   else 
      {
	      printf("\n        Skipping: %d", first_user_range);
	      sum = sum_evens(first_user_range + 1, last_user_range);
      }
   }
	printf("\nExiting sum function for range %d to %d with result: %d", 
      first_user_range, last_user_range, sum);
   return sum;
}

/**********************************************************************/
/*                    Check if the Number is Even                     */
/**********************************************************************/
int is_even(int user_number)
{
	return (user_number % 2);
}
