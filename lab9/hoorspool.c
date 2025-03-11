#include<stdio.h>
#include<string.h>
#define ALPHABET_SIZE 256

int Table[ALPHABET_SIZE];

void shiftTable(char pattern[]) {
    int pLen = strlen(pattern);
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        Table[i] = pLen;
    }
    
    for (int i = 0; i < pLen - 1; i++) {
        Table[(unsigned char)pattern[i]] = pLen - i - 1;
    }
}


int horspool(char pattern[], char text[], int pLen, int tLen){
    
    shiftTable(pattern);  

    int i = pLen - 1;

    while (i <= tLen - 1) {
        int k = 0;

        while (k <= pLen - 1 && pattern[pLen - 1 - k] == text[i - k]) {
            k++;
        }

        if (k == pLen) {
            return i - pLen + 1;  
        } else {
            i += Table[(unsigned char)text[i]];
        }
    }

    return -1; 
}

void main(){

    char p[100], t[100];

    printf("Enter the pattern:");
    scanf("%s", p);

    printf("Enter the text:");
    scanf("%s", t);

    int pLen=strlen(p);
    int tLen=strlen(t);

    int pos=horspool(p,t,pLen,tLen);
    pos++;

    if(pos!=-1){
        printf("Substring found at position:%d.\n",pos);
    }
    else{
        printf("Substring not found. \n");
    }

}