//TODO : insertion SORT 
// complexity - O(n^2)
#include<iostream>
using namespace std;
void insertion_sort(int array[],int size);
void display(int* array,int size);

int main()
{int array[5]={1,0,-10,100,50};
insertion_sort(array,5);
display(array,5);
    return 0;
}
//- insertion SORT DEFINITION :  
void insertion_sort(int array[],int size){
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;/* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}


//- DISPLAY FUNCTION DEFINITION
void display(int* array,int size){
    for(int i=0;i<size;i++){
        if(i==0){cout<<"[ "<<array[i]<<", ";}
            else if(i==size-1){cout<<array[i]<<" ]"<<endl;}
        else{cout<<array[i]<<", ";}
    }
}