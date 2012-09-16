package com.github.benjbouv;

import java.util.Random;

public class RandomPivot implements GetPivotAlgorithm {

	private Random r = new Random();
	
	public int get(int b, int e) {
		return b+r.nextInt(e-b+1);
	}
	
	public String toString() {
		return "random pivot";
	}
}
