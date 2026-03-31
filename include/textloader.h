#ifndef TEXTLOADER_H
#define TEXTLOADER_H
 
#include "common.h"
 
// max chars in a single sentence or paragraph
#define MAX_TEXT_LEN  512
// max number of entries loaded from a file
#define MAX_ENTRIES   200
 
// loads a random sentence from assets/sentences.txt
// loads a random paragraph from assets/paragraphs.txt
// writes into dest (must be at least MAX_TEXT_LEN bytes)
// returns 1 on success, 0 on failure (dest gets a fallback string)
int loadRandomText(int mode, char *dest);
 
#endif