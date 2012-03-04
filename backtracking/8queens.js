/* This program can be launched with nodejs, by tpying node 8queens.js
 * in a terminal.
 */
var config = {
	/* Would you like to find just one solution or all solutions ? */
	find_all_solutions: true,
	
	/* Would you like to show solutions ?
	 * If you say no, you'll just have the number of solutions found.
	 */
	show_solutions: true
};

/* Algorithm : Backtracking.
 * 1) Puts a queen in the first column.
 * 2) Tries to find a solution by deeper calls.
 * 3) If the solution is accepted, stop. Otherwise, tries with another
 * choice.
 */
 
/*
 * Acceptation function. Returns true if the queens (given as a table)
 * can be a solution, false otherwise.
 */
function accept(queens) {
	for (var i = 0; i < queens.length; ++i) { 
		var base = queens[i];
		for (var j = i+1; j < queens.length; ++j) {
			if (base === queens[j] 			  // same line
				|| (j-i === queens[j] - base) // same diag SW => NE
				|| (j-i === base - queens[j]) // same diag NW => SE
				) {
				return false;
			}
		}
	}
	return true;
}

/*
 * Checks whether function accept is correct.
 */
function testAccept() {
	var oldN = n;
	n = 4;
	var queens = [1, 3, 0, 2];
	if (!accept(queens)) {
		console.log("Error : a good solution is not accepted.");
	}
	queens = [0, 1, 0, 3];
	if (accept(queens)) {
		console.log("Error : a wrong solution (line) is accepted.");
	}
	queens = [3, 1, 2, 3];
	if (accept(queens)) {
		console.log("Error : a wrong solution (diag) is accepted.");
	}
	n = oldN;
}

var nbSolutions;

/* 
 * Backtracking function, based on the "classical model".
 */
function backtrack(queens) {
	var isAccepted = accept(queens);
	if (queens.length === n && isAccepted) {
		if (config.show_solutions) {
			console.log(queens); // if you need to show solutions
		}
		nbSolutions++;
		return true;
	}
	
	if (!isAccepted) {
		return false;
	}
	
	var newI = queens.length;
	queens[newI] = 0;
	while (queens[newI] < n) {
		if (backtrack(queens) && !config.find_all_solutions) {
			return true; 
		}
		queens[newI]++;
		queens.length = newI+1;
	}
}

/*
 * Call to backtracking function.
 */
function solveNqueens() {
	nbSolutions = 0;
	backtrack([]);
	console.log("Number of distinct solutions : " + nbSolutions);
}

var n = 0;
var presentationText = "For which number of queens would you like to solve" +
	" the problem?";
var stdin = process.openStdin();
console.log(presentationText);
stdin.on('data', function(d) {
	n = parseInt(d);
	console.log("Queens problem for n = " + n);
	solveNqueens();
	console.log(presentationText);
});
