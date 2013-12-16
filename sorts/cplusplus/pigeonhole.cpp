# include "sort.h"
# include <vector>

class PigeonHole : public AutoSorter
{
    // Works only for discrete keys
    // O(n) in time and O(n) in memory
    //
    // As we don't know the maximum value in the array, we add overhead by
    // resizing the array, but a simple linear scan could avoid the copies.
    void sort(int size, int *array)
    {
        std::vector<int> buf(size, 0);
        for (int i = 0; i < size; ++i) {
            int v = array[i];
            if (v >= buf.size()) {
                buf.resize(v+1, 0);
            }
            buf[v] += 1;
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
    PigeonHole sort;
    if (!sort(argc, argv))
        return -1;
    return 0;
}
