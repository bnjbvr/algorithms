# include <iostream>
# include <fstream>
# include <set>
# include <vector>
# include <string>
using namespace std;

const int SQUARE_SIZE = 3;
const int SIZE = SQUARE_SIZE * SQUARE_SIZE;

class Grid : public vector< vector<short> >
{
public:
    void show()
    {
        for(int i = 0; i < SIZE; ++i)
        {
            for(int j = 0; j < SIZE; ++j)
            {
                cout << (*this)[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void readFromFile( const string& filename )
    {
        ifstream file( filename.c_str()  );
        int i = 0, j = 0;
        (*this)[0].reserve( SIZE );
        while ( file )
        {
            if ( i == SIZE )
            {
                break;
            }

            file >> (*this)[i][j];
            if( ++j == SIZE )
            {
                ++i;
                (*this)[i].reserve( SIZE );
                j = 0;
            }
        }
        file.close();
    }

    bool correctLine( int line )
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for(int j = i+1; j < SIZE; ++j)
            {
                if ( (*this)[line][i] != 0 && (*this)[line][i] == (*this)[line][j] )
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool correctColumn( int col )
    {
        for(int i = 0; i < SIZE; ++i)
        {
            for(int j = i+1; j < SIZE; ++j)
            {
                if ( (*this)[i][col] != 0 && (*this)[i][col] == (*this)[j][col] )
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool correctCase( int i, int j )
    {
        int iBottomLeft = ( i / SQUARE_SIZE ) * SQUARE_SIZE,
            jBottomLeft = ( j / SQUARE_SIZE ) * SQUARE_SIZE;

        set<short> alreadyTaken;
        for(int i = 0; i < SQUARE_SIZE; ++i)
        {
            for(int j = 0; j < SQUARE_SIZE; ++j)
            {
                int k = iBottomLeft + i;
                int l = jBottomLeft + j;
                //cout << "k,l : " << k << "," << l << endl;

                if( (*this)[k][l] != 0 )
                {
                    if (alreadyTaken.find( (*this)[k][l] ) == alreadyTaken.end() )
                        alreadyTaken.insert( (*this)[k][l] );
                    else
                        return false;
                }
            }
        }
        return true;
    }

    bool correct( )
    {
        for (int i = 0; i < SIZE; ++i)
        {
            if (! correctLine(i) || ! correctColumn(i) )
            {
                return false;
            }
        }

        for (int i = 0; i < SQUARE_SIZE; ++i)
        {
            for(int j = 0; j < SQUARE_SIZE; ++j)
            {
                if(! correctCase( i * SQUARE_SIZE, j * SQUARE_SIZE ) )
                {
                return false;
                }
            }
        }

        return true;
    }

    bool full()
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for(int j = 0; j < SIZE; ++j)
            {
                if ((*this)[i][j] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int emptyCases()
    {
        int empty = 0;
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                if ( (*this)[i][j] == 0 )
                {
                    ++empty;
                }
            }
        }
        return empty;
    }

    Grid& operator=( const Grid& other )
    {
        if( other != *this)
        {
            deep_copy( other );
        }
        return *this;
    }

    Grid( const Grid& other )
    {
        deep_copy( other );
    }

    Grid(size_t size) : vector< vector<short> >( size )
    {
        // empty
    }

    void deep_copy( const Grid& other )
    {
        resize( other.size() );
        for(int i = 0; i < SIZE; ++i)
        {
            (*this)[i].resize( SIZE );
            for(int j = 0; j < SIZE; ++j)
            {
                (*this)[i][j] = other[i][j];
            }
        }
    }
};

bool backtrack( Grid & grid, const vector<short>& candidates )
{
    bool coherent = grid.correct();
    if (!coherent) 
    {
        return false;
    }

    if (coherent && grid.full() )
    {
        return true;
    }

    Grid copyGrid( grid );

    vector<short>::const_iterator candidate = candidates.begin();

    // Seek the first unfound value
    int iSaved = 0, jSaved = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            if (copyGrid[i][j] == 0)
            {
                iSaved = i;
                jSaved = j;
                break;
            }
        }
    }

    do {
        copyGrid[iSaved][jSaved] = *candidate;
        if( backtrack( copyGrid, candidates ) )
        {
            grid = copyGrid;
            return true;
        }
        ++candidate;
    } while( candidate != candidates.end() );
    return false;
}

int main ( void )
{
    Grid grid( SIZE );
    grid.readFromFile( "sudoku.data" );
    grid.show();
    cout << "Research..." << endl;

    // Generate candidates
    vector<short> candidates( SIZE );
    for (short i = 0; i < SIZE; ++i)
    {
        candidates[i] = i+1;
    }

    // Launch algorithm!
    if ( backtrack( grid, candidates ) )
    {
        cout << "A solution has been found : " << endl;
        grid.show();
    }
    else
    {
        cout << "No solution has been found, sorry." << endl;
    }
    return 0;
}

