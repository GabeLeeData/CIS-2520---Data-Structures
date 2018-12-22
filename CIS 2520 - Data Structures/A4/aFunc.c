//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 4


#include "treeN.h"


//Total Count of tree.
int totalC (avl* index){

    int total = 1;
    if (index != NULL) {

      //Counting through nodes.
      total += totalC(index->left);
      total += totalC(index->right);
      return total;

    }

    else return 0;
}



//Finding Frequency Count
avl* freqCount (int count, avl* index){

    if (index != NULL){

      //If over the count print.
      if (index->freq > count) printf("| KEY: %s | Frequency: %d\n", index->key, index->freq);

      freqCount(count, index->left);
      freqCount(count, index->right);

      return index;

    }

    else return NULL;
}

//finding Minimum
avl* min(avl* index){

  if (index->left == NULL) return index;
  else if (index == NULL) return index;
  else return min(index->left);

}


//Deleting Node - 2
avl* del2(avl* index){

  //Deletion Process.
  if ((index->left != NULL) || (index->right != NULL)){
    avl *newIndex = min(index->right);
    strcpy(newIndex->key, index->key);
    index->right = del(index->right, newIndex->key);

  }

  else {

    avl *newIndex = index->left ? index->left : index->right;
    if (newIndex != NULL) *index = *newIndex;
    else {
      newIndex = index;
      index = NULL;
    }
  }

  return index;
}



//Balancing
avl* balance(avl* index){
  int temp = 0;

  temp = bigN(checkH(index->left), checkH(index->right));
  index->height = temp + 1;


  return index;
}


//Deleting Node.
avl* del(avl* index, char* key){

    int check = 0;
    check = strcmp(index->key, key);

    if (check > 0) index->right = del(index->right,key);

    else if (check < 0) index->left = del(index->left,key);

    else index = del2(index);

    if (index == NULL) return index;

    //Balancing
    index = balance(index);

    return index;

}

//Double Rotation - Left
avl* lDouble(avl* newIndex){
    newIndex->left = rSingle(newIndex->left);

    return lSingle(newIndex);
}

//Double Rotation - Right
avl* rDouble(avl* newIndex){
    newIndex->right = lSingle(newIndex->right);

    return rSingle(newIndex);
}


//Left Rotation
avl* lSingle(avl* newIndex){

    avl* tNode = NULL;
    int temp1, temp2;

    tNode = newIndex->left;
    newIndex->left = tNode->right;
    tNode->right = newIndex;

    temp1 = bigN(checkH(newIndex->left),checkH(newIndex->right));
    newIndex->height = temp1+1;

    temp2 = bigN(checkH(tNode->left),newIndex->height);
    tNode->height = temp2+1;

    return tNode;
}


//Right Rotation
avl* rSingle(avl* newIndex){

    avl* tNode = NULL;
    int temp1, temp2;

    tNode = newIndex->right;
    newIndex->right = tNode->left;
    tNode->left = newIndex;

    temp1 = bigN(checkH(newIndex->left), checkH(newIndex->right));
    newIndex->height = temp1+1;

    temp2 = bigN(checkH(tNode->right),newIndex->height);
    tNode->height = temp2+1;

    return tNode;
}

//Reading in File
avl* fileRd (char *fname, avl* index){


  avl* check;
	avl* newIndex = NULL;
	char listW[280];
	char* tok;

  FILE* text;
  text = fopen(fname, "r");

  if (text != NULL) {

    //Going through text file
    while(fgets(listW,280,text) != NULL) {

      tok = strtok(listW, " ");

      while(tok != NULL) {
        //Removing New line
        if (tok[strlen(tok)-1] == '\n') tok[strlen(tok)-1] = '\0';

        check = keyF(tok, newIndex);
        //If Key is found, add to Frequency
        if (check != NULL) check->freq++;
        //New Node.
        else newIndex = ins(1,tok,newIndex);

        tok = strtok(NULL, "\n ");
      }
    }
    fclose(text);
    return newIndex;
  }

  else {
    //Error Checking
    printf("Please Enter Appropriate Name of File. ");
    return NULL;
  }


}

//Inserting
avl* ins(int freq ,char* tok, avl* newIndex){

    int check = 0;
    int temp1 = 0;

    //Creation of New Node.
    if( newIndex == NULL )
    {
        newIndex = (avl*)malloc(sizeof(avl));
        newIndex->left = NULL;
        newIndex->right = NULL;
        newIndex->height = 0;
        newIndex->freq = freq;
        strcpy(newIndex->key,tok);
    }

    check = strcmp(newIndex->key,tok);

    // Lesser.
    if (check<0){

        newIndex->left = ins(freq,tok,newIndex->left);

        if(checkH(newIndex->left)-checkH(newIndex->right)==2){

            //Double rotation
            if(check > 0) newIndex = lDouble(newIndex);

            //Single rotation
            else newIndex = lSingle(newIndex);
        }
    }


    // Greater.
    else if (check > 0) {

        newIndex->right =ins(freq,tok,newIndex->right);

        if(checkH(newIndex->right)-checkH(newIndex->left)==2){

            //Double Rotation
            if(check<0) newIndex = rDouble(newIndex);

            //Single rotation
            else newIndex = rSingle(newIndex);
        }
    }

    //Updating Height.
    temp1 = bigN(checkH(newIndex->left),checkH(newIndex->right));
    newIndex->height = temp1+1;

    return newIndex;
}


//Finding the Key.
avl* keyF (char* tok, avl *newIndex){

    int check;

    if(newIndex == NULL) return NULL;

		else {

      check = strcmp(newIndex->key,tok);

      // Left Node.
      if(check<0) return keyF(tok, newIndex->left);

      //Right Node.
      else if(check>0) return keyF(tok, newIndex->right);

			else return newIndex;
		}
}

//Chech which node is bigger
int bigN(int nodeL, int nodeR){

    //Return Left if left is bigger
    if (nodeL>nodeR) return nodeL;
    //Vice versa
    else return nodeR;

}

//Grabbing height.
int checkH(avl* newIndex){

    if( newIndex != NULL ) return newIndex->height;
    else return -1;

}
