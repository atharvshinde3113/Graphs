/* BT is also a graph as condition for graph = Must have Nodes and edges

edges in an undirected graph go both ways
	
cycle: start at node and end at the same node. 2 nodes are also enough to create a cycle

path: contain a lot of nodes/vertices and each of them are reachable. A node cant appear twice in a path. adjacent nodes must have an edge between them.

Degree of a node(Undirected graph) : No. of nodes attached to a node. 

Total Degree of a graph(sum of degree of all nodes)= 2 x No. of Edges (as every edge is associated with 2 Nodes)


Directed graph:

1. Indegree(Node): Number of incoming edges

2. Outdegree(Node): Number of outgoing edges

*/

//Count the number of undirected graphs that can be formed with n vertices.
int countingGraphs(int n)
{
    int edges = (n*(n-1))/2;
    return pow(2,edges);
}

