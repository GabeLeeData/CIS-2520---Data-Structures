//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 2 - b)

#include "infoStack.h"

//Obtaining the final value
double finalC(infoL *stackL){

  return stackL->list[stackL->start];

}

//Adding the value towards the stack.
void push(infoL *stackL, double value){
  int adder;
  adder = stackL->start + 1;

  if (stackL->start <= 19) {
    stackL->start = adder;
    stackL->list[adder] = value;
  }

  else printf("Full Stack");
}


//Removing Value from the Stack and Sent to be calculated.
double pop(infoL *stackL){
  int sub;
  double value =0;

  if (stackL->start > 0) {

    value = (double)stackL->list[stackL->start];
    sub = stackL->start - 1;
    stackL->start = sub;
    return value;
  }
  else {
    printf("\nEmpty Stack- Please Enter Correct Format (2 Numbers Subsequently)");
    return 0;

  }
}
