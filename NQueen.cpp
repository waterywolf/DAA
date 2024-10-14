#include <iostream>
using namespace std;

int IsSafe(int Queen[][10], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (Queen[i][col] == 1) {
            return 0;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (Queen[i][j] == 1) {
            return 0;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (Queen[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}

int PlaceQueen(int Queen[][10], int n, int row) {
    if (n == row) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << Queen[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";
        return 1;
    }

    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (IsSafe(Queen, row, i, n) == 1) {
            Queen[row][i] = 1;
            flag = PlaceQueen(Queen, n, row + 1) || flag;
            Queen[row][i] = 0;
        }
    }

    return flag;
}

int main() {
    int n;
    cout << "Enter No. of Queens: ";
    cin >> n;

    int Queen[10][10] = {0};

    if (PlaceQueen(Queen, n, 0) == 1) {
        cout << "Solution Exists!!\n";
    } else {
        cout << "Oops! Solution Does not Exist!!\n";
    }

    return 0;
}
