#include <iostream>
using namespace std;
const int TAILLE_TAB = 8;
const int SENTINELLE = 9; // héhé

void fusion(int* tab, int p, int q, int r)
// O(n)
{
	int n1 = q-p+1;
	int n2 = r-q; // r - (q+1) + 1

	int* L = new int[n1+1]; // on laisse une place pour les sentinelles
	int* R = new int[n2+1];
	
	int i, j;
	
	// Construction du sous tableau de gauche
	for (i = 0; i < n1; ++i)
	{
		L[i] = tab[p+i];
	}
	L[n1] = SENTINELLE;
	
	// Construction du sous tableau de droite
	for (j = 0; j < n2; ++j)
	{
		R[j] = tab[q+1+j];
	}
	R[n2] = SENTINELLE;
	
	i = 0;
	j = 0;
	for (int k = p; k <= r; ++k)
	{
		if (L[i] <= R[j])
		{
			tab[k] = L[i];
			++i;
		} else {
			tab[k] = R[j];
			++j;
		}
	}
	
	delete [] L;
	delete [] R;
}

void triFusionRecursif(int* tab, int p, int r)
// O(n log2(n))
{
	if (p < r)
	{
		int q = (p+r) / 2;
		triFusionRecursif(tab, p, q);
		triFusionRecursif(tab, q+1, r);
		fusion(tab, p, q, r);
	}
}

void triFusion(int * tab)
{
	triFusionRecursif(tab, 0, TAILLE_TAB-1);
}

int main (void)
{
	int tab[TAILLE_TAB] = {2, 4, 3, 6, 8, 7, 1, 5};
	triFusion(tab);
	cout << "Tableau trié : " << endl;
	for (int i = 0; i < TAILLE_TAB; ++i)
	{
		cout << tab[i] << " ";
	}	
	cout << endl;
}
