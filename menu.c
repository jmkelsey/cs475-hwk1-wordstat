/*
 * menu.c
 *
 *  Created on: Jun 16, 2015
 *      Author: dchiu
 */

#include <stdio.h>
#include "menu.h"
#define MENU_STATS 1
#define MENU_HISTO 2
#define MENU_INPUT 3
#define MENU_EXIT 4

int getMenuOption() {
	int opt;
	printf("*** WORD STATS MENU ***\n");
	//printf("Enter %d to print vowel and consonant frequency.\n", MENU_STATS);
	//printf("Enter %d to print histogram.\n", MENU_HISTO);
	//printf("Enter %d to return to inputting more strings.\n", MENU_INPUT);
	//printf("Enter %d to quit.\n", MENU_EXIT);

	printf("Enter 1 to print vowel and consonant frequency.\n");
	printf("Enter 2 to print histogram.\n");
	printf("Enter 3 to return to inputting more strings.\n");
	printf("Enter 4 to quit.\n");
	scanf("%d", &opt);
	return opt;
}
