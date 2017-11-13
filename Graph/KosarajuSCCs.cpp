#include<iostream>
#include<list>
#include<stack>
#include<vector>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    void fillOrder(int v, vector<bool> &visited,stack<int> &Stack);
    void DFSUtil(int v,vector<bool> &visited);
    public:
    Graph(int v);
    void addEdge(int v,int w);
    void printSCCs();
    Graph getTranspose();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::DFSUtil(int v, vector<bool> &visited)
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
        if(!visited[*i])
            DFSUtil(*i,visited);
}

Graph Graph::getTranspose()
{
    Graph g(v);
    for(int j=0;j<v;j++)
    {
        list<int>::iterator i;
        for(i=adj[j].begin();i!=adj[j].end();i++)
            g.adj[*i].push_back(j);
    }
    return g;
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, vector<bool> &visited,stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
        if(!visited[*i])
            fillOrder(*i,visited,Stack);
    Stack.push(v);
}

void Graph::printSCCs()
{
    stack<int> Stack;
    vector<bool> visited(v,false);

    for(int i=0;i<v;i++)
        if(!visited[i])
            fillOrder(i,visited,Stack);

    Graph gr = getTranspose();

    for(int i=0;i<v;i++)
        visited[i] = false;

    while(!Stack.empty())
    {
        int v= Stack.top();
        Stack.pop();

        if(visited[v] == false)
        {
            gr.DFSUtil(v,visited);
            cout << endl;
        }
    }
}


int main()
{
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);

    cout << "Following are the stringly connected components in the given graph " << endl;

    g.printSCCs();

    return 0;
}
