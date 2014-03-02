#include "stdafx.h"

const unsigned int LEN = 10;

struct car
{
	char model[LEN];
	char carnumber[LEN];
	unsigned int year;
	float probih;
	unsigned int included_probih;
};
/*displays some information about program*/
void Interface();

/*checking correctness of entered data and return 0 if type mismatch occurs*/
unsigned char Type_checking(unsigned char retCode, int val);

/*input information about cars into list of cars*/
unsigned char Input(struct car* cars, unsigned int num);

/*displays list of information about cars on display*/
unsigned char Output(const struct car* cars, unsigned int num);

/*sorted cars by year*/
unsigned char Sort_cars(struct car* p, int num);

/*Estimates the average mileage for different models of cars*/
unsigned char Get_mileage(struct car* cars, unsigned int num);

/*checking if string pstr involves only digits*/
unsigned char Is_digit(const char* pstr);