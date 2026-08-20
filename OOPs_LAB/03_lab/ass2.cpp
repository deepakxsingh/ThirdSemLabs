#include <iostream>
using namespace std;

class Matrix
{
    int a[10][10];
    int rows, columns;

public:

    // Function to take matrix input
    void input()
    {
        cout << "Enter number of rows: ";
        cin >> rows;

        cout << "Enter number of columns: ";
        cin >> columns;

        cout << "Enter matrix elements:\n";

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    // Function to multiply two matrices
    Matrix multiply(Matrix m)
    {
        Matrix result;

        result.rows = rows;
        result.columns = m.columns;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m.columns; j++)
            {
                result.a[i][j] = 0;

                for (int k = 0; k < columns; k++)
                {
                    result.a[i][j] =
                        result.a[i][j] + a[i][k] * m.a[k][j];
                }
            }
        }

        return result;
    }

    // Function to display matrix
    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << a[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Matrix m1, m2, result;

    cout << "Enter first matrix:\n";
    m1.input();

    cout << "\nEnter second matrix:\n";
    m2.input();

    result = m1.multiply(m2);

    cout << "\nResult of matrix multiplication:\n";
    result.display();

    return 0;
}