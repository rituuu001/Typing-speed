#include "textloader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// fallbacks used when the file is missing or empty
const char *FALLBACK_SENTENCE =
    "the quick brown fox jumps over the lazy dog";
const char *FALLBACK_PARAGRAPH =
    "the quick brown fox jumps over the lazy dog and the cat sat "
    "on the mat while the dog ran across the field and jumped over "
    "the fence into the garden";
// File format (sentence.txt / paragraph.txt):
//   - One entry per line
//   - Lines longer than MAX_TEXT_LEN-1 chars are truncated

int loadRandomText(int mode, char *dest)
{
    const char *filepath = (mode == MODE_SENTENCE)
                           ? "assets/sentence.txt"
                           : "assets/paragraph.txt";
 
    const char *fallback  = (mode == MODE_SENTENCE)
                            ? FALLBACK_SENTENCE
                            : FALLBACK_PARAGRAPH;
 
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        strncpy(dest, fallback, MAX_TEXT_LEN - 1);
        dest[MAX_TEXT_LEN - 1] = '\0';
        return 0;
    }  
    char entries[MAX_ENTRIES][MAX_TEXT_LEN];
    int count = 0;
    char line[MAX_TEXT_LEN];
    //stores all the sentences and para into the array "entries"
     while (fgets(line, sizeof(line), fp) != NULL && count < MAX_ENTRIES) {
        strncpy(entries[count], line, MAX_TEXT_LEN - 1);
        entries[count][MAX_TEXT_LEN - 1] = '\0';
        count++;
    }
    fclose(fp);
    // pick a random entry 
    int index = rand() % count;
    strncpy(dest, entries[index], MAX_TEXT_LEN - 1);
    dest[MAX_TEXT_LEN - 1] = '\0';
    return 1;}
