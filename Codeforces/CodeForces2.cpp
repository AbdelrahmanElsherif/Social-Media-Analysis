#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <sstream>
#include <set>
#include <limits>
using namespace std;
typedef std::numeric_limits< double > dbl;
int number_of_nodes;
int number_of_edges;

int dijkstra(int source, int destination, vector<list<pair<int, int>>> &adj_list);
double closeness_centrality(int n, vector<list<pair<int, int>>> &adj_list);

int main() {
		cout.precision(dbl::max_digits10);

		cin >> number_of_nodes;
		cin >> number_of_edges;

		vector<list<pair<int, int>>> adj_list(number_of_nodes);

		for (int i = 0; i < number_of_edges; i++)
		{
			int node;
			int target;
			int weight;
			cin >> node >> target >> weight;

			adj_list[node].push_back(make_pair(target, weight));
			adj_list[target].push_back(make_pair(node, weight));
		}
		
		for(int i=0;i<number_of_nodes;i++)
		{
		
			cout << closeness_centrality(i, adj_list) << "\n";
		}


	
}

int dijkstra(int source, int destination, vector<list<pair<int, int>>> &adj_list) {
	vector <int> cost(number_of_edges + 9, -1);
	set<pair<int, int>> s;
	s.insert({ 0,source }); // <cost of reaching the node , node>

	while (!s.empty()) {
		pair<int, int> p = *(s.begin()); // top of priority queue but with least cost
		s.erase(p); // pop
		int node = p.second, nodecost = p.first;
		if (cost[node] != -1) continue; //node was out from the queue before with lower cost 
		cost[node] = nodecost;
		for (pair<int, int> edge : adj_list[node]) if (cost[edge.first] == -1)
		{
			s.insert({ nodecost + edge.second, edge.first }); // cost of reaching current node + edge to neighbor , neighbor
		}
	}
	if (cost[destination] == -1) return -1;
	else return cost[destination];
}

double closeness_centrality(int n, vector<list<pair<int, int>>> &adj_list) {
	double sum = 0;
	//for (list<pair<int, int>> ::iterator it = adj_list[n].begin(); it != adj_list[n].end(); it++)
	for (int j=0;j<number_of_nodes;j++)
	{
		sum += dijkstra(n,j,adj_list);
	}
	return (double(number_of_nodes - 1) / sum);
}
