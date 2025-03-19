/*
Input:
  Let n distinct intervals [a1, b1[, . . . , [an, bn[ of the real line be given, 
  open to the right, where interval i is associated with a profit wi, 1 ≤ i ≤ n.

Disjoint intervals:
  Two intervals i and j are called disjoint if: bj ≤ ai or bi ≤ aj

Problem:
  Find a maximum-weight independent set, that is, a subset of mutually disjoint intervals 
  such that the sum of their profits is as large as possible.

Version-0:
  We could try every possible set combination, 
  but the number of possibility grows exponentialy. O(2^n)

Version-1:
  If we want to use DP a preprocessing step is required: 
  sorting the intervals by non-decreasing right endpoints. 
  But it would take
  O(n^2)



*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
 
    return 0;
}