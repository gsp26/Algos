#include<iostream>
#include<limits.h>
#include<queue>

using namespace std;

#define v 6

bool bfs(int rGraph[v][v],int s, int t, vector<int>& parent)
{
    vector<bool> visited(v,false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0;i<v;i++)
        {
            if(visited[i] ==false  && rGraph[u][i] >0)
            {
                q.push(i);
                parent[i] = u;
                visited[i] = true;
            }
        }
    }
    return (visited[t] == true);
}


int fordFulkerson(int graph[v][v],int s,int t)
{
    
    int rGraph[v][v];

    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            rGraph[i][j] = graph[i][j];

    vector<int> parent(v);
    
    int max_flow = 0;

    while(bfs(rGraph,s,t,parent))
    {
        int path_flow = INT_MAX;
        for(int i=t;i!=s;i=parent[i])
        {
            int j = parent[i];
            path_flow = min(path_flow,rGraph[j][i]);
        }

        for(int i=t;i!=s;i=parent[i])
        {
            int j =parent[i];
            rGraph[j][i] -= path_flow;
            rGraph[i][j] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int graph[v][v] = { {0,16,13,0,0,0},
                        {0,0,10,12,0,0},
                        {0,4,0,0,14,0},
                        {0,0,9,0,0,20},
                        {0,0,0,7,0,4},
                        {0,0,0,0,0,0}};
     cout << "The maximum possible flow - " << fordFulkerson(graph,0,5) << endl;

     return 0;
}
