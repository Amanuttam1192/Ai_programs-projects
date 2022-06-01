#include <bits/stdc++.h>
using namespace std;
#define V 4
// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
// store all vertex apart from source vertex
vector<int> vertex;
for (int i = 0; i < V; i++)
if (i != s)
vertex.push_back(i);
// store minimum weight Hamiltonian Cycle.
int min_path = INT_MAX;
do {
// store current Path weight(cost)
int current_pathweight = 0;
// compute current path weight
int k = s;
for (int i = 0; i < vertex.size(); i++) {
current_pathweight += graph[k][vertex[i]];
k = vertex[i];
}
current_pathweight += graph[k][s];
// update minimum
min_path = min(min_path, current_pathweight);
} while (
next_permutation(vertex.begin(), vertex.end()));
return min_path;
}
// Driver Code
int main()
{
// matrix representation of graph
int graph[][V] = { { 0, 10, 15, 20 },
{ 10, 0, 35, 25 },
{ 15, 35, 0, 30 },
{ 20, 25, 30, 0 } };
int s = 0;
cout << travllingSalesmanProblem(graph, s) << endl;
return 0;}
Problem 11: Write a Program to Implement Camel and Banana Puzzle. 
#include <bits/stdc++.h>
using namespace std;
int dp[1001][3001];
int recBananaCnt(int A, int B, int C)
{
if (B <= A) {
return 0;
}
if (B <= C) {
return B - A;
}
// Base Case where distance = 0
if (A == 0) {
return B;
}
if (dp[A][B] != -1) {
return dp[A][B];
}
// Stores the maximum count of bananas
int maxCount = INT_MIN;
int tripCount = B % C == 0 ? ((2 * B) / C) - 1
: ((2 * B) / C) + 1;
for (int i = 1; i <= A; i++) {
int curCount
= recBananaCnt(A - i,
B - tripCount * i, C);
if (curCount > maxCount) {
maxCount = curCount;
// Memoize the current value
dp[A][B] = maxCount;
}
}
return maxCount;
}
int maxBananaCnt(int A, int B, int C)
{
// Initialize dp array with -1
memset(dp, -1, sizeof(dp));
// Function Call
return recBananaCnt(A, B, C);
}
// Driver Code
int main()
{
int A = 1000;
int B = 3000;
int C = 1000;
cout << maxBananaCnt(A, B, C);
return 0;
}
