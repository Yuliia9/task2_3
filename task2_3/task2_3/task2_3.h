/**
* @file		task2_3.h
* @brief	header file for task2_3.cpp
			defines data types and prototypes for functions used in task2_3.cpp
*/

#include "stdafx.h"

/*maximum length of characters for car's model and number */
const unsigned int LEN = 10;


/*defines data type for holding information about cars*/
struct car
{
	char model[LEN];		
	char carnumber[LEN];
	unsigned int year;
	float probih;
	unsigned int included_probih; 
};


/**
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface();


/**
* @brief						Checking if data match requirements set to that data type or functions return values

* @param	[in]				unsigned char retCode - return value of other functions for checking if functions ended properly
			[in]				int val - number for checking if it's negative or zero
* @return	unsigned char		Return ERROR if data doesn't match requirements
								Return SUCCESS if inputed data match requirements
*/
unsigned char Type_checking(unsigned char retCode, int val);



/**
* @brief					Function for input information about cars
* @param	[in/out]		struct car* cars - pointer to array of structures that holds information about cars
			[in]			unsigned int num - the number of cars in created database
* @return	unsigned char	Return ERROR if pointer to array of structures is NULL
							Return SUCCESS if data was inputed
*/
unsigned char Input(struct car* cars, unsigned int num);




/**
* @brief					Function for displaying information stored in car's database
* @param	[in]			const struct car* cars - pointer to array of structures that holds information about cars
			[in]			unsigned int num - the number of cars stored in created database
* @return	unsigned char	Return ERROR if pointer to array of structures is NULL
							Return SUCCESS if data was displayed
*/
unsigned char Output(const struct car* cars, unsigned int num);





/**
* @brief					Function sorts cars by ascending productions year
* @param	[in/out]		struct car* p - pointer to array of structures that holds  information about cars
			[in]			unsigned int num - the number of cars stored in created  database
* @return	unsigned char	Return ERROR if pointer to array of structures p is NULL
							Return SUCCESS if cars were sorted
*/
unsigned char Sort_cars(struct car* p, unsigned int num);


/**
* @brief					Function estimates the average mileage for different cars models
* @param	[in/out]		struct car* cars - pointer to array of structures that holds  information about cars
			[in]			unsigned int num - the number of cars stored in created database
* @return	unsigned char	Return ERROR if pointer to array of structures p is NULL
							Return SUCCESS if average mileage was estimated
*/
unsigned char Get_mileage(struct car* cars, unsigned int num);




/**
* @brief					Function for checking if inputed string involves only digits
* @param	[in]			const char* pstr - pointer to, checking for numbers, string
* @return	unsigned char	Return ERROR if string contains not only numbers
							Return SUCCESS if string contains only numbers
*/
unsigned char Is_digit(const char* pstr);