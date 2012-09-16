package com.github.benjbouv;

public class InPlaceQuickSort extends QuickSort {

	InPlaceQuickSort(GetPivotAlgorithm getPivot) {
		super(getPivot);
	}

	@Override
	public int partition(int[] array, int pivotIndex, int b, int e) {
		{
			int pivot = array[ pivotIndex ];
			
			// swap pivot and last element
			array[pivotIndex] = array[e];
			array[e] = pivot;
			
			// put every element lower than the pivot before this latter
			int swap;
			int newPosition = b;
			for( int i = b; i < e; ++i ) {
				if( array[i] < pivot ) {
					swap = array[i];
					array[i] = array[ newPosition ];
					array[ newPosition++ ] = swap;
				}
			}
			
			// swap pivot and newPosition
			array[ e ] = array[ newPosition ];
			array[ newPosition ] = pivot;
			
			return newPosition;
		}
	}
	
	public String toString() {
		return super.toString() + " in place";
	}
	
	

}
