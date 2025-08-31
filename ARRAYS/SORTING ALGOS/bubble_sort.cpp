//TODO : BUBBLE SORT 
// complexity - O(n^2)
#include<iostream>
using namespace std;
void bubble_sort(int array[],int size);
void display(int* array,int size);

int main()
{int array[5]={1,0,-10,100,50};
bubble_sort(array,5);
display(array,5);
    return 0;
}
//- BUBBLE SORT DEFINITION :  
void bubble_sort(int array[],int size){
    int pass=0;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            cout<<i<<" "<<j<<endl;
            if(array[j]>array[j+1]){
                int temp=array[j];
                    array[j]=array[j+1];
                array[j+1]=temp;
                pass++;
                cout<<" array after "<<pass<<" pass is :";
                display(array,size);
                
            }
        }
    }display(array,size);
}


//- DISPLAY FUNCTION DEFINITION
void display(int* array,int size){
    for(int i=0;i<size;i++){
        if(i==0){cout<<"[ "<<array[i]<<", ";}
            else if(i==size-1){cout<<array[i]<<" ]"<<endl;}
        else{cout<<array[i]<<", ";}
    }
}