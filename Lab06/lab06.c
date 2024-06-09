/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
 #include <unistd.h>
/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
bool userinput( int timeInput);

/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle;
    int circle;
    int x = 0;
    int square;
    int i;
    int timeInput;
    srand(time(NULL)); /* This will ensure a random game each time. */
    printf("Press the X button to Start the Bop-it game. \n");
    while(x != 1){
        scanf(" %d, %d, %d, %d, %d", &timeInput, &triangle, &circle, &x, &square);
    }

    //this uses i as the time input for our function to decrease the allowed time every turn.
    for(i = 2000; i >= 0; i-=100){
        if(userinput(i) == false){
            break;
        }
    }

    printf("You didnt quite get that one! \n");
    printf("Rounds complete: %d \n", (2000 - i) / 100);

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
bool userinput(int timer){
    int triangle;
    int circle;
    int x;
    int square;
	int timeInput;
    int button = rand() % 4;


    scanf(" %d, %d, %d, %d, %d", &timeInput, &triangle, &circle, &x, &square);
    
    switch(button){
        case 0:
			printf("\nPress Triangle \n");
			break;
		case 1:
			printf("\nPress Circle \n");
			break;
		case 2:
			printf("\nPress X \n");
			break;
		case 3:
			printf("\nPress Square \n");
			break;
    }

    printf("You have %d seconds. \n", timer);

    bool buttonPress = false;
    bool pTriangle, pX, pCircle, pSquare = false;
    bool wrong = false; 
    int prevTriangle, prevCircle, prevX, prevSquare = 0;

    scanf(" %d, %d, %d, %d, %d", &timeInput, &triangle, &circle, &x, &square);

    prevTriangle = triangle;
    prevCircle = circle;
    prevX = x;
    prevSquare = square;
    int startTime = timeInput;


    while(timer - startTime < timeInput && !buttonPress && !wrong){
		scanf("%d, %d, %d, %d, %d", &timeInput, &triangle, &circle, &x, &square);
		
		pTriangle = (triangle == 1 && triangle != pTriangle);
		pCircle = (circle == 1 && circle != pCircle);
		pX = (x == 1 && x != pX);
		pSquare = (square == 1 && square != pSquare);
		
		switch(button){
			case 0:
				buttonPress = pTriangle;
				wrong = (pCircle == true || pX == true || pSquare == true);
				break;
			case 1:
				buttonPress = pCircle;
				wrong = (pTriangle == true || pX == true || pSquare == true);
				break;
			case 2:
				buttonPress = pX;
				wrong = (pCircle == true || pTriangle == true || pSquare == true);
				break;
			case 3:
				buttonPress = pSquare;
				wrong = (pCircle == true || pX == true || pTriangle == true);
				break;
		}
		pTriangle = triangle;
		pCircle = circle;
		pX = x;
		pSquare = square;
	}

    if(buttonPress){
		return true;
	} 
    else {
		if(wrong){
			printf("\nWrong button!\n");
		} else {
			printf("\nYou ran out of time!");
		}
		return false;
	}
}

