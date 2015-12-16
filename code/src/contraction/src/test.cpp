#include "../graphMinimizer.hpp"
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include "./fetch.hpp"
using namespace std;
using namespace boost;
typedef adjacency_list<vecS, vecS, undirectedS, Vertex,Edge> G;
void check(Edge *edges,int num_vertices,int num_edges)
{
	int path_size=0;
	typedef Graph_Minimizer<G> Graph;
	Graph g(UNDIRECTED,num_vertices);
	g.initialize_graph(edges,num_edges);
	g.reduced_graph->print_graph();
	g.print_Vertex_Degree();
	g.print_Degree_Vertices();
	//g.remove_vertex(0);
	cout << "Contracting...." << endl;
	g.contract_to_level(0);
	Edge *reduced=NULL;
	int final_edges=g.getreducedGraph(&reduced);
	cout << "final_edges " << final_edges << endl;
	for (int i = 0; i < final_edges; ++i)
	{
		cout << "id:- " << reduced[i].id << ", " << "source:- " << reduced[i].source << ", target:- " << reduced[i].target << endl;
	}
	//g.reduced_graph->print_graph();
}

int main(int argc, char const *argv[])
{
	Edge* edges;
	int num_edges=18;
	int num_vertices=17;
	edges=(Edge*)malloc(sizeof(Edge)*num_edges);
	loadGraph("ways.txt",&edges);
	//check(edges,num_vertices,num_edges);

	return 0;
}





























/*edges[0].id=0;
	edges[0].source=1;
	edges[0].target=2;
	edges[0].cost=0.625;
	edges[0].revcost=-1;
	
	edges[1].id=1;
	edges[1].source=2;
	edges[1].target=3;
	edges[1].cost=4;
	edges[1].revcost=-1;
	
	edges[2].id=1;
	edges[2].source=3;
	edges[2].target=4;
	edges[2].cost=4;
	edges[2].revcost=-1;
	
	edges[3].id=1;
	edges[3].source=4;
	edges[3].target=9;
	edges[3].cost=4;
	edges[3].revcost=-1;
	
	edges[4].id=1;
	edges[4].source=9;
	edges[4].target=12;
	edges[4].cost=4;
	edges[4].revcost=-1;
	
	edges[5].id=1;
	edges[5].source=12;
	edges[5].target=11;
	edges[5].cost=4;
	edges[5].revcost=-1;
	
	edges[6].id=1;
	edges[6].source=11;
	edges[6].target=10;
	edges[6].cost=4;
	edges[6].revcost=-1;

	edges[7].id=1;
	edges[7].source=10;
	edges[7].target=5;
	edges[7].cost=4;
	edges[7].revcost=-1;
	
	edges[8].id=1;
	edges[8].source=5;
	edges[8].target=2;
	edges[8].cost=4;
	edges[8].revcost=-1;

	edges[9].source=17;
	edges[9].target=16;
	edges[9].cost=4;
	edges[9].revcost=-1;
	
	edges[10].id=1;
	edges[10].source=6;
	edges[10].target=3;
	edges[10].cost=4;
	edges[10].revcost=-1;
	
	edges[11].id=1;
	edges[11].source=10;
	edges[11].target=13;
	edges[11].cost=4;
	edges[11].revcost=-1;
	
	edges[12].id=1;
	edges[12].source=14;
	edges[12].target=15;
	edges[12].cost=4;
	edges[12].revcost=-1;
	
	edges[13].id=1;
	edges[13].source=7;
	edges[13].target=8;
	edges[13].cost=4;
	edges[13].revcost=-1;
	
	edges[14].id=1;
	edges[14].source=8;
	edges[14].target=5;
	edges[14].cost=4;
	edges[14].revcost=-1;
	
	edges[15].id=1;
	edges[15].source=5;
	edges[15].target=6;
	edges[15].cost=4;
	edges[15].revcost=-1;
	
	edges[16].id=1;
	edges[16].source=6;
	edges[16].target=9;
	edges[16].cost=4;
	edges[16].revcost=-1;
	
	edges[17].id=1;
	edges[17].source=11;
	edges[17].target=6;
	edges[17].cost=4;
	edges[17].revcost=-1;*/
	
	