#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
	for (int i = 0; i < c; i++) {
		if (q[i] == q[c] || abs(q[i] - q[c]) == c - i) { // check to see if we're on the same row or diagonal
			return false;
		}
	}

	return true;
}

int nQueens(int n) {
	int *q = new int[n]; // dynamcially allocate array and start on the first column
	int c = 0, solutions = 0;
	q[c] = 0; // let the first element of the array be 0
	while (c >= 0) {
		if (c == n - 1) { // if we reach the end of the column, update the number of solutions (a solution has been found)
			++solutions;
			--c;
		} else {
			q[++c] = -1; // move to one before the first row
		}
		while (c >= 0) {
			++q[c];        // move to the next row
			if (q[c] == n) // if we reach the end of the row, backtrack (no solution found)
				--c;
			else if (ok(q, c)) {
				break; // break if queen is ok
			}
		}
	}
	// delete the array once we have found all solutions
	delete[] q;
	return solutions;
}

int main() {
	int n = 12;
	// loop thru all solutions from 1 to n
	for (int i = 1; i <= n; i++) {
		cout << "There are " << nQueens(i) << " solutions to the " << i << " queens problem" << endl;
	}
	return 0;
}


