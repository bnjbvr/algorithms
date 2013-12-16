# include "sort.h"

class Sort : public AutoSorter
{
    int *buffer;

public:
    Sort() : buffer(NULL) {}
    ~Sort() {
        if (buffer)
            delete [] buffer;
    }

private:
    void init(int n) {
        buffer = new int[n];
    }

    void merge (int *array, int beg, int mid, int end)
    {
        int i = beg, j = mid + 1, k = 0;

        while (true) {
            if (array[i] <= array[j]) {
                buffer[k++] = array[i];
                if (++i > mid)
                    break;
            } else {
                buffer[k++] = array[j];
                if (++j > end)
                    break;
            }
        }

        while (i <= mid)
            buffer[k++] = array[i++];
        while (j <= end)
            buffer[k++] = array[j++];

        for (i = beg; i <= end; ++i)
            array[i] = buffer[i - beg];
    }

    void r (int *array, int beg, int end)
    {
        if (beg >= end)
            return;

        int mid = (beg + end) / 2;
        r(array, beg, mid);
        r(array, mid + 1, end);
        merge(array, beg, mid, end);
    }

    void sort (int size, int *array)
    {
        init(size);
        r(array, 0, size - 1);
    }
};

int main (int argc, char **argv)
{
    Sort sorter;
    if (!sorter(argc, argv))
        return -1;
    return 0;
}
