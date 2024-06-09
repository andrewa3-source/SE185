/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name:		Andrew Ahrenkiel															 -
- 	Section:	1															 -
-	NetID:		andrewa3														     -
-	Date:			2-22-2022														 -
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
int close_to(double tolerance, double point, double value);
double is_moving(double magnitude);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle = 0, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
    double t;
    double tolerance = .2;
    double pointtop = 1;
    double pointbot = -1;
    double pointleft = 1;
    double pointright = -1;
    double pointfort = -1;
    double pointback = 1;
    double magnituder;
    int i;
    int wasTop = 0;
    int wasBot = 0;
    int wasLeft = 0;
    int wasRight = 0;
    int wasFront = 0;
    int wasBack = 0;
    int wasError = 0;
    int wasMoving = 0;
    while (triangle != 1)
    {

        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);
        
        magnituder = magnitude(ax,ay,az);

        if (close_to(tolerance, pointtop, gy) == 1 && wasTop == 0) {
                printf("TOP\n");
            wasTop = 1;
            wasBot = 0;
            wasLeft = 0;
            wasRight = 0;
            wasFront = 0;
            wasBack = 0;
            wasError = 0;
            wasMoving = 1;

        }
        else if (close_to(tolerance, pointbot, gy) == 1 && wasBot == 0){
            printf("BOTTOM\n");
            wasTop = 0;
            wasBot = 1;
            wasLeft = 0;
            wasRight = 0;
            wasFront = 0;
            wasBack = 0;
            wasError = 0;
            wasMoving = 1;
        }
        else if (close_to(tolerance, pointleft, gx)== 1 && wasLeft == 0) {
            printf("LEFT\n");
            wasTop = 0;
            wasBot = 0;
            wasLeft = 1;
            wasRight = 0;
            wasFront = 0;
            wasBack = 0;
            wasError = 0;
            wasMoving = 1;
        }
        else if (close_to(tolerance, pointright, gx) == 1 && wasRight == 0) {
            printf("RIGHT\n");
            wasTop = 0;
            wasBot = 0;
            wasLeft = 0;
            wasRight = 1;
            wasFront = 0;
            wasBack = 0;
            wasError = 0;
            wasMoving = 1;
        }
        else if (close_to(tolerance, pointfort, gz) == 1 && wasFront == 0) {
            printf("FRONT\n");
            wasTop = 0;
            wasBot = 0;
            wasLeft = 0;
            wasRight = 0;
            wasFront = 1;
            wasBack = 0;
            wasError = 0;
            wasMoving = 1;
        }
        else if (close_to(tolerance, pointback, gz) == 1 && wasBack == 0) {
            printf("BACK\n");
            wasTop = 0;
            wasBot = 0;
            wasLeft = 0;
            wasRight = 0;
            wasFront = 0;
            wasBack = 1;
            wasError = 0;
            wasMoving = 1;
        }
        else if (is_moving(magnituder) == 1 && wasMoving == 0) {
            printf("STOP MOVING\n");
            wasTop = 0;
            wasBot = 0;
            wasLeft = 0;
            wasRight = 0;
            wasFront = 0;
            wasBack = 0;
            wasError = 0;
            wasMoving = 1;
        } 
        else {
            
            
        }
        
        //printf("Echoing output: %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n",
               //ax, ay, az, gx, gy, gz, triangle, circle, x_button, square);
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int close_to(double tolerance, double point, double value)
{
    int result;
    
    if(value >= (point - tolerance) && value <= (point + tolerance)){
        result = 1;
    }
    else {
        result = 0;
    }   
    return result;
    
}


double magnitude(double x, double y, double z) {
    double result;
    result = (sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z,2.0)));
    return result;
}

double is_moving(double magnitude) {
    
    if(magnitude >= .21) {
        return 1;
    }
    else {
        return 0;
    }
    
}