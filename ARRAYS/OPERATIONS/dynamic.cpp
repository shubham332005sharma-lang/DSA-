//TODO : PLAY WITH ARRAYS 
// ARRAY - It is a linear data structure which stores elements in a contiguous memory location that are accessible with indexs. 
// THERE ARE TWO TYPES OF ARRAYS MAJORLY -  Static and Dynamic arrays

// Dynamic arrays:- 1) resizable manual resizing
//                  2) stored in heaps
//                  3) they are used when the size of the array is unknown at the compile time 
//                  4) they do allow VLA (variable length arrays , they work only beacause of the compiler or g++).
//                  5) they need manual memory allocation using new and delete[] 
//                  6) random access allowed with index.
//                  7) suitable for frequent resizing.

#include <iostream>
using namespace std;
void display(int* array,int size);
void insert_elements(int* array,int size);
int main(){

// DECLARING A DYNAMIC ARRAY 
int size;
cout<<" ENTER SIZE OF THE ARRAY :";
cin>>size;
int* array= new int[size]; // new keyword is used for new memory allocation

// INSERTING ELEMENTS USING LOOP
insert_elements(array,size);

// DISPLAYING ARRAY ( TRAVERSING USING LOOP):
display(array,size);

// FREE SPACE USING - delete[]
delete[] array;
return 0;
}


//- DISPLAY FUNCTION DEFINITION
void display(int* array,int size){
    for(int i=0;i<size;i++){
        if(i==0){cout<<"{ "<<array[i]<<", ";}
        else if(i==size-1){cout<<array[i]<<" }"<<endl;}
        else{cout<<array[i]<<", ";}
    }
}

//- INSERT FUNCTION DEFINITION
void insert_elements(int* array,int size){
    cout<<"ENTER ELEMENTS OF THE ARRAY "<<endl;
    int holder;
    for(int i=0;i<size;i++){
        cout<<"Enter element number ->"<<i+1<<" :";
        cin>>holder;
        array[i]=holder;
    }
}