#include <iostream>
#include <list>
#include <stack>
#include <cstring>
#include <limits.h>
using namespace std;
class Graph
{
    int V;    
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}
 
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    Stack.push(v);
}
void Graph::topologicalSort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    while (Stack.empty() == false)
    {
        cout << (char) ('a' + Stack.top()) << "\n";
        Stack.pop();
    }
}
 
int min(int x, int y)
{
    return (x < y)? x : y;
}
 
void printOrder(string words[], int n, int alpha)
{
    Graph g(alpha);
    for (int i = 0; i < n-1; i++)
    {
        string word1 = words[i], word2 = words[i+1];
        for (int j = 0; j < min(word1.length(), word2.length()); j++)
        {
            if (word1[j] != word2[j])
            {
                g.addEdge(word1[j]-'a', word2[j]-'a');
                break;
            }
        }
    }
    g.topologicalSort();
}
int main()
{
	int n,i,j,count=0,c[26]={0},max=INT_MIN;
    string words[1000];
    cin>>n;
    for(i=0;i<n;i++)
	cin>>words[i];
	for(i=0;i<n;i++)
	{
		for(j=0;words[i][j];j++)
		{
			c[words[i][j]-97]++;
		}
	}
	for(i=0;i<26;i++)
	{
		if(c[i]>0)
		count++;
	}
  printOrder(words, n,count);
    return 0;
}