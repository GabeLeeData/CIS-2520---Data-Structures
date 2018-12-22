//Student ID: 0836295
//Gabriel Lee
// CIS 2520
// Assignment 3 - a)


#include "fName.h"

int finT = -1;
int finT2 = -1;
int finTN = -1;
int listOp[100];
int listOp2[100];
char list[100];
float listN[100];
int front = 0;
int rear = -1;
int totalC = 0;
int front2 = 0;
int rear2 = -1;
int totalC2 = 0;
char list2[100];

//Check for queue to be empty
bool isEmpty2(){
  return totalC2 ==0;
}

//Check for queue to be full
bool isFull2(){
  return totalC2 == 100;
}


//Add to queue - Char only
void enqueue2(char element){

  if (!isFull2()) {
    if (rear2 == 99) {
      rear2 = -1;
    }

    list2[++rear2] = element;
    totalC2++;
  }
}


//Remove from queue - Char only
char dequeue2(){
  char element = list2[front2++];

  if (front2 == 100){
    front2 = 0;
  }
  totalC2--;
  return element;
}


//Check for queue to be empty
bool isEmpty(){
  return totalC ==0;
}

//Check for queue to be full
bool isFull(){
  return totalC == 100;
}


//Add to queue - Char only
void enqueue(char element){

  if (!isFull()) {
    if (rear == 99) {
      rear = -1;
    }

    list[++rear] = element;
    totalC++;
  }
}


//Remove from queue - Char only
char dequeue(){
  char element = list[front++];

  if (front == 100){
    front = 0;
  }
  totalC--;
  return element;
}

//Push number from stack.
void pushN (float element){

  if (finTN == 100){
    printf("Full\n");
    exit(0);
  }
  else {
    finTN = finTN + 1;
    listN[finTN] = element;
  }
}

//Pop number from stack
float popN(){

  if (finTN == -1)
  {
    printf("Empty\n");
    exit(0);
  }

  else return(listN[finTN--]);
}

//Pusher Operator into stack.
void pushOp2 (char element){

  if (finT2 == 100){
    printf("Full\n");
    exit(0);
  }
  else {
    finT2 = finT2 + 1;
    listOp2[finT2] = element;
  }

}

//Pop operator from stack.
char popO2(){

  if (finT2 == -1)
  {
    printf("Empty\n");
    exit(0);
  }

  else return(listOp2[finT2--]);
}

//Pusher Operator into stack.
void pushOp (char element){

  if (finT == 100){
    printf("Full\n");
    exit(0);
  }
  else {
    finT = finT + 1;
    listOp[finT] = element;
  }

}

//Pop operator from stack.
char popO(){

  if (finT == -1)
  {
    printf("Empty\n");
    exit(0);
  }

  else return(listOp[finT--]);
}

//Function for calculating expression.
void calculate(char* exps) {
  char tempExps[100];
  char single;
  char tempN[5];
  float tempC, final, fi, sec;
  int length = strlen(exps);
  strcpy(tempExps,exps);

  for (int x = 0; x < length; x++){
    single = tempExps[x];

    //If unitialized variable make it 0.
    if (single == 'x'){
      //Skipping by 1
      x = x +1;
      //Setting variable to 0 and sending to stack.
      tempC = 0.00;
      pushN(tempC);
    }

    //Pushing Operator to stack.
    else if ((single == '+') || (single == '*') || (single == '/') || (single == '-')) {
      pushOp2(single);
    }

    //If a digit send to queue
    else if (isdigit(single)){
      //Copying over to temp.
      memcpy(tempN, &tempExps[x],4);
      tempN[4] = '\0';
      //Skipping by 3
      x = x + 3;
      //Converting to float  and sending to stack
      tempC = atof(tempN);
      pushN(tempC);
    }

    //Doing calculation
    else if (single == ')') {
      //Setting Varariables
      sec = popN();
      fi = popN();
      char pO2 = popO2();
      //Check for values
      printf("%0.2f  %c %0.2f\n", fi, pO2, sec);
      //Do Calculations
      if (pO2 == '+'){
        pushN(fi + sec);
      }

      else if (pO2 == '-'){
        pushN(fi - sec);
      }

      else if (pO2 == '*'){
        pushN(fi * sec);
      }

      else if (pO2 == '/'){
        pushN(fi / sec);
      }
    }
  }
  //Printing final value
  final = listN[finTN];
  printf("Result: %.2f\n", final);
}


//Function for displaying postorder.
void postorder (char* exps) {
  char tempExps[100];
  char single;

  int length = strlen(exps);
  strcpy(tempExps,exps);

  for (int x = 0; x < length; x++){

    single = tempExps[x];

    //If its the operator or '(' send to stack
    if ((single == '+') || (single == '*') || (single == '/') || (single == '-') || (single == '(')) {
      pushOp(single);

    }

    //If its a number send to the queue, send decimal, and x.
    else if (isdigit(single) || (single == '.') || (single == 'x')){
     enqueue(single);
    }

    // Printing values
    else {

      //Printing Queue - Values
      while (!isEmpty()) {
        char tempp = dequeue();
        printf("%c", tempp);
      }

      //Printing Stack - Operator
      while (finT != -1) {
        char pO = popO();
        if (pO != '(') printf("%c", pO);
      }
   }
  }
}

//Function for displaying inorder
void inorder (char* exps) {

  //initializaing and copying.
  char tempExps[100];
  int length = strlen(exps);
  strcpy(tempExps,exps);
  char single;

  //Printing with Paranethesis because its inorder.
  for (int x = 0; x < length; x++){
    single = tempExps[x];
    printf("%c", single);

  }

}

//Function for displaying Preorder
void preorder (char* exps){

  char tempExps[100];
  int length = strlen(exps);
  char single;
  char check;
  int placer = 1;

  //Create Temporary expression
  strcpy(tempExps,exps);
  for (int x = 0; x < length; x++){
    //Update placer.
    placer = 1;
    single = tempExps[x];
    //Check for Operand in Expression
    if ((single == '+') || (single =='*') || (single == '-') || (single == '/')){

      tempExps[x] = ' ';
      //Traversing Expression backwards
      for (int l = x; l >= 0; l--) {

        check = tempExps[l];
        if (placer ==1 && check == '('){
          placer++;
          tempExps[l] = single;
        }
      }
    }
  }

  //Printing through Expression
  for (int x = 0; x < length; x++){
    single = tempExps[x];
    if (single != ')') printf("%c", single);
  }

}
