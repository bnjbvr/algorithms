# include "sort.h"

class QuickSort : public AutoSorter
{
    int partition( int* array, int pivotIndex, int from, int to )
    {
        int pivot = array[pivotIndex];

        array[pivotIndex] = array[to];
        array[to] = pivot;

        int nextIndex = from;
        for(int i = from; i < to; ++i)
        {
            if( array[i] < pivot ) {
                int swp = array[nextIndex];
                array[nextIndex] = array[i];
                array[i] = swp;
                ++nextIndex;
            }
        }

        array[to] = array[nextIndex];
        array[nextIndex] = pivot;
        return nextIndex;
    }

    void sort_helper(int* a, int from, int to)
    {
        if( from >= to )
            return;

        int pivotIndex = to;
        int newPivotIndex = partition(a, pivotIndex, from, to);
        sort_helper(a, from, newPivotIndex-1);
        sort_helper(a, newPivotIndex+1, to);
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
