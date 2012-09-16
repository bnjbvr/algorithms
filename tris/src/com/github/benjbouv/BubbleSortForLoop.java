package com.github.benjbouv;

public class BubbleSortForLoop implements SortAlgorithm {

	@Override
	public void sort(int[] array) {
		for( int i = array.length-1; i > 0; --i ) {
			for( int j = 0; j < i; ++j ) {
				if( array[j] > array[j+1] ) {
					int swap = array[j+1];
					array[j+1] = array[j];
					array[j] = swap;
				}
			}
		}
	}

	@Override
	public String toString() {
		return "Bubble Sort with 2 for loops";
	}
	
}
