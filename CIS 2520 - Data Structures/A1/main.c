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


void carbonM(void);
void ackermannM(void);
void newtonM(void);

int main(void)
{


  int option = 0;

  while (option != 4)
  {

    //Simple menu, scans in the the choice.
    printf("Choose One of the Following Options with a Number \n");
    printf("1. Carbon Program \n");
    printf("2. Ackermann Program \n");
    printf("3. Newton Program \n");
    printf("4. Exit \n");

    scanf("%d", &option);

    //Different options to call the programs
    if (option == 1) carbonM();
    else if (option ==2)  ackermannM();
    else if (option ==3)  newtonM();
    else if (option ==4)
    {
      printf("Exiting Program...");
      break;
    }

    else
    {
      printf("Please Enter one of the following options \n");
    }

  }

  return 0;

}
