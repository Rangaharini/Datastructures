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
void SelectionSort()
{
    for ( i = 0; i < n - 1; i++)
    {
        int min = i;
        for ( j = i+1; j < n ; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min!=i)
        {
            swap(array[i],array[min]);
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
    SelectionSort();
    cout << "Sorted array  : ";
    for ( i = 0; i < n; i++)
        cout << array[i] << " ";
}