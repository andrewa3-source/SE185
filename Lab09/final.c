#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#define WORDLENGTH 11
#define MAXWORDS 1100
#define DEBUGM 0
#include <time.h>

int read_words(char* WL[MAXWORDS], char* file_name);
void trimws(char* str);
void draw_character(int x, int y, char use);
void generate_display(char input[WORDLENGTH]);

typedef struct wordPositions{
    char* word[WORDLENGTH];
    int xpos;
    int ypos;
}wordPositions;

int main(int argc, char* argv[]){
    char* wordlist[MAXWORDS];
	int wordcount;
	int i;
	wordcount = read_words(wordlist, argv[1]);
    int p = 0;
    int w = 0;
    int gameoption;
    int minWordLen;
    char addWord[30];
    FILE* inFile = NULL;
    char* file_name = argv[1];
    char input[WORDLENGTH];
    time_t seconds;
    wordPositions words[20];


    if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
			printf("%s,", wordlist[i]);

		}
		printf("\n");
	}
    while(p != 1 && w != 1){
        printf("Hello, this is a typing game. You will need to type the words as they appear\nWould you like to play or add a word");
        printf("\nYou currently have %d words that can be used. (play = 1 / word = 2)\n", wordcount);
        scanf("%d", &gameoption);
        if(gameoption == 1){
            srand(time(NULL));
            words->word[0] = wordlist[rand() % wordcount];
            printf("%s", words->word[0]);
            printf("What would you like your minimum word length to be?\n");
            scanf("%d", &minWordLen);
            p = 1;
        }
        else if(gameoption == 2){
            printf("Whats the word you would like to add?\n");
            scanf("%s", addWord);
            inFile = fopen("wordList.txt", "a");
            fprintf(inFile, "\n%s", addWord);
            fclose(inFile);
        }
    }



    //main game
    initscr();

    while(1){
        srand(time(NULL));
        words->word[0] = wordlist[rand() % wordcount];
        mvprintw(0, 20, "%s", words->word[0]);




        time(&seconds);
        generate_display(input);
        scanf("%s", input);
        

       
    }


    endwin();
    
	
	
}
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
void draw_character(int x, int y, char use){
    mvaddch(y,x,use);
    refresh();
}

void generate_display(char input[WORDLENGTH]){
    int i;
    int j;

    mvprintw(19, 0, "%s", "Type here:  ");
    mvprintw(19, 11, "%s", "                                                          ");
    mvprintw(19, 11, "%s", input);
    for(i = 0; i < 25; ++i){
        for(j = 0; j < 50; ++j){
            if (i == 0){
                draw_character(j, i, '_');
            }
            if (i > 0 && i <= 15 && (j == 0 || j == 49)){
                draw_character(j, i, '|');
            }
            if (i > 15 && i < 18){
                draw_character(j, i, '_');
            }
        }
    }
    refresh();
}