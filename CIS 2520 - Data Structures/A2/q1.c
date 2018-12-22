//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 2 - a)

#include "carInfo.h"


int main(int argc, char**argv) {

  //Initialization.
  int opt =0;
  int mile, retDate;
  int finalC = 0;
  int tempmile, newmile, cost;
  char liPlate[10];
  int nodate=0;
  nodeCar* ava = malloc(sizeof(struct nodeCar));
  nodeCar* rent = malloc(sizeof(struct nodeCar));
  nodeCar* repair = malloc(sizeof(struct nodeCar));
  nodeCar* temp = malloc(sizeof(struct nodeCar));
  nodeCar* temp2 = malloc(sizeof(struct nodeCar));
  nodeCar* start = malloc(sizeof(struct nodeCar));
  ava = readA(ava);
  rent = readRen(rent);
  repair = readRep(repair);


  do {
    //Sorting.
    sort(ava, 1);
    sort(rent,0);
    //Choosing which option
    printf("Please Select a option\n");
    printf("1. Add a new car to the available-for-rent list \n");
    printf("2. Add a returned car to the available-for-rent list \n");
    printf("3. Add a returned car to the repair list \n");
    printf("4. Transfer a car from the repair list to the available-for-rent list \n");
    printf("5. Rent the first available car \n");
    printf("6. Print all the lists \n");
    printf("7. quit. \n");
    scanf("%d", &opt);
    printf("\n");


    //Envoke Adding a new car
    if (opt == 1){

      printf("Please Enter the Plate Number: ");
      scanf("%s", liPlate);

      //Checking for Correct Format.
      while ( (strlen(liPlate) <5) || (strlen(liPlate) > 7))
      {
        printf("Please Enter Correct Format");
        printf("\n");
        scanf("%s", liPlate);
      }

      //Checking for duplicates.
      if ((dupL(ava, liPlate)) != 0) printf("Duplicate License Plate Found\n");

      else{
        printf("Please Enter the Mileage: ");
        scanf("%d", &mile);

        //Create Temp Node to be added to list.
        temp = createNode(mile,liPlate,nodate);
        //Adding node to list.
        ava = listNode(ava, temp);

        printf("Successfully Added Car: %s to the Available List\n\n", liPlate);
      }

    }

    //Adding car from Rent to Available List.
    else if (opt ==2){

      printf("Please Enter the Plate Number: ");
      scanf("%s", liPlate);
      //Checking for Correct Format.
      while ( (strlen(liPlate) <5) || (strlen(liPlate) > 7))
      {
        printf("Please Enter Correct Format");
        printf("\n");
        scanf("%s", liPlate);
      }


      //Checking for duplicates.
      if ((dupL(rent, liPlate)) == 0) printf("No Exisiting License in Registry\n");

      else {
        tempmile = searcher(rent,liPlate);
        printf("Please Enter the new mileage: ");
        scanf("%d", &mile);

        //Error checking for mileage
        while((searcher(rent,liPlate)) > mile){

          printf("Incorrect - Please add more than original miles: \n");
          scanf("%d", &mile);
        }
        //Calculations
        newmile = mile - tempmile;
        if (newmile > 100) cost = calc(newmile);
        else cost = 40;

        //Counting Total Cost
        finalC = finalC + cost;

        //Create Temp Node to be added to list.
        temp = createNode(mile,liPlate,nodate);
        ava = listNode(ava, temp);

        //Udating nodes
        delNode(rent, liPlate);
        printf("Orginial Miles %d\nDifference (miles): %d\nTotal Cost: $%d\n", tempmile, newmile, cost);
        printf("Moving Car: %s to Available - List", liPlate);
      }
    }


    //Adding Car to Repair List
    else if (opt ==3){
      printf("Please Enter the Plate Number: ");
      scanf("%s", liPlate);
      //Checking for Correct Format.
      while ( (strlen(liPlate) <5) || (strlen(liPlate) > 7))
      {
        printf("Please Enter Correct Format");
        printf("\n");
        scanf("%s", liPlate);
      }


      //Checking for duplicates.
      if ((dupL(rent, liPlate)) == 0) printf("No Exisiting License in Registry\n");

      else {
        tempmile = searcher(rent,liPlate);
        printf("Please Enter the new mileage: ");
        scanf("%d", &mile);

        //Error checking for mileage
        while((searcher(rent,liPlate)) > mile){

          printf("Incorrect - Please add more than original miles: \n");
          scanf("%d", &mile);
        }
        //Calculations
        newmile = mile - tempmile;
        if (newmile > 100) cost = calc(newmile);
        else cost = 40;

        //Counting total Cost
        finalC = finalC + cost;

        //Create Temp Node to be added to list and adding to node.
        temp = createNode(mile,liPlate,nodate);
        repair = listNode(repair, temp);

        //Udating nodes
        delNode(rent, liPlate);
        printf("Orginial Miles %d\nDifference (miles): %d\nTotal Cost: $%d\n", tempmile, newmile, cost);
        printf("Moving Car: %s to Repair - List", liPlate);
      }
    }

    //Transfer from Repair List to Available List
    else if (opt ==4) {
      printf("Please Enter the Plate Number: \n");
      scanf("%s", liPlate);
      //Checking for Correct Format.
      while ( (strlen(liPlate) <5) || (strlen(liPlate) > 7))
      {
        printf("Please Enter Correct Format: ");
        printf("\n");
        scanf("%s", liPlate);
      }

      //Checking for duplicates.
      if ((dupL(repair, liPlate)) == 0) printf("No Exisiting License in Registry\n");
      else {

        //Create Temp Node to be added to list and adding.
        mile = searcher(repair, liPlate);
        temp = createNode(mile,liPlate,nodate);
        ava = listNode(ava, temp);

        //Udating nodes
        delNode(repair, liPlate);

        printf("Successfully Moved Car: %s to Available List\n", liPlate);
    }
  }

    //Renting the First Available Car.
    else if (opt ==5){

      printf("Please Enter Return Date in the format 'yymmdd'\n");
      scanf("%d", &retDate);

      while((retDate < 99999) || (retDate > 1000000)){
        printf("Please Enter Correct Format 'yymmdd' \n");
        scanf("%d", &retDate);
      }
      //Grabbing First Node.
      start = ava;
      temp = start;
      //Creating new New Node.
      temp2 = createNode(temp->mile, temp->liPlate, retDate);
      //Adding Node, to list.
      rent = listNode(rent, temp2);
      //Printing
      printf("First Car Avaialble: %s\n", temp->liPlate);
      //Deleting Node
      delNode(ava, temp->liPlate);

    }

    else if (opt ==6){

      //Printing all cars within each category..
      print(ava, 1);
      printf("\n");
      print(repair, 2);
      printf("\n");
      print(rent, 3);
      printf("\n");


    }

    else if (opt ==7){

      //Writing to file.
      writeF(ava, repair, rent);

      printf("All Money Spent = $ %d\n", finalC);
      printf("***Exiting Program***\n");
    }

  } while (opt !=7);

}
