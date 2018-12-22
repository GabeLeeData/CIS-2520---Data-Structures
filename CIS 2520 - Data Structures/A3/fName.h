//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 3 - a)

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void calculate (char* exps);
void preorder (char* exps);
void inorder (char* exps);
void postorder (char* exps);
void pushOp (char element);
void pushOp2 (char element);
void enqueue(char element);
void pushN (float element);
void enqueue2(char element);
char dequeue();
char dequeue2();
char popO();
char popO2();
bool isEmpty();
bool isFull();
bool isEmpty2();
bool isFull2();
float popN();
