/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_4.c -o lab04-1_4
// Run with ./lab04-1_4
/* This program calculates the energy of one photon
 * of user-inputted wave-length of light */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double speed_of_light; //removed illegal symbol from variable
    double wave_length; //removed illegal symbol from variable name
    double length_in_meters;//removed illegal symbol from variable name
    double plankconst;//removed illegal symbol from variable name
    double energy;//removed illegal decleration from variable

    plankconst = 6.62606957 * pow(10, -34); // Planck's constant
    speed_of_light = 2.99792458 * pow(10, 8); // Constant for the speed of light
    wave_length = 0;
    length_in_meters = 0;
    energy = 0;

    printf("Welcome! This program will give the energy, in Joules,\n");
    printf("of 1 photon with a certain wave-length.\n");
    printf("Please input a wave-length of light in nano-meters.\n");
    printf("Please do not enter a negative, or zero, wave-length.\n");

    scanf("%lf", &wave_length);

    if (wave_length > 0.0)
    {
        length_in_meters = wave_length / pow(10, 9); // Converting nano-meters to meters
        energy = (plankconst * speed_of_light) / length_in_meters; // Calculating the energy of 1 photon
        printf("A photon with a wave_length of %08.3lf nano-meters, carries "
               "\napproximately %030.25lf joules of energy.", wave_length, energy);
    } else
    {
        printf("Sorry, you put in an invalid number.");
        printf("Please rerun the program and try again.");
    }

    return 0;
}
