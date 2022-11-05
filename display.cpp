#include "main.h"

void display(int arr[][COLUMNS])
{
    for(int i=0;i<ROWS;++i)
    {
        for( int j=0;j<COLUMNS;++j)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl; 
    }
}
