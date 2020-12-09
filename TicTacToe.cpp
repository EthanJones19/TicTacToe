#include <iostream>

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << std::endl;

    system("pause");
}




int main()
{
    int number[9] = { 7, 5, 2, 1, 9, 3, 6, 8, 4 };
    printArray(number, 5);

}