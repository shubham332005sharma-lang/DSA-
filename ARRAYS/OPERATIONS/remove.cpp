//TODO :  REMOVING ELEMENTS FROM AN ARRAY 
//removing elements from the end of an array is a constant complexity function O(1).
//removing elemnets from anywhere else is a linear complexity O(n) task as you will have to shift each element after that element to one place left .
//      { 1   2    3    4    5    6 } removing 2 from here we will have to 
//      { 1    <-3  <-4  <-5  <-6    }

#include<iostream>
using namespace std;
void reduce(int& size);
void remove(int array[],int& size,int index);
void display(int* array,int size);


int main() 
{   int size=6;
    int array[size]={1,2,3,4,5,6};
    cout<<"Array before removal is : ";
    display(array,size);
    //removing the element : 
    remove(array,size,5);
    remove(array,size,1);
    remove(array,size,0);



    cout<<"Array after removal is : ";
    display(array,size);
    return 0;
}


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
    if(size!=0){
    for(int i=0;i<size;i++){
        if(size==1){cout<<"{ "<<array[i]<<" }"<<endl;}
        else if(i==0){cout<<"{ "<<array[i]<<", ";}
        else if(i==size-1){cout<<array[i]<<" }"<<endl;}
        else{cout<<array[i]<<", ";};}
    }else{cout<<"{ }"<<endl;}
    }
       