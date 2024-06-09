/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
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
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);


/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-1.c -o lab03-1
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -a | ./lab03-1

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double ax, ay, az;

    while (1)
    {
        scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
        
        /* CODE SECTION 0 */
        printf("Echoing output: %5.3d, %3.4lf, %3.4lf, %3.4lf\n", t/1000, ax, ay, az);

        
        /* 	CODE SECTION 1 */
        double magnitude = (sqrt(pow(ax, 2.0) + pow(ay, 2.0) + pow(az,2.0)));
        printf("At %d ms, the acceleration's magnitude was: %lf\n", t, magnitude);
        

        /* 	CODE SECTION 2 */
            int minutes = (t/60)/(1000);
            int seconds = (t/1000) - (60 * minutes);
            int milliseconds = t - (minutes * 60 *1000) - (seconds * 1000);
        
            printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n",
            minutes, seconds, milliseconds, magnitude);


        
    }

    return 0;
}

/* Put your functions here */

/**
 * Calculates and returns the magnitude of three given values.
 *
 * @param x - The x-axis scanned values from the DS4 controller.
 * @param y - The y-axis scanned values from the DS4 controller.
 * @param z - The z-axis scanned values from the DS4 controller.
 * @return - The magnitude of the given values.
 */
double magnitude(double x, double y, double z)
{
    // Step 8, uncomment and modify the next line
    // return sqrt( );
}

