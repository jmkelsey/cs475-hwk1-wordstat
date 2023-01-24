/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[])
{
	// declare and initialize the histogram
	int histogram[ALPHABET_SIZE];
	for (int i = 0; i < 26; i++)
	{
		histogram[i] = 0;
	}

	// TODO: start by getting strings from users until # is input
	char strings[128][MAX_INPUT_LEN];
	char input[MAX_INPUT_LEN] = "";
	int i = 0;
	int totalchars = 0;

	// ask for input
	printf("Enter strings (# to stop): \n");

	// now we read until # comes up

	while (i < 128)
	{
		fgets(input, MAX_INPUT_LEN, stdin);
		if (!strcmp(input, "#\n"))
		{
			break;
		}

		strcpy(strings[i], input);
		input[strcspn(input, "\n")] = 0;
		// add all letters to histogram from input string
		for (int j = 0; j < MAX_INPUT_LEN && input[j] != '\0'; j++)
		{
			if ((int)input[j] >= 65 && (int)input[j] <= 90)
			{
				histogram[(int)input[j] - 65] = histogram[(int)input[j] - 65] + 1;
				totalchars++;
			}
			else if ((int)input[j] >= 97 && (int)input[j] <= 122)
			{
				histogram[(int)input[j] - 97] = histogram[(int)input[j] - 97] + 1;
				totalchars++;
			}
		}
		i++;
	}

	// TODO: after # is input, print menu options

	int choice = 5;

	while (choice != 4)
	{
		choice = getMenuOption();
		if (choice == 1)
		{
			int vowels = histogram[0] + histogram[4] + histogram[8] + histogram[14] + histogram[20];
			int consonants = totalchars - vowels;
			printf("Vowels = %d (%f%%), Consonants = %d (%f%%), Total = %d\n\n", vowels, (float)vowels / totalchars * 100, consonants, (float)consonants / totalchars * 100, totalchars);
		}
		else if (choice == 2)
		{
			printHisto(histogram);
		}
		else if (choice == 3)
		{
			// input more strings
			int i = 0;
			char input[MAX_INPUT_LEN] = "";
			while (i < 128)
			{
				fgets(input, MAX_INPUT_LEN, stdin);
				if (!strcmp(input, "#\n"))
				{
					break;
				}
				strcpy(strings[i], input);
				input[strcspn(input, "\n")] = 0;
				// add all letters to histogram from input string
				for (int j = 0; j < MAX_INPUT_LEN && input[j] != '\0'; j++)
				{
					if ((int)input[j] >= 65 && (int)input[j] <= 90)
					{
						histogram[(int)input[j] - 65] = histogram[(int)input[j] - 65] + 1;
						totalchars++;
					}
					else if ((int)input[j] >= 97 && (int)input[j] <= 122)
					{
						histogram[(int)input[j] - 97] = histogram[(int)input[j] - 97] + 1;
						totalchars++;
					}
				}
				i++;
			}
		}
	}

	printf("Exiting...\n");
	return 0;
}
