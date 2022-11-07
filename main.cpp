/* Authors: Clinton Nguyen (cdn0116), Manuel Osorto (meo0106), Aaron Millman (amm1076), Jaxon Olson (jco0120)
   Instructor:  Shrestha
   Description: CSCE 1030 Project 02
*/

#include "main.h"

const int ROWS = 10;
const int COLUMNS = 10;

bool IsWrongFormat(string email)
{

    return false;
}

void initialize(int arr[][COLUMNS], int rows, int columns, int num = -1)
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
    return false;
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
void checkGuess(int& guessX, int& guessY, int userRow, int userCol, bool match = true)
{
    while(guessX >= userRow || guessY >= userCol || guessX < 0 || guessY < 0)
    {
        cout << "Co-ordinates are out of range." << endl;
        if(match)
        {
            cout << "Select co-ordinates to match: ";
        }
        else
        {
            cout << "Enter co-ordinates to reveal: ";
        }
        scanf("%d %d", &guessX, &guessY);
    }
}

int main()
{
    int num_array[ROWS][COLUMNS];
    int disp_array[ROWS][COLUMNS];
    int repeat_array[ROWS][COLUMNS];

    string email;

    cout << "Enter your email: ";
    cin >> email;
    while(IsWrongFormat(email))
    {
        cout << "Your email is not in correct format. Please enter again." << endl;
        cout << "Enter your email: ";
        cin >> email;
        break;
    }

    int userRow;
    int userCol;
    cout << "Enter rows and columns of the matrix: ";
    scanf("%d %d", &userRow, &userCol);
   
    checkSize(userRow, userCol);

    initialize(num_array, userRow, userCol, 1);
    initialize(disp_array, userRow, userCol);
    initialize(repeat_array, userRow, userCol);

    display(disp_array, userRow, userCol);

    int points = 10;

    do
    {
        cout << "Enter co-ordinates to reveal: ";
        int i, j;
        scanf("%d %d", &i, &j);
        checkGuess(i, j, userRow, userCol, false);
        disp_array[i][j] = num_array[i][j];
        int revealedNum = disp_array[i][j];
        display(disp_array, userCol, userCol);
        repeat_array[i][j] = 1;

        cout << "Select co-ordinates to match: ";
        int guessX, guessY;
        scanf("%d %d", &guessX, &guessY);
        checkGuess(guessX, guessY, userRow, userCol);
        while(checkRepeat(repeat_array,guessX, guessY))
        {
            cout << "You have already entered these co-ordinates. Please enter again." << endl;
            cout << "Select co-ordinates to match: ";
            scanf("%d %d", &guessX, &guessY);
        }
        if (num_array[guessX][guessY] == revealedNum)
        {
            cout << "You found a match." << endl;
            points+= 2;
            disp_array[guessX][guessY] = num_array[guessX][guessY];
            display(disp_array,userRow, userCol);
        }
        else
        {
            cout << "It does not match" << endl;
            points--;
        }
        cout << "Points balance: " << points << endl;
        char retry;
        if (points != 0)
        {
            cout << "Make another guess? Y/N: ";
            cin >> retry;
            retry = toupper(retry);
        }
        else
        {
            cout << "You have run out of points." << endl;
            cout << "Game over." << endl;
            exit(0);
        }
        if(retry == 'Y')
        {
            continue;
        }
        else
        {
            cout << "You have " << points << " points remaining." << endl;
            cout << "Your results will be emailed to you at " << email << "." << endl;
            cout << "Goodbye!!!" << endl;
            exit(0);
        }
    }
    while(true);
}
