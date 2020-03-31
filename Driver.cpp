#include <iostream>

using namespace std;

void printArray(int* ar, int begin, int end)
{
    for(int i = begin; i <= end; i++)
    {
        cout << ar[i] << " ";
    }
    cout << "\n";
}

void mergeSort(int* ar, int begin, int end)
{
    cout << "Merge Sorting: ";
    printArray(ar, begin, end);
    int ended = end;
    int* array = new int[5];
    if(begin != end)
    {
        int begin1 = begin;
        int end1 = (end + begin) / 2;
        int begin2 = end1 + 1;
        int end2 = end;

        mergeSort(ar, begin1, end1);

        mergeSort(ar, begin2, end2);
        
        if(ar[begin1] > ar[begin2])
        {
            if((end1-begin1)==(end2-begin2))
            {
                cout << "we're doing it" << "\n";
                for(int i = 0; i < (end1-begin1+1); i++)
                {
                    int holder = ar[begin1+i];
                    ar[(begin1+i)] = ar[(begin2+i)];
                    ar[(begin2+i)] = holder;
                    printArray(ar, begin, end);
                }
            }
            else
            {
                int len1 = end1-begin1+1;
                int len2 = end2-begin2+1;
                int* holder = new int[(len1+len2)];
                
                for(int i = 0; i <= len2; i++)
                {
                    holder[i] = ar[i];
                    ar[i] = ar[begin2+i];
                    
                }
                int count = 0;
                
                for(int i = (len2); i < (len2 + len1); i++)
                {
                    ar[i] = holder[count];
                    count = count + 1;
                }
            }
        }
        int count = 0;
        int tracker = (end2 - end1) -1;
        for(int i = 0; i <= (end1+tracker); i++)
        { 
            int holder = ar[i];
            if(ar[begin2+count] < ar[i])
            {
                ar[i] = ar[begin2+count];
                ar[begin2+count] = holder;
                count = count + 1;
            }            
        }
        count = 0;
        for(int i = 0; i <= (end1+tracker); i++)
        { 
            int holder = ar[i];
            if(ar[begin2+count] < ar[i])
            {
                ar[i] = ar[begin2+count];
                ar[begin2+count] = holder;
                count = count + 1;
            }            
        } 
        
    }
    else
    {
        cout << "One List! Do nothing\n";
    }  
    
}

int main()
{
    int ar[5] = {7, 5, 1, 4, 3};
    mergeSort(ar, 0, 4);
    printArray(ar, 0, 4);
}