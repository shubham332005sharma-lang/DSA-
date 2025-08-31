#include<iostream>
using namespace std;
void display(int** array,int rows,int cols);
int main()
{int rows,cols;
    cout<<" Enter number of rows : ";
    cin>>rows;
    cout<<" Enter number of cols : ";
    cin>>cols;

    //array to hold pointers of each array
    int** array= new int*[rows];
    // declaring each row (having size as cols)
    for(int i=0;i<rows;i++){
        array[i]=new int[cols];
    }
   

    //insert elements :
    int holder;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<" Enter element to be inserted at :["<<i+1<<"]["<<j+1<<"] position :";
            cin>>holder;
            array[i][j]=holder;
        }
    }
    display(array,rows,cols);

    //free space 
    for(int i=0;i<rows;i++){
        delete[] array[i];
    }
    delete[] array;
return 0;
} 
//- DISPLAY FUNCTION DEFINITION :
void display(int** array,int rows,int cols){
    for(int i=0;i<rows;i++){
        cout << "[ ";
for (int j = 0; j < cols; j++) {
    cout << array[i][j];
    if (j < cols - 1) cout << ", ";}
    cout << " ]" << endl;
    }
    
}