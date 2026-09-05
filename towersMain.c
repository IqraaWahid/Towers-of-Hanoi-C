#include <stdio.h>
#include <stdlib.h>
#include "towers.h"

int main(int argc, char **argv){
    int n = 3;
    int from = 1;
    int dest = 2;
	//SYNTAX:
	/*
     * argc: Argument count (data type: int)
     * Stores the number of things typed in the terminal
     * example: ./towers 5 6 7 --> argc = 4
     * */
     
     /*
      * argv: Argument vector
      * An array of strings
      * Holds what was typed in the terminal
      * argv[0]= "./towers" ; argv[1] = "5" ; argv[2]= "6" ; argv[3]= "7"
      * 
      * To convert these Strings into int we use: atoi()
      * example: n=atoi(argv[1]); --> n=5
      * */
      
      /*
       * printf() --> stdout (normal output)
       * fprintf(stderr,...) --> errors/debug
       * Both appear on the terminal
       * But they can be redirected: '>': stdout & '2>': stderr
       * 
       * return 0; --> program ran successfully
       * return nonZeroValue; --> program failed (used for invalid input)
       * */
      
    //No arguments:
    if(argc == 1){
		towers(n, from, dest);
	}
	
	//One argument: only numberDisks
	else if(argc==2){
		n=atoi(argv[1]); //covert the numberDisks from String to int, and store into n
		if(n<0){
			fprintf(stderr, "Error: numberDisks cannot be smaller than zero!"); //error: stderr
			return 1; //program failed
		}
		
		towers(n, from, dest);
	}
	
	//Three arguments:
	else if(argc==4){
		n=atoi(argv[1]);
		from=atoi(argv[2]);
		dest=atoi(argv[3]);
		
		if(n<0){
			fprintf(stderr, "Error: numberDisks cannot be smaller than zero!");
			return 1; //program failed
		}
		if(from<1 || from>3 || dest<1 || dest>3 || from==dest){
			fprintf(stderr, "Error: Invalid tower numbers!");
			return 1;
		}
		
		towers(n, from, dest);
	}
	
	//Any other wrong input
	else{
		fprintf(stderr, "Error: Invalid input");
		return 1;
	}
	
	return 0;
}

