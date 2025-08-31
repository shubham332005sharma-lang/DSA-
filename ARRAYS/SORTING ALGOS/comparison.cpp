//TODO : EMPERICAL STUDIES AND COMPARISON OF SORTING ALGOS USING CTIME LIBRARY.

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void copy_array(int* source, int* destination, int size) ;
void bubble_sort(int array[],int size);
void display(int* array,int size);
void insertion_sort(int array[],int size);
void selection_sort(int array[],int size);
int find_min(int array[],int size,int start);
int* quicksort(int* array,int start,int end);
int partition(int* array,int start,int end);
int* merge_sort(int* array, int size);
int* merge(int* array1, int* array2, int size1, int size2);



int main()
{   
    const int size = 10000;
    int array[size];

    // Fill array with random numbers
    for (int i = 0; i < size; ++i)
        array[i] = rand() % 100000;

    int array1[size], array2[size], array3[size],array4[size],array5[size];
    copy_array(array, array1, size);
    copy_array(array, array2, size);
    copy_array(array, array3, size);
    copy_array(array, array4, size);
    copy_array(array, array5, size);


clock_t start1=clock();
bubble_sort(array1,size);            
clock_t end1=clock();
double time1=double(end1-start1)/CLOCKS_PER_SEC;
cout<<" time taken by bubble sort is : "<<time1<<endl;


clock_t start2=clock();
insertion_sort(array2,size);
clock_t end2=clock();
double time2=double(end2-start2)/CLOCKS_PER_SEC;
cout<<" time taken by insertion sort is : "<<time2<<endl;


clock_t start3=clock();
selection_sort(array3,size);
clock_t end3=clock();
double time3=double(end3-start3)/CLOCKS_PER_SEC;
cout<<" time taken by selection sort is : "<<time3<<endl;

clock_t start4=clock();
int* result = merge_sort(array4, size);   
copy_array(result, array4, size);        
delete[] result;                        
clock_t end4=clock();
double time4=double(end4-start4)/CLOCKS_PER_SEC;
cout<<" time taken by merge sort is : "<<time4<<endl;


clock_t start5=clock();
quicksort(array5,0,size-1);
clock_t end5=clock();
double time5=double(end5-start5)/CLOCKS_PER_SEC;
cout<<" time taken by quick sort is : "<<time5<<endl;

// display(array1,size);
// display(array2,size);
// display(array3,size);
// display(result,size);
// display(array5,size);
    return 0;
}

//- BUBBLE SORT DEFINITION :  
void bubble_sort(int array[],int size){
    int pass=0;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                    array[j]=array[j+1];
                array[j+1]=temp;
                pass++;
            }
        }
    }
}
//- INSERTION SORT DEFINITION :  
void insertion_sort(int array[],int size){
    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

//- SELECTION SORT DEFINITION :
void selection_sort(int array[],int size){
    for(int i=0;i<size;i++){
        int min=find_min(array,size,i);
        int temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }
}

//- FIND MIN FUNCTION :
int find_min(int array[],int size,int start){
    int min=start;
    for(int i=start;i<size;i++){
        if(array[i]<array[min]){min=i;}
    }
    return min;
}


//- DISPLAY FUNCTION DEFINITION
void display(int* array,int size){
    for(int i=0;i<size;i++){
        if(i==0){cout<<"[ "<<array[i]<<", ";}
            else if(i==size-1){cout<<array[i]<<" ]"<<endl;}
        else{cout<<array[i]<<", ";}
    }
}


void copy_array(int* source, int* destination, int size){
    for(int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}
int* quicksort(int* array,int start,int end){
    if(start<end){
        int pivot=partition(array,start,end);
        quicksort(array,start,pivot-1);
        quicksort(array,pivot+1,end);
    }
        return array;
}

//- PARTITION FUNCTION DEFINITION -
// to place pivot in right place and get sizes of left and right half.
int partition(int* array,int start,int end){
    int index=start-1;
    int pivot=end;
    for(int j=start;j<end;j++){
        if(array[j]<array[pivot]){
            index++;
            swap(array[j],array[index]);

        }
    }
    index++;
    swap(array[index],array[pivot]);
    return index;
    // to place pivot in correct position ( so that we can get sizes of left and right half)
}

// Merge Sort function
int* merge_sort(int* array, int size) {
    if (size <= 1) {
        // Base case: copy the array and return
        int* single = new int[size];
        for (int i = 0; i < size; i++) {
            single[i] = array[i];
        }
        return single;
    }

    int mid = size / 2;

    // Create left and right subarrays
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    // Recursively sort both halves
    int* sorted_left = merge_sort(left, mid);
    int* sorted_right = merge_sort(right, size - mid);

    // Merge sorted halves
    int* merged = merge(sorted_left, sorted_right, mid, size - mid);

    delete[] sorted_left;
    delete[] sorted_right;

    return merged;
}

// Merge function
int* merge(int* array1, int* array2, int size1, int size2) {
    int* result = new int[size1 + size2];
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (array1[i] <= array2[j]) {
            result[k++] = array1[i++];
        } else {
            result[k++] = array2[j++];
        }
    }
    while (i < size1) {
        result[k++] = array1[i++];
    }
    while (j < size2) {
        result[k++] = array2[j++];
    }

    return result;
}


