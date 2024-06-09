/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Andrew Ahrenkiel
- Section: 1 
-	NetID: Andrewa3
-	Date: 04 - 
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80

/* 	Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 10


/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{


  if (argc != 2 )
  {
      printf("You must enter the difficulty level on the command line.");
      refresh();
      return;
  }
  else
  {
    int difficulty = 0;
    sscanf(argv[1], "%d", &difficulty );

    /* 	Setup screen for Ncurses
        The initscr functionis used to setup the Ncurses environment
        The refreash function needs to be called to refresh the outputs
        to the screen */
    initscr();
    refresh();

    /* WEEK 2 Generate the Maze */
    /* Read gyroscope data and fill the buffer before continuing */
    int t;
    double new_x;
    double new_y;
    double new_z;
    int i;
    int j;
    int xpos = 60;
    int ypos = 0;
    int xxx;
    int lose = 0;
    double buffer[5];
    generate_maze(difficulty);
    scanf("%d, %lf, %lf, %lf", &t, &new_x, &new_y, &new_z);
    
    
    /* Event loop */
       
        while(ypos <=80){
            
            scanf("%d, %lf, %lf, %lf", &t, &new_x, &new_y, &new_z);
            xxx = m_avg(buffer, 5, new_x);
            //using the moving average value instead of the raw value absolutley destroys the movement of the Avatar, it is much better this way.
            if (new_x > .2 && t % 100 <= 20){
                if (MAZE[xpos-1][ypos] == EMPTY_SPACE){
                    xpos -= 1;
                    draw_character(xpos+1, ypos, EMPTY_SPACE);
                }
                if (MAZE[xpos][ypos+1] == EMPTY_SPACE){
                    ypos += 1;
                    draw_character(xpos, ypos-1, EMPTY_SPACE);
                }
                
                draw_character(xpos, ypos, AVATAR);
                //draw_character(xpos+1, ypos-1, EMPTY_SPACE);
            }
            else if(new_x < -.2 && t % 100 <= 20){
                if (MAZE[xpos+1][ypos] == EMPTY_SPACE){
                    xpos += 1;
                    draw_character(xpos-1, ypos, EMPTY_SPACE);
                }
                if (MAZE[xpos][ypos+1] == EMPTY_SPACE){
                    ypos += 1;
                    draw_character(xpos, ypos-1, EMPTY_SPACE);
                }
                
                draw_character(xpos, ypos, AVATAR);
                //draw_character(xpos-1, ypos-1, EMPTY_SPACE);
            }
            else if(t % 100 <= 20){
                if (MAZE[xpos][ypos+1] == EMPTY_SPACE){
                    ypos += 1;
                }
                draw_character(xpos, ypos, AVATAR);
                draw_character(xpos, ypos-1, EMPTY_SPACE);
            }
            else if(MAZE[xpos-1][ypos] == WALL && MAZE[xpos+1][ypos] == WALL && MAZE[xpos][ypos+1] == WALL){
                lose = 1;
                break;
            }
            else if(t > 60000){
                lose = 2;
                break;
            }

        }
        /* Read data, update average */
        if(lose == 0){
            endwin();
            printf("YOU WIN!\n");
        }
        else if(lose == 1){
            endwin();
            printf("YOU LOSE OMEGALOL YOU GOT STUCK!\n");
        }
        else{
            endwin();
            printf("YOU RAN OUT OF TIME 4WEIRD");
        }
        /* Is it time to move?  if so, then move avatar */

      // Change this to end game at right time

    /* Print the win message */


    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */
    

  }

    
}

double m_avg(double buffer[], int avg_size, double new_item)
{

    int i;
    double avg = 0;
    for(i = avg_size - 1; i > 0; --i){
        buffer[i] = buffer[i-1];
        avg += buffer[i];
    }
    buffer[0] = new_item;
    avg += new_item;


    return avg / avg_size;
}




/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}

void generate_maze(int difficulty){
    int mega;
    int i;
    int j;

    srand(time(NULL));
    for(i = 0; i < 80; ++i){
        for(j = 0; j < 100; ++j){
            mega = rand() % 100;
            if(mega > 0 && mega < difficulty){
                draw_character(j, i, WALL);
                MAZE[j][i] = WALL;
                mega = 0;
            }
            else{
                MAZE[j][i] = EMPTY_SPACE;
            }
        }
    }
}

