
// Author: Arshaq Waseem
// Roll No: 22L-7697

#include <iostream>

#include <string>
#include <fstream>

#include <Windows.h>
#include <stdlib.h>

#include "BinarySearchTree.h"
#include "Min_Heap.h"
#include "my_Graph.h"
#include "Customer.h"

#include <cwchar>
#include <vector>

#include<chrono>
#include<thread>


using namespace std;

using namespace this_thread;
using namespace chrono;


int index(int* arr, vector<int>& vec, int var){
	for (auto i : vec){
		if (arr[i] == var){
			return i;
		}
	}
	return -1; 
}

void shortest_path(my_Graph& my_map, int source, int destination){

	const int total_locations = my_map.total_vertices;
	int start = source;

	int* arr = new int[total_locations];
	for (int i = 0; i < total_locations; i++){
		arr[i] = INT_MAX; //initialize to infinity
	}

	bool* visited = new bool[total_locations];
	for (int i = 0; i < total_locations; i++){
		visited[i] = false;
	}

	arr[source] = 0;
	visited[source] = true;


	int* prev = new int[total_locations];
    for (int i = 0; i < total_locations; i++) {
        prev[i] = -1;
    }


	for (int i = 0; i < total_locations; i++)
	{
		Min_Heap<int> f(total_locations);
		vector<int> vec;
		for (int j = 0; j < total_locations; j++){
			if (arr[j] == INT_MAX && my_map.matrix[start][j] != 0)
			{
				arr[j] = my_map.matrix[start][j] + arr[start];
				prev[j] = start;
				f.insert(my_map.matrix[start][j] + arr[start]);
				vec.push_back(j);
			}
			else if (visited[j] != true && my_map.matrix[start][j] != 0)
			{
				if (my_map.matrix[start][j] + arr[start] < arr[j]){
					arr[j] = my_map.matrix[start][j] + arr[start];
					prev[j] = start;
				}
				f.insert(arr[j]);
				vec.push_back(j);
			}
			//else if (my_map.matrix[start][j] != 0 && arr[j] > my_map.matrix[start][j] + arr[start]){
			//	arr[j] = my_map.matrix[start][j] + arr[start];
			//	f.insert(my_map.matrix[start][j] + arr[start]);
			//	vec.push_back(j);
			//}
		}
		visited[start] = true;
		start = index(arr, vec, f.Delete());
		if (start == -1){
			break;
		}
	}

	vector<int> path;
    for (int at = destination; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

	if (path.size() == 1 && path[0] == source) {
        cout << "No path from " << source << " to " << destination << endl;
    } else {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

	delete[] prev;



}


int main()
{

	const int nodes = 40;
	
	my_Graph my_map(29);


	my_map.construct_road(0, 1, 4);
	my_map.construct_road(0, 2, 5);
	my_map.construct_road(0, 3, 3);
	my_map.construct_road(0, 4, 2);
	my_map.construct_road(0, 5, 1);

	my_map.construct_road(5, 6, 1);
	my_map.construct_road(5, 9, 2);
	my_map.construct_road(5, 28, 6);

	my_map.construct_road(6, 7, 2);

	my_map.construct_road(7, 8, 1);
	my_map.construct_road(7, 11, 3);
	my_map.construct_road(8, 12, 3);
	my_map.construct_road(8, 10, 2);

	my_map.construct_road(10, 13, 4);
	my_map.construct_road(10, 14, 3);
	my_map.construct_road(10, 15, 2);
	my_map.construct_road(10, 16, 1);
	my_map.construct_road(10, 17, 3);

	my_map.construct_road(16, 18, 4);
	my_map.construct_road(16, 19, 3);

	my_map.construct_road(19, 20, 3);

	my_map.construct_road(20, 21, 2);
	my_map.construct_road(20, 22, 1);

	my_map.construct_road(22, 23, 1);

	my_map.construct_road(23, 24, 1);

	my_map.construct_road(24, 25, 2);
	my_map.construct_road(24, 27, 1);

	my_map.construct_road(25, 27, 4);

	my_map.construct_road(26, 28, 2);

	my_map.construct_road(27, 28, 4);


	shortest_path(my_map, 0, 6);

	
	

	system("pause");
	return 0;
}