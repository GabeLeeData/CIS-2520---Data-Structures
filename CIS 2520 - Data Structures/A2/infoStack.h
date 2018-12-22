//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 2 - b)

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct infoL{
  int start;
  double list[20];
}infoL;

double finalC (infoL *stackL);
void push(infoL *stackL, double value);
double pop(infoL *stackL);
