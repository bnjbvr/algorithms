# include "sort.h"
# include <vector>

class BucketSort : public AutoSorter
{
    // Works only for discrete keys
    // O(n) in time and O(n) in memory
    void sort(int size, int *array)
    {
        // find the maximal value
        int *max = NULL;
        for (int i = 0; i < size; ++i) {
            if (max == NULL || array[i] > *max)
                max = &array[i];
        }

        if (max == NULL)
            return;

        std::vector<int> buf(*max + 1, 0);
        for (int i = 0; i < size; ++i) {
            buf[array[i]] += 1;
        }

        int j = 0;
        for (int i = 0; j < size && i < buf.size(); ++i) {
            while (buf[i]) {
                array[j++] = i;
                buf[i] -= 1;
            }
        }
    }
};

int main (int argc, char **argv)
{
    BucketSort sort;
    if (!sort(argc, argv))
        return -1;
    return 0;
}
