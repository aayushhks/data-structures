//
// Created by Aayush Kumar on 16/09/23.
//

#include <stdio.h>
#include <string.h>

void printFrequency(int freq[]) {
    for (int i = 0; i < 52; i++) {
        if (freq[i] != 0)
            printf("%c - %d\n", i + 'a', freq[i]);
    }
}

void findFrequency(char A[]){
    int i = 0; int freq[52] = { 0 };
    while (A[i] != NULL) {
        freq[A[i] - 'a']++;
        i++;
    }
    printFrequency(freq);
}

int main(){
    char A[100] = "aayush"; findFrequency(A);
}

