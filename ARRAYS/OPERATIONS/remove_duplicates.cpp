//TODO :  REMOVING DUPLICATE ELEMENTS FROM AN ARRAY 
//removing elements from the end of an array is a constant complexity function O(1).
//removing elemnets from anywhere else is a linear complexity O(n) task as you will have to shift each element after that element to one place left .
//      { 1   1    3    4    5    6 } removing 1 from here we will have to 
//      { 1    <-3  <-4  <-5  <-6    }

#include<iostream>
using namespace std;
//function prototypes :
void reduce(int& size);
void remove(int array[],int& size,int index);
void display(int* array,int size);
void remove_duplicates(int array[],int& size);
void sort(int array[],int size);


int main() 
{   int size=10;
    int array[size]={10,9,10,9,10,9,1,1,-1,-2};
    cout<<"Array before removal is : ";
    display(array,size);
    //removing the element :
    sort(array,size) ;
    remove_duplicates(array,size);
    cout<<"Array after removal is : ";
    display(array,size);
    return 0;
}
//- SORT FUNCTION DEFINITION :
void sort(int array[],int size){
    if(size<2){cout<<"Array already sorted ."<<endl; return;}
    int temp;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(array[i]>array[j]){
                temp=array[j];
                array[j]=array[i];
                array[i]=temp;
            }
        }
    }
}
//- REMOVE DUPLICATES DEFINI9TION : 
void remove_duplicates(int array[],int& size){
    for(int i=0;i<size-1;i++){
        if(array[i]==array[i+1]){
            remove(array,size,i+1);
            i--;
        }
    }
};

//- REMOVE FUNCTION DEFINITION :
void remove(int array[],int& size, int index){
    if((index >= size || index < 0 || size <= 0)){
        cout<<"INVALID ARGUMENTS : either size or index is incorrect "<<endl;
    }else{
    cout<<"Element at index ["<<index<<"] , value : "<<array[index]<<"    Removed successfully <3 "<<endl;
    for(int i=index;i<size-1;i++){
        array[i]=array[i+1];
    }
    //calling reduce size to reduce size by pass by reference
    reduce(size);}
}
//- REDUCE SIZE FUNCTION DEFINITION :
void reduce(int& size){
    if(size>0){
    size--; }else{
        cout<<" Array size already 0, hence cant be reduced ."<<endl;
    };
}

//- DISPLAY FUNCTION DEFINITION
void display(int* array,int size){
    if(size==1){cout<<"{ "<<array[0]<<" }"<<endl;return;}
    if(size!=0){
    for(int i=0;i<size;i++){
       
        if(i==0){cout<<"{ "<<array[i]<<", ";}
        else if(i==size-1){cout<<array[i]<<" }"<<endl;}
        else{cout<<array[i]<<", ";};}
    }else{cout<<"{ }"<<endl;}
    }
       