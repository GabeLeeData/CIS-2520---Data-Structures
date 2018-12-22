//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 2 - b)

#include "infoStack.h"

int main(int argc, char const *argv[]){
  int check2 = 0;
  int check = 0;
  char buffer[50];
  double temp = 0;
  double calc1 = 0;
  double calc2 = 0;
  double final = 0;

  //Initailizaing Struct and Creating Stack.
  infoL stackL;
  stackL.start = 0;

  //Error Check
  if ((argc > 3) || (argc < 2)) {

    printf("Please Enter the correct format\n");
    return -1;
  }

  //Coppying Input to buffer and initializing Start of stack
  strcpy(buffer,argv[1]);


  //Looping through input.
  for (int x = 0; x < (int)strlen(buffer); x++){

    //Sending Values to Stack
    if (isdigit(buffer[x])) {
      check++;
      temp = (double)buffer[x]-'0';
      push(&stackL, temp);

      //If there are 3 subsequent numbers , End Program.
      if (check > 2) {
        check2 = 1;
        break;
      }
    }

    //Operator Calculations.
    else{

      //Reset Counter
      check = 0;
      calc2 = pop(&stackL);
      calc1 = pop(&stackL);

      //Calculating Equation based on Operators.
      if (buffer[x] == '+'){

        final = calc1 + calc2;
        push(&stackL, final);

      }

      else if (buffer[x] == '*'){

        final = calc1 * calc2;
        push(&stackL, final);

      }

      else if (buffer[x] == '-'){

        final = calc1 - calc2;
        push(&stackL, final);

      }

      else if (buffer[x] == '/'){

        final = calc1 / calc2;
        push(&stackL, final);

      }

      else {
        check2 = 1;
        printf("\nPlease Enter Appropriate Operator or Number \n");
        break;
      }

    }
  }

  //Grabing Final Value from Stack.
  final = finalC(&stackL);
  if (check2 == 0) {
    printf(" Answer is : %0.2lf\n", final);
    printf("***Exiting Program***\n");
  }

  else printf("***Exiting Program***\n");


  return 0;
}
