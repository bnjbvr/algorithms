#include <iostream>
using namespace std;
const int TAILLE_TAB = 8;

void triSelection(int* tab)
// O(n²)
{
	for (int i = 0; i < TAILLE_TAB-1; ++i)
	{
		// Sélection du minimum
		int iMin = i;
		for (int j = i+1; j < TAILLE_TAB; ++j)
		{
			if (tab[j] < tab[iMin])
			{
				iMin = j;
			}
		}
		
		// Permutation
		if (i != iMin)
		{
			int temp = tab[i];
			tab[i] = tab[iMin];
			tab[iMin] = temp;
		}
	}
}

int main (void)
{
	int tab[TAILLE_TAB] = {2, 4, 3, 6, 8, 7, 1, 5};
	triSelection(tab);
	cout << "Tableau trié : " << endl;
	for (int i = 0; i < TAILLE_TAB; ++i)
	{
		cout << tab[i] << " ";
	}	
	cout << endl;
}
