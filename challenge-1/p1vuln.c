#include <stdio.h>
#include <stdlib.h>  // For exit()

#define FLAGSIZE 32
#define BUFSIZE 128


void read_flag(char *buf) {
    FILE *f = fopen("flag.txt", "r");
    if (f == NULL) {
        printf("Error opening file\n");
        exit(1);  
    }
    fgets(buf, FLAGSIZE, f);  
    fclose(f); 
}


int main() {
    char flag[FLAGSIZE];
    char buf[BUFSIZE];

    read_flag(flag);
    printf("The flag is on the system, but good luck ever getting it >:D\n");

    printf("What should I call you?: ");
    char c;
    for(int i=0; i<BUFSIZE; i++) {
        c = getchar();
        buf[i] = c;
        if (c == '\n') {
            break;
        }
    }
    printf("Hello %s", buf);
    return 0;
}



