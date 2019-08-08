//============================================================================
// Name        : Project_DS.cpp
// Author      : Ali Amr Farouk
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

/*
Used this input as a test:
 	 4 5
	0 2 10
	1 0 1
	0 3 5
	3 1 1
	2 3 4
 *
 */

//Returns degree of node n
int find_degree(int n, vector<list<pair<int, int>>> adj_list);

int main() {
	//File that the dot language will be saved in, describing the graphs (to be used by graphviz)
	ofstream  dotfile("graph1.dt", ofstream::trunc);
	int number_of_nodes;
	int number_of_edges;

	cin >> number_of_nodes;
	cin >> number_of_edges;

	//Each pair is (destination node, weight of edge)
	vector<list<pair<int, int>>> adj_list(number_of_nodes);


	dotfile << "graph" << endl;
	dotfile << "{" << endl;
//INPUT PART
	for(int i = 0; i < number_of_edges; i++)
	{
		int node;
		int target;
		int weight;
		cin >> node >> target >> weight;

		adj_list[node].push_back(make_pair(target, weight));
		adj_list[target].push_back(make_pair(node, weight));
		dotfile << node << " -- " << target << " [label = " << weight << "];" << endl;
	}
//END OF INPUT PART

	//Change node size according to it's degree (in dot language)
	for(int i = 0; i < number_of_nodes; i++)
		dotfile << i << "[shape = circle, width = " << ((float)find_degree(i, adj_list) / number_of_edges) * 3 << "];" << endl;

	//Closing the dot file.
	dotfile << "}";
	dotfile.close();

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

	system("cppbatch_main.bat");

	return 0;
}


//Returns degree of node n
int find_degree(int n, vector<list<pair<int, int>>> adj_list)
{
	return adj_list[n].size();
}
