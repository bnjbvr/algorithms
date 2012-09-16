# include <iostream>
using namespace std;

const int TAILLE_TAB = 8;

void triInsertion(int * tab)
// O(n²)
{
	for (int j = 1; j < TAILLE_TAB; ++j)
	{
		int cle = tab[j];
		int i = j - 1;
		while(i >= 0 && tab[i] > cle)
		{
			tab[i+1] = tab[i];
			--i;
		}
		tab[i+1] = cle;
	}
}

int main (int argc, char** argv)
{
	int tableau[TAILLE_TAB] = {2, 1, 8, 6, 4, 3, 5, 7};
	triInsertion(tableau);
	cout << "Tableau trié : " << endl;
	for (int i = 0; i < TAILLE_TAB; ++i) 
	{
		cout << tableau[i] << " ";
	}
	cout << endl;
}
