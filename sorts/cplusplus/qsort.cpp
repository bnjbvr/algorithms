# include <iostream>
using namespace std;

int partition( int* a, int pI, int b, int e )
{
    int pivot = a[ pI ];

    a[pI] = a[e];
    a[e] = pivot;

    int nI = b;
    for(int i = b; i < e; ++i)
    {
        if( a[i] < pivot ) {
            int swp = a[nI];
            a[ nI ] = a[i];
            a[i] = swp;
            ++nI;
        }
    }

    a[e] = a[nI];
    a[nI] = pivot;
    return nI;
}

void sort_helper( int* a, int b, int e )
{
    if( b >= e )
        return;

    int pivotIndex = e;
    int newPivotIndex = partition( a, pivotIndex, b, e );
    sort_helper( a, b, newPivotIndex-1 );
    sort_helper( a, newPivotIndex+1, e );
}

void sort( int* a, int len )
{
    sort_helper( a, 0, len-1 );
}

int main( int argc, char** argv )
{
    int array[] = { 4, 8, 5, 6, 3, 7, 1, 2, 9 };
    int len = 9;
    for(int i = 0; i < len; ++i) cout << array[i] << ", ";
    cout << endl;
    sort( array, len );
    for(int i = 0; i < len; ++i) cout << array[i] << ", ";
    cout << endl;
}
