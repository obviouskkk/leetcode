/* ***********************************************************************

  > File Name: UniquePaths_62.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 30 Apr 2019 02:30:11 PM CST

 ********************************************************************** */

/*
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 *
 */

/*
 *
 * 示例 1:
 *
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 示例 2:
 *
 * 输入: m = 7, n = 3
 * 输出: 28
 *
 */

/*
 * dp : f(i,j) = f(i-1,j) + f(j-1,i)
 * 因为对称位置的次数是一样的，所以又有 f(i,j) = f(j,i)
 */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include<gtest/gtest.h>

using std::vector;
using std::string;

class Solution {
public:
	int uniquePaths(int m, int n) {
		int dp[m][n];
		for (int i = 0; i < m; ++i) {
			dp[i][0] = 1;
		}
		for (int i = 0; i < n; ++i) {
			dp[0][i] = 1;
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
	}
};


TEST(testCase,test0) {
	Solution s;
	EXPECT_EQ(s.uniquePaths(7,3), 28);
	EXPECT_EQ(s.uniquePaths(10,10), 48620);
	EXPECT_EQ(s.uniquePaths(3,7), 28);
	EXPECT_EQ(s.uniquePaths(2,3), 3);
	EXPECT_EQ(s.uniquePaths(3,2), 3);

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

