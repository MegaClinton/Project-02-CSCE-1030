#include "main.h"

void display(int arr[][COLUMNS], int userRow, int userCol)
{
    for(int i=0;i<userRow;++i)
    {
        for( int j=0;j<userCol;++j)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl; 
    }
}
