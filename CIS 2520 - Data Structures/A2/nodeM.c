//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 2 - a)


#include "carInfo.h"

//Writing to file.
void writeF(nodeCar *ava, nodeCar* repair, nodeCar* rent){

  FILE *text;
  text = fopen("cars.txt","w");
  nodeCar *start;

  //Adding each list to the file one by one.
    start = ava;
    while(start->next != NULL){
      fprintf(text, "Ava, %s, %d, %d \n", start->liPlate, start->mile, start->date);
      start = start->next;
    }

    start = repair;
    while(start->next != NULL){

    fprintf(text, "Rep, %s, %d, %d \n", start->liPlate, start->mile, start->date);
    start = start->next;

    }

    start = rent;
    while(start->next != NULL){

    fprintf(text, "Rent, %s, %d, %d \n", start->liPlate, start->mile, start->date);
    start = start->next;

    }


  fclose(text);

}


//Sorting through Date within the list.
void daSort(nodeCar *temp, nodeCar *start, int final){

  int mileT,dateT;
  char* tPlate;

  for (int x =0; x < final; x++){
    temp = start;
    while (temp->next->next != NULL){

      if (temp->date > temp->next->date){

        mileT = temp->mile;
        dateT = temp->date;
        tPlate = temp->liPlate;

        temp->mile = temp->next->mile;
        temp->liPlate = temp->next->liPlate;
        temp->date = temp->next->date;

        temp->next->mile = mileT;
        temp->next->liPlate = tPlate;
        temp->next->date = dateT;
      }
      temp = temp->next;
    }
  }
}

//Sorting through Mileage within the list.
void miSort(nodeCar *temp, nodeCar *start, int final){

  int mileT, dateT;
  char* tPlate;

  for (int x = 0; x < final; x++){
    temp = start;
    while (temp->next->next != NULL){

      if (temp->mile > temp->next->mile){

        mileT = temp->mile;
        dateT = temp->date;
        tPlate = temp->liPlate;

        temp->mile = temp->next->mile;
        temp->liPlate = temp->next->liPlate;
        temp->date = temp->next->date;

        temp->next->mile = mileT;
        temp->next->liPlate = tPlate;
        temp->next->date = dateT;
      }
      temp = temp->next;
    }
  }

}

//Sorting Lists.
void sort(nodeCar *list, int type){

  int total=0;
  int final;
  nodeCar *temp = list;
  nodeCar *start = list;

  while (temp->next != NULL){
    temp = temp->next;
    total++;
  }

  final = total -1;

  //Sorting Mileage
  if (type==1) miSort(temp,start,final);

  //Sorting Date
  else if (type==0) daSort(temp,start,final);

}


void swap (nodeCar *start, nodeCar *prev){

  prev->next = start->next;
  prev->liPlate = start->liPlate;
  prev->date = start->date;
  prev->mile = start->mile;

}

//Deleting Node within the list.
void delNode (nodeCar *list, char *liPlate){

  nodeCar *prev = list;
  nodeCar *start = list;

  while (prev->next != NULL){

    start = start->next;
    if (strcmp(liPlate, prev->liPlate) == 0){

      swap(start, prev);
      free(start);
      break;
    }
    prev = prev->next;
  }
}

//Calculations for finding the final cost.
int calc (int newmile){

  int final;
  final = (int)((newmile-100) * 0.15);
  final = final + 40;
  return final;

}


//Finding the mile based on License Plate.
int searcher (nodeCar *list, char* liPlate){

  int miles = 0;
  nodeCar* current = list;

  while(current->next != NULL) {

    if(strcmp(liPlate, current->liPlate) ==0) miles = current->mile;

    current = current->next;
  }
  return miles;
}




//Finding Dupliecates based on License Plates.
int dupL(nodeCar *list, char* liPlate){

  int checker = 0;
  nodeCar* current = list;

  while(current->next != NULL){

    if(strcmp(liPlate, current->liPlate) ==0) {
      checker = 1;
      break;
    }
    else checker = 0;

    current = current->next;
  }

 return checker;
}

//Printing the List.
void print(nodeCar *list, int type){


  nodeCar* start = list;

  if (start != NULL) {
    if (type ==1) printf("\nAvailable List of Cars to Rent\n");
    else if (type ==2) printf("\nList of Car to be repaired\n");
    else if (type ==3) printf("\nList of Cars that are rented\n");

    while (start->next != NULL)
      {
        printf("[Car License] : %s",start->liPlate);
        printf(" || [Mileage] : %d", start->mile);
        printf(" || [Return Date](YYMMDD): %d\n", start->date);
    		start = start->next;
      }

  }

  else {
    printf("Empty");
    return;
  }
}


//Creating a Single Node.
nodeCar* createNode (int mile, char* liPlate, int date){

  nodeCar* node;
  node = malloc(sizeof(struct nodeCar));
  node->liPlate = malloc(sizeof(char)*(strlen(liPlate)+1));

  //Passing info to node.
  node->mile = mile;
  node->date = date;
  node->next = NULL;
  strcpy(node->liPlate, liPlate);

  return node;
}

//Creating the Linked List.
nodeCar* listNode (nodeCar *list, nodeCar *future){

  nodeCar* temp = future;

  if (list !=NULL)
  {

    temp->next = list;
    list = future;
    return list;

  }

  else {
    list = future;
    return list;
  }
}


//Reading in Rented List - Starts with 'Rent'
nodeCar* readRen (nodeCar *list) {

    char buffer[300];
    char * tok;
    FILE *text;
    nodeCar* node = malloc(sizeof (struct nodeCar));


    text = fopen("cars.txt", "r");

    while (fgets (buffer, 300, text) != NULL){

      tok = strtok(buffer, " , ");
      int mi, da;
      char * liC;
      char * miC;
      char * dateC;


      if(strcmp(tok, "Rent") == 0)
      {
        liC = strtok(NULL, " , ");
        miC = strtok(NULL," , ");
        dateC = strtok(NULL, " , ");
        da = atoi(dateC);
        mi = atoi(miC);


        if (liC != NULL){
        //Create Node and add
          node = createNode(mi, liC, da);
          list = listNode(list, node);
        }

        else return list;

      }
    }
    fclose(text);
    return list;
}

//Reading in Repair List - Starts with 'Rep'
nodeCar* readRep (nodeCar *list){

    char buffer[300];
    char * tok;
    FILE *text;
    nodeCar* node = malloc(sizeof (struct nodeCar));


    text = fopen("cars.txt", "r");

    while (fgets (buffer, 300, text) != NULL){

      tok = strtok(buffer, " , ");
      int mi, da;
      char * liC;
      char * miC;
      char * dateC;


      if(strcmp(tok, "Rep") == 0)
      {
        liC = strtok(NULL, " , ");
        miC = strtok(NULL," , ");
        dateC = strtok(NULL, " , ");
        da = atoi(dateC);
        mi = atoi(miC);


        if (liC != NULL){
        //Create Node and add
          node = createNode(mi, liC, da);
          list = listNode(list, node);
        }

        else return list;

      }
    }
    fclose(text);
    return list;
}




//Reading in Available List - starts with 'Ava'
nodeCar* readA(nodeCar *list){

  char buffer[300];
  char * tok;
  FILE *text;
  nodeCar* node = malloc(sizeof (struct nodeCar));

  text = fopen("cars.txt", "r");

  while (fgets (buffer, 300, text) != NULL){

    tok = strtok(buffer, " , ");
    int mi, da;
    char * liC;
    char * miC;
    char * dateC;

    if(strcmp(tok, "Ava") == 0)
    {
      liC = strtok(NULL, " , ");
      miC = strtok(NULL," , ");
      dateC = strtok(NULL, " , ");
      da = atoi(dateC);
      mi = atoi(miC);

      if (liC != NULL){
        //Create Node and add
        node = createNode(mi, liC, da);
        list = listNode(list, node);
      }

      else return list;

    }
  }
  fclose(text);
  return list;
}
