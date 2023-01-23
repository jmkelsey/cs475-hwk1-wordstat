/*
 * histo.c
 */

#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"

// TODO: function definitions for dealing with histogram below
void printHisto(int histogram[]) {
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    int height = 0;

    // find the highest frequency in the histogram
    for (int i = 0; i < 26; i++) {
        if (histogram[i] > height) {
            height = histogram[i];
        }
    }

    // print the histogram
    for (int i = height; i > 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (histogram[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // print the alphabet and the frequencies
    for (int i = 0; i < 26; i++) {
        printf("%c ", alphabet[i]);
    }
    printf("\n");

    for (int i = 0; i < 26; i++) {
        printf("%d ", histogram[i]);
    }
    printf("\n\n");
}
