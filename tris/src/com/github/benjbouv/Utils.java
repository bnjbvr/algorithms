package com.github.benjbouv;

import java.util.HashMap;
import java.util.Random;

public class Utils {

	public static int[] generate(int n) {
		Random random = new Random();
		int[] list = new int[n];
		for (int i = 0; i < n; ++i) {
			list[i] = random.nextInt() % n;
		}
		return list;
	}

	public static boolean checkSorted(int[] array) {
		for (int i = 1, s = array.length; i < s; ++i) {
			if (array[i - 1] > array[i]) {
				return false;
			}
		}
		return true;
	}

	public static boolean sameValues(int[] array1, int[] array2) {
		HashMap<Integer, Integer> m1 = new HashMap<Integer, Integer>();
		for (int n : array1) {
			int before;
			if (m1.get(n) == null) {
				before = 0;
			} else {
				before = m1.get(n);
			}
			m1.put(n, before + 1);
		}

		for (int n : array2) {
			if (m1.get(n) == null || ( m1.get(n) != null && m1.get(n) == 0 )) {
				return false;
			} else {
				m1.put(n, m1.get(n) - 1);
			}
		}
		return true;
	}
}
