#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPS_SIZE 20
#define SSN_SIZE 9
#define MAX_EMPS 19 

typedef struct {
	int salary;
	int yearBorn;
	char ssn[SSN_SIZE];
	char * name;
}Employee;	

Employee *emps[EMPS_SIZE];
int totalEmps = 0;

void displayEmployee(Employee * person)
{
	printf("\nYou entered the name: %s\nYou entered the year: %d\nYou entered the social security number: ",person->name, person->yearBorn);
	
	for (int i = 0; i < SSN_SIZE ; i++)
        {
                if (i == 2)
                {
                        printf("%c-",person->ssn[i]);
                }
                else if (i == 4)
                {
                        printf("%c-",person->ssn[i]);
                }
		else if (i == 9)
		{
			printf("%c ",person->ssn[i]);
		}
                else
		{
                	printf("%c",person->ssn[i]);
		}
        }
	int num = person->salary / 1000;
	int num2 = person->salary % 1000;
	printf("\nYou entered the salary: $%d,%03d\n\n\n", num, num2);	
}

void readEmployee(Employee * person)
{
	int * inputYearBorn = &person->yearBorn;
	int * inputSalary = &person->salary;
	char buff[256];	

	printf("Welcome to the add employee manager!\n\n");
	
	printf("Enter the Employees name: ");
	scanf("%s", buff);
	person->name = malloc(strlen(buff+1));
	strcpy(person->name, buff);
	
	printf("Enter the year the Employee was born: ");
	scanf("%d", inputYearBorn);
	
	printf("Enter the salary the Employee makes: ");
	scanf("%d", inputSalary);

	printf("Enter the ssn of the Employee: ");
	scanf("%s", buff);
	*person->ssn = '\0';
	strncat(person->ssn, buff, 9);
}

void createEmployee (void)
{
	if (totalEmps <= MAX_EMPS){
		for(int i=0; i <= MAX_EMPS; ++i ) {
  			if( emps[i] == NULL ) {
    				Employee * newEmployee = (Employee*)malloc(sizeof (Employee));
				emps[i] = newEmployee;
				totalEmps++;
				readEmployee(newEmployee);
				break;
  			}
		}
	}
	else{
		printf("You cannot hire anymore employees\n\n");
	}
}

void releaseEmployee (Employee * person)
{
	free(person->name);
	free(person);
}

void listEmployees (void)
{
	for (int i=0; i <= MAX_EMPS; i++)
	{
		if (emps[i] == NULL)
		{
			printf("No employee at : %d\n", i);
		}
		else{
			printf("Employee position in list : %d\n", i);
			displayEmployee(emps[i]);
		}
	}
	printf("Thats all the employees!\n\n");
}

Employee * findEmployee(char * name)
{
	printf("You entered the name: %s\n\n", name);
	int counter = 0;
	for (int i=0; i < totalEmps; i++)
        {
                if (!strcmp(emps[i]->name,name))
                {
                        printf("%s is an employee! They are at: %d\n", name, i);
			return emps[i];
                }
                else{
                	counter++;
		}
        }
	printf("This employee doesn't exist\n");
	return NULL;
}

void fireEmployee(char * name)
{
	printf("You entered the name: %s\n\n", name);
        int counter = 0;
        for (int i=0; i < totalEmps; i++)
        {
                if (!strcmp(emps[i]->name,name))
                {
                
			printf("%s is now fired! They were at: %d\n", name, i);
			free(emps[i]);
			emps[0] = NULL;

			return;
                }
                else{
                        counter++;
                }
        }
        printf("This employee doesn't exist\n");
        return;
}

int salaryComp(Employee ** a, Employee ** b) 
{     		
	Employee *empA = *a;
	Employee *empB = *b;
	if (&empA->salary == NULL && &empB->salary != NULL)
        {
                printf("I got here 2\n\n");
                return 1;
        }
        else if (&empB->salary == NULL && &empA->salary != NULL)
        {
                printf("I got here 3\n\n");
                return -1;
        }
        else if (&empA->salary == NULL && &empB->salary == NULL)
        {
                printf("I got here 4\n\n");
                return -1;
        }
        else {
		printf("empA salary == %d\n",empA->salary);
        	printf("empB salary == %d\n",empB->salary);
        	return  (empB->salary - empA->salary);
        }
}

int nameComp(Employee **a, Employee **b)
{
	Employee *empA = *a;
	Employee *empB = *b;

	if (empA == NULL && empB != NULL)
        {
                return 1;
        }
        else if (empB == NULL  && empA != NULL)
        {
                return -1;
        }
        else if (empA == NULL && empB == NULL)
        {
                return -1;
        }
        else {
			return 0;
	/*	if (lengthA > lengthB)
		{
			return 1;
		}
		if (lengthB > lengthA)
		{
			return -1;
		}
		else
		{
			return 0;
		}	*/
	}	
}

void sort(Employee * base[], int n, int (*compareFunc)( Employee ** , Employee **))
{
     qsort((void **)base,n,sizeof(void *),(int (*)(const void *,const void *))compareFunc);
}

void main(void)
{
	int end = 1;
	char * command;
	char buff[256];
	char * findEmp;
	char findBuff[256];
	char * sortType;
	char sortBuff[256];
	
	char hire[] = "HIRE";
    char list[] = "LIST";
	char quit[] = "QUIT";	
	char find[] = "FIND";
	char fire[] = "FIRE";
	char _sort[] = "SORT";
	char salary[] = "SALARY";
	char name[] = "NAME";

	printf("Welcome to the Employee Manager dashboard!\n");
	while (end){	
		printf("Would you like to HIRE, LIST, FIND, FIRE, SORT, or QUIT?\n\n");
		scanf("%s", buff);
		command = malloc(strlen(buff+1));
	        strcpy(command, buff);

		printf("You entered the command: %s\n\n", command); 

		if (!strcmp(command,hire))
		{
			createEmployee();
		}
		else if (!strcmp(command,list))
		{
			listEmployees();
		}
	        else if (!strcmp(command,find))
                {
                	printf("Enter an employee name, to find if they are a current employee:\n\n");
	                scanf("%s", findBuff);
        	        findEmp = malloc(strlen(findBuff+1));
               		strcpy(findEmp, findBuff);

			findEmployee(findEmp);
                }
		else if (!strcmp(command,fire))
		{
			printf("Enter an employee name, to fire\n\n");
                        scanf("%s", findBuff);
                        findEmp = malloc(strlen(findBuff+1));
                        strcpy(findEmp, findBuff);
                        fireEmployee(findEmp);

		}
		else if (!strcmp(command,_sort))
		{		
			printf("Would you like to sort by SALARY or NAME?\n\n");
			scanf("%s", sortBuff);
			sortType = malloc(strlen(sortBuff+1));
			strcpy(sortType, sortBuff);

			if (!strcmp(sortType,name))
			{
				printf("sorting by name\n\n");
				sort(emps, EMPS_SIZE, nameComp);
				listEmployees();
			}
			else if (!strcmp(sortType,salary))
			{
				printf("sorting by salary\n\n");
				sort(emps, EMPS_SIZE, salaryComp);	
				listEmployees();
			}
			else {

				printf("Improper sort type entered, exiting to main menu\n\n");
			}
		}
		else if (!strcmp(command,quit))
		{
			printf("Quitting the managers dashboard!\n\n");
			end = 0;	
		}
		else{
			printf("Please enter a proper command\n\n");
		}
	}

}
