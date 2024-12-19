#include <stdio.h>

int binarySerach(int arr[] , int size ,int target){
    int sol=0,sag=size-1,orta;
    while(sol<=sag){
        orta=sol+(sag-sol)/2;
        if(arr[orta]==target){
            return orta;
        }
        if(arr[orta]>target) {
            sag=orta-1;
        }
        else{
            sol=orta+1;
        }
        return -1;
    }
}
    void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        
    }
}
}    
    int main (){
        int arr[5];
        arr[0]=5;
        arr[1]=14;
        arr[2]=10;
        arr[3]=2;
        arr[4]=21;
    bubbleSort(arr,5);
    printf("Hedef %d dizinin %d. index ", 10 ,binarySerach(arr,5,10));

    return 0;        
    }


