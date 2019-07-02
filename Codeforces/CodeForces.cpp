#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <list>
#include <sstream>
#include <set>
using namespace std;

long number_of_nodes;
long number_of_edges;


int main() {
	
	cin >> number_of_nodes;
	cin >> number_of_edges;

	vector<list<pair<int, int>>> adj_list(number_of_nodes);


	//INPUT PART
	for (long i = 0; i < number_of_edges; i++)
	{
		int node;
		int target;
		int weight;
		cin >> node >> target >> weight;

		adj_list[node].push_back(make_pair(target, weight));
		adj_list[target].push_back(make_pair(node, weight));
	}
	//END OF INPUT PART

	for (long i = 0; i < number_of_nodes; i++)
	{
		cout << adj_list[i].size() << "\n";
	}

}
