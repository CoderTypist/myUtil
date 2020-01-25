#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int bytesPerCol = 20;
int preSpaces = 2;
int midSpaces = 10;

// prints bytesPerCol characters to the console
// returns true if EOF was reached
// returns false if EOF was not reached
bool display(FILE *fpFile){
    
    char c;
    int byteInCol = 1;
    bool atEnd = false;
    
    while( byteInCol <= bytesPerCol ){

        c = fgetc(fpFile);
        
        // print spaces if EOF has been reached
        if ( c == EOF ){
            atEnd = true;
            printf(" ");
        }
        
        // EOF has not been reached
        else {
            
            // print a space in place of these characters
            if ( c == '\n' | c == '\t' | c == '\v' | c == '\0' | c == '\r' ){
                printf(" ");
            }

            else{
                printf("%c", c);
            }
        }

        byteInCol++;
    }

    // EOF was reached
    if ( true == atEnd ){
        return true;
    }
    
    // EOF was not reached
    return false;
}

// prints x spaces to the console
void spaces(int x){
    
    int i;
    for( i = 0 ; i < x ; i++ ){
        printf(" ");
    }
}

int main(int argc, char *argv[]){
    
    if(argc < 3){
        printf("\nToo few arguments\n");
        exit(1);
    }
    
    char *firstFileName = argv[1];
    char *secondFileName = argv[2];

    // If the user specified how many characters to display per line
    if ( argc >= 3 ){
        bytesPerCol = atoi(argv[3]);
    }

    FILE *fpFirst;
    FILE *fpSecond;

    if (NULL == (fpFirst=fopen(firstFileName,"r"))){
        printf("\nFailed to open: %s\n", firstFileName);
        exit(1);
    }

    if (NULL == (fpSecond=fopen(secondFileName,"r"))){
        printf("\nFailed to open: %s\n", secondFileName);
        exit(1);
    }
    
    bool end1 = false;
    bool end2 = false;
    
    printf("\n");
    
    // loop until the end of both files has been reached
    while( end1 == false || end2 == false ){
        
        // padding to the right
        spaces(preSpaces);

        // print text from first file
        if ( end1 == false ) { end1 = display(fpFirst); }
        else { spaces(bytesPerCol); }

        // spaces between text from the two files
        spaces(midSpaces);
        
        // print text from second file
        if( end2 == false ) { end2 = display(fpSecond); }
        printf("\n");
    }
    
    printf("\n");

    return 1;
}

