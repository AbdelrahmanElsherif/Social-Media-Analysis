#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

//Returns degree of node n
int find_degree(int n, vector<list<pair<int, int>>> adj_list);

int main() {
	int number_of_nodes;
	int number_of_edges;

	cin >> number_of_nodes;
	cin >> number_of_edges;

	//Each pair is (destination node, weight of edge)
	vector<list<pair<int, int>>> adj_list(number_of_nodes);


//INPUT PART
	for(int i = 0; i < number_of_edges; i++)
	{
		int node;
		int target;
		int weight;
		cin >> node >> target >> weight;

		adj_list[node].push_back(make_pair(target, weight));
		adj_list[target].push_back(make_pair(node, weight));
	}
//END OF INPUT PART


//JUST AN EXAMPLE OF ACCESSING THE ADJACENCY LIST!, CAN BE OMITTED
	for(int i = 0; i < number_of_nodes; i++)
	{
		for(list<pair<int, int>>::iterator j = adj_list[i].begin(); j != adj_list[i].end(); j++)
		{
			cout << "Node:" << i << ", Target: " << j->first << ", Weight: " << j->second << endl;
		}
	}
//END OF EXAMPLE


//JUST AN EXAMPLE OF FINDING THE DEGREES OF NODES
	for(int i = 0; i < number_of_nodes; i++)
	{
		cout << "degree of " << i << " = " << find_degree(i, adj_list) << endl;
	}
//END OF EXAMPLE

	return 0;
}


//Returns degree of node n
int find_degree(int n, vector<list<pair<int, int>>> adj_list)
{
	return adj_list[n].size();
}
