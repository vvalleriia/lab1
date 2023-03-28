#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <math.h>
using namespace std;
const int MAX_SIZE = 200;



void Task1(int A[], int N)
{
    int B[MAX_SIZE], C[MAX_SIZE];
    for (int i = 0; i < N; i++)
    {
        printf("B[%d]: ", i);
        scanf_s("%d", &B[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        C[i] = A[i] * B[i];
        printf("C[%d]: %d\n", i, C[i]);
    }
}




void Task2(int A[], int N)
{
    int max, even;
    max = A[0];
    for (int i = 0; i < N; i++)
    {
        if (A[i] % 2 == 1)
        {
            even = i;
            break;
        }
        else
        {
            if (A[i] > max)
            {
                max = A[i];
            }
        }
    }
    if (even != 0)
    {
        printf("\nMaximum element: %d", max);
    }
    else
    {
        printf("\nNo parnyh elements before first neparny");
    }
}


double* Task3(int A[], int N)
{
    int bN = 0;
    double B[MAX_SIZE], discriminant;

    for (int i = 0; i < N; i++)
    {
        double root1 = -1, root2 = -1;
        discriminant = pow((3 * A[i]), 2) - 4 * 5;
        if (discriminant >= 0)
        {
            root1 = (-3 * A[i] + sqrt(discriminant)) / 2;
            root2 = (-3 * A[i] - sqrt(discriminant)) / 2;
        }
        if (root1 > 0 && root2 > 0)
        {
            B[bN++] = A[i];
        }
    }
    printf("\n");
    for (int i = 0; i < bN; i++)
    {
        printf("%0.2lf     ", B[i]);
        if (i % 5 == 4)
        {
            printf("\n");
        }
    }
    return B;
}


int MenuTask()
{
    int taskNumber;
retask:    printf("\nTasks:\n   Task 1: C[i] = A[i] * B[i]\n   Task 2: Max element\n   Task 3: Roots of ecuacion\nPres 4 to exit\n");
    printf("Enter task number you want to do: ");
    scanf_s("%d", &taskNumber);
    if (taskNumber > 4 || taskNumber < 1)
    {
        goto retask;
    }
    return taskNumber;
}
int MenuFunction()
{
    int functionNumber;
refunk:    printf("\nPossible functions:\n   Function 1: Input/Output from console to file\n   Function 2: Input array from console + Input random numbers to array + Output array to binary file\n   Function 3: Input/Output array from file to file to console\n   Function 4: InputOutput array from file to vector to console\n");
    printf("Enter function number you want to use: ");
    scanf_s("%d", &functionNumber);
    if (functionNumber > 4 || functionNumber < 1)
    {
        goto refunk;
    }
    return functionNumber;
}

//Функції введення масивів з консолі та запис масивів в текстовий файл(текстові файли);
void Funk1_Int(int taskNumber)
{
    int A[MAX_SIZE], B[MAX_SIZE], N;

resize:    printf("Enter N: ");
    scanf_s("%d", &N);
    if (N <= 0)
    {
        printf("N > 0!!!");
        goto resize;
    }
    for (int i = 0; i < N; i++)
    {
        printf("A[%d]: ", i);
        scanf_s("%d", &A[i]);
    }
    printf("\n");

    if (taskNumber == 1)
    {
        Task1(A, N);
    }
    else
    {
        Task2(A, N);
    }

    ofstream MyFile("file.txt");
    MyFile << N << endl;
    for (int i = 0; i < N; i++)
    {
        MyFile << A[i] << "   ";
    }
    MyFile.close();
}
void Funk1_Double()
{
    int N; int A[MAX_SIZE];
resize:    printf("Enter N: ");
    scanf_s("%d", &N);
    if (N <= 0)
    {
        printf("N > 0!!!");
        goto resize;
    }
    for (int i = 0; i < N; i++)
    {
        printf("A[%d]: ", i);
        scanf_s("%d", &A[i]);
    }

    double* B = Task3(A, N);

    ofstream MyFile("doublefile.txt");
    MyFile << N << endl;
    for (int i = 0; i < N; i++)
    {
        MyFile << B[i] << "   ";
    }
    MyFile.close();
}

//Функції введення розміру масиву(масивів) з консолі, створення масиву(масивів) з використанням датчика випадкових чисел та 
//запис масиву(масивів) в бінарний файл(бінарний файли);
int Size()
{
    int N;
resize:    printf("Enter N: ");
    scanf_s("%d", &N);
    if (N <= 0)
    {
        printf("N > 0!!!");
        goto resize;
    }
    return N;
}
int* Random_Int(int N)
{
    srand(time(0));
    int A[MAX_SIZE];
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 10;
        if (rand() % 2 == 1)
        {
            A[i] = -A[i];
        }
        printf("A[%d]: %d\n", i, A[i]);
    }
    return A;
}
double* Random_Double(int N)
{
    srand(time(0));
    double X[MAX_SIZE];
    for (int i = 0; i < N; i++)
    {
        X[i] = 100 * rand() / (1.0 + rand());
        if (rand() % 2 == 1)
        {
            X[i] = -X[i];
        }
        printf("A[%d]: %lf\n", i, X[i]);
    }
    return X;
}
void Funk2_Int(int taskNumber)
{
    int N = Size();
    int* A = Random_Int(N);

    if (taskNumber == 1)
    {
        Task1(A, N);
    }
    else
    {
        Task2(A, N);
    }

    ofstream MyFile("binary.dat", ios::out | ios::binary);
    for (int i = 0; i < N; i++)
    {
        MyFile.write((char*)&A[i], sizeof(int));
    }
    MyFile.close();
}
void Funk2_Double()
{
    int N = Size();
    int* A = Random_Int(N);
    double* B = Task3(A, N);

    ofstream MyFile("binary.dat", ios::out | ios::binary);
    for (int i = 0; i < sizeof(B); i++)
    {
        MyFile.write((char*)&B[i], sizeof(double));
    }
    MyFile.close();
}

//Функції розв’язання задач згідно варіанту з використанням динамічних масивів.
//Вхідні дані зчитаються з файлів, результати записуються в нові файли та виводиться в консоль.
void Funk3_Int(int taskNumber)
{
    int N;
    int* A = new int[MAX_SIZE];
    ifstream MyFile("file.txt");
    if (MyFile.fail()) return;
    MyFile >> N;
    if (N <= 0) return;
    double d;
    for (int i = 0; i < N; i++)
    {
        MyFile >> d;
        A[i] = d;
    }
    MyFile.close();

    if (taskNumber == 1)
    {
        Task1(A, N);
    }
    else
    {
        Task2(A, N);
    }

    ofstream AnotherFile("file.txt");
    AnotherFile << N << endl;
    for (int i = 0; i < N; i++)
    {
        AnotherFile << A[i] << "   ";
    }
    AnotherFile.close();
}
void Funk3_Double()
{
    int N;
    int* A = new int[MAX_SIZE];
    ifstream MyFile("file.txt");
    if (MyFile.fail()) return;
    MyFile >> N;
    if (N <= 0) return;
    double d;
    for (int i = 0; i < N; i++)
    {
        MyFile >> d;
        A[i] = d;
    }
    MyFile.close();

    double* B = Task3(A, N);

    ofstream AnotherFile("doublefile.txt");
    AnotherFile << N << endl;
    for (int i = 0; i < N; i++)
    {
        AnotherFile << B[i] << "   ";
    }
    AnotherFile.close();
}

//Функцію читає дані з файлів в контейнер (vector, valarray або array) та з контейнера дані виводиться в консоль.
void Funk4_Int(int taskNumber)
{
    ifstream MyFile("file.txt");
    if (MyFile.fail()) return;
    int N;
    double d;
    vector<int> vA;
    int A[MAX_SIZE];
    MyFile >> N;
    for (int i = 0; i < N; i++)
    {
        MyFile >> d;
        vA.push_back(d);
        A[i] = d;
    }
    MyFile.close();

    if (taskNumber == 1)
    {
        Task1(A, N);
    }
    else
    {
        Task2(A, N);
    }
}
void Funk4_Double()
{
    ifstream MyFile("file.txt");
    if (MyFile.fail()) return;
    int N;
    double d;
    vector<int> vA;
    int A[MAX_SIZE];
    MyFile >> N;
    for (int i = 0; i < N; i++)
    {
        MyFile >> d;
        vA.push_back(d);
        A[i] = d;
    }
    MyFile.close();

    double* B = Task3(A, N);
}


int main()
{
task:    int functionNumber = MenuFunction();
    system("cls");
    int taskNumber = MenuTask();
    system("cls");

    if (taskNumber == 1 || taskNumber == 2)
    {
        switch (functionNumber)
        {
        case 1:
            Funk1_Int(taskNumber);
            break;
        case 2:
            Funk2_Int(taskNumber);
            break;
        case 3:
            Funk3_Int(taskNumber);
            break;
        case 4:
            Funk4_Int(taskNumber);
            break;
        default:
            break;
        }
    }
    else if (taskNumber == 3)
    {
        switch (functionNumber)
        {
        case 1:
            Funk1_Double();
            break;
        case 2:
            Funk2_Double();
            break;
        case 3:
            Funk3_Double();
            break;
        case 4:
            Funk4_Double();
            break;
        default:
            break;
        }
    }
    else
    {
        printf("End");
        return 0;
    }

    goto task;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
