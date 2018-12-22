/*
Gabriel Lee
0836295
CIS 2520
2018-09-23
Assignment 1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


double sqrtRec (long num, double acc, double fin);
double sqrtNon (long num, double acc, double fin2);

void newtonM (void) {

  double acc, fin, fin2 = 0;
  long num = 0;

  //Scanning in Values
  printf("Enter a number that will calculate the Square Root using Newtons Method: ");
  scanf ("%lu", &num);



  printf("Please Enter the Value for the Accuracy:  ");
  scanf("%lf", &acc);

  //Initial Approximation
  fin = num / 2;
  fin2 = num / 2;

  //Calling Recursion
  fin = sqrtRec(num, acc, fin);

  //Calling Non-Recursion
  fin2 = sqrtNon(num, acc, fin2);

  printf("\nWith the Non-Recursion Method Square Root of %lu with a accuracy of %e is: \n  %e \n", num, acc, fin2);

  printf("\nWith the Recursion Method the Square Root of %lu with a accuracy of %e is: \n  %e \n", num, acc, fin);



  printf("\n\n");
}


//Recursion Function
double sqrtRec (long num, double acc, double fin) {

  //Final Conclucsion on the Recurssion
  if (abs(fin * fin - num) <= acc) return fin;

  //The repeat of the function until a final condition is met.
  else {
    fin = (fin + (num/fin)) / 2;
    return sqrtRec(num, acc, fin);

  }

}


//Non-Recurssion
double sqrtNon (long num, double acc, double fin2) {

  //While loop to implement the newton method inregards to Square Root.
  while(abs(fin2 * fin2 - num) > acc)
  {
        fin2 = ( fin2 + (num/fin2)) / 2;
  }

  return fin2;
}
