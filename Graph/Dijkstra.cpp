#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<queue>

#define INF 0x3f3f3f3f
using namespace std;

class Graph
{
        int V;
        list <pair<int,int> > * adj;
        public:
        Graph(int v);
        void addEdge(int u,int v,int w);
        void shortestPathDijkstras_usingSet(int src);
        void shortestPathDijkstras_usingPriorityQueue(int src);
};

Graph::Graph(int v)
{
        this->V = v;
        adj = new list < pair<int,int> > [v];
}

void Graph::addEdge(int u,int v,int w)
{
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w)); //undirected so adding the edge to both the vertices
}

void Graph::shortestPathDijkstras_usingSet(int src)
{
        set< pair<int,int> > setds;
        vector<int> dist(V,INF);
        setds.insert(make_pair(0,src));
        dist[src] = 0;
        while(!setds.empty())
        {
                pair<int,int> tmp = *(setds.begin());
                setds.erase(setds.begin());
                int u = tmp.second; // the vertex
                list< pair<int,int> >::iterator i;
                for(i=adj[u].begin();i!=adj[u].end();i++)
                {
                        int v = (*i).first;
                        int weight = (*i).second;
                        if(dist[v] > dist[u]+weight)
                        {
                                if(dist[v] != INF)
                                        setds.erase(setds.find(make_pair(dist[v],v)));
                                dist[v] = dist[u] + weight;
                                setds.insert(make_pair(dist[v],v));
                        }
                }
        }

        cout << "Vertex distances from source" << endl;
        for(int i=0;i<dist.size();i++)
                cout << i << " : " << dist[i] << endl;

}

void Graph::shortestPathDijkstras_usingPriorityQueue(int src)
{
        priority_queue< pair<int,int>, vector<pair<int,int> > , greater< pair<int,int> > >pq;
        vector<int> dist(V,INF);
        pq.push(make_pair(0,src));
        dist[src] = 0;
        while(!pq.empty())
        {
                int u = pq.top().second;
                cout << pq.top().first << " :: " << pq.top().second << endl;
                pq.pop();
                list< pair<int,int> >::iterator i;
                for(i=adj[u].begin(); i!= adj[u].end(); i++)
                {
                        int v= (*i).first;
                        int weight = (*i).second;

                        if(dist[v] > dist[u]+weight)
                        {
                                dist[v] = dist[u] + weight;
                                pq.push(make_pair(dist[v],v));
                                //cout << "Size of pq : " << pq.size() << endl;
                        }
                }
        }
        cout << "Vertex distances from source||PQ" << endl;
        for(int i=0;i<dist.size();i++)
                cout << i << " : " << dist[i] << endl;
}



int main()
{
        cout << "Graph Algorithms >>>>>> " << endl;
        int V=9;
        Graph g(V);
        g.addEdge(0,1,4);
        g.addEdge(0,7,8);
        g.addEdge(1,2,8);
        g.addEdge(1,7,11);
        g.addEdge(2,3,7);
        g.addEdge(2,8,2);
        g.addEdge(2,5,4);
        g.addEdge(3,4,9);
        g.addEdge(3,5,14);
        g.addEdge(4,5,10);
        g.addEdge(5,6,2);
        g.addEdge(6,7,1);
        g.addEdge(6,8,6);
        g.addEdge(7,8,7);

        g.shortestPathDijkstras_usingSet(0);
        g.shortestPathDijkstras_usingPriorityQueue(0);
        priority_queue< pair<int,int>, vector<pair<int,int> > , greater< pair<int,int> > >pq1;
        pq1.push(make_pair(0,2));
        cout << "size of pq1 " << pq1.size()<< endl;
        pq1.push(make_pair(0,1));
        cout << "size of pq1 " << pq1.size()<< endl;

        while(!pq1.empty())
        {
                cout <<  pq1.top().first << " : " << pq1.top().second << endl;
                pq1.pop();
        }

        return 0;
}
