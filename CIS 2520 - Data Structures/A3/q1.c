//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 3 - a)

#include "fName.h"


int main(int argc, char**argv) {

  //Initialization.
  int opt =0;
  char exps[100];
  int length2;
  char single2, tempo;
  char var[2];
  char newV[3];
  int start = 0;
  int check = 0;

  //Error check argv[1];
  if ((argc < 2) || (argc > 3)) {
    printf("Please Enter Correct Format");
    exit(0);
  }
  //Moving expression into buffer;
  strcpy(exps, argv[1]);

  do {
    printf("The Expression:\n ");
    length2 = strlen(exps);
    for (int i = 0; i < length2; i++){
      single2 = exps[i];
      printf("%c", single2);
    }


    printf("\n");
    printf("\n");
    //Choosing which option
    printf("Please Select a option\n");
    printf("1. Display. \n");
    printf("2. Preorder. \n");
    printf("3. Inorder. \n");
    printf("4. Postorder. \n");
    printf("5. Update. \n");
    printf("6. Calculate. \n");
    printf("7. Exit. \n");
    scanf("%d", &opt);
    printf("\n");



    //Display
    if (opt == 1){
      printf("Displaying");
      inorder(exps);
      printf("\n");

    }

    //Preorder.
    else if (opt ==2){

      printf("Preorder\n");
      preorder(exps);
      printf("\n");

    }

    //Inorder
    else if (opt ==3){
      printf("Inorder \n");
      inorder(exps);
      printf("\n");
    }

    //Postorder
    else if (opt ==4) {
      printf("Postorder \n");
      postorder(exps);
      printf("\n");
    }

    //Update
    else if (opt ==5){
      printf("Updating \n");
      check = 0;
      start = 0;
      length2 = strlen(exps);

      printf("Please Enter Variable Name\n");
      scanf("%s", var);
      printf("Please Enter New Value of Variable\n");
      scanf("%s", newV);

      //error checking.
      if (strlen(newV) > 4 || strlen(newV) < 0) printf("Please Enter 3 digit Value");

      else {
        //Looking to see if variable exists.
        for (int x = 0; x < length2; x++){
          single2 = exps[x];
          //Looking to see if a variable is found.
          if (single2 == 'x' && exps[x+1] == var[1]) check = 1;
        }


        if (check == 1){
          //Build Queue to store all values
          for (int t = 0; t < length2; t++){
            single2 = exps[t];

            if (single2 == 'x' && exps[t+1] == var[1]) {

            //If found skip over and throw new value into queue
            t = t+1;
            enqueue2(newV[0]);
            enqueue2(newV[1]);
            enqueue2(newV[2]);
            enqueue2(newV[3]);
            }

            //Throwing rest of expression into queue.
            else enqueue2(single2);

          }
          //Overwriting values of old array
          while (!isEmpty2()) {
            tempo = dequeue2();
            exps[start] = tempo;
            start++;
          }
        }

        //If Variable not found.
        else {
          printf("Incorrect Variable Name");
        }
      }

      printf("\n");
    }


    //Calculate
    else if (opt ==6){
      printf("Calculate\n");
      calculate(exps);
      printf("\n");

    }

    //Quit.
    else if (opt ==7){
      printf("Exiting Program");
      break;
    }

  } while (opt !=7);

}
