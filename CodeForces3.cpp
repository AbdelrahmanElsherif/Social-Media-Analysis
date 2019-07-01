#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <sstream>
#include <set>
#include <limits>
#include <stack>
#include <queue>
using namespace std;

typedef std::numeric_limits< double > dbl;

int number_of_nodes;
int number_of_edges;

void All_Routes(int Src, int Dst, int &Betweenness, vector<bool> &visited, vector<int> &Route, int &Index, vector<list<pair<int, int>>> &adj_list, vector<int> &Shortest_Route, vector<vector<int>> & Solve);
int Get_Weight(int Src, int Dst, vector<list<pair<int, int>>> &adj_list);

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

		for (int k = 0; k < number_of_nodes; k++)
		{
			vector<float> Sum;

			float Answer = 0;

			for (int i = 0; i < number_of_nodes; i++)
			{
				for (int j = i + 1; j < number_of_nodes; j++)
				{
					vector<int> Shortest_Route;

					vector<vector<int>> Solve;

					vector<bool> Visited(number_of_nodes);

					vector<int> Route(number_of_nodes);

					int Numerator = 0;

					int Denominator = 1;

					int Index = 0;

					All_Routes(i, j, k, Visited, Route, Index, adj_list, Shortest_Route, Solve);

					for (int i = 0; i < Solve.size(); i++)
					{
						if ((Solve[i][0] == Shortest_Route[0]) && (Solve[i][1] == 1))
							Numerator++;
					}

					for (int i = 1; i < Shortest_Route.size(); i++)
					{
						if (Shortest_Route[i] == Shortest_Route[0])
							Denominator++;
					}

					Sum.push_back((float)Numerator / Denominator);
				}
			}

			for (int i = 0; i < Sum.size(); i++)
			{
				Answer += Sum[i];
			}

			cout << Answer << endl;
		}
	
}

void All_Routes(int Src, int Dst, int &Betweenness, vector<bool> &visited, vector<int> &Route, int &Index, vector<list<pair<int, int>>> &adj_list, vector<int> &Shortest_Route, vector<vector<int>> & Solve)
{
	visited[Src] = true;
	Route[Index] = Src;
	Index++;

	int Check = 0;

	if (Src == Dst)
	{
		vector<int> Into_Vector;

		int Total_Weight = 0;
		for (int i = 1; i < Index; i++)
		{
			Total_Weight += Get_Weight(Route[i - 1], Route[i], adj_list);
		}
		Shortest_Route.push_back(Total_Weight);
		Into_Vector.push_back(Total_Weight);
		sort(Shortest_Route.begin(), Shortest_Route.end());

		for (int i = 0; i < Index; i++)
		{
			if (Route[i] == Betweenness && (i != 0) && (i != (Index - 1)))
				Check = 1;
		}

		if (Check)
		{
			Check = 0;
			Into_Vector.push_back(1);
		}
		else
			Into_Vector.push_back(0);
		Solve.push_back(Into_Vector);
	}

	else
	{
		for (list<pair<int, int>>::iterator it = adj_list[Src].begin(); it != adj_list[Src].end(); it++)
		{
			if (!visited[it->first])
				All_Routes(it->first, Dst, Betweenness, visited, Route, Index, adj_list, Shortest_Route, Solve);
		}
	}
	Index--;
	visited[Src] = false;
}

int Get_Weight(int Src, int Dst, vector<list<pair<int, int>>> &adj_list)
{
	for (list<pair<int, int>>::iterator j = adj_list[Src].begin(); j != adj_list[Src].end(); j++)
	{
		if (j->first == Dst)
			return j->second;
	}
}