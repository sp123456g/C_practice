#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        int minRow, maxRow,minCol,maxCol;
    
        for(int i=0;i<n/2;i++){
            minRow  = i;
            minCol  =i;
            maxRow  = n-i-1;
            maxCol  = n-i-1;

            for(int kk=minRow,jj=0;kk<maxRow;kk++,jj++){
                temp = matrix[minRow][minCol+jj];
                matrix[minRow][minCol+jj] = matrix[maxRow-jj][minCol];
                matrix[maxRow-jj][minCol] = matrix[maxRow][maxCol-jj];
                matrix[maxRow][maxCol-jj] = matrix[minRow+jj][maxCol];
                matrix[minRow+jj][maxCol] = temp;
            }
        }
    }
};

void printMatrix(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    for(int i = 0 ; i < n;++i)
    {
        for(int j = 0 ; j < n;++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<std::vector<int>> matrix {
				{ 1, 2, 3, 4 },
				{ 5, 6, 7, 8 },
				{ 9, 10, 11, 12 },
				{ 13, 14, 15, 16 }
			};

    printMatrix(matrix);
    printf("\n");
    Solution s;
    s.rotate(matrix);
    printMatrix(matrix);

    return 0;
}
