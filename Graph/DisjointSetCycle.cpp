//Detect cycle in a undirected graph using disjoint set
#include<iostream>
#include<vector>

using namespace std;

struct Edge
{
    int src,dest;
};

struct Graph
{
    int v,e;
    Edge * edge;
};

Graph * createGraph(int v, int e)
{
    Graph * graph = new Graph;
    graph->v = v;
    graph->e = e;
    graph->edge = new Edge[e];
    return graph;
}

int find(vector<int>& parent,int i)
{
    if(parent[i] == -1)
        return i;
    return find(parent,parent[i]);
}

void Uniion(vector<int>& parent,int x, int y)
{
    int xset = find(parent,x);
    int yset = find(parent,y);

    parent[xset] = yset;
}

//the main function to check whether there is a cycle in a graph
int isCycle(Graph * graph)
{
    int v = graph->v;
    int e = graph->e;
    vector<int> parent(v,-1);
    for(int i=0;i<graph->e ; i++)
    {
        int x = find(parent,graph->edge[i].src);
        int y = find(parent,graph->edge[i].dest);

        if(x==y)
            return 1;

        Uniion(parent,x,y);
    }
    return 0;
}
int main()
{
    int v = 3, e = 3;
    Graph* graph = createGraph(v,e);

    //add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    //add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    //add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if(isCycle(graph))
        cout << "There is a cycle in this graph " << endl;
    else
        cout << "NO CYCLE in this graph " << endl;

     return 0;
}
