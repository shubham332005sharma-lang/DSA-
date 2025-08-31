//TODO : implement SPARSE matrices in c++
//sparse matrix - a matrix having a large number of 0 entries as compared to non zero ones . usually these matrices will take so much space to store all non_zeroes so what we do is we compress them by only storing non zero elements and their location in a separate 2d array , this can also be implemented using linked lists (we will do it once we reach :).
#include<iostream>
using namespace std;
void display(int** array, int rows , int cols);
int count_non_zeroes(int** sparse,int rows,int cols);
int main()
{   // taking number of rows and columns for sparse matrix as inputs:
    int rows,cols;
    cout<<" enter number of rows : ";
    cin>>rows;
    cout<<" enter number of columns :"; 
    cin>>cols;

    // creating 2d array 
    int** matrix= new int*[rows];
    for(int i =0;i<rows;i++)
        matrix[i]=new int[cols];

    // taking elements as inputs;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cin>> matrix[i][j];
    display(matrix,rows,cols);

    // creaating sparse matrix array:
    int non_zeroes =count_non_zeroes(matrix,rows,cols);
    int** sparse=new int*[non_zeroes];
    for(int i=0;i<non_zeroes;i++){
        sparse[i]=new int[3];
    }
    // final step
    int step_row=0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            if(matrix[i][j]!=0){
               sparse[step_row][0]=i;
               sparse[step_row][1]=j;
               sparse[step_row][2]=matrix[i][j];
               step_row++;
            }
        }
    cout<<endl;
    cout<<"**************************"<<endl;
    cout<<"[ rows | columns | value ]"<<endl;
    display(sparse,non_zeroes,3);
    for(int i=0;i<rows;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    for(int i=0;i<non_zeroes;i++){
        delete[] sparse[i];
    }
    delete[] sparse;
    return 0;
}
//- DISPLAY FUNCTION DEFINITION :
void display(int** array , int rows, int cols){
    for(int i=0;i<rows;i++){
        cout<<"[";
        for(int j=0;j<cols;j++){
            cout<<array[i][j]<<" ";}
        cout<<"]"<<endl;
    }
}

//- NONZERO COUNT DEFINITION : 
int count_non_zeroes(int** sparse,int rows,int cols){
    int count=0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            if(sparse[i][j]!=0){
                count++;
            }
        }
        return count;
}