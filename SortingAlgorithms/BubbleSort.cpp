#include<iostream>
using namespace std;
#define Max 50
int array[Max],i,j,n;
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void BubbleSort()
{
    for ( i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for ( j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                flag = 1;
            }
        }
        if (flag==0)
        {
            break;
        }
    }
    
}
int main()
{
    cout << "Enter  Total Number of elements:";
    cin >> n;
    cout << "Enter the Elements:";
    for ( i = 0; i < n; i++)
        cin >> array[i];
    BubbleSort();
    cout << "Sorted array is : ";
    for ( i = 0; i < n; i++)
        cout << array[i] << " ";
}