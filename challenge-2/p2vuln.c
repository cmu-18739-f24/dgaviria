
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include <string.h>


#define CANARYSIZE 8
#define BUFSIZE 32

char global_canary[CANARYSIZE];



void win() {
    char flag[BUFSIZE];
    FILE *file = fopen("flag.txt", "r");  
    fgets(flag, BUFSIZE, file);  
    fclose(file);  
    puts(flag); 
}


void generate_canary() {
    srand(time(NULL) + getpid());
    char c;
    for (int i=0; i<CANARYSIZE; i++) {
        c = (rand() % 95) + 32;
        global_canary[i] = c;
    }
}


void vuln() {
    char canary[CANARYSIZE];
    char user[BUFSIZE];
    char email[BUFSIZE];

    memcpy(canary, global_canary, CANARYSIZE);

    printf("Welcome to our Awesome Page!  To recieve updates, enter your name and the email to contact you through.\n");
    printf("Enter username: \n");
    gets(user);
    printf(user);
    printf("\nEnter email: \n");
    gets(email);

    if (memcmp(canary, global_canary, CANARYSIZE) != 0) {
        printf("Hacker detected, aborting!\n");
        exit(1);
    }
    printf("Thank you for registering, goodbye!\n");
}


int main() {
    generate_canary();
    vuln();
}