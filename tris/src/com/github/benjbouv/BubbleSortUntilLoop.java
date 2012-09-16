package com.github.benjbouv;

public class BubbleSortUntilLoop implements SortAlgorithm {

	@Override
	public void sort(int[] array) {
		boolean swap;
		do {
			swap = false;
			for(int i = 1, s = array.length; i < s; ++i ) {
				if( array[i-1] > array[i] ) {
					swap = true;
					int swapped = array[i];
					array[i] = array[i-1];
					array[i-1] = swapped;
				}
			}
		} while( swap );
	}

	@Override
	public String toString() {
		return "Bubble Sort with until loop";
	}

}
