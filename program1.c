/**********************************************************************/
/*                                                                    */
/* Program Name:   program1 - Inclusive Sum of a Range                */
/* Author:         Ethan Pinto					                         */
/* Installation:   Pensacola Christian College, Pensacola, Florida    */
/* Course:	       CS227, Data Structures and Algorithms              */
/* Date Written:   September 16, 2016                                 */
/*								                                              */
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
/*This program prompts for a minimum and maximum value, inclusively   */
/*sums the values, and then prints the sum.                           */
/**********************************************************************/

#include   <stdio.h>

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define   PROGRAM_NUMBER   1        /* Teacher assigned course number */
#define   LAST_NAME        "Pinto"  /* The programmers last name      */  
#define   COURSE_NUMBER    "CS227"  /* PCC Assigned Course Number     */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Prints the program heading                                      */
void get_range(int *p_maxValue, int *p_minValue);
   /* Gets the range of values                                        */
int sum_range(int maxValue, int minValue);
   /* Sums the range                                                  */
   
/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int   maxValue, /* User's maximum value                            */
         minValue; /* User's minimum value                            */
	 
   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n\n");
   print_heading();
   
   /* Prompt the user for a range of numbers                          */
   get_range(&maxValue, &minValue);
   
   /* Sum and print the range                                         */ 
   printf("\nThe sum of all numbers between %d and ", minValue);
   printf("%d (inclusively) is %d", maxValue, 
          sum_range(maxValue, minValue));
   
   /*Print a goodbye message and terminate the program                */
   printf("\n\nThanks for using this program.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Print the program heading                      */
/**********************************************************************/
void print_heading()
{
   printf("\n======================================================");
   printf("\n               Program Number: %d", PROGRAM_NUMBER);
   printf("\n               Programmer: %s", LAST_NAME);
   printf("\n               PCC Course Number: %s", COURSE_NUMBER);
   printf("\n======================================================");
   printf("\n\nI'll sum whole numbers in a number range ");
   printf("(inclusively).");
   printf("\n------------------------------------------------------");
   return;
}

/**********************************************************************/
/*                    Get the range from the user                     */
/**********************************************************************/
void get_range(int *p_maxValue, int *p_minValue)
{
   printf("\nEnter a range of whole numbers now, lower number first:");
   printf("\n    What is your small number: ");
   scanf("%d", p_minValue);
   printf("    Give me your large number: ");
   scanf("%d", p_maxValue);
   return;
}

/**********************************************************************/
/*                   Sum the range of given values                    */
/**********************************************************************/
int sum_range(int maxValue, int minValue)
{ 
   int count,
       sum = 0;
   for (count = minValue; count <= maxValue; count++)
       sum += count;
   return sum;
}
   
   
		 
