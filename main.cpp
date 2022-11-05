/* Authors: Clinton Nguyen (cdn0116), Manuel Osorto (meo0106), Aaron Millman (amm1076), Jaxon Olson (jco0120)
   Instructor:  Shrestha
   Description: CSCE 1030 Project 02
*/

#include "main.h"

const int ROWS = 10;
const int COLUMNS = 10;

bool IsWrongFormat(string email)
{

}

void intialize(int arr[][COLUMNS], int rows, int columns, int num = -1)
{
    srand((time(NULL)));
    if(num != -1)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                arr[i][j] = (rand() % 20) + 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                arr[i][j] = num;
            }
        }
    }
}

bool checkRepeat(const int arr[][COLUMNS], int i, int j)
{

}

void display(const int arr[][COLUMNS], int userRow, int userCol)
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

void checkSize(int& userRow, int& userCol)
{
       while(userRow > ROWS || userCol > COLUMNS || userRow <= 1 || userCol <= 1)
    {
        cout << "The number must be less than 11 and greater than 1" << endl;
        cout << "Enter rows and columns of the matrix: ";
        scanf("%d %d", &userRow, &userCol);
    }
}

int main()
{
    int num_array[ROWS][COLUMNS];
    int disp_array[ROWS][COLUMNS];

    string email;

    cout << "Enter your email: ";
    cin >> email;
    while(IsWrongFormat(email))
    {
        break;
    }

    int userRow;
    int userCol;
    cout << "Enter rows and columns of the matrix: ";
    scanf("%d %d", &userRow, &userCol);
   
    checkSize(userRow, userCol);

    intialize(num_array,userRow,userCol,1);
    intialize(disp_array,userRow,userCol);

    display(disp_array, userRow, userCol);

    int points = 10;



    return 0;
}
