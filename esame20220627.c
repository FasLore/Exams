#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBUFF 128

int check_arg (char* arg, int* val);//prototipo di funzione
int stampaMatrix(int row, int col, FILE *file, char p, char *line[]);

int main(int argc, char** argv) {

    int nr, nc;
    if (argc != 4) {
        printf("!ERROR: Si prega di fornire 2 argomenti: nr, nc, fileName\n");
        return 1;

    }
    if (check_arg(argv[1], &nr) != 0) return 2;
    if (check_arg(argv[2], &nc) != 0) return 2;

    printf("%d %d ", nr, nc);

    int m[nr][nc];

    FILE *f= fopen(argv[3], "rb");

    printf("Apertura file %s\n", argv[3]);
    if(f==NULL){
        printf("!ERRORE");
        exit(-1);
    } else{
        printf("Apertura avvenuta con successo!\n");
    }

    char* c=NULL;
    char line[MAXBUFF];
    int rowMatrix=0;
    int colMatrix=0;
    printf("\n");

    stampaMatrix(rowMatrix, colMatrix, f, c, line);

    if (nr>rowMatrix || nc>colMatrix || nr<=0|| nc<=0){
        printf("!ERROR");
        exit(-1);
    }

    fclose(f);
    return 0;
}

int check_arg(char* arg, int* val){
    char* check;
    int num;
    num = strtol(arg, &check, 10);
    if(check && strlen(check) !=  0){
        printf("Gli argomenti devono essere interi");
        return 1;
    }

    *val = num;
    return 0;
}
int stampaMatrix(int row, int col, FILE *file, char p, char *line[]){
    do{
        printf("%d \n", p);
        if(line[0] == "\n"){
            row++;
        }
        if(line[0] != "\n" && row<1){
            col++;
        }
    }while((p= fgets(line, MAXBUFF, file)) != NULL);

    printf("La matrice ha dimensioni %d * %d\n", row, col);
}
