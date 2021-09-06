#include<iostream>
using namespace std;
#define Max 50
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partitioning(int array[], int lb,int ub)
{
    int pivot = array[lb];
   int start = lb;
   int end = ub;
   while(start < end)
   {
       while(array[start]<=pivot)
       {
           start++;
       }
       while(array[end]>pivot)
       {
           end--;
       }
       if(start<end)
       {
           swap(array[start],array[end]);
       }
   }
   swap(array[lb],array[end]);
   return end;
}
void QuickSort(int array[], int lb,int ub)
{
    if(lb<ub)
    {
        int loc = partitioning(array,lb,ub);
        QuickSort(array,lb,loc-1);
        QuickSort(array,loc+1,ub);
    }
}
int main()
{
    int n;
    int array[50];
    cout << "Enter Total Number of elements:";
    cin >> n;
    cout << "Enter the Elements:";
    for (int i = 0; i < n; i++)
        cin >> array[i];
    QuickSort(array, 0, n-1);
    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
}