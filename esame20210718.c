#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//funzione per prendere argomenti inseriti da terminale
int get_arg(char *arg, int *val);
int insertRC (int rc, int m);
int main(int argc, char **argv) {

    int row, col, max;

//1.Legge da linea di comando 3 argomenti:numero di righe(row), numero di colonne(col), numero massimo(max)
    if (argc != 4) {
        printf("Error si prega di fornire 3 argomenti: row, col, max\n");
        exit(-1);
    }
    if (get_arg(argv[1], &row) != 0) return 2;
    if (get_arg(argv[2], &col) != 0) return 2;
    if (get_arg(argv[3], &max) != 0) return 2;

    int m[row][col];
    int min;
    int i, j;
    min= -1*(max);
    printf("n. righe: %d\n", row);
    printf("n. colonne: %d\n", col);
    printf("range valori: [%d, %d]\n", min, max);
    printf("\n");

    time_t t;
    srand((unsigned) time(&t));
    //Creazione matrice m;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            m[i][j]= min + (rand() % (1+max-min));
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    if (row<3 || col<3){
        printf("\n");
        printf("Per eseguire la parte successiva del programma e' necessario inserire una matrice: '3*3'. La matrice inserita e' inferiore ai valori richiesti quindi il programma terminera' qui.");
        exit(1);
    } else{

        int r, c;
        printf("\n");

        //Inserimento Coordinate
        r= insertRC(r, row);
        c= insertRC(c, col);

        //Verifica coerenza con matrice;
        printf("Il valore della coordinata (%d,%d) e' %d.\n", r, c, m[r][c]);

        int v[3][3];
        int count=0;
        int minV;
        int b[9];

        v[0][0]= ( (r-1)<=0 || (c-1)<=0 )?99:m[r-1][c-1];
        v[0][1]= ( (r-1)<=0 || (c)<=0 )?99:m[r-1][c];
        v[0][2]= ( (r-1)<=0 || (c+1)<=0 )?99:m[r-1][c];

        v[1][0]= ( (c-1)<=0 )?99:m[r][c-1];
        v[1][1]= m[r][c];
        v[1][2]= ( (c+1)<=0 )?99:m[r][c+1];

        v[2][0]= ( (r+1)<=0 || (c-1)<=0 )?99:m[r+1][c-1];
        v[2][1]= ( (r+1)<=0 || (c)<=0 )?99:m[r+1][c];
        v[2][2]= ( (r+1)<=0 || (c+1)<=0 )?99:m[r+1][c+1];

        b[0]=v[0][0];
        b[1]=v[0][1];
        b[2]=v[0][2];
        b[3]=v[1][0];
        b[4]=v[1][1];
        b[5]=v[1][2];
        b[6]=v[2][0];
        b[7]= v[2][1];
        b[8]= v[2][2];

        for (i = 0; i < 9; i++) {
            if (i == 0) {
                minV = b[i];
            }

            if (b[i]< minV){
                minV = b[i];
            }
        }

        int countR=0;
        for (i=0; i<9; i++){
            if(i%3==0) {
                countR++;
            }
            if(b[i]==minV){
                printf("Minimo trovato in posizione v[%d][%d].\n",countR,(i>=3)?i:(i-(i%3)));
                count++;
            }
        }

        printf("\n");
        printf("Il minimo e' %d ed e' presente %d volte.\n", minV, count);

        printf("\n\n");

        FILE *file = fopen("C:\\Users\\Lorenzo Fasiello\\CLionProjects\\Gestione File in C\\esEsami2021\\18072021\\cmake-build-debug\\file.txt", "wt");

        printf("Apertura file file.txt\n");
        if(file == NULL){
            printf("!ERRORE");
            exit(-1);
        } else{
            printf("Apertura avvenuta con successo!\n");
        }

        //Stampa Sottomatrice
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d ", v[i][j]);
                fprintf(file, "%d ", v[i][j]);
            }
            printf("\n");
            fprintf(file, "\n");
        }

        printf("Chiusura File.");
        fclose(file);
    }
    exit(0);
}

int get_arg(char *arg, int *val){
    char *check;
    int num;
    num = strtol(arg, &check, 10);
    if (check && strlen(check) != 0) {
        printf("Gli argomenti devono essere interi");
        return 1;
    }
    *val = num;
    return 0;
}
int insertRC (int rc, int m){
    do {
        printf("Inserire valore coordinata: ");
        scanf("%d", &rc);
        printf("\n");
        if (rc < 0 || rc >= m)
            printf("!ERRORE, inserire un valore compreso tra 0 e %d\n", m-1);
    }while(rc < 0 || rc >= m);
    return rc;
}

