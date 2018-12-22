/*
Gabriel Lee
0836295
Assignment 3 - b)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void print (int info[20][12]);
void heapConst (int info[20][12]);
void swap (int info_1[12], int info_2[12]);

//Swapping elements within a array.
void swap (int info_1[12], int info_2[12]){

  int tempO = 0;
  for (int x = 0; x < 12; x++){
    //Swapping
    tempO = info_1[x];
    info_1[x] = info_2[x];
    info_2[x] = tempO;

  }

}

//Heap Construct / Sort
void heapConst (int info[20][12]){

  int c;
  int res;
  int test;

  for (int p = 0; p < 20; p++){

      c = (p*2) + 1;
      test = c+1;
      res = 0;

      //Index is finished Sorting. Break.
      if (c >= 20) break;

      //Swap - Left is Greater
      if (info[p][1] > info[c][1]){
        res = 1;
        swap(info[p], info[c]);
      }

      //Swap - Right is Greater.
      if (info[p][1] > info[c+1][1]){
        res = 1;
        swap(info[p], info[c+1]);

      }

      //Index becomes bigger then array, Break.
      if (test >= 20) break;

      //Recursive call, Restart loop if swap was made.
      if (res==1) heapConst(info);

  }

}

//Printing Array.
void print (int info[20][12]){

  for (int x = 0; x < 20; x++){
    printf("KEY: ");
    for (int l = 1; l<12; l++){
      if (l == 1) printf("%d | ", info[x][l]);
      else printf("%d ", info[x][l]);
    }
    printf("\n");
  }
}



int main(int argc, char const *argv[]){
  //Initializing.
  FILE *data;
  data = fopen("f.dat", "r");
  int i = 0;
  int j = 2;
  char buff[1000];
  char *tok;
  int info[20][12];


  //Reading in data file
  while (fgets(buff, 1000, data) != NULL){
    j = 2;
    tok = strtok(buff, " ");

    while (tok != NULL){
      if (strlen(tok) > 1) info[i][j]= atoi(tok);
      j++;
      tok = strtok(NULL, " ");
    }
    i++;
  }


  printf("Displaying Non Sorted Array\n\n");

  //Creating keys from first 3 values
  for (int k = 0; k < 20; k++){
    info[k][0] = k;
    info[k][1] = info[k][2] + info[k][3] + info[k][4];

  }
  //Printing Array before heapsort
  print(info);

  //Constructing heap and sorting
  heapConst(info);

  //print final.
  printf("\nDisplaying New Sorted Array\n\n");
  print(info);

}
