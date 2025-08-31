// TODO: PLAY WITH 2D STATIC ARRAYS
// arrays can be multidimensional . it means that an array of arrays is possible . this is implemented using array[ 3 ][ columns ].
// useful for storing data in a grid fashion ex :- matrix operations ,chess , sudoku etc..
// useful for tabular data like spreadsheets.
// useful for storing image pixel values .
// maps , mazes , BFS , DFS , Djikstra etc.
#include<iostream>
using namespace std;
void display(int array[3][3]);

int main()
{
    int arr[3][3];

    //inserting elements :
    int holder;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<" Enter element to be inserted at :["<<i+1<<"]["<<j+1<<"] position :";
            cin>>holder;
            arr[i][j]=holder;
        }
    }

    // displaying entered array :
    display(arr);
    

    return 0;
}

//- DISPLAY FUNCTION DEFINITION :
void display(int array[3][3]){
    for(int i=0;i<3;i++){
        cout<<"[";
        for(int j=0;j<3;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }

    
}