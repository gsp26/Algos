#include<iostream>
#include<list>
#include<stack>
#include<vector>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    public:
    Graph(int v);
    void addEdge(int v,int w);
    void BFS(int s);
    void DFSUtil(int v,bool visited[]);
    void DFS();
    void DFSIterative(int s);
    void topologicalSort();
    void topologicalSortUtil(int v,vector<bool>& visited,stack<int> &st);
    void DijkstraShortestPath(int src);
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    //mark all vertices not visited 
    bool * visited = new bool[v];

    for(int i=0;i<v;i++)
        visited[i] = false;
    //queue for bfs
    list<int> queue;

    //insert source s and mark as visited 
    queue.push_back(s);
    visited[s] = true;

    while(!queue.empty())
    {
        s = queue.front();
        queue.pop_front();

        cout << s << " ";
        list<int>::iterator i;
        for(i=adj[s].begin();i != adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}


void Graph::DFSUtil(int v,bool visited[])
{
    //make the current node visited and print it
    visited[v] = true;
    cout << v << " ";

    //recur all vertices adjacent to this vertex.
    list<int>::iterator i;
    for(i= adj[v].begin();i != adj[v].end();i++)
        if(!visited[*i])
           DFSUtil(*i,visited);
}

void Graph::DFS()
{
    bool *visited = new bool[v];
    for(int i=0;i<v;i++)
        visited[i] = false;

    //call the recusrsive helper function to print dfs traversal
    //starting from all the vertices one by one
    for(int i=0;i<v;i++)
        if(visited[i] == false)
            DFSUtil(i,visited);
}

void Graph::DFSIterative(int s)
{
    vector<bool> visited(v,false);

    stack<int> st;
    st.push(s);

    while(!st.empty())
    {
        s = st.top();
        st.pop();

        //stack may contain some vertex twice. so we need 
        //to print the popped item only if it is unvisited
        if(!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }

        //get all adjacent vertices of the popped vertex s
        //if a adjacent vertex is not visited then push it to stack
        for(list<int>::iterator i = adj[s].begin();i!= adj[s].end();i++)
            if(!visited[*i])
                st.push(*i);
    }
}

void Graph::topologicalSortUtil(int i,vector<bool>& visited,stack<int>& st)
{
    visited[i] = true;
    list<int>:: iterator it;
    for(it = adj[i].begin();it!=adj[i].end();it++)
        if(!visited[*it])
            topologicalSortUtil(*it,visited,st);

    st.push(i);
}




void Graph::topologicalSort()
{
    vector<bool> visited(v,false);
    stack<int> st;

    for(int i=0;i<v;i++)
        if(!visited[i])
            topologicalSortUtil(i,visited,st);

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
    

void Graph::DijkstraShortestPath(int src)
{
    //a data structure to store all nodes with there distance 



int main()
{
    Graph g(6);
    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);


    cout << "BFS Traversal" << endl;

    g.BFS(2);

    cout << "\nDFS recursive Traversal " << endl;
    g.DFS();

    cout << "\nDFS Iterative Traversal " << endl;
    g.DFSIterative(0);

    cout << "\nTopological sort Traversal " << endl;
    g.topologicalSort();
    cout << endl;
    return 0;
}

