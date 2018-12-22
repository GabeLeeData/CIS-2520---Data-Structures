Name: Gabriel Please
ID: 0836295
Assignment Number: 3


***Compiling***

To compile the program simply type "make" within the appropriate directory where all the files are located within the terminal.
After the program is compiled type in "./q1" to run the first question while following a expression and to run the second question type in "./q2".  
A example of running the first question is ./q1 "(((x1+5.12)*(x2-7.68))/x3)"
It is also noted that there must be quotations around the expression for the program to execute.



***Programs***

Q1.

When launching the program, the user will be presented with 7 options. Each option can be selected from the menu by inputing the corresponding number such as 1,2, or 3. 
The program will traverse through the expression as it is implanted into a char array. From there you can choose different traversal methods that will sort the
array in the corresponding method. The program is also capable of updating variables and calculating the expression. If a variable is not set, it will be put to 0.


Q2.

This program will read in a file called "f.dat" and will store the values in a 20 x 10 array. The first three integers are summed up and considered the key. The
program will use a downheap algorithm on the set of keys to sort. 


****Limitations***

I did not finish the display tree for question 1.


***Sample Output***

Q1.

./q1 "(((x1+5.12)*(x2-7.68))/x3)"


The Expression:
 (((x1+5.12)*(x2-7.68))/x3)

Please Select a option
1. Display. 
2. Preorder. 
3. Inorder. 
4. Postorder. 
5. Update. 
6. Calculate. 
7. Exit. 
1

Displaying(((x1+5.12)*(x2-7.68))/x3)
The Expression:
 (((x1+5.12)*(x2-7.68))/x3)

Please Select a option
1. Display. 
2. Preorder. 
3. Inorder. 
4. Postorder. 
5. Update. 
6. Calculate. 
7. Exit. 
2

Preorder
/*+x1 5.12 -x2 7.68 x3
The Expression:
 (((x1+5.12)*(x2-7.68))/x3)

Please Select a option
1. Display. 
2. Preorder. 
3. Inorder. 
4. Postorder. 
5. Update. 
6. Calculate. 
7. Exit. 
3

Inorder 
(((x1+5.12)*(x2-7.68))/x3)
The Expression:
 (((x1+5.12)*(x2-7.68))/x3)

Please Select a option
1. Display. 
2. Preorder. 
3. Inorder. 
4. Postorder. 
5. Update. 
6. Calculate. 
7. Exit. 
4

Postorder 
x15.12+x27.68-*x3/
The Expression:
 (((x1+5.12)*(x2-7.68))/x3)

Please Select a option
1. Display. 
2. Preorder. 
3. Inorder. 
4. Postorder. 
5. Update. 
6. Calculate. 
7. Exit. 
5

Updating 
Please Enter Variable Name
x3
Please Enter New Value of Variable
1.00

The Expression:
 (((x1+5.12)*(x2-7.68))/1.00)

Please Select a option
1. Display. 
2. Preorder. 
3. Inorder. 
4. Postorder. 
5. Update. 
6. Calculate. 
7. Exit. 
6

Calculate
0.00  + 5.12
0.00  - 7.68
5.12  * -7.68
-39.32  / 1.00
Result: -39.32

The Expression:
 (((x1+5.12)*(x2-7.68))/1.00)

Please Select a option
1. Display. 
2. Preorder. 
3. Inorder. 
4. Postorder. 
5. Update. 
6. Calculate. 
7. Exit. 



Q2.


./q2

Displaying Non Sorted Array

KEY: 54 | 25 12 17 82 52 53 5 3 68 64 
KEY: 90 | 43 27 20 59 4 84 10 42 43 2 
KEY: 137 | 81 14 42 21 9 69 5 30 20 91 
KEY: 260 | 96 89 75 0 63 24 54 20 20 24 
KEY: 185 | 41 62 82 46 69 42 74 68 79 28 
KEY: 65 | 50 9 6 44 59 87 32 36 36 46 
KEY: 208 | 83 82 43 11 21 4 8 97 93 14 
KEY: 139 | 3 60 76 23 14 81 82 0 38 4 
KEY: 114 | 9 83 22 90 74 56 64 75 67 55 
KEY: 176 | 41 82 53 40 29 84 24 61 87 20 
KEY: 186 | 99 37 50 93 57 6 29 91 92 39 
KEY: 77 | 25 41 11 88 15 39 88 69 31 49 
KEY: 137 | 3 37 97 53 36 54 69 68 38 43 
KEY: 139 | 44 27 68 96 70 98 85 13 25 47 
KEY: 178 | 51 90 37 86 42 44 48 64 41 1 
KEY: 57 | 16 14 27 99 29 99 79 45 59 19 
KEY: 203 | 88 56 59 88 39 30 44 59 49 72 
KEY: 110 | 49 17 44 32 33 54 60 33 51 87 
KEY: 80 | 12 0 68 68 49 68 74 32 9 30 
KEY: 127 | 81 30 16 65 40 39 44 49 32 60 

Displaying New Sorted Array

KEY: 54 | 25 12 17 82 52 53 5 3 68 64 
KEY: 57 | 16 14 27 99 29 99 79 45 59 19 
KEY: 65 | 50 9 6 44 59 87 32 36 36 46 
KEY: 80 | 12 0 68 68 49 68 74 32 9 30 
KEY: 127 | 81 30 16 65 40 39 44 49 32 60 
KEY: 77 | 25 41 11 88 15 39 88 69 31 49 
KEY: 139 | 44 27 68 96 70 98 85 13 25 47 
KEY: 114 | 9 83 22 90 74 56 64 75 67 55 
KEY: 90 | 43 27 20 59 4 84 10 42 43 2 
KEY: 176 | 41 82 53 40 29 84 24 61 87 20 
KEY: 186 | 99 37 50 93 57 6 29 91 92 39 
KEY: 137 | 81 14 42 21 9 69 5 30 20 91 
KEY: 137 | 3 37 97 53 36 54 69 68 38 43 
KEY: 208 | 83 82 43 11 21 4 8 97 93 14 
KEY: 178 | 51 90 37 86 42 44 48 64 41 1 
KEY: 260 | 96 89 75 0 63 24 54 20 20 24 
KEY: 203 | 88 56 59 88 39 30 44 59 49 72 
KEY: 139 | 3 60 76 23 14 81 82 0 38 4 
KEY: 110 | 49 17 44 32 33 54 60 33 51 87 
KEY: 185 | 41 62 82 46 69 42 74 68 79 28 



