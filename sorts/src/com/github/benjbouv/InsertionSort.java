package com.github.benjbouv;

public class InsertionSort implements SortAlgorithm {

	@Override
	public void sort(int[] list) {
		for( int i = 1, s = list.length; i < s; ++i) {
			int n = list[i];
			int j = i-1;
			while( j >= 0 && n < list[j] ) {
				list[j+1] = list[j];
				--j;
			}
			list[j+1] = n;
		}
	}
	
	@Override
	public String toString() {
		return "Insertion Sort";
	}

}
