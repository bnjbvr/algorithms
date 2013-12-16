# include "sort.h"
# include <cassert>
# include <list>

class Radix : public AutoSorter
{
    void sort(int size, int *array)
    {
        // Find the maximal power of 10 and put it into d
        int n = 1,
            d = 0;
        for (int i = 0; i < size; ++i) {
            while (array[i] >= n) {
                n *= 10;
                d += 1;
            }
        }

        // use the last digit for the first insertion
        std::list<int> buckets[10];
        std::list<int> swap[10];
        for (int i = 0; i < size; ++i) {
            buckets[array[i] % 10].push_back(array[i]);
        }

        // loop on the other digits, using the values present in buckets
        int c = 1;
        n = 10;
        while (c < d) {
            int s = 0;
            for (int i = 0; i < 10; ++i) {
                for (std::list<int>::iterator it = buckets[i].begin(), end = buckets[i].end();
                     it != end;
                     ++it)
                {
                    swap[(*it / n) % 10].push_back(*it);
                    s++;
                }
            }
            assert(s == size);

            // do the harlem swap
            for (int i = 0; i < 10; ++i) {
                buckets[i].swap(swap[i]);
                swap[i].clear();
            }

            c += 1;
            n *= 10;
        }

        // read values in order
        int j = 0;
        for (int i = 0; i < 10; ++i) {
            for (std::list<int>::iterator it = buckets[i].begin(), end = buckets[i].end();
                 it != end && j < size;
                 ++it)
            {
                array[j++] = *it;
            }
        }
    }
};

int main (int argc, char **argv)
{
    Radix sort;
    if (!sort(argc, argv))
        return -1;
    return 0;
}
