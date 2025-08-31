// TODO : MERGE TWO SORTED ARRAYS INTO A SINGLE SORTED ARRAY .
// ITS USEFUL FOR QUICK AND MERGE SORT.
#include<iostream>
using namespace std;

void display(int* array,int size);
int* merge(int* array1,int* array2, int size1 , int size2);


int main()

{   int size1,size2;
    cout<<" enter size of first array : ";
    cin>>size1;
    cout<<" enter the size of second array : ";
    cin>>size2; 
    int* array1= new int[size1];
    int* array2= new int[size2];

    // taking inputs :- 
    for(int i=0;i<size1;i++){
        cout<<" ENTER ELEMENTS OF ARRAY 1: ";
        cin>>array1[i];
    }
    for(int i=0;i<size2;i++){
        cout<<" ENTER ELEMENTS OF ARRAY 2: ";
        cin>>array2[i];
    }
    // calling merge function :
    int result_size=size1+size2;
    int* merged_array=merge(array1,array2,size1,size2);
    display(merged_array,result_size);
    
    // freeing space 
    delete[] array1;
    delete[] array2;
    delete[] merged_array;
    return 0;
}
//- display function definition :
void display(int* array,int size){
    for(int i=0;i<size;i++){
        if(i==0){cout<<"[ "<<array[i]<<", ";}
        else if(i==size-1){cout<<array[i]<<" ]"<<endl;}
        else{cout<<array[i]<<", ";}
    }
}

//- MERGE FUNCTION DEFINITION :
int* merge(int* array1,int* array2, int size1 , int size2){
    int* result = new int[size1+size2];
    int i=0; // pointer used for first array .
    int j=0; // pointer used for second array .
    int k=0;
    while(i<size1 && j<size2){
        if(array1[i]<=array2[j]){
            result[k]=array1[i];
            k++;
            i++;
        }else{
            result[k]=array2[j];
            k++;
            j++;
        }
    }
    while(j<size2){
            result[k]=array2[j];
            j++;
            k++;
        }
    while(i<size1){
        result[k]=array1[i];
            i++;
            k++;}
    
    return result;
    
    }
    
