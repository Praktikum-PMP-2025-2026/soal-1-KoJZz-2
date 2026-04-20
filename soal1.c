/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Nicholas L.M.Simarmata (13224060)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program yang merecover array yang hilang lalu menghitung maksimumnya
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void prints(int* array, int size){
    for(int i = 0; i < size; i++){
        printf("%d", array[i]);
    }
    printf("\n");
}

void display(int array[], int size){
    int sum = 0;
    printf("RECOVERED ");
    for(int i = 0; i < size; i++){
        printf("%d", array[i]);
        if (i != size-1) printf(" ");
        if(array[i] > 0) sum += array[i];
    }
    printf("\nMAX_SUM %d", sum);
}

int cari(int* array, int index, int size){
    int temp = 0; int temp1 = -1; int temp2 = -1;
    if (index != size-1){
        for(int i = index+1; i < size; i++){ // cek kanan
            if (array[i] != -1){
                temp1 = array[i];
                break;
            }
        }
        // printf("cek kanan, temp1: %d\n", temp1);
    }
    
    if (index != 0){
        for(int i = index-1; i >= 0; i--){
            if (array[i] != -1){
                temp2 = array[i];
                break;
            }
        }
        // printf("cek kiri, temp2: %d\n", temp2);
    }

    if (temp1 != -1 && temp2 != -1){
        temp = floor((temp1+temp2)/2);
    } else if (temp1 != -1) {
        temp = temp1;
    } else if (temp2 != -1) {
        temp = temp2;
    }
    // printf("temp: %d\n", temp);

    return temp;
}

void recovery(int array[], int size){
    for(int i = 0; i < size; i++){ // ganti dari kiri ke kanan
        // printf("index: %d;%d\n", i, array[i]);
        if(array[i] == -1){
            // printf("idnex: %d", i);
            // if(i == size-1){ //elemen terakhir
            //     if (array[i-1] != -1){
            //         array[i] = array[i-1];
            //     }
            // } else if (i != 0) { // tengah-tengah
            //     if (array[i+1] != -1 )
                
            // } else { // elemen pertama
                
            // } 
            // printf("cari: %d\n", cari(array, i, size));
            array[i] = cari(array, i, size);
        }
    }
    // prints(array, size);
}

void inputs(int* array, int* arrSize){
    scanf("%d ", arrSize);
    array = (int*) malloc(*arrSize * sizeof(int));

    for(int i = 0; i < *arrSize; i++){
        scanf("%d", &array[i]);
    }

    // prints(array, *arrSize);
 }


  
 int main() {
    // int* array; 
    int arrSize; 

    scanf("%d ", &arrSize);
    // array = (int*) malloc(*arrSize * sizeof(int));
    int array[arrSize];

    for(int i = 0; i < arrSize; i++){
        scanf("%d", &array[i]);
    }

    // prints(array, arrSize);

    // inputs(array, &arrSize);

    

    // printf("sizeL %d\n", arrSize);
    recovery(array, arrSize);
    display(array, arrSize);
  
 }
