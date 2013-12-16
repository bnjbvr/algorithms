# include "sort.h"

class QuickSort : public AutoSorter
{
    int partition( int* a, int pI, int b, int e )
    {
        int pivot = a[pI];

        a[pI] = a[e];
        a[e] = pivot;

        int nI = b;
        for(int i = b; i < e; ++i)
        {
            if( a[i] < pivot ) {
                int swp = a[nI];
                a[nI] = a[i];
                a[i] = swp;
                ++nI;
            }
        }

        a[e] = a[nI];
        a[nI] = pivot;
        return nI;
    }

    void sort_helper(int* a, int b, int e)
    {
        if( b >= e )
            return;

        int pivotIndex = e;
        int newPivotIndex = partition(a, pivotIndex, b, e);
        sort_helper(a, b, newPivotIndex-1);
        sort_helper(a, newPivotIndex+1, e);
    }

    void sort(int len, int* a)
    {
        sort_helper(a, 0, len-1);
    }
};

int main( int argc, char** argv )
{
    QuickSort sort;
    if (!sort(argc, argv))
        return -1;
    return 0;
}
