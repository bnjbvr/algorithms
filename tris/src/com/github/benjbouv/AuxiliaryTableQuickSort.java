package com.github.benjbouv;

public class AuxiliaryTableQuickSort extends QuickSort {

	AuxiliaryTableQuickSort(GetPivotAlgorithm getPivot) {
		super(getPivot);
	}

	@Override
	public int partition(int[] array, int pivotIndex, int b, int e) {
		int pivot = array[ pivotIndex ];
		// Using an auxiliary table (easier to understand, but memory impact is
		// greater)
		int copyB = 0;
		int copyE = e - b;
		int[] copyArray = new int[e - b + 1];

		for (int i = b; i <= e; ++i) {
			if (i == pivotIndex) {
				continue;
			} else if (array[i] <= pivot) {
				copyArray[copyB++] = array[i];
			} else {
				copyArray[copyE--] = array[i];
			}
		}

		pivotIndex = copyB;
		copyArray[pivotIndex] = pivot;
		for (int i = 0, s = copyArray.length; i < s; ++i) {
			array[b + i] = copyArray[i];
		}

		pivotIndex += b;
		array[pivotIndex] = pivot;
		return pivotIndex;
	}
	
	public String toString() {
		return super.toString() + " with auxiliary table";
	}

}
