#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Settlement {
public:
  template <typename T> static T input() {
    T value;
    cin >> value;
    return value;
  }
};
class Main {
public:
  static void floydAlgo(vector<vector<int>> &graph, int no_of_vertices) {
    int i;
    int j;
    int k;
    for (i = 0; i < no_of_vertices; i++) {
      for (j = 0; j < no_of_vertices; j++) {
        for (k = 0; k < no_of_vertices; k++) {
          if (graph[j][i] + graph[i][k] < graph[j][k]) {
            graph[j][k] = graph[j][i] + graph[i][k];
          }
        }
      }
    }
    Main::printResult(graph, no_of_vertices);
  }
  static void printResult(vector<vector<int>> &graph, int no_of_vertices) {
    for (int i = 0; i < no_of_vertices; ++i) {
      for (int j = 0; j < no_of_vertices; ++j) {
        if (graph[i][j] == 999999) {
          cout << "-1 ";
        } else {
          cout << to_string(graph[i][j]) + " ";
        }
      }
      cout << endl;
    }
  }
  static void main(vector<string> &args) {
    int no_of_vertices = Settlement::input<int>();
    // user input
    vector<vector<int>> graph(no_of_vertices, vector<int>(no_of_vertices));
    for (int i = 0; i < no_of_vertices; i++) {
      for (int j = 0; j < no_of_vertices; j++) {
        int input = Settlement::input<int>();
        if (input == -1) {
          input = 999999;
        }
        graph[i][j] = input;
      }
    }
    Main::floydAlgo(graph, no_of_vertices);
  }
};
int main(int argc, char **argv) {
  vector<string> parameter(argv + 1, argv + argc);
  Main::main(parameter);
  return 0;
};