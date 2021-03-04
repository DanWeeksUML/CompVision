Dan Weeks - Project 1 README

Contents:
proj1.c - This program takes an integer in from the terminal, then creates a number of
	  child processes equal to that integer. Each child prints that it was started
	  and runs a random test program (out of the five tests included). The parent 
	  process waits for the child to finish, then print that that specific child
	  has ended (identified by process number and pid).
Makefile - file to easily compile the program.
ReadMe - you are here.

Steps to run this program:
1. Unzip all files to the same directory.
2. Make sure all external test files, such as test1.c, are in the same directory as proj1.c
3. Open terminal and change to that directory.
4. type "make compile" to compile the program
5. type "./proj1 <# of child processes> to run the program, for example: "./proj1 56."