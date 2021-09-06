#include<iostream>
using namespace std;
#define Max 50
int array[Max],i,j,n;
void insertionSort()
{
    for(i=1;i<n;i++)
    {
        int temp = array[i];
        j=i-1;
        while(j>=0 && array[j]>temp)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1]=temp;
    }
}
int main()
{
    cout << "Enter Total Number of elements:";
    cin >> n;
    cout << "Enter the Elements:";
    for (i = 0; i < n; i++)
        cin >> array[i];
    insertionSort();
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
        cout << array[i] << " ";
}