package com.github.benjbouv;

public abstract class QuickSort implements SortAlgorithm {
	
	QuickSort( GetPivotAlgorithm getPivot ) {
		this.getPivot = getPivot;
	}
	
	private GetPivotAlgorithm getPivot;
	
	@Override
	public String toString() {
		return "Quick Sort (pivot: " + getPivot.toString() + ")";
	}
	
	abstract public int partition(int[] array, int pivotIndex, int b, int e);
	
	private void sort(int[] array, int b, int e) {
		
		if( b >= e ) {
			return;
		}

		int pivotIndex = getPivot.get(b, e);
		int newPivotIndex = partition(array, pivotIndex, b, e);
		sort( array, b, newPivotIndex-1 );
		sort( array, newPivotIndex+1, e );
	}

	@Override
	public void sort(int[] array) {
		sort( array, 0, array.length-1 );
	}

}
