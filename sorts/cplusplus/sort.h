# include <iostream> // cout
# include <sstream>  // stringstream

class AutoSorter
{
    public:
        bool operator()(int argc, char **argv) {
            int size;
            std::stringstream ss;

            if (argc < 2) {
                std::cout << "at least one argument needed: size of the array" << std::endl;
                return false;
            }

            ss << argv[1];
            ss >> size;
            if (argc - 2 != size) {
                std::cout << "needs " << size << " arguments, found " << (argc - 2) << std::endl;
                return false;
            }

            int *array = new int[size];
            for (int i = 0; i < size; ++i) {
                ss.clear();
                ss << argv[2+i];
                ss >> array[i];
            }

            sort(size, array);

            for (int i = 0; i < size; ++i) {
                if (i) std::cout << ' ';
                std::cout << array[i];
            }

            delete [] array;
            return true;
        }

    protected:
        virtual void sort(int size, int *array) = 0;
};
