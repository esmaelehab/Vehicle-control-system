/*
 * MiniProject1.c
 *
 *  Created on: ٠٨‏/٠٩‏/٢٠٢١
 *      Author: laptop World
 */

#include <stdio.h>
#include "MiniProject1.h"
#define ON 1
#define OFF 0

//prototypes
void Turn_On_Engine(void);
void Turn_Off_Engine(void);
int Set_the_traffic_light_colour(void);
float Set_the_room_temperature(float *);
float Set_the_engine_temperature(float *);
char sensors_set_menu(void);
void vehicle_state(void);

int vehicle_speed=0, engine_state;
float room_temp=35, engine_temp=90, AC, ETC;

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char input1;
	//display the first menu
	printf("\nchoose what you want :\n");
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	scanf(" %c",&input1);

	switch(input1)
	{
	case 'A' :
	case 'a' : engine_state = ON;
		       printf("the engine is now ON\n");
			   Turn_On_Engine();
	break;
	case 'B' :
	case 'b' : engine_state = OFF;
		       printf("the engine is OFF\n\n");
		       Turn_Off_Engine();
	break;
	case 'C' :
	case 'c' : printf("the system is OFF\n");
		       return 0;
	break;
	}
}

void Turn_Off_Engine(void)   //function that print the first menu in case of chose turn off engine
{
	main();
}

void Turn_On_Engine(void)  //function that will be called in case of chose turn on engine
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char input2;
	input2 = sensors_set_menu();  //takes the chosen set from the sensors set menu

	while ( engine_state == ON )
	{
		if (input2 == 'a' || input2 == 'A')
		{
			engine_state = OFF;
			vehicle_state();  //show the vehicle state
			Turn_Off_Engine();  //return back to the first menu
		}
		if (input2 == 'b' || input2 == 'B')
		{
			vehicle_speed = Set_the_traffic_light_colour();
			if ( vehicle_speed == 30)
				{
					AC = ON;
					room_temp = room_temp *(5/4) + 1;
					ETC = ON;
					engine_temp = engine_temp *(5/4) + 1;
				}
			vehicle_state();                            //after getting the the vehicle speed print the the vehicle state
			input2 = sensors_set_menu();                //shows the sensors set menu again
		}
		if ( input2 == 'c' || input2 == 'C')
		{
			room_temp = Set_the_room_temperature(&AC);  //gets the room temperature and the AC state by passing it by reference
			vehicle_state();                            //after getting the the room temperature print the the vehicle state
			input2 = sensors_set_menu();                //show the sensors set menu again
		}
		if ( input2 == 'd' || input2 == 'D')
		{
			engine_temp = Set_the_engine_temperature(&ETC);  //gets the engine temperature and the ETC state by passing it by reference
			vehicle_state();                                 //after getting the the room temperature print the the vehicle state
			input2 = sensors_set_menu();                     //show the sensors set menu again
		}
	}
}

char sensors_set_menu(void) //function that take print the sensors set menu and return the chosen set
{
	char input2;
	printf("\nsensors set menu\n");
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light colour\n");
	printf("c. Set the room temperature\n");
	printf("d. Set the engine temperature\n\n");
	scanf(" %c", &input2);
	return input2;
}

int Set_the_traffic_light_colour(void)   //function that return the vehicle speed
{
   char traffic_light;
   int speed;
   printf("\ntraffic light data is : ");
   scanf(" %c", &traffic_light);
   switch (traffic_light)
   {
   case 'g' :
   case 'G' : speed = 100;
   break;
   case 'o' :
   case 'O' : speed = 30;
   break;
   case 'r' :
   case 'R' : speed = 0;
   break;
   }
   return speed;
}

float Set_the_room_temperature(float *ac)   //function that return the room temperature
{
	float R_temp_data;
	printf("\nroom temperature data is : ");
	scanf(" %f", &R_temp_data);
	if ( R_temp_data < 10 || R_temp_data >30)
	{
		*ac = ON;
		R_temp_data = 20;
	}
	else
	{
		*ac = OFF;
	}
	return R_temp_data;
}

float Set_the_engine_temperature(float *etc) //function that return the engine temperature
{
	float E_temp_data;
	printf("\nengine temperature data is : ");
	scanf(" %f", &E_temp_data);
	if ( E_temp_data < 100 || E_temp_data > 150 )
	{
		*etc = ON;
		E_temp_data = 125;
	}
	else
	{
		*etc = OFF;
	}
	return E_temp_data;
}

void vehicle_state(void)  //function that print the vehicle state
{
	printf("\nvehicle state :\n");
	if ( engine_state == ON )
	    printf("engine state : ON\n");

	if ( engine_state == OFF )
       printf("engine state : OFF\n");


	if( AC == ON )
		printf("AC : ON\n");
	if( AC == OFF )
		printf("AC : OFF\n");

	printf("Vehicle Speed = %d\n", vehicle_speed);
	printf("Room Temperature = %.1f\n", room_temp);

	if ( ETC == ON )
	   printf(" Engine Temperature Control State : ON\n");
	if ( ETC == OFF )
		printf("Engine Temperature Control State : OFF\n");

	printf("engine temperature = %.1f\n", engine_temp);
}



















