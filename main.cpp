//
//  main.cpp
//  way_to_school
//
//  Created by 정현민 on 2020/11/25.
//

#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> puddle_vec_vec;
vector<vector<int>> memo_vec_vec; // memoization variable
int col_size; // x size
int row_size; // y size

int move(int row, int col)
{
  if (col == col_size || row == row_size) // check out of map
  {
    return 0;
  }
  for (const auto& puddle_vec : puddle_vec_vec) // check here is puddle
  {
    if (col + 1 == puddle_vec[0] && row + 1 == puddle_vec[1])
    {
      return 0;
    }
  }
  if (col == col_size - 1 && row == row_size - 1) // check arrived
  {
    return 1;
  }
  if (memo_vec_vec[row][col] == 0)
  {
    memo_vec_vec[row][col] += move(row + 1, col) + move(row, col + 1);
    memo_vec_vec[row][col] %= 1000000007;
  }
  return memo_vec_vec[row][col];
}

int solution(int _col_size, int _row_size, vector<vector<int>> _puddle_vec_vec)
{
  col_size = _col_size;
  row_size = _row_size;
  puddle_vec_vec = _puddle_vec_vec;
  memo_vec_vec.resize(row_size, vector<int>(col_size));
  return move(0, 0);;
}

int main(int argc, const char * argv[])
{
  cout << solution(4, 3, {{2,2}}) << endl;
  return 0;
}
