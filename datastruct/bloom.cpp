# include <iostream>
# include <cassert>
# include <cstdlib>

class BloomFilter {
    public:
        BloomFilter(int n) : _n(n) {
            _table = new bool[n];
            for (int i = 0; i < n; ++i)
                _table[i] = false;
        }

        void add(int x) {
            int i1 = hash1(x),
                i2 = hash2(x),
                i3 = hash3(x);
            _table[i1] = true;
            _table[i2] = true;
            _table[i3] = true;
        }

        bool contains(int x) {
            int i1 = hash1(x),
                i2 = hash2(x),
                i3 = hash3(x);
            return _table[i1] && _table[i2] && _table[i3];
        }

        ~BloomFilter() {
            delete [] _table;
        }

    private:
        int hash1(int x) {
            unsigned int h = x;

            for (int i = 6; i ; --i) {
                h += (h << 10);
                h ^= (h >> 6);
                h += (h << 3);
            }

            h ^= (h >> 11);
            h += (h << 15);
            return h % _n;
        }

        int hash2(int x) {
            static long int basis = 0xcbf29ce484222325;
            static long int prime = 0x100000001b3;

            unsigned long int h = basis;

            for (int i = 5; i; --i) {
                h *= prime;
                h ^= x;
            }

            return h % _n;
        }

        int hash3(int x) {
            return x % _n;
        }

        bool *_table;
        int _n;
};

int main (int argc, char **argv)
{
    BloomFilter bf(128);

    for (int i = 0; i < 10; ++i) {
        assert(!bf.contains(i));
        bf.add(i);
        assert(bf.contains(i));
    }

    int error = 0;
    for (int i = 10; i < 128; ++i)
        error += bf.contains(i);
    assert(error == 0);

    srand(time(NULL));
    for (int i = 0; i < 32768; ++i)
        error += bf.contains(rand());
    std::cout << "error: " << 100. * error / 32768. << std::endl;

    return 0;
}
