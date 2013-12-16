# include "sort.h"

class MergeSort : public AutoSorter
{
    // O(n)
    void merge(int *tab, int p, int q, int r)
    {
        int n1 = q - p + 1; // size of left sub array
        int n2 = r - q;     // size of right sub array (== r - (q+1) + 1)

        int* L = new int[n1];
        int* R = new int[n2];

        int i, j;
        for (i = 0; i < n1; ++i) {
            L[i] = tab[p + i];
        }
        for (j = 0; j < n2; ++j) {
            R[j] = tab[q + 1 + j];
        }

        i = 0;
        j = 0;
        int k = p;
        for (; k <= r; ++k) {
            if (L[i] <= R[j])
            {
                tab[k] = L[i++];
                if (i > n1)
                    break;
            } else {
                tab[k] = R[j++];
                if (j > n2)
                    break;
            }
        }

        for (; i < n1; ++i) {
            tab[k++] = L[i];
        }
        for (; j < n2; ++j) {
            tab[k++] = R[j];
        }

        delete [] L;
        delete [] R;
    }

    // O(n log2(n))
    void sort_recursive(int* tab, int p, int r)
    {
        if (p < r)
        {
            int q = (p + r) / 2;
            sort_recursive(tab, p, q);
            sort_recursive(tab, q + 1, r);
            merge(tab, p, q, r);
        }
    }

    void sort(int size, int *tab)
    {
        sort_recursive(tab, 0, size - 1);
    }
};

int main (int argc, char **argv)
{
    MergeSort sorter;
    if (!sorter(argc, argv))
        return -1;
    return 0;
}
