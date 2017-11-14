#include<iostream>
#include<vector>
#include<list>

using namespace std;

#define NIL -1

class Graph
{
    int v;
    list<int> * adj;
    void APUtil(int v,bool visited[],int disc[],int parent[],int low[],bool ap[]);
    public:
    Graph(int v);
    void addEdge(int v,int w);
    void AP();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
//Arecursive function that finds Articulation points using DFS
//u --> the vertex to be visited 
//visited[] : keeps track of visited vertices
//disc[] : stores discovery times of vertices
//parent[] : stores parent vertices in DFS tree
//ap[] : stores the articulation vertices in graph
void Graph::APUtil(int u,bool visited[],int disc[],int low[],int parent[],bool ap[])
{
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    
    list<int>::iterator i;
    for( i = adj[u].begin(); i!= adj[u].end();i++)
    {
        int v= *i;
        if(!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v,visited,disc,low,parent,ap);

            low[u] = min(low[u],low[v]);

            //u is an articulation in following cases

            //(1) u is a root and it has more than 2 children
            if( parent[u] == NIL && children > 1)
                ap[u] = true;

            //(2) if u is not root and low value of one its child is more than
            // discovery value of u
            if( parent[u] != NIL && low[v] >= disc[u])
                ap[u] = true;

        }
        //update low value of u for parent function calls
        else if (v != parent[u])
            low[u] = min(low[u],disc[v]);
    }
}

void Graph::AP()
{
    bool * visited = new bool[v];
    int * parent = new int[v];
    int * disc = new int[v];
    int *low = new int[v];
    bool * ap = new bool[v];

    for(int i=0;i<v;i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    for(int i=0;i<v;i++)
        if(visited[i] == false)
            APUtil(i,visited,disc,low,parent,ap);

    for(int i=0;i<v;i++)
        if(ap[i] == true)
            cout << i << " ";
}

int main()
{
    cout << "\nArticulation points in first Graph " << endl;
    Graph g1(5);
    g1.addEdge(1,0);
    g1.addEdge(0,2);
    g1.addEdge(2,1);
    g1.addEdge(0,3);
    g1.addEdge(3,4);
    g1.AP();

    cout <<"\nArticulation points in 2nd graph " << endl;
    Graph g2(4);
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.AP();

    cout << "\nArticulation points in 3rd graph " << endl;
    Graph g3(7);
    g3.addEdge(0,1);
    g3.addEdge(1,2);
    g3.addEdge(2,0);
    g3.addEdge(1,3);
    g3.addEdge(1,4);
    g3.addEdge(1,6);
    g3.addEdge(3,5);
    g3.addEdge(4,5);
    g3.AP();

    cout << endl;
    return 0;
}
