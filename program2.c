/**********************************************************************/
/*																	                   */
/* Program Name:  program2 - Math Operations on Two Whole Numbers		 */
/* Author:		   Ethan Pinto										             */
/* Installation:  Pensacola Christian College, Pensacola, Florida     */
/* Course:		   CS227, Data Structures and Algorithms			       */
/* Date Written:  September 30, 2016								          */
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
/* This program performs four math operations on a pair of whole      */
/* numbers given by the user. After printing a menu and prompting for */
/* a menu choice, the program will either add the two whole numbers,  */
/* raise the first number to the power of the second, sum all of the  */
/* numbers in the range between the two numbers inclusively, and put  */
/* the two numbers into ascending order if needed.                    */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define PROGRAM_NUMBER  2        /* Teacher assigned course number    */
#define LAST_NAME       "Pinto"  /* The programmers last name         */  
#define COURSE_NUMBER   "CS227"  /* PCC assigned course number        */
#define MIN_MENU_CHOICE 1        /* Minimum choice for the menu       */
#define MAX_MENU_CHOICE 5        /* Maximum choice for the menu       */
#define MENU_CHOICE_ERR 1        /* Impossible menu choice error      */
#define QUIT            MAX_MENU_CHOICE
                                  /* Choice that quits the program    */
									
/**********************************************************************/
/*                       Function Prototypes                          */
/**********************************************************************/
void  print_heading();
   /* Prints the program heading                                      */
void  print_menu();
   /* Prints the program menu                                         */
int   get_menu_choice();
   /* Gets the menu choice from the user                              */
void  get_whole_numbers(int *p_number_one, int *p_number_two);
   /* Gets two whole numbers from the user                            */
int   sum_two_numbers(int number_one, int number_two);
   /* Adds two whole numbers                                          */
float raise_to_power(int number_one, int number_two);
   /* Raises the first number to the power of the second              */
int   range_sum(int number_one, int number_two);
   /* Sums inclusively the range of the two whole numbers             */
void  order_numbers(int *p_number_one, int *p_number_two);
   /* Puts the two numbers in ascending order                         */
   
/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int menu_choice, /* Stores the menu choice                         */
       number_one,  /* Stores the first whole number                  */
       number_two;  /* Stores the second whole number                 */
   
   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n\n");
   print_heading();
   
   /* Loop processing whole number pairs until the user quits         */
   while (print_menu(), (menu_choice = get_menu_choice()) != QUIT)
   {
      /* Gets two whole numbers                                       */
	  get_whole_numbers(&number_one, &number_two);
	  
	  /* Displays the menu choices                                    */
	  switch (menu_choice)
	  {
         /* Sums two whole numbers                                    */    
	     case 1:
	        printf("\nThe sum of %d and %d is %d", number_one, 
               number_two, sum_two_numbers(number_one, number_two));
		    break;
		    
		 /* Raises the first number to the power of the second        */   
		 case 2:
            printf("\n%d raised to the power of %d = %1.6e", number_one,
               number_two, raise_to_power(number_one, number_two));
            break;
            
         /* Sums the range inclusively from number one to number two  */
		 case 3:
		    printf("\nThe sum of the numbers between %d ", number_one);
		    printf("and %d (inclusive) is %d", number_two, 
		       range_sum(number_one, number_two));
		    break;
		    
         /*If needed, orders the two whole numbers                    */
		 case 4:
		    if (number_one <= number_two)
               printf("%d and %d are already in order", number_one,
                  number_two);
            else 
            {
               order_numbers(&number_one, &number_two);
               printf("%d and %d are properly ordered", number_one,
                  number_two);
            }
		    break;
			
		/* Impossible menu choice error                               */	
		default:
		   printf("\nError # %d occured in main().", MENU_CHOICE_ERR);
		   printf("\nAn impossible choice occurred");
		   printf("\nThe program is aborting");
		   exit  (MENU_CHOICE_ERR); 
      }
   }		   
   
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
   printf("\n               Program Number: %d",    PROGRAM_NUMBER);
   printf("\n               Programmer: %s",        LAST_NAME);
   printf("\n               PCC Course Number: %s", COURSE_NUMBER);
   printf("\n======================================================");
   return;
}

/**********************************************************************/
/*                           Print the Menu                           */
/**********************************************************************/
void print_menu()
{
   printf("\n\nMake a selection from the following menu:");
   printf("\n-----------------------------------------");   
   printf("\n     1 - Add two whole numbers");
   printf("\n     2 - Raise the 1st number to the power of the 2nd");
   printf("\n     3 - Sum all numbers between two whole numbers");
   printf("\n     4 - Put two whole numbers into ascending order");
   printf("\n     5 - Quit");
   return;
}

/**********************************************************************/
/*                     Prompt for the Menu Choice                     */
/**********************************************************************/
int get_menu_choice()
{
   int menu_choice; /* Stores the menu choice                         */
   
   printf("\nEnter your menu selection: ");
   scanf ("%d", &menu_choice);
   return menu_choice;
}

/**********************************************************************/
/*                       Get two whole numbers                        */
/**********************************************************************/
void get_whole_numbers(int *p_number_one, int *p_number_two)
{
   printf("\nType in any two whole numbers now:");
   printf("\n    What is your first number: ");
   scanf ("%d", p_number_one);
   printf("    Give me your second number: ");
   scanf ("%d", p_number_two);
   return;
}

/**********************************************************************/
/*                       Sum two whole numbers                        */
/**********************************************************************/
int sum_two_numbers(int number_one, int number_two)
{
   return number_one + number_two;
}

/**********************************************************************/
/*         Raise the first number to the power of the second          */
/**********************************************************************/
float raise_to_power(int number_one, int number_two)
{
  return powf((double) number_one, (double) number_two);
}

/**********************************************************************/
/*                 Inclusive sum of two whole numbers                 */
/**********************************************************************/
int range_sum(int number_one, int number_two)
{
   int range_counter, /* Control variable in the for loop             */
       range_sum = 0; /* Stores the inclusive sum of the range        */
       
   /* Checks if the numbers are in the right order                    */
   order_numbers(&number_one, &number_two); 
          
   for (range_counter = number_one; range_counter <= number_two;
                                                       range_counter++) 
      range_sum += range_counter;
   return range_sum;                          
}

/**********************************************************************/
/*              Put two whole numbers in ascending order              */
/**********************************************************************/
void order_numbers(int *p_number_one, int *p_number_two)
{
   int temp; /* Temporary storage variable for rearranging the numbers*/
   
   if (*p_number_one > *p_number_two)
   {
      temp = *p_number_one;
      *p_number_one = *p_number_two;
      *p_number_two = temp;
   }
   return;  
}
