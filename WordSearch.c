#include <stdio.h>
#include <stdlib.h>
#define MAP_SIZE 100
#define BUFFER_SIZE MAP_SIZE*2+2

int checkRT();
int checkLT();
int checkUP();
int checkDN();
int checkDNR();
int checkDNL();
int checkUPR();
int checkUPL();

char temp[MAP_SIZE][MAP_SIZE];
char anothaOne [MAP_SIZE][MAP_SIZE];
int main(int argc, char* argv[]){
    int i, firstLine=-1;
    int row, col,tLine,count,j,k, wordSize;


    /*file pointer*/

    FILE *fPtr = NULL;

    char buf[BUFFER_SIZE] = {0};

    /*There has to be more than one argument*/
    if (argc != 1)
        fPtr= fopen(argv[1], "r");

    /*We have to see if the file actually exists*/
    if(fPtr == NULL){
        printf("File cannot be opened. \n");
        return 0;
    }

    for(row=0;row < MAP_SIZE; row++){
        for (col = 0; col < MAP_SIZE; col++){
            anothaOne[row][col] = ' ';
        }
    }
 /*Reading in the information*/
    while(fgets(buf,sizeof buf, fPtr) != NULL) {
        /* printf("%s", buf);*/

        if(firstLine == -1){
            while(buf[j] != '\n'){
                j++;
            }
            tLine = j;
            j=0;
            firstLine=0;
        }

        if (i>= tLine/2){
            for (k=0; k< sizeof(buf); k++){
                if(buf[k] == '\n')
                    break;
            }
            for(row=0; row< tLine; row++){
                for(col=0; col < tLine; col++){
                    checkRT(buf,row ,col, wordSize, tLine,0);
                    checkLT(buf,row ,col, wordSize, tLine,0);
                    checkUP(buf,row ,col, wordSize, tLine,0);
                    checkDN(buf,row ,col, wordSize, tLine,0);
                    checkDNR(buf,row ,col, wordSize, tLine,0);
                    checkDNL(buf,row ,col, wordSize, tLine,0);
                    checkUPR(buf,row ,col, wordSize, tLine,0);
                    checkUPL(buf,row ,col, wordSize, tLine,0);        }
            }
        }
        else{
            for (count = 0; count < tLine +1; count++){
                if(buf[count] == '\n')
                    break;
                else
                    temp[i][count] = buf[count];

            }
        }

        i++;
    }
 for(j = 0; j < tLine/2; j++){
        for(k = 0; k <tLine; k++){
            if(anothaOne[j][k] == '\n')
                break;
            printf("%c", anothaOne[j][k]);
        }
        printf("\n");
    }

    fclose(fPtr);

    return 0;
}
/*check to right of*/
int checkRT(char *word, int a, int b, int wSize, int lSize, int x){
    /*is this letter the same as the one in the search*/
    if(word[x] == temp[a][b]){
        if(temp[a][b+2] !='\n'){

            /*recursive call*/
            if (checkRT(word, a, b+2, wSize, lSize, x+1)==1|| (x+1)== wSize)
            {
                anothaOne[a][b]= temp[a][b];
                return 1;
            }

        }
    }
    else
        return 0;
    return 0;

}

/*check to left of*/
int checkLT(char *word, int a, int b, int wSize, int lSize, int x){
    if(word[x] == temp[a][b]){
        if((b-2)>=0){

            if (checkLT(word, a, b-2, wSize, lSize, x+1)==1|| word[x+1] == '\n'){
                anothaOne[a][b] = temp[a][b];
                return 1;
            }
        }
    }
else
        return 0;
    return 0;
}

/*check upwards*/
int checkUP(char *word, int a, int b, int wSize, int lSize, int x){
    if(word[x] == temp[a][b]){
        if((a-1)>=0){

            if (checkUP(word, a-1, b, wSize, lSize, x+1)==1|| word[x+1] =='\n')
            {
                anothaOne[a][b] = temp[a][b];
                return 1;
            }
        }
    }
    else
        return 0;
    return 0;
}
/*check downwards*/
int checkDN(char *word, int a, int b, int wSize, int lSize, int x){
    if(word[x] == temp[a][b]){
        if((a+1) <= lSize/2){

            if (checkDN(word, a-1, b, wSize, lSize, x+1)==1|| word[x+1] == '\n')
            {
                anothaOne[a][b] = temp[a][b];
                return 1;
            }
        }
    }
    else
        return 0;
    return 0;
}
/*check down right*/
int checkDNR(char *word, int a, int b, int wSize, int lSize, int x){
    if(word[x] == temp[a][b]){
        if((a+1) <= lSize/2 && temp[a][b+2] !='\n'){

            if (checkDNR(word, a-1, b+2, wSize, lSize, x+1)==1|| word[x+1] =='\n')
            {
                anothaOne[a][b] = temp[a][b];
                return 1;
            }
        }
    }
    else
        return 0;
    return 0;
}
/*check down left*/
int checkDNL(char *word, int a, int b, int wSize, int lSize, int x){
    if(word[x] == temp[a][b]){
        if((a+1) <= lSize/2 && (b-2) >=0){

            if (checkDNL(word, a-1, b-2,wSize, lSize, x+1)==1 || word[x+1] == '\n')
            {
                anothaOne[a][b] = temp[a][b];
                return 1;
            }
        }
    }
    else
        return 0;
return 0;
}
/* check up right*/
int checkUPR(char *word, int a, int b, int wSize, int lSize, int x){
    if(word[x] == temp[a][b]){
        if((a-1) >= 0 && temp[a][b+2]!= '\n'){

            if (checkUPR(word, a+1, b+2, wSize, lSize, x+1)==1|| word[x+1] == '\n')
            {
                anothaOne[a][b] = temp[a][b];
                return 1;
            }
        }
    }
    else
        return 0;
    return 0;
}
/*check up left*/
int checkUPL(char *word, int a, int b, int wSize,  int lSize, int x){
    if(word[x] == temp[a][b]){
        if((a-1) >=0 && (b-2) >=0){


            if (checkUPL(word, a+1, b-2, wSize, lSize, x+1)==1|| word[x+1] == '\n')
            {
                anothaOne[a][b] = temp[a][b];
                return 1;
            }
        }
    }
    else
        return 0;
    return 0;
}
