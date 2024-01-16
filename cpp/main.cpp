/*!
    \file "main.cpp"

    Author: Matt Ervin <matt@impsoftware.org>
    Formatting: 4 spaces/tab (spaces only; no tabs), 120 columns.
    Doc-tool: Doxygen (http://www.doxygen.com/)

    https://leetcode.com/problems/path-sum/
*/

//!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/main.md
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode const* root, int const targetSum, int_least32_t const cumulativeSum = 0) {
        if (!root) { return false; }
        auto const currentSum = cumulativeSum + root->val;
        return !root->left && !root->right
               ? targetSum == currentSum
               : (hasPathSum(root->left, targetSum, currentSum)
                  || hasPathSum(root->right, targetSum, currentSum));
    }
};

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

TEST_CASE("Case 1")
{
    cerr << "Case 1" << '\n';
    auto tree = createLevelOrderBT({5,4,8,11,null,13,4,7,2,null,null,null,1});
    auto const targetSum = 22;
    auto const expected = true;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result =  Solution{}.hasPathSum(tree.get(), targetSum);
        CHECK(result == expected);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 2")
{
    cerr << "Case 2" << '\n';
    auto tree = createLevelOrderBT({1,2,3});
    auto const targetSum = 5;
    auto const expected = false;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result =  Solution{}.hasPathSum(tree.get(), targetSum);
        CHECK(result == expected);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 3")
{
    cerr << "Case 3" << '\n';
    auto tree = createLevelOrderBT({});
    auto const targetSum = 0;
    auto const expected = false;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result =  Solution{}.hasPathSum(tree.get(), targetSum);
        CHECK(result == expected);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 4")
{
    cerr << "Case 4" << '\n';
    auto tree = createLevelOrderBT({1,2});
    auto const targetSum = 1;
    auto const expected = false;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result =  Solution{}.hasPathSum(tree.get(), targetSum);
        CHECK(result == expected);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 4")
{
    cerr << "Case 4" << '\n';
    auto tree = createLevelOrderBT({-2,null,-3});
    auto const targetSum = -5;
    auto const expected = true;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result =  Solution{}.hasPathSum(tree.get(), targetSum);
        CHECK(result == expected);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

/*
    End of "main.cpp"
*/
