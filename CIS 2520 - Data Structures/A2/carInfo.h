//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 2 - a)

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//Creating Structure for Car
typedef struct nodeCar
{
  int mile;
  int date;
  char* liPlate;
  struct nodeCar *next;

} nodeCar;


void daSort(nodeCar *temp, nodeCar *start, int final);
void miSort(nodeCar *temp, nodeCar *start, int final);
void sort(nodeCar *list, int type);
void print(nodeCar *list, int type);
void delNode (nodeCar *list, char* liPlate);
void writeF(nodeCar *ava, nodeCar* repair, nodeCar* rent);
void swap (nodeCar *start, nodeCar *prev);
nodeCar* createNode (int mile, char* liPlate, int date);
nodeCar* listNode (nodeCar *list, nodeCar *future);
nodeCar* readA (nodeCar *list);
nodeCar* readRen (nodeCar *list);
nodeCar* readRep (nodeCar *list);
int dupL(nodeCar *list, char* liPlate);
int searcher (nodeCar *list, char* liPlate);
int calc (int newmile);
