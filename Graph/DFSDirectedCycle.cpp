#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph
{
    int v;
    list<int> * adj;
    bool isCyclicUtil(int v,vector<bool>& visited,vector<bool>& recStack);
    public:
    Graph(int v);
    void addEdge(int u,int v);
    bool isCyclic();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
};

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}

bool Graph::isCyclicUtil(int v,vector<bool>& visited,vector<bool>& recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(i= adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i] && isCyclicUtil(*i,visited,recStack))
                return true;
            else if(recStack[*i])
                return true;
        }
    }
    recStack[v] = false; //remove from recursion stack
    return false;
}

bool Graph::isCyclic()
{
    vector<bool> visited(v,false);
    vector<bool> recStack(v,false);

    for(int i=0;i<v;i++)
        if(isCyclicUtil(i,visited,recStack))
            return true;

    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    if(g.isCyclic())
        cout << "There is a CYCLE in graph" << endl;
    else
        cout << "NO CYCLE in graph " << endl;

    return 0;
}
