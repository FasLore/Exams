/*
 Scrivere una applicazione per il bin packing. L’obiettivo è posizionare dei container rettangolari
all’interno della stiva di una nave rappresentata da una matrice di dimensione dimx * dimy.
Inizialmente la matrice che rappresenta la nave è inizializzata a tutti i valori pari a 0. I container da
posizionare nella nave sono descritti in un file di testo che contiene per ogni riga di testo 3 valori
interi:
- Un numero intero che identifica il container
- La dimensione lungo la direzione x del container
- La dimensione lungo la direzione y del container
Fissato un punto della stiva libero si scorre l’array dei container per cercare il primo container che
entra nella stiva, se esiste un container compatibile allora posiziona il container nella stiva
modificando tutte quelle celle della stiva che corrispondono con la forma del container scrivendo
l’identificativo del container e si elimina il container dall’array dei container; si cambia posizione
della stiva spostandosi alla successiva posizione libera e si ripete la ricerca del container adatto alla
posizione. Al termine di tutte le posizioni della stiva l’applicazione stampa a video la matrice della
stiva e indicando quanti container non sono stati posizionati.

 Nella implementazione della soluzione procedere nel seguente ordine:
1. (5 punti) Creare una struttura dati che possa rappresentare un singolo container il tipo di
dato deve essere denominato struct container

2. (3 punti) Leggere da linea di comando: nome del file di testo; dimensione ‘x’ della stiva;
dimensione ‘y’ della stiva

3. (5 punti) Leggere il file di testo che contiene una riga di testo per ogni container secondo
quanto specificato poco sopra e memorizzare le informazioni dei container in un array di
container opportunamente allocato (la lettura dei dati da file e il riempimento dell’array dei
container deve essere fatto in una funzione diversa dal main)

4. (3 punti) Allocare la matrice della stiva e inizializzare tutti i valori a 0. Il valore 0 indica che
la cella non è occupata da nessun container

5. (5 punti) Scrivere una funzione con il seguente prototipo
int check_container(int dimx, int dimy, int stiva[dimy][dimx], int posx,
int posy, struct container* k);
La funzione ritorna 0 (falso) oppure 1 (vero) e controlla se partendo dalla riga posy e dalla
colonna posx c’è uno spazio nella matrice stiva che sia compatibile (cioe’ che contiene
tutti 0) con la dimensione del container k

6. (5 punti) Scrivere una funzione con il seguente prototipo
void put_container(int dimx, int dimy, int stiva[dimy][dimx], int posx,
int posy, struct container* k);
La funzione modifica tutti i valori della matrice stiva partendo dalla riga posy e dalla
colonna posx scrivendo l’identificativo del container k nelle sole celle occupate dal
container k. Non è richiesto che la funzione faccia un check per evitare di scrivere fuori
dalla matrice.

7. (5 punti) Nel main selezionare una posizione della stiva alla volta se la posizione della stiva
e’ vuota procedere con il successivo punto altrimenti si seleziona la cella successiva;
scorrere l’array dei container e invocare la funzione check_container usando il container
correntemente selezionato sulla posizione della stiva correntemente selezionata; scorrere
array dei container fintanto che la funzione check_container restituisce valore 1; se esiste
un container compatibile con la posizione corrente allora invocare la funzione
put_container ed eliminare il container dal vettore dei container. In un caso o nell’altro
proseguire quindi con la successiva cella della matrice stiva e ripetere il check_container.
L’algoritmo termina quando si arriva all’ultima cella della matrice oppure quando sono
terminati i container.

8. (2 punti) Stampare a video la matrice stiva

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256

typedef struct{
    int numeroContainer;
    int posX;
    int posY;
}container[MAX_SIZE];

int get_arg(char* arg, int* val) //funzione che mi permette di verificare se x e y siano 2 interi
{
    char* check;
    int num;
    num = strtol(arg, &check, 10);
    if(check && strlen(check) !=  0) //strlen mi serve a calcolare la lunghezza di una stringa, escluso il carattere terminatore.
    {
        printf("Gli argomenti devono essere interi");
        return 1;
    }
    *val = num;
    return 0;
}

//int fillArray(int *f, int *v[])
//{
//    int i;
//    printf("Elenco container presenti: ");
//    for (i = 0; i < 54; i++) //Questa funzione mi servirà per portare su array gli elementi presenti nel file.txt
//    {
//        fscanf(f, "%d", &v[i]);
//        printf("%d ", v[i]);
//        if(v[i]==EOF)
//            break;
//    }
//    printf("\n");
//}

void printArray( int *array,int dim)
{
    for (int j = 0; j < dim; j++) //Questa funzione mi servirà per portare su array gli elementi presenti nel file.txt
    {
        printf("%d ", array[j]);
    }
    printf("\n");
}
int count(int *array,char *type){
    return sizeof(array) / sizeof(type);
}
void printMatrix(int rows, int cols, int *m)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%2d ", m[i*cols+j]);
        }
        printf("\n");
    }
    printf("\n");
}
void fillArray(int *file, Container *list)
{
    int i;
    for (i=0; i<54; i=i+3)
    {
        while(fgets(Container,60, matchFP)){

            printf("%s", matches_array);
            fscanf(matchFP,"%s, %d, %lf, %s, %d, %d",
                   &matches_array[i].day[i],
                   &matches_array[i].day,
                   &matches_array[i].time,
                   &matches_array[i].teams,
                   &matches_array[i].score,
                   &matches_array[i].specs);
            i++;
        }

    }










//    fseek(file,0,SEEK_END);
//    int count=(ftell(file)/sizeof(Container));
//    printf("iyufouyfo\n");
//    printf("%ld",sizeof(Container));
//    rewind(file);
//    list =  malloc(sizeof(Container) * count);
//    fread(list,sizeof(Container),count,file);
//    fclose(file);

    //printArray(list, count(list,"container"));
    //printArray(v, count(v,"int"));

}

int check_container(int dimx, int dimy, int stiva[dimy][dimx], int posx,
                    int posy, struct Container* k)
                            {

                            }

put_container(int dimx, int dimy, int stiva[dimy][dimx], int posx,
              int posy, struct Container* k)
                      {

                      }

int main(int argc, char** argv) {
    int i, j;
    int x, y;
    struct container *k;

    if (argc != 4) {
        printf("Error si prega di fornire 3 argomenti: nome del file di testo, x, y\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rt");
    if (get_arg(argv[2], &x) != 0) exit(2);
    if (get_arg(argv[3], &y) != 0) exit(2);

    int stiva[x][y];
    memset(stiva, 0, sizeof(stiva[0][0]) * x * y);
    printMatrix(x, y, stiva);
    if (fp == NULL) {
        printf("!ERROR!\n");
        exit(-1);
    }
    printf("Aperto con successo!\n");


    Container *list;
    fillArray(fp, list);
    printArray(list, count(list, "Container"));

}
