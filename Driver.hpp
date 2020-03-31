#include <iostream>

using namespace std;

void printArray(int* ar, int begin, int end)
{
    for(int i = begin; i < end; i++)
    {
        cout << ar[i] << " ";
    }
    cout << "\n";
}

void mergeSort(int* ar, int begin, int end)
{
    cout << "Merge Sorting: ";
    printArray(ar, begin, end);
    if(begin != end)
    {
        int begin1 = begin;
        int end1 = (end + begin) / 2;
        int begin2 = end1 + 1;
        int end2 = end;

        mergeSort(ar, begin1, end1);

        mergeSort(ar, begin2, end2);

        cout << "Now we have to merge!!!!\n Start to cry Clancy!!!\n";
    }
    else
    {
        cout << "One List! Do nothing\n";
    }
    
}

int main()
{
    int ar[5] = {7, 2, 1, 4, 3};
    mergeSort(ar, 0, 4);
    printArray(ar, 0, 4);
}