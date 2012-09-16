package com.github.benjbouv;

public class Sorts {
	
	public static void unit_test( final int ARRAY_SIZE ) {
		SortAlgorithm[] algorithms = { 
				new InsertionSort(),
				new BubbleSortForLoop(),
				new BubbleSortUntilLoop(),
				new SelectionSort(),
				new MergeSort(),
				new InPlaceQuickSort( new LastElementAsPivot() )
		};
		
		for( SortAlgorithm algo : algorithms ) {
			System.out.print("Launching " + algo.toString() + "... ");
			int[] list = Utils.generate(ARRAY_SIZE);
			int[] copy = list.clone();
			
			long begin = System.currentTimeMillis();
			algo.sort( list );
			System.out.println("Finished in " + (System.currentTimeMillis() - begin) + "ms.");
			
			if( !Utils.sameValues(list, copy) ) {
				System.out.println("Error at this point: the input and output arrays are not the same.");
				System.out.println("Original:");
				for(int i = 0; i < copy.length; ++i) System.out.print(copy[i] + ",");
				System.out.println("\nSorted:");
				for(int i = 0; i < list.length; ++i) System.out.print(list[i] + ",");
				return;
			}
			
			if( !Utils.checkSorted( list ) ) {
				for(int i = 0; i < list.length; ++i) System.out.print(list[i] + ",");
				System.out.println("Error at this point: array not sorted");
				return;
			}
		}
		System.out.println("Everything worked :)");
	}
	
	public static void compare( final int ARRAY_SIZE, final int iterations, SortAlgorithm[] algos ) {

		int size = algos.length;
		long means[] = new long[ size ];
		for(int i = 0; i < size; means[i++] = 0) {
			// nothing to do
		}
		
		for(int i = 0; i < iterations; ++i) {
			System.out.print("Iteration " + (i+1) + "...");
			int[] initialList = Utils.generate(ARRAY_SIZE);
			
			for( int j = 0; j < size; ++j ) {
				int[] copy = initialList.clone();
				
				long begin = System.currentTimeMillis();
				algos[j].sort(copy);
				long diff = System.currentTimeMillis() - begin;
				means[j] += diff;
				System.out.print( algos[j].toString() + ": " + diff + "ms / ");
			}
			System.out.println();
		}
		
		for( int i = 0; i < size; ++i ) {
			means[i] /= iterations;
			System.out.println(algos[i].toString() + " average time: " + means[i] + "ms");
		}
	}
	
	public static void main(String[] args) {
		final int ARRAY_SIZE = 10000000;
		// unit_test(ARRAY_SIZE);
		
		GetPivotAlgorithm randomPivot = new RandomPivot();
		GetPivotAlgorithm lastElement = new LastElementAsPivot();
		SortAlgorithm sorts[] = {
				new InPlaceQuickSort( lastElement ),
				new InPlaceQuickSort( randomPivot ),
				new AuxiliaryTableQuickSort( lastElement ),
				new AuxiliaryTableQuickSort( randomPivot ),
		};
		compare( ARRAY_SIZE, 21, sorts );
	}

}
