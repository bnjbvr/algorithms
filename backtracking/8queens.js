function applyChessCase(chess, func) {
	for (var i = 0; i < n; ++i) {
		for (var j = 0; j < n ; ++j) {
			func(chess[i][j]);
		}
	}
}

function makeChess() {		
	var chess = [];
	for (var i = 0; i < n; ++i) {
		chess[i] = [];
		for (var j = 0; j < n ; ++j) {
			chess[i][j] = 0;
		}
	}
	return chess;
}

function printChess(chess) {
	applyChessCase(chess, function(c) { console.log(c) });
}

/* Algorithm : Backtracking.
 * 1) Puts a queen in the first column.
 * 2) Tries to find a solution by deeper calls.
 * 3) If the solution is accepted, stop. Otherwise, tries with another
 * choice.
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

function backtrack(queens) {
	var isAccepted = accept(queens);
	if (queens.length === n && isAccepted) {
		console.log(queens); // if you need to show solutions
		nbSolutions++;
		return true;
	}
	
	if (!isAccepted) {
		return false;
	}
	
	var newI = queens.length;
	queens[newI] = 0;
	while (queens[newI] < n) {
		///* // if you just want one solution
		if (backtrack(queens)) {
			return true; 
		}
		//*/
		// backtrack(queens);
		queens[newI]++;
		queens.length = newI+1;
	}
}

function solveNqueens() {
	nbSolutions = 0;
	backtrack([]);
	console.log("Number of distinct solutions : " + nbSolutions);
}

var stdin = process.openStdin();
var n = 0;
console.log("For which number of queens would you like to solve" +
" the problem?");
stdin.on('data', function(d) {
	n = parseInt(d);
	console.log("Queens problem for n = " + n);
	solveNqueens();
	console.log("For which number of queens would you like to solve" +
	" the problem?");
});
