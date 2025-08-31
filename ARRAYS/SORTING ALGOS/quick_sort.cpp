// TODO : QUICK SORT
#include<iostream>
void display(int* array,int size);
int* quicksort(int* array,int start,int end);
int partition(int* array,int start,int end);


using namespace std;
int main()
{   int size;
    cout<<" enter size of array :";
    cin>>size;

    int array[size];

    for(int i=0;i<size;i++){
        cout<<" enter elements for the array : ";
        cin>>array[i];
    }
    quicksort(array,0,size-1);
    display(array,size);
    return 0;
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

//- display function definition :
void display(int* array,int size){
    for(int i=0;i<size;i++){
        if(i==0){cout<<"[ "<<array[i]<<", ";}
        else if(i==size-1){cout<<array[i]<<" ]"<<endl;}
        else{cout<<array[i]<<", ";}
    }
}