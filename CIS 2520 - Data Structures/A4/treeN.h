//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct avl
{
  struct avl* left;
  struct avl* right;
	char key[30];
	int freq, height;

} avl;


avl* balance(avl* index);
avl* min(avl* index);
avl* del2(avl* index);
avl* keyF (char* tok, avl *newIndex);
avl* lSingle(avl* newIndex);
avl* rSingle(avl* newIndex);
avl* lDouble(avl* newIndex);
avl* rDouble(avl* newIndex);
avl* ins(int freq,char* tok, avl* newIndex);
avl* fileRd (char *fname, avl* index);
avl* del(avl* index, char* key);
avl* freqCount (int count, avl* index);
int totalC (avl* index);
int bigN(int nodeL, int nodeR);
int checkH(avl* newIndex);
