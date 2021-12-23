#include <bits/stdc++.h>

#define MEM(a,b) memset((a),(b),sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MIN3(a,b,c) MIN(MIN(a,b),c)
#define MIN4(a,b,c,d) MIN(MIN(MIN(a,b),c),d)
#define In freopen("In.txt", "r", stdin);
#define Out freopen("out.txt", "w", stdout);

#define i64 long long
#define u64 long long unsigned
#define INF (1<<28)

#define sz 100

using namespace std;

vector<int> nodes[sz];
bool color[sz];

//what is bi-coloring?
//Bi-coloring is a process by which
// a graph is color-able with only
//two colors where every adjacent
//node will have different color

bool isBicolorable(int source)
{
    // this algorithms is almost as
    // Breadth first search algorithm

    queue<int> Q;
    Q.push(source);
    color[source] = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0; i<nodes[u].size(); i++)
        {
            int element = nodes[u][i];
            if(color[element]==-1) // check weather still this element is not colored
            {
                if(color[u]==0)
                    color[element] = 1; // if the previous node color is 0 then make it 1
                else color[element] = 0; // else color it using 1
                Q.push(element);
            }
            // if parent node and child node has the same color
            // means the graph is not bi-colorable
            if(color[u] == color[element])
                return false;
        }
    }
    //that means everything is fine
    //so return true
    return true;
}


int main()
{
    int node,edges;
    int u,v;
    cin >> node >> edges; // total number of nodes && edges
    for(int i=0; i<edges; i++)
    {
        cin >> u >> v; // edges between u && v
        nodes[u].push_back(v); // connection between u to v
        nodes[v].push_back(u); // connection between v to u
    }
    MEM(color,-1); // memset color using -1


    // call bi-color function which returns true if
    // it's possible to color a graph using only
    // two colors where every adjacent nodes will
    // have different colors else will return false

    bool ok = isBicolorable(0);
    cout << (ok ? "Graph is bi-colorable!!" : "Graph is not bi-colorable") << endl;

    return 0;
}

/*
Sample input:
5 6
1 2
1 3
2 4
2 5
3 5
3 4
Sample Output:
Graph is bi-colorable!!
*/
