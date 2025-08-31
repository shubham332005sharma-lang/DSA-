//TODO : SELECTION SORT 
#include<iostream>
using namespace std;
void selection_sort(int array[],int size);
void display(int* array,int size);
int find_min(int array[],int size,int start);

int main()
{int array[5]={-1,-1,-10,-100,-1000};
selection_sort(array,5);
display(array,5);
    return 0;
}




//- selection SORT DEFINITION :  
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