#include <iostream>
#include <time.h>
#include <Windows.h>


using namespace std;

void craft_arr(int* arr, int size)
{
    srand(time(NULL));
     
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
}

int sort_bubble(int* arr, const int size)
{
    int temp;
    int count=0;
    
    for (int i = 0; i < size - 1; i++)
    {
        
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }

        }
        if (count == 0)
        {
            return i;
        }
    }
    return count;
}


int sort_choice(int* arr, int size)
{
    int min,temp, count = 0;
    

    for (int i = 0; i < size; i++)
    {
        min = i;
        temp = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < temp)
            {
                min = j; 
                temp = arr[j];
            }
        }
        if (min != i)
        {
            arr[min] = arr[i];
            arr[i] = temp;
            count++;
        }
    }
    return count;
}

int main()
{

    setlocale(LC_ALL, "ru");
    const int SIZE = 1000;

    int count_Bubble = 0;
    int count_Choice = 0;
    
    for (int i = 0; i < 10; i++)
    {
        int* arr1 = new int[SIZE];
        int* arr2 = new int[SIZE];
        craft_arr(arr1, SIZE);
        craft_arr(arr2, SIZE);
        count_Bubble += sort_bubble(arr1, SIZE);
        count_Choice += sort_choice(arr2, SIZE);
       
    }
    cout << "Среднее количество перестановок усовершенствованным методом пузырька: " << count_Bubble / 10 << endl;
    cout << "Среднее количество перестановок методом выбора: " << count_Choice / 10 << endl;
}


