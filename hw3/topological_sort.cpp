#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

class Graph {
private:
	std::unordered_map<int, std::vector<int> >
		graph; // adjacency list
	int V; // number of vertices
public:
	Graph(int vertices)
		: V(vertices)
	{
	}

	// function to add an edge to graph
	void addEdge(int u, int v) { graph[u].push_back(v); }

	// non-recursive topological sort
	void nonRecursiveTopologicalSort()
	{
		std::vector<bool> visited(
			V,
			false); // mark all the vertices as not visited
		std::stack<int> stack; // result stack

		// call the helper function to store Topological
		// Sort starting from all vertices one by one
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				nonRecursiveTopologicalSortUtil(i, visited,
												stack);
			}
		}

		// print contents of the stack in reverse
		std::vector<int> sorted;
		while (!stack.empty()) {
			sorted.push_back(stack.top());
			stack.pop();
		}
		std::cout << "The following is a Topological Sort "
					"of the given graph:\n";
		for (auto& i : sorted) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

private:
	// helper function for non-recursive topological sort
	void nonRecursiveTopologicalSortUtil(
		int v, std::vector<bool>& visited,
		std::stack<int>& stack)
	{
		visited[v] = true;

		for (auto& next_neighbor : graph[v]) {
			if (!visited[next_neighbor]) {
				nonRecursiveTopologicalSortUtil(
					next_neighbor, visited, stack);
			}
		}
		stack.push(v);
	}
};

int main()
{
	Graph g(8);
	g.addEdge(3, 7);
	g.addEdge(4, 7);
	g.addEdge(4, 5);
	g.addEdge(5, 9);
	g.addEdge(1, 9);
	g.addEdge(1, 6);
	g.addEdge(6, 8);
	g.addEdge(2, 8);

	g.nonRecursiveTopologicalSort();
	return 0;
}





