#include<iostream>
using namespace std;
void display(int** array,int rows,int cols);
void matrix_multi(int**array ,int rows ,int cols,int** array2, int rows2,int cols2);
void addition(int** array ,int rows ,int cols,int**array2,int rows2,int cols2);
void subtract(int** array ,int rows ,int cols,int**array2,int rows2,int cols2);
int main()
{int rows,cols;
    cout<<" Enter number of rows of first matrix : ";
    cin>>rows;
    cout<<" Enter number of cols of first matrix : ";
    cin>>cols;
    int rows2,cols2;
    cout<<" Enter number of rows of second matrix : ";
    cin>>rows2;
    cout<<" Enter number of cols of second matrix : ";
    cin>>cols2;

    //array to hold pointers of each array
    int** array= new int*[rows];
    int** array2= new int*[rows2];
    // declaring each row (having size as cols)
    for(int i=0;i<rows;i++){
        array[i]=new int[cols];
    }
    for(int i=0;i<rows2;i++){
        array2[i]=new int[cols2];
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
    cout<<"***************************************************"<<endl;
    int holder2;
    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            cout<<" Enter element to be inserted at :["<<i+1<<"]["<<j+1<<"] position :";
            cin>>holder2;
            array2[i][j]=holder2;
        }
    }

    cout<<"MATRIX A IS =>"<<endl;
    display(array,rows,cols);
    cout<<endl;

    cout<<"MATRIX B IS =>"<<endl;
    display(array2,rows2,cols2);
    cout<<"***************************************************"<<endl;
    addition(array,rows,cols,array2,rows2,cols2);
    subtract(array,rows,cols,array2,rows2,cols2);
    






    for(int i=0;i<rows;i++){
        delete[] array[i];
       
    }
    delete[] array;
    for(int i=0;i<rows2;i++){
        delete[] array2[i];
       
    }
    delete[] array2;
   
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

//- MULTIPLICATION FUNCTION DEFINITION : 
void matrix_multi(int**array ,int rows ,int cols,
                  int** array2, int rows2,int cols2)
{   int intermediate=0;
    if(cols!=rows2){cout<<"Matrices cant be multiplied ."<<endl; return;}
    int** result=new int*[rows];
    for(int i=0;i<rows;i++){
        result[i]=new int[cols2];
    }
     for(int i=0;i<rows;i++){
        for(int j=0;j<cols2;j++){
            for(int k=0;k<cols;k++){
                intermediate+=array[i][k]*array2[k][j];
                if(k==cols-1){result[i][j]=intermediate;
                intermediate=0;}
            }
            
        }
     }
    cout<<endl;
    cout<<"***************************************************"<<endl;
    cout<< "A X B =>"<<endl;
     display(result,rows,cols2);
    for(int i=0;i<rows;i++){
        delete[] result[i];
    }
    delete[] result;

}
//- MATRIX ADDITION DEFINITION : 
void addition(int** array ,int rows ,int cols,int**array2,int rows2,int cols2){
    if(rows!=rows2 || cols!=cols2 ){cout<<"Matrix addition not possible as order of two matrices are different. "<<endl; return;}
    int** result=new int*[rows];
    for(int i=0;i<rows;i++){
        result[i]=new int[cols2];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j]=array[i][j]+ array2[i][j];
        }
    }
    cout<<endl;
    cout<<"***************************************************"<<endl;
    cout<< "A + B =>"<<endl;
    display(result,rows,cols);
    for(int i=0;i<rows;i++){
        delete[] result[i];
    }
    delete[] result;

}
//- MATRIX SUBTRACTION DEFINITION : 
void subtract(int** array ,int rows ,int cols,int**array2,int rows2,int cols2){
    if(rows!=rows2 || cols!=cols2 ){cout<<"Matrix addition not possible as order of two matrices are different. "<<endl; return;}
    int** result=new int*[rows];
    for(int i=0;i<rows;i++){
        result[i]=new int[cols2];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j]=array[i][j]- array2[i][j];
        }
    }
    cout<<endl;
    cout<<"***************************************************"<<endl;
    cout<< "A - B =>"<<endl;
    display(result,rows,cols);
    for(int i=0;i<rows;i++){
        delete[] result[i];
    }
    delete[] result;

}