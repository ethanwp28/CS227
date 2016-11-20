/**********************************************************************/
/*																	                   */
/* Program Name:   program4 -  Database of Customer Accounts          */
/*								                Receivable                    */
/* Author:		    Ethan Pinto										          */
/* Installation:   Pensacola Christian College, Pensacola, Florida    */
/* Course:		    CS227, Data Structures and Algorithms			       */
/* Date Written:   October 28, 2016						    		          */
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
/* This program 
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define PROGRAM_NUMBER  4       /* Teacher assigned program number    */
#define LAST_NAME       "Pinto" /* The programmer's last name         */  
#define COURSE_NUMBER   "CS227" /* PCC assigned course number         */
#define MIN_CUSTOMER    2       /* Minimum number of customers        */ 
#define MAX_CUSTOMER    100     /* Maximum number of customers        */
#define MAX_NAME_LENGTH 20      /* Maximum length of customer's name  */
#define QUIT            0       /* Program exit value                 */
#define DB_ALLOC_ERR    1       /* Can't allocate memory for database */
#define END_OF_STRING   '\0'    /* End of string character            */
#define NEW_LINE        '\n'    /* New line characer                  */

/**********************************************************************/
/*                       Program Structures                           */
/**********************************************************************/
/* Database of customer accounts receivable records                   */
struct customer
{
   char  p_last_name[MAX_NAME_LENGTH + 1]; /* Customer's last name    */                        
	float amount;                           /* Amount owed             */
	int   priority;                         /* Customer priority       */
};

/**********************************************************************/
/*                       Function Prototypes                          */
/**********************************************************************/
void print_heading();
   /* Prints the program heading                                      */
void print_instructions();
   /* Prints the program instructions                                 */
int  get_number_customers();
   /* Gets the number of customer accounts                            */
void get_customer_data(struct customer *p_customer, int num_customers);
   /* Gets the customer data for the accounts database                */
void clean_data(struct customer *p_customer, int num_customers);
   /* Cleans the customer name in the accounts database               */
void sort_data(struct customer *p_customer, int num_customers);
   /* Sorts the customer data in the accounts database                */
void print_data(struct customer *p_customer, int num_customers);
   /* Prints the customer accounts receivable                         */
   
/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
	struct customer *p_customer;   /* Points to the accounts database  */
   int             num_customers; /* Number of customer accounts      */
	
   /* Prints the program heading                                      */
   printf("\n\n\n\n\n\n\n");
   print_heading();
   
   /* Loop processing customer databases until user quits             */
   while (print_instructions(), (num_customers = 
   									   get_number_customers()) != QUIT)
   {
      /* Allocate memory for customer databases and abort if an error */
      /* occurs                                                       */
      if ((p_customer = (struct customer *) 
	     malloc(sizeof(struct customer) * num_customers)) ==  NULL) 
      {
       printf("\nError # %d occurred in main().", DB_ALLOC_ERR);
		 printf("\nCan't allocate memory for customer databases");
		 printf("\nThe program is aborting");
		 exit  (DB_ALLOC_ERR);
	  }	 
	  
	  /* Gets the customer accounts receivable, removes any           */
	  /* non-characters and titlecases the customer names, sorts the  */
	  /* accounts alphabetically, and prints the customer accounts    */
	  /* receivable                                                   */
	  get_customer_data(p_customer, num_customers);
	  clean_data       (p_customer, num_customers);
	  sort_data        (p_customer, num_customers);
	  print_data       (p_customer, num_customers);
   }
   
   /* Prints the end of data processing line                          */
   printf("\n******* END OF DATA PROCESSING *******");
   
   /* Releases memory allocated for customer databases                */
   free  (p_customer);
   
   /* Prints a goodbye message and terminates the program             */
   printf("\n\nThanks for using this program for processing a ");
   printf(    "database of customer accounts receivable.");  
	printf(  "\nHave a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Prints the Program Heading                     */
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
/*                       Prints the Instructions                      */
/**********************************************************************/
void print_instructions()
{
   printf("\n\nThis program allows you to input customers which owe");
   printf(  "\nyou money (your accounts receivable), and manage these");
   printf(  "\naccounts in a database.  You will enter the following:");
   printf(  "\n   Customer last name (%d-%d characters)", MIN_CUSTOMER,
      MAX_CUSTOMER);
   printf(  "\n   Amount the customer owes (to the exact cent)");
   printf(  "\n   Customer priority (1=VIP, 2=Important, 3=Regular)");
   printf(  "\nFrom %d to %d customers may be processed.",
      MIN_CUSTOMER, MAX_CUSTOMER);
   return;
}

/**********************************************************************/
/*           Gets the Number of Customer Accounts Receivable          */
/**********************************************************************/
int get_number_customers()
{
	int num_customers; /* Number of customer accounts receivable       */
	
	printf("\n\nGet the customers for the database");
	printf(  "\n--------------------------------------------------");
	
	do
	{
	   printf("\nHow many customers do you have (%d to ", MIN_CUSTOMER);
	   printf("%d, %d = quit): ", MAX_CUSTOMER, QUIT);
      scanf ("%d", &num_customers);
	}
	while(num_customers != QUIT && (num_customers < MIN_CUSTOMER ||
	                                      num_customers > MAX_CUSTOMER));
	return num_customers;
}

/**********************************************************************/
/*   Gets the Name, Amount Owed, and Priority Level of the Customer   */
/**********************************************************************/
void get_customer_data(struct customer *p_customer_start, 
                       int num_customers)
{
	struct customer *p_customer;  /* Points to the accounts database   */ 
	char            *p_last_name; /* Points to the customer's last     */
	                              /* name in the accounts database     */
	
	/* Loop points to every customer account receivable                */
	for (p_customer = p_customer_start; 
	    (p_customer - p_customer_start) < num_customers; p_customer++)
	{
		/* Prints the customer number                                   */
		printf("\nCustomer number %d :",  + 1);
		
		/* Gets the customer name                                       */
		printf("\n   Enter the customer's last name: ");
		while (getchar() != NEW_LINE);
	       p_last_name = p_customer->p_last_name;
	   do
	   {
	   	*p_last_name++ = getchar();
		}
		while(*(p_last_name - 1) != NEW_LINE);
		
		/* Gets the amount that the customer owes                       */
		*(p_last_name - 1) = END_OF_STRING;
		printf("   Enter the amount owed: ");
		scanf ("%f", &p_customer->amount);
		
		/* Gets the priority of the customer                            */
		do
		{
			printf("   Enter the customer's priority (1-3): ");
			scanf ("%d", &p_customer->priority);
		}
		while(p_customer->priority < 1 || p_customer->priority > 3);
	}
	return;
}

/**********************************************************************/
/*    Removes All Non-Characters and Title-cases the Customer Name    */
/**********************************************************************/
void clean_data(struct customer *p_customer_start, int num_customers)
{
	struct customer *p_customer; /* Points to the accounts database    */
	char            *p_fast = p_customer_start->p_last_name, 
	                             /* Points to every char in word       */
	                *p_slow = p_customer_start->p_last_name; 
					                /* Receives all valid characters       */ 
					   
	for(p_customer = p_customer_start; 
	   (p_customer - p_customer_start) < num_customers; p_customer++)
	{
	   p_fast = p_customer->p_last_name;
	   p_slow = p_customer->p_last_name;
	   while (*p_fast != END_OF_STRING)
	   {
		   if (isalpha(*p_fast))
		      *p_slow++ = tolower(*p_fast);
		   p_fast++;
	   }
	   *p_slow                  = END_OF_STRING;
	   *p_customer->p_last_name = toupper(*p_customer->p_last_name);
	} 
	return;
}

/**********************************************************************/
/*              Sorts the Accounts in Alphabetical Order              */
/**********************************************************************/
void sort_data(struct customer *p_customer_start, int num_customers)
{
	struct customer *p_customer,   /* Points to the accounts database  */
	                *p_outer,      /* Points to the beginning of the   */
	                               /* customer's name                  */
			          *p_inner,      /* Points 
			          temp_customer; /* Temporary customer account       */
			 
	for(p_outer = p_customer_start; 
	   (p_outer - p_customer_start) < num_customers; p_outer++)
	{
		p_inner = p_customer;
		for(p_outer = p_inner + 1; 
		   (p_outer - p_customer_start) < num_customers; p_outer++)
		{
			if(strcmp(p_inner->p_last_name, p_outer->p_last_name) < 0)
			   p_outer    = p_inner;
			temp_customer = *p_customer;
			*p_customer   = *p_inner;
			*p_inner      = temp_customer;
			p_inner++;
		}
		
	}
	return;	  	 
}

/**********************************************************************/
/*               Prints the Customer Accounts Receivable              */
/**********************************************************************/
void print_data(struct customer *p_customer_start, int num_customers)
{
	struct customer *p_customer; /* Points to the accounts database    */
	
	printf("\n  Here is the accounts receivable customer database");
	printf("\n=====================================================");
	printf("\n    Customer Name          Amount        Priority");
	printf("\n---------------------     ---------    -------------");
	
	for(p_customer = p_customer_start; 
	   (p_customer - p_customer_start) < num_customers; p_customer++)
	{
		printf("\n%20s    $%9.2f    %d ", p_customer->p_last_name, 
		   p_customer->amount, p_customer->priority);
		
		switch (p_customer->priority)
		{
			case 1:
				printf("(VIP)");
				break;
			case 2:
				printf("(Important)");
				break;
			case 3:
				printf("(Regular)");
				break;
		}
	}
	return;
}
