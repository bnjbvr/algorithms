# include "sort.h"

class InsertionSort : public AutoSorter
{
    // O(n²)
    void sort(int size, int *tab)
    {
        for (int j = 1; j < size; ++j)
        {
            int key = tab[j];
            int i = j - 1;
            while (i >= 0 && tab[i] > key)
            {
                tab[i+1] = tab[i];
                --i;
            }
            tab[i+1] = key;
        }
    }
};

int main (int argc, char** argv)
{
    InsertionSort sorter;
    if (!sorter(argc, argv))
        return -1;
    return 0;
}
