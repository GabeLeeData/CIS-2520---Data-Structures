/*
Gabriel Lee
0836295
CIS 2520
2018-09-23
Assignment 1
*/

#include <stdio.h>

int ack (int x, int y);

void ackermannM (void) {

  int first, second;
  int final;

  //Getting inputs
  printf("First Number of Ackerman Function: ");
  scanf("%d", &first);

  printf("Second Number of Ackerman Function: ");
  scanf("%d", &second);


  //loop to call the ackerman function
  for (int x = 0; x <= first; x++) {

    for (int y = 0; y < second - x; y++){
      //Calling the recursive function
      final = ack(x,y);

      printf("A(%d, %d) = %d\n", x, y, final);

    }
  }

  printf("\n");
}


//Recurssion function
int ack (int x, int y) {
  //Conditions for the recursion.
  if (x == 0) return y+1;
  else if (y == 0) return ack(x-1, 1);
  else return ack(x-1, ack(x,y-1));

}
