#include "he.h"
void deleteArr(void)
{
    for (int i = 0; i < arrX; i++)
        for (int j = 0; j < arrY; j++)
            Arr[i][j] =  0;
}
void randArr(void)
{
    srand(time(NULL));
    for (int ii = 0; ii < arrX; ii++)
        for (int jj = 0; jj < arrY; jj++)
            Arr[ii][jj] =  !(rand() % 10);
}
Arr2d saveArr(void)
{
    Arr2d savedArr;
    for (int ii = 0; ii < arrX; ii++)
        for (int jj = 0; jj < arrY; jj++)
            savedArr[ii][jj] =   Arr[ii][jj];
            return savedArr;
}
void loadArr(Arr2d arrsave)
{
    for (int ii = 0; ii < arrX; ii++)
        for (int jj = 0; jj < arrY; jj++)
            Arr[ii][jj] =   arrsave[ii][jj];
}
void recalc_array(void)
{
    int ArrT[arrX][arrY];
    for (int i = 0; i < arrX; i++)
        for (int j = 0; j < arrY; j++)
        {
            int cter = 0;
            for (int i1 = -1; i1 <= 1; i1++)
                for (int j1 = -1; j1 <= 1; j1++)
                {
                    if (i+i1 > -1 && j+j1 > -1 && i+i1 < arrX + 1 && j+j1 < arrY + 1) //array bounds
                        if (Arr[i+i1][j+j1])
                            if (!(i1 == 0 && j1 == 0))
                                cter++;
                }
            //    cout << cter << " ";
            switch (cter)
            {
            case 3 :
                ArrT[i][j] = 1;
                break;
            case 2 :
            {
                if (Arr[i][j] == 1)
                    ArrT[i][j] = 1;
                else ArrT[i][j] = 0;
            }
            break;
            default :
                ArrT[i][j] = 0;
            }
        }
    for (int i = 0; i < arrX; i++)
        for (int j = 0; j < arrY; j++)
            Arr[i][j] = ArrT[i][j];
}

