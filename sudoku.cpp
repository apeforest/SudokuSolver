#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool solveSudoku(vector<vector<char>>& board) {
    stack<int> solved;
    stack<int> unsolved;

    int n = board.size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	if (board[i][j] == '.') {
	  unsolved.push(i*n + j);
	}
      }
    }

    while (!unsolved.empty()) {
      int us = unsolved.top();
      int col = us % n;
      int row = us / n;
      // solve us                                                                                
      if (solve(board, row, col)) {
	solved.push(us);
	unsolved.pop();
      }
      else {
	board[row][col] = '.';
	if (solved.empty()) {
	  cout << "This sudoku is unsolvable!" << endl;
	  return false;
	}

	int s = solved.top();
	unsolved.push(s);
	solved.pop();
      }
    }

    return true;
  }

  bool solve(vector<vector<char>>& board, int r, int c) {
    int box = static_cast<int>(sqrt(board.size()));
    int num = 1;
    if (board[r][c] != '.')
      num = (board[r][c] - '0') + 1;

    bool valid = false;
    while (num <= 9) {
      valid = true;
      // check row                                                                                   
      for (int i = 0; i < board.size(); i++) {
	if (i == c) continue;
	if (board[r][i] != '.' && (board[r][i] - '0') == num) {
	  valid = false;
	  break;
	}
      }

      if (!valid) {
	num++;
	continue;
      }

      // check col                                                                                   
      for (int i = 0; i < board.size(); i++) {
	if (i == r) continue;
	if (board[i][c] != '.' && (board[i][c] - '0') == num) {
	  valid = false;
	  break;
	}
      }

      if (!valid) {
	num++;
	continue;
      }

      // check box                                                                                   
      for (int i = 0; i < box; i++) {
	for (int j = 0; j < box; j++) {
	  int br = (r / box) * box + i;
	  int bc = (c / box) * box + j;

	  if (br == r && bc == c) continue;
	  if (board[br][bc] != '.' && (board[br][bc] - '0') == num) {
	    valid = false;
	    break;
	  }
	}
      }

      if (!valid) {
	num++;
	continue;
      }

      if (valid)
	break;
    }

    if (valid)
      board[r][c] = num + '0';

    return valid;
  }
};


int main() {
  /*
  vector<vector<char>> board = {{'.','6','1','.','.','7','.','.','3'},
				{'.','9','2','.','.','3','.','.','.'},
				{'.','.','.','.','.','.','.','.','.'},
				{'.','.','8','5','3','.','.','.','.'},
				{'.','.','.','.','.','.','5','.','4'},
				{'5','.','.','.','.','8','.','.','.'},
				{'.','4','.','.','.','.','.','.','1'},
				{'.','.','.','1','6','.','8','.','.'},
				{'6','.','.','.','.','.','.','.','.'}
  };
  */  
  /*
  vector<vector<char>> board = {{'.','.','.','2','.','.','.','6','3'},
				{'3','.','.','.','.','5','4','.','1'},
				{'.','.','1','.','.','3','9','8','.'},
				{'.','.','.','.','.','.','.','9','.'},
				{'.','.','.','5','3','8','.','.','.'},
				{'.','3','.','.','.','.','.','.','.'},
				{'.','2','6','3','.','.','5','.','.'},
				{'5','.','3','7','.','.','.','.','8'},
				{'4','7','.','.','.','1','.','.','.'}
  };
  */
  
  vector<vector<char>> board = {{'.','.','.','.','.','.','.','.','.'},
				{'.','.','.','.','.','3','.','8','5'},
				{'.','.','1','.','2','.','.','.','.'},
				{'.','.','.','5','.','7','.','.','.'},
				{'.','.','4','.','.','.','1','.','.'},
				{'.','9','.','.','.','.','.','.','.'},
				{'5','.','.','.','.','.','.','7','3'},
				{'.','.','2','.','1','.','.','.','.'},
				{'.','.','.','.','4','.','.','.','9'}
  };
  
  /*
  vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
				{'6','.','.','1','9','5','.','.','.'},
				{'.','9','8','.','.','.','.','6','.'},
				{'8','.','.','.','6','.','.','.','3'},
				{'4','.','.','8','.','3','.','.','1'},
				{'7','.','.','.','2','.','.','.','6'},
				{'.','6','.','.','.','.','2','8','.'},
				{'.','.','.','4','1','9','.','.','5'},
				{'.','.','.','.','8','.','.','7','9'}
  };
  */
  Solution sol;

  if (sol.solveSudoku(board)) {
    for (auto i = 0; i < board.size(); i++) {
      for (auto j = 0; j < board[i].size(); j++)
	cout << board[i][j] << " ";
      cout << endl;
    }
  }

  return 0;
}
