#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) {
        vector<int> ans(queries.size());
        int sumOfEvens = 0;
        for (auto item : A)
            if (item % 2 == 0)
                sumOfEvens += item;
        for (int i = 0; i < queries.size(); ++i) {
            int index = queries[i][1];
            int add = queries[i][0];
            if (A[index] % 2 == 0) {
                // even
                if (add % 2 == 0) {
                    sumOfEvens += add;
                } else {
                    sumOfEvens -= A[index];
                }
            } else {
                // odd
                if (add % 2 != 0) {
                    sumOfEvens += A[index] + add;
                }
            }
            A[index] += add;
            ans[i] = sumOfEvens;
        }
        return ans;
    }
};

void test1() {
//    vector<int> v1{1, 2, 3, 4};
//    vector<vector<int>> q1{
//            vector<int>{1, 0},
//            vector<int>{-3, 1},
//            vector<int>{-4, 0},
//            vector<int>{2, 3}
//    };
//
//    cout << "[8,6,2,4] ? " << Solution().sumEvenAfterQueries(v1, q1) << endl;

    // [-1,3,-3,9,-6,8,-5]
    //[[-5,1],[10,2],[10,2],[3,2],[9,5],[7,5],[8,0]]

    vector<int> v2{-1, 3, -3, 9, -6, 8, -5};
    vector<vector<int>> q2{
            vector<int>{-5, 1},
            vector<int>{10, 2},
            vector<int>{-6, 3},
            vector<int>{3, 2},
            vector<int>{9, 5},
            vector<int>{7, 5},
            vector<int>{8, 0},

    };

    cout << "[0,0,0,10,2,26,26] ? " << Solution().sumEvenAfterQueries(v2, q2) << endl;

}

void test2() {

}

void test3() {

}