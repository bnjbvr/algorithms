package com.github.benjbouv;

public class MergeSort implements SortAlgorithm {

	@Override
	public String toString() {
		return "Merge Sort";
	}
	
	private void merge( int[] array, int b1, int e1, int b2, int e2 ) {
		int i = b1;
		int j = b2;
		int k = 0;
		
		int[] tempArray = new int[ e2-b1+1 ];
		
		while( i <= e1 && j <= e2 ) {
			if( array[i] < array[j] ) {
				tempArray[k++] = array[i++];
			} else {
				tempArray[k++] = array[j++];
			}
		}
		
		while( i <= e1 ) {
			tempArray[k++] = array[i++];
		}
		while( j <= e2 ) {
			tempArray[k++] = array[j++];
		}
		
		for( int l = 0, s = tempArray.length; l < s; ++l ) {
			array[b1+l] = tempArray[l];
		}
	}
	
	private void sort( int[] array, int b, int e )
	{
		if( b >= e ) {
			return;
		} else if ( e == b+1 ) {
			if( array[e] > array[b] ) {
				int swap = array[b];
				array[b] = array[e];
				array[e] = swap;
			}
		}
		
		int middle = ( e-b ) / 2;
		sort( array, b, b + middle );
		sort( array, b + middle + 1, e );
		merge( array, b, b + middle, b + middle + 1, e );
	}

	@Override
	public void sort(int[] array) {
		sort( array, 0, array.length-1 );
	}

}
