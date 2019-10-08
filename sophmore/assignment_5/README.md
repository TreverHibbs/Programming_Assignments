# PA5
Class projec

CSE 222 Programming Assignment #5 – Group Project
For assignment #5, you're to implement a program to solve the integer unlimited knapsack problem.
For this assignment only, you may work in groups of up to 4 people each.


IMPORTANT GROUP-RELATED NOTES:
1. Your main program must begin with comments including the name of each person in your
group
2. The particular tasks/pieces worked on by each group member must be identified in the
comments. Do not say something like “we all worked on everythng.” Break the problem
into pieces, assign different pieces to each member, and describe this assignment in the
comments.
3. One group member must submit the assignment to Canvas by the due date. If mulitple
submissions are made, I will grade the first one I see alphabetically.
Details
Your program should be called "pa5" and should operate as follows:

• pa5 expects a single argument, which is the weight capacity of the knapsack e.g.
 pa5 15
would run your program for a bag with a weight capacity of 15;

• your program should read the file knapsack.data from the current directory. This file
should contain a set of weight/value/name triples, such as the following:

1 10 mouse
2 25 cellphone
5 40 tablet
7 100 laptop

In the above file, there are four items: a mouse with a weight of 1 and value of 10; a
cellphone with a weight of 2 and value of 25; and so on.

• After reading knapsack.data and storing the data in arrays, you should call a function (I
called this MaxVal(x) in class) for computing the maximum value that can be loaded into a
knapsack with a weight capacity of x. MaxVal(x) works by returning 0 if x <= 0, otherwise
returning the maximum of (v0+MaxVal(x-w0), v1+MaxVal(x-w1), ..., Vn+MaxVal(x-wn))
where each (vi,wi) is the value and weight of item i, and the maximum is computed over all
items where wi <= x (i.e. where item i can fit in a bag with capacity x). This is the algorithm
that was discussed in class.

• In addition to printing the maximum possible value, you should print how many of
each item should be put in the bag.

• Your program should operate efficiently by storing the value of each MaxVal(x) that is
computed, and retrieving that value (max value and list of items) instead of computing it
whenever possible.

• Your program should echo the contents of knapsack.data, and then print the maximum value
that can be loaded in a knapsack of the given capacity (which was specified as the argument
to "pa5").
Error Checking

Make sure you handle error conditions, including: no argument to the program; too many arguments
to the program; invalid argument to the program; missing or invalid knapsack.data file; and so on.
Assumptions
You may assume a maximum of 128 items in the knapsack.data file, and a maximum bag capacity
of 1024. You may assume a maximum length of 32 characters for the 3rd column of knapsack.data
(the item name), and assume that the name contains no spaces.
Submission
Include a makefile, put it and all source code into a .tar file, and upload to Canvas (one upload per
group only) by the due date.
