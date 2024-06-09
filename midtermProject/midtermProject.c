/*----------------------------------------------------------------------------
-		         SE 185: Midterm Project   	               -
- List the names of all team members, their roles, and their participation
1- Student 1 - Role: Quiz Creator	and debugger - Participation: x%
(Use this line to describe your contribution to the project)
2- Student 2 - Role: Quiz Creator and debugger - Participation: y%
(Use this line to describe your contribution to the project)
3-
4-
5-																                                     -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									                                   -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------
-	                            Functions Prototypes                                   -
-----------------------------------------------------------------------------*/
int quiz_1();
int quiz_2();
int quiz_3();
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/

// Compile with gcc midtermProject.c -o proj

/*----------------------------------------------------------------------------
-								Implementation								                               -
-----------------------------------------------------------------------------*/
int main()
{
    
	while(rand != 0){

    
    
    
        double total = 0;
        int rand;
        int quiz;
        int score1;
        int score2;
        int score3;
        double i = 0;
        double avg;
        int scr1;
        int scr2;
        int scr3;
        
        //avg = total / i;

        printf("Welcome,\nWe have 3 quizzes today!\nQuiz 1\nQuiz 2\nQuiz 3\n");
        //printf("Your average so far is %lf", avg);
        printf("\nPlease enter a number from 1 to 9  to choose your quiz.\n");
        scanf(" %d", &rand);



        if(rand == 0){
            break;
        }


        switch(rand){
            case 1:
            case 2:
            case 3:
                while(scr1 != 15){
                    scr1 = quiz_1();
                    total += scr1;
                    i += 1;
                    avg = total / i;
                    printf("\nYour average so far is %lf\n", avg);
                }
                break;
            case 4:
            case 5:
            case 6:
                while(scr2 != 15){
                    scr2 = quiz_2();
                    total += scr2;
                    i += 1;
                    avg = total / i;
                    printf("\nYour average so far is %lf\n", avg);

                }
                break;
            case 7:
            case 8:
            case 9:
                while(scr3 != 15){
                    scr3 = quiz_3();
                    total += scr3;
                    i += 1;
                    avg = total / i;
                    printf("\nYour average so far is %lf\n", avg);
                }
                break;

        
        }
       
    }








    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int quiz_1(){
    char one;
    int two;
    char three;
    int score1;
    score1 = 0;
    printf("\nFirst question, is the Eiffel Tower in France. Enter T for True or F for False.\n");
    scanf(" %c", &one);
    if(one == 'T'){
        score1 += 5;
        printf("\nCORRECT!");
    }
    else {
        printf("\nWRONG!");
    }

    printf("\nSecond Question, 3 to the power of 3 is ...\n 1) 9\n 2) 36\n 3) 27\n 4) 325");
    scanf(" %d", &two);
    if(two == 3){
        score1 += 5 ;
        printf("\nCORRET!");
    }
    else {
        printf("\nWRONG!");
    }


    printf("\nFINAL QUESTION, Type the single letter to complete the word.\n basket_all\n");
    scanf(" %c", &three);
    if(three == 'b'){
        score1 += 5 ;
        printf("\nCORRET!");
    }
    else {
        printf("\nWRONG!");
    }
    return score1;
}

int quiz_2(){
    char one = 'a';
    int two = 0;
    int three= 0;
    int score2;
    score2 = 0;
    printf("\nFirst question, Conversations Dining Hall in the best and most consistent on campus. Enter T for True or F for False.\n");
    scanf(" %c", &one);
    if(one == 'T'){
        score2 += 5;
        printf("\nCORRECT!");
    }
    else {
        printf("\nWRONG!");
    }

    printf("\nSecond Question, Kayne West's Best album is ...\n 1) Yeezus\n 2) The College Dropout\n 3) My Beautiful Dark Twisted Fantasy\n 4) Graduation\n");
    scanf(" %d", &two);
    if(two == 3){
        score2 += 5 ;
        printf("\nCORRET!");
    }
    else {
        printf("\nWRONG!");
    }


    printf("\nFINAL QUESTION, Complete the equation...\n The number of feet in a mile is\n");
    scanf(" %d", &three);
    if(three == 5280){
        score2 += 5 ;
        printf("\nCORRET!");
    }
    else {
        printf("\nWRONG!");
    }

    return score2;
}


int quiz_3(){
    char one = 'a';
    int two = 0;
    int three= 0;
    int score3;
    score3 = 0;
    printf("\nFirst question, Kobe Bryant and Shaq led the Lakers to win the 2002 NBA Championship. Enter T for True or F for False.\n");
    scanf(" %c", &one);
    if(one == 'T'){
        score3 += 5;
        printf("\nCORRECT!");
    }
    else {
        printf("\nWRONG!");
    }

    printf("\nSecond Question, Who led the NBA in three pointers made in 2016 ...\n 1) Stephen Curry\n 2) Kevin Durrant\n 3) Paul George \n 4) James Harden\n");
    scanf(" %d", &two);
    if(two == 1){
        score3 += 5 ;
        printf("\nCORRET!");
    }
    else {
        printf("\nWRONG!");
    }


    printf("\nFINAL QUESTION, Finish this mathmatical equation...\n 3 * __ = 36\n");
    scanf(" %d", &three);
    if(three == 12){
        score3 += 5 ;
        printf("\nCORRET!");
    }
    else {
        printf("\nWRONG!");
    }
    
    return score3;
}