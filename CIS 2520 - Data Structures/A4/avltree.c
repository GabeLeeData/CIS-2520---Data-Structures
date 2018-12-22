//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 4

#include "treeN.h"


int main(int argc, char**argv) {

  //Initialization of vars.
  int opt =0;
  char fileN[30];
  char key[30];
  int size = 0;
  int fin = 0;
  int count = 0;
  avl *temp = malloc(sizeof(struct avl));
  avl *index = malloc(sizeof(struct avl));
  avl *search = malloc (sizeof(struct avl));


  do {

    printf("\n");
    printf("\n");
    //Choosing which option
    printf("Please Select a option\n");
    printf("1. Initialization. \n");
    printf("2. Find. \n");
    printf("3. Insert. \n");
    printf("4. Remove. \n");
    printf("5. Check Height, Size and Total Count. \n");
    printf("6. Find All (Above a given Frequency). \n");
    printf("7. Exit. \n");
    printf("Enter a code (1-7) and hit Return \n");
    printf("avl/> ");

    scanf("%d", &opt);
    printf("\n");

    //Initialization
    if (opt == 1){
      printf("\n");
      printf("Please Enter the Name of the File: ");
      scanf("%s", fileN);
      index = fileRd(fileN, index);
    }

    //Finding Key.
    else if (opt ==2){
      printf("\n");
      printf("Find Key: ");
      scanf("%s", key);
      //Finding Key.
      search = keyF(key, index);

      //Error checking
      if (search != NULL) {
        printf("\n| Key: %s | Frequency: %d | \n", search->key, search->freq);
      }

      else printf("no_such_key");

    }

    //Inserting Node.
    else if (opt ==3){

      printf("\n");
      printf("Insert Key: ");
      scanf("%s", key);
      //Searching for Key
      search = keyF(key, index);

      //If Key is found add to frequency of exisiting Node
      if (search != NULL) search->freq++;

      //Insert New Node if nothing found.
      else index = ins(1,key,index);

      //Updated Info
      search = keyF(key,index);
      printf("\n***UPDATED***\n");
      printf("\n| Key: %s | Frequency: %d | \n", search->key, search->freq);

    }

    //Removing Node.
    else if (opt ==4) {

      printf("\n");
      printf("Remove Key: ");
      scanf("%s", key);

      //Finding Key
      search = keyF(key,index);

      if (search != NULL){

        if (search->freq == 1){
          printf("Key: %s Has Been Deleted\n", key);
          //Deleting Node if it has a count of 1
          index = del(index, key);

        }

        else {
          search->freq--;
          printf("\n***UPDATED***\n");
          printf("\n| Key: %s | Frequency: %d | \n", search->key, search->freq);
        }
      }

      else printf("\n no_such_key \n");

    }

    //Check height, Size and Total Count
    else if (opt ==5){
      size = 0;
      temp = index;
      //Getting the Size.
      while (temp != NULL){
        size++;
        temp = temp->left;
      }
      fin = pow(2,size);
      printf("\n | Height: %d | Size: %d | Count: %d |", checkH(index),fin, totalC(index));

    }

    //Find all - Frequencies
    else if (opt ==6){

      printf("\n Frequency: ");
      scanf("%d", &count);

      freqCount (count, index);

    }

    //Quit.
    else if (opt ==7){
      printf("Exiting Program");
      break;
    }

  } while (opt !=7);

}
