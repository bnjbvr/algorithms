# Backtracking

These little programs are here to show examples of usage of 
backtracking. There are classical problems which can be easily resolved
with backtracking.

The "model algorithm" for backtracking is the following, according to
Wikipedia :

Function Backtracking (candidate : data)
1. if reject(candidate), i.e candidate can't be a solution, return false.
2. if accept(candidate), i.e candidate can be a solution, or *is* a
solution, returns true.
3. nextCandidate = generates first candidate.
4. while size of solution is not reached, do 
	1. if Backtracking(nextCandidate), returns true.
	2. otherwise, nextCandidate = next candidate to test.
5. enjoy :)

This version finds just one solution to the problem. If you want to
show all solutions (which can have no sense, for instance for Sudoku
problems which have a priori only one solution), you just have to 
replace 4.1) by Backtracking(nextCandidate).
