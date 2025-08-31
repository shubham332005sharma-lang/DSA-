//TODO :- MANUALLY RESIZE THE DYNAMIC ARRAYS
// this is done in these steps :
// i)                   Create a new array of larger size .
// ii)                  Copy the elements from old to new .
// iii)                 delete the old array .
// iv)                  change pointer to point to new array .
#include <iostream>
using namespace std;
// function prototypes 
void display(int* array,int size);
void insert_elements(int* array,int size);
void copy(int* array_1 , int* array_2 ,int size_1 );



int main(){
int size;
cout<<"ENTER SIZE OF THE ARRAY :";
cin>>size;
int size_new=size*2;
int* array= new int[size]; 
insert_elements(array,size);
cout<<"Original array is : ";
display(array,size);

// creating new array :
int* new_array = new int[size_new];

// copying elements :
copy(array,new_array,size);

// displaying new array:
cout<<"Copied array is  :  ";
display(new_array,size);

// deleting old array
delete[] array;

// fixing pointer to point to new array and delteing array
array=new_array;


// displaying array
cout<<"Checking if array* points to new array : ";
display(array,size);

delete[] array;
return 0;
}




//- COPY FUNCTION DEFINITION :-
void copy(int* array_1 , int* array_2 ,int size_1 ){
    for(int i=0;i<size_1;i++){
        array_2[i]=array_1[i];
    }
}


//- DISPLAY FUNCTION DEFINITION
void display(int* array,int size){
    for(int i=0;i<size;i++){
        if(size==1){cout<<"{ "<<array[i]<<" }"<<endl;}
        else if(i==0){cout<<"{ "<<array[i]<<", ";}
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