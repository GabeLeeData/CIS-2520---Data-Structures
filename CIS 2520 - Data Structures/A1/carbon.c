/*
Gabriel Lee
0836295
CIS 2520
2018-09-23
Assignment 1
*/


#include <stdio.h>
#include <string.h>

void carbonM(void)
{
  //Initializing Word
  int count = 0;
  char Word[5];
  Word[0] = 'c';
  Word[1] = 'a';
  Word[2] = 'r';
  Word[3] = 'b';
  Word[4] = 'o';
  Word[5] = 'n';
  int lenWord = strlen(Word);

  //Loop to go through each Character
  for(int t = 0; t < lenWord; t++){
    for (int a = 0; a < lenWord; a++) {
      for (int r = 0; r < lenWord; r++) {
        for (int i = 0; i < lenWord; i++) {
          for (int o = 0; o < lenWord; o++) {
            for (int n = 0; n < lenWord; n++){
              //Swapping around each character and re arranging.
              if (t!=a &&t!=r &&t!=i &&t!=o &&t!=n && a != r && a != i && a != o && a != n
                  && r != i && r != o && r != n && i != o && i != n && o != n){
                    //printing the combination
                    count++;
                    printf("%c%c%c%c%c%c \n", Word[t], Word[a], Word[r], Word[i], Word[o], Word[n]);

                  }

            }
          }
        }
      }
    }
  }

printf("There are %d possible combinations for the word carbon \n\n", count);


}
