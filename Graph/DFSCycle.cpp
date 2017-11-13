#include<iostream>
#include<list>
#include<limits.h>
#include<vector>

using namespace std;

class Graph
{
    int v;
    list<int> * adj;
    bool isCyclicUtil(int v,vector<bool> & visited,int parent);
    public:
    Graph(int v);
    void addEdge(int v,int u);
    bool isCyclic();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::isCyclicUtil(int v,vector<bool>& visited,int parent)
{
    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if(!visited[*i])
        {
            if(isCyclicUtil(*i,visited,v))
                return true;
        }
        else if (*i != parent)
            return true;
    }
    return false;
}

bool Graph::isCyclic()
{
    vector<bool> visited(v,false);

    for(int u=0;u<v;u++)
        if(!visited[u] )
            if(isCyclicUtil(u,visited,-1))
                return true;

    return false;
}

int main()
{
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);

    g.isCyclic() ? cout << "There is a CYCLE " << endl : cout << "NO CYCLE " << endl;

    Graph g1(3);

    g1.addEdge(0,1);
    g1.addEdge(1,2);

    g1.isCyclic() ? cout << "There is a CYCLE " << endl : cout << "NO CYCLE " << endl;


    return 0;
}
    
