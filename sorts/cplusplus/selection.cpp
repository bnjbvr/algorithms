# include "sort.h"

class SelectionSort : public AutoSorter
{
    // O(n²)
    void sort(int size, int* tab)
    {
        for (int i = 0; i < size - 1; ++i)
        {
            // Select minimum
            int iMin = i;
            for (int j = i+1; j < size; ++j)
            {
                if (tab[j] < tab[iMin])
                    iMin = j;
            }

            // Permute
            if (i != iMin)
            {
                int temp = tab[i];
                tab[i] = tab[iMin];
                tab[iMin] = temp;
            }
        }
    }
};

int main (int argc, char **argv)
{
    SelectionSort sorter;
    if (!sorter(argc, argv))
        return -1;
    return 0;
}
