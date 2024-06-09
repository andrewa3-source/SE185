// Lab 09 DS4Talker Skeleton Code       

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 1   // Set this to 0 to disable debug output

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);

// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);

void draw_character(int x, int y, char use);



int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordcount;
	int i;
	int percol = 15;
	wordcount = read_words(wordlist, argv[1]);
	int wordtoprint = 0;
	char* NEWORDARRAY[5][15];

	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
			printf("%s,", wordlist[i]);

		}
		printf("\n");
	}

	// most of your code goes here. Do not forget to include the ncurses library

	initscr();
	for(i = 0; i < 5; i++){
		for(int j = 0; j < percol; ++j){
			if(wordtoprint > wordcount - 1){
				break;
			}
			NEWORDARRAY[i][j] = wordlist[wordtoprint];
			mvprintw(j,i * 15, "%15s", wordlist[wordtoprint]);
			wordtoprint += 1;
			refresh();

		}
	}

	int t, tri, cir, x, squ = 0;
	int prjoy, pljoy, options, share;
	int righttrig, lefttrig, rightbump, leftbump;
	int ljoyx, ljoyy, rjoyx, rjoyy;
	int xpos = 15;
	int ypos = 0;
	int wasright, wasleft, wasup, wasdown = 0;
	int printposx = 0;
	char lastword;
	char totalchars;

	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &tri, &cir, &x, &squ, &prjoy, &pljoy,
		&options, &share, &righttrig, &lefttrig, &rightbump, &leftbump, &ljoyx, &ljoyy, &rjoyx, &rjoyy);
	while(righttrig != 1){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &tri, &cir, &x, &squ, &prjoy, &pljoy,
			&options, &share, &righttrig, &lefttrig, &rightbump, &leftbump, &ljoyx, &ljoyy, &rjoyx, &rjoyy);
		//draw_character(xpos, ypos, '<');
		if(ljoyx > 100 && wasright == 0 ){
			draw_character(xpos, ypos, ' ');
			xpos += 15;
			draw_character(xpos, ypos, '<');
			wasright = 1;
		}
		else if(ljoyx < -100 && wasleft == 0){
			draw_character(xpos, ypos, ' ');
			xpos -= 15;
			draw_character(xpos, ypos, '<');
			wasleft = 1;
		}
		else if(ljoyy < -100 && wasup == 0){
			draw_character(xpos, ypos, ' ');
			ypos -= 1;
			draw_character(xpos, ypos, '<');
			wasup = 1;
		}
		else if(ljoyy > 100 && wasdown == 0){
			draw_character(xpos, ypos, ' ');
			ypos += 1;
			draw_character(xpos, ypos, '<');
			wasdown = 1;
		}
		else if(ljoyx < 10 && ljoyx > -10 && ljoyy < 10 && ljoyy > -10){
			wasleft = 0;
			wasright = 0;
			wasup = 0;
			wasdown = 0;
		}
		else if(tri == 1){
			//print selected word with a space
			mvprintw(printposx + strlen(lastword), 15, "%s ", NEWORDARRAY[(xpos /15) - 1][ypos]);
			lastword == NEWORDARRAY[(xpos /15) - 1][ypos])
			strcat(totalchars, NEWORDARRAY[(xpos /15) - 1][ypos]));
		}
		else if(x == 1){
			//clear the print line
			mvprintw(printposx, 15, "                                                                                                  ");
		}
		else if(x == 1){
			//maybe make the print out an array and be able to print from the array, this would make it easy to delete words
			mvprintw(printposx, 15, "%s",  )
		}
	}
	endwin();
	return 0;
}

// DO NOT MODIFY THIS FUNCTION!
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}


// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}

void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}
