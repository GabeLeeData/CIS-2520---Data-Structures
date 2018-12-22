Name: Gabriel Please
ID: 0836295
Assignment Number: 2


***Compiling***

To compile the program simply type "make" within the appropriate directory where all the files are located within the terminal.
After the program is compiled type in "./q1" to run the first question or "./q2" and a expression after , to run the second question. 
A example of running the second question is "./q2 13+53-*"



***Programs***

Q1.

When launching the program, the user will be presented with 7 options. Each option can be selected from the menu by inputing the corresponding number such as 1,2, or 3. 
The program will read in the file "cars.txt", this textfile has already been pre-loaded with cars. 
When ending the program, the number "7" is entered in the menu screen and all the transformations done on the data set will be saved back into "cars.txt".
This program did implement error checking for all functions such as duplicate license plate and incorrect date format. 


Q2.

This program will calculate the expression that is entered after "./q2" , it will return the answer in 2 decimal places.
The format for the expression should be 2 numbers followed by a operator (+,-,/,*). 
An example of this is "./q2 13+53-*" which means (1+3) * (5-3).
Error checking was done for this program and it will only accept 2 subsequent numbers, numbers and operators (+,-,/,*). 


***Sample Output***

Q1.

    Please Select a option
    1. Add a new car to the available-for-rent list 
    2. Add a returned car to the available-for-rent list 
    3. Add a returned car to the repair list 
    4. Transfer a car from the repair list to the available-for-rent list 
    5. Rent the first available car 
    6. Print all the lists 
    7. quit. 
    6


    Available List of Cars to Rent
    [Car License] : XARP100 || [Mileage] : 3000 || [Return Date](YYMMDD): 0
    [Car License] : TARP200 || [Mileage] : 4000 || [Return Date](YYMMDD): 0
    [Car License] : LARP300 || [Mileage] : 5000 || [Return Date](YYMMDD): 0


    List of Car to be repaired
    [Car License] : SOOT400 || [Mileage] : 7000 || [Return Date](YYMMDD): 0
    [Car License] : LOOT200 || [Mileage] : 8000 || [Return Date](YYMMDD): 0
    [Car License] : MOOT100 || [Mileage] : 9000 || [Return Date](YYMMDD): 0


    List of Cars that are rented
    [Car License] : LEER300 || [Mileage] : 8000 || [Return Date](YYMMDD): 171014
    [Car License] : TEER200 || [Mileage] : 4000 || [Return Date](YYMMDD): 180115
    [Car License] : BEET100 || [Mileage] : 9000 || [Return Date](YYMMDD): 180912

    Please Select a option
    1. Add a new car to the available-for-rent list 
    2. Add a returned car to the available-for-rent list 
    3. Add a returned car to the repair list 
    4. Transfer a car from the repair list to the available-for-rent list 
    5. Rent the first available car 
    6. Print all the lists 
    7. quit. 


Q2.

    "./q2 12+53-*" <- Terminal.
     Answer is : 6.00
    ***Exiting Program***




