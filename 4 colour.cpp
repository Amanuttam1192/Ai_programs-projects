#include <iostream>
#include <cstdio>
#define V 5
using namespace std;
bool isSafe (int v, bool graph[V][V], int col[], int C) {
   for (int i = 0; i < V; i++)
   if (graph[v][i] && C == col[i])
   return false;
   return true;
}
bool graphColoringtil(bool g[V][V], int k, int col[], int v) {
   if (v == V) //If all vertices are assigned a color then
   return true;
   for (int c = 1; c <= k; c++) { //Consider this vertex v and try different colors
      if (isSafe(v, g, col, c)) { //Check if assignment of color c to v is fine
         col[v] = c;
         if (graphColoringtil (g, k, col, v+1) == true) //recur to assign colors to rest of the vertices
            return true;
         col[v] = 0; //If assigning color c doesn't lead to a solution then remove it
      }
   }
   return false;
}
void solution(int color[]) {
   cout<<"The assigned colors are: \n";
   for (int i = 0; i < V; i++)
      cout<<color[i];
   cout<<"\n";
}
bool graphColor(bool graph[V][V], int k) {
   int *color = new int[V];
   //initialize all colors value as 0
   for (int i = 0; i < V; i++)
   color[i] = 0;
   if (graphColoringtil(graph, k, color, 0) == false) {
      cout<<"Solution does not exist";
      return false;
   }
   solution(color);
   return true;
}
int main() {
   bool g[V][V] = {
      {0, 0, 1, 0,1},
      {1, 1, 1, 0,0},
      {1, 1, 0, 0,1},
      {0, 1, 1, 0,0}
   };
   int k= 4;
   graphColor(g, k);
   return 0;
}
