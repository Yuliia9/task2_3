#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2_3.h"

const unsigned char ERROR = 0;
const unsigned char SUCCESS = 1;
const unsigned char MAIN_SUCCES = 0;


/*present year for checking year of production cars*/
const int PR_YEAR = 2014;



int main()
{
	Interface();
	unsigned int num;
	int retCode;
	do 
	{
		printf("Please enter integer number of cars that you want to identify: ");
		retCode = scanf("%u", &num);
		fflush(stdin); // Flush the input buffer

	} while (Type_checking(retCode, (int) num) == ERROR);
	printf("List will consist of %u cars.\n", num);

	struct car* cars = (car*)malloc(num* sizeof(car));
	if (cars == NULL)
	{
		printf("Error occurs while trying to allocate memory for list of cars. \n");
		return (int) ERROR;
	}

	retCode = Input(cars, num);
	if (retCode == ERROR)
	{
		free(cars);
		return (int)ERROR;
	}

	retCode = Sort_cars(cars, num);
	if (retCode == ERROR)
	{
		free(cars);
		return (int)ERROR;
	}


	retCode = Output(cars, num);
	if (retCode == ERROR)
	{
		free(cars);
		return (int)ERROR;
	}


	retCode = Get_mileage(cars, num);
	if (retCode == ERROR)
	{
		free(cars);
		return (int)ERROR;
	}

	free(cars);
	system("pause");
	return (int) MAIN_SUCCES;
}
void Interface()
{
	printf("Hi! Please welcome to your personal cars information handler. \n");
	printf("You can store information about model of cars, it's production year,\n number and mileage. \n");
	printf("Program will show you the list from oldest to newest cars \n");
	printf("and will estimate for each model of cars average mileage.\n");
	printf("Program made by Yuliia Lyubchik;)\n");
}

unsigned char  Type_checking(unsigned char retCode, int val)
{
	if (retCode == 0)
	{
		printf("Type mismatch. Next time please check the number.\n");
		return ERROR;
	}
	if (val <= 0)
	{
		printf("The number can't be negative or zero. Next time please check the number.\n");
		return ERROR;
	}
	return SUCCESS;
}


unsigned char Input(struct car* cars, unsigned int num)
{
	if (cars == NULL)
	{
		printf("Error occurs trying to get access to memory.\n");
		return ERROR;
	}
	unsigned int i;
	unsigned char retCode;
	for (i = 0; i < num; ++i)
	{
		printf("Enter data about %i car: \n", i + 1);
		do
		{
			printf("model:  ");
			gets(cars[i].model);
		} while (strlen(cars[i].model) == 0);
		
		do
		{
			printf("car number: ");
			gets(cars[i].carnumber);
		} while (strlen(cars[i].carnumber) == 0);
		

		do 
		{
			printf("year of production car: ");
			retCode = scanf("%u", &cars[i].year);
			fflush(stdin); // Flush the input buffer
		} while (Type_checking(retCode, (int) cars[i].year) == ERROR);

		if (cars[i].year > PR_YEAR)
		{
			printf("Year of car production doesn't match reasonable requirements. \n");
		}
		do 
		{
			char temp[20];
			printf("mileage of car(probih): ");
			retCode = scanf("%s", &temp);
			if (Is_digit(temp) == ERROR)
			{
				printf("Type mismatch. Please check the number.\n");
			}
			else
			{
				cars[i].probih = atof(temp);
			}
			fflush(stdin);// Flush the input buffer

		} while (Type_checking(retCode, (int)cars[i].probih) == ERROR);
		
		cars[i].included_probih = 0;
		printf("\n");
	}
	return SUCCESS;
}


unsigned char Sort_cars(struct car* p, int num)
{
	if (p == NULL)
	{
		printf("Error occurs while trying to sort data. \n");
		return ERROR;
	}
	struct car temp;
	unsigned int i, j;
	for (i = 0; i < num; ++i)
	{
		for (j = i + 1; j < num; ++j)
		{
			if ((p + i)->year < (p + j)->year)
			{
				memcpy(&temp, p + i, sizeof(car));
				memcpy(p + i, p + j, sizeof(car));
				memcpy(p + j, &temp, sizeof(car));
			}
		}
	}
	return SUCCESS;
}

unsigned char Output(const struct car* cars, unsigned int num)
{
	if (cars == NULL)
	{
		printf("Error occurs while trying to display data. \n");
		return ERROR;
	}
	printf("Sorted cars by year: \n");
	for (int i = 0; i < num; i++)
	{
		printf("%s \t", cars[i].model);
		printf("%s \t", cars[i].carnumber);
		printf("%u \t", cars[i].year);
		printf("%f \t\n", cars[i].probih);
	}
	return SUCCESS;
}

unsigned char Get_mileage(struct car* cars, unsigned int num)
{
	if (cars == NULL)
	{
		printf("Error occurs while trying to get data to estimate average mileage");
		return ERROR;
	}
	unsigned int i, j;
	int n;
	float serednii_probih;
	for (i = 0; i < num ; ++i)
	{
		if (cars[i].included_probih == 0)
		{
			n = 1;
			serednii_probih = 0;
			serednii_probih += cars[i].probih;
			for (j = i; j < num; ++j)
			{
				if (0 == strcmp(cars[i].model, cars[j].model))
				{
					++n;
					serednii_probih += cars[j].probih;
					cars[j].included_probih = 1;
				}
			}
			printf("Average mileage of car(probih) model");
			printf("  %s: %f\n", cars[i].model, serednii_probih / n);
		}
	}
}

unsigned char Is_digit(const char* pstr)
{
	if (pstr == NULL)
	{
		return ERROR;
	}
	unsigned int i;
	unsigned char krapka = 0;
	for (i = 0; i < strlen(pstr); ++i)
	{
		if (pstr[i] >= 48 && pstr[i] <= 57)
		{
			continue;
		}
		else if (pstr[i] == '.')
		{
			if (krapka == 0)
			{
				krapka = 1;
			}
			else
			{
				return ERROR;
			}
		}
		else return ERROR;
	}
	return SUCCESS;
}
