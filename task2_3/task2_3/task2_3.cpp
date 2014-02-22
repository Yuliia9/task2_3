#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*maximum number of chars for typing car model/ car number*/
const int LEN = 10;

/*present year for checking year of production cars*/
const int PR_YEAR = 2014;

struct car
{
	char model[LEN];
	char carnumber[LEN];
	unsigned int year;
	float probih;
	int included_probih;
};

/*checking correctness of entered data and return 0 if type mismatch occurs*/
int Type_checking(int retCode, int val);

/*sorted cars by year*/
void Sort_cars(struct car* p, int num);


int main(int argc, _TCHAR* argv[])
{
	printf("Please enter integer number of cars that you want to identify: ");
	unsigned int num_of_cars;
	int retCode ;
	retCode = scanf("%u",&num_of_cars);

	if(0 == Type_checking(retCode,num_of_cars)) 
	{
		return 0;
	}

	struct car* car_table = (car*) malloc(num_of_cars* sizeof(car));
	for(int i=0; i<num_of_cars;i++)
	{
		printf("Enter data about %i car: \n",i+1);
		printf("model (maximum lenght of model 10 characters): ");
		scanf("%s", &car_table[i].model);
		printf("car number: ");
		scanf("%s", &car_table[i].carnumber);

		printf("year of production car: ");
		retCode = scanf("%i", &car_table[i].year);
		if(0 == Type_checking(retCode,car_table[i].year)) 
			return 0;
		if(car_table[i].year>PR_YEAR)
		{
			printf("year of car production doesn't match reasonable requirements");
			return 0;
		}

		printf("mileage of car(probih): ");
		retCode = scanf("%f", &car_table[i].probih);

		if(0 == retCode)
		{
			printf("Type mismatch. Next time please enter float number.\n");
			return 0;
		}
		car_table[i].included_probih=0;
		printf("\n");
	}

	Sort_cars(car_table, num_of_cars );
	printf("Sorted cars by year: \n");
	for(int i=0; i  <num_of_cars; i++)
	{
		printf("%s \t", car_table[i].model);
		printf("%s \t", car_table[i].carnumber);
		printf("%i \t", car_table[i].year);
		printf("%f \t\n", car_table[i].probih);
	}
	
	for(int i=0; i < num_of_cars; i++)
	{
		if(0 == car_table[i].included_probih)
		{
			int n = 1;
			float serednii_probih = 0;
			serednii_probih += car_table[i].probih;
			for(int j = i;j  <num_of_cars; j++)
			{
				if(0 == strcmp(car_table[i].model, car_table[j].model))
				{
					n++;
					serednii_probih+=car_table[j].probih;
					car_table[j].included_probih = 1;
				}
			}
			printf("Average mileage of car(probih) model");
			printf("  %s: %f\n", car_table[i].model, serednii_probih / n);
		}
	}
	return 0;
}

int Type_checking (int retCode, int val)
{
	if(0 == retCode)
	{
		printf("Type mismatch. Next time please enter integer number.\n");
		return 0;
	}
	if(val <= 0)
	{
		printf("The number cann't be negative or null. Next time please check the number.\n");
		return 0;
	}
	return 1;
}

void Sort_cars(struct car* p, int num)
{
	struct car temp;
	for(int i=0; i < num; i++)
	{
		for(int j = i + 1; j < num; j++)
		{
			if((p+i)->year < (p+j)->year)
			{
				temp = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
}