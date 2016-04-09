#include <iostream>
#include <vector>

using namespace std;

class ABoardGame {

private:
	int calc(int x, int y, int z) {
		int a = 0;
		int b = 0;
		if (x <= z - 1 && y <= z - 1) {
			a = z - y;
			b = z - x;
		} else if (x < z && y >= z) {
			a = y - z + 1;
			b = z - x;
		} else if (x >= z && y < z) {
			a = z - y;
			b = x - z + 1;
		} else { // i >= n && j >= n
			a = y - z + 1;
			b = x - z + 1;
		}
		return a > b ? a : b;
	}

public:
	string whoWins(vector<string> board) {
		int n = (board.size() / 2);
		int score_A[n];
		int score_B[n];

		for (int i = 0; i < n; i++) {
			score_A[i] = score_B[i] = 0;
		}

		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				int r = calc(i, j, n);
				if (board[i][j] == 'A')
					score_A[r - 1]++;
				else if (board[i][j] == 'B')
					score_B[r - 1]++;
			}
		}

		for (int i = 0; i < n; i++) {
			cout << score_A[i] << ":" << score_B[i] << endl;
			if (score_A[i] > score_B[i])
				return "Alice";
			else if (score_A[i] < score_B[i])
				return "Bob";
		}
		return "Draw";
	}
};