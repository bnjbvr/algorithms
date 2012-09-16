package com.github.benjbouv;

public class SelectionSort implements SortAlgorithm {

	@Override
	public String toString() {
		return "Selection Sort";
	}

	@Override
	public void sort(int[] array) {
		for( int i = 0, s = array.length; i < s; ++i ) {
			Integer min = array[i];
			int minIndex = i;
			for( int j = i+1; j < s; ++j ) {
				if( min > array[j] ) {
					minIndex = j;
					min = array[j];
				}
			}
			
			int swap = min;
			array[ minIndex ] = array[i];
			array[i] = swap;
		}
	}

}
