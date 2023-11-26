#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <ctime>

using namespace std;


void initializeGrid(vector<vector<bool>>& grid) {
   int M = grid.size();
   int N = grid[0].size();
   srand(time(nullptr));
   for (int i = M/2 - 6; i < M/2 + 6; ++i) {
       for (int j = N/2 - 6; j < N/2 + 6; ++j) {
           grid[i][j] = rand() % 4 < 3; // Alive with probability 3/4
       }
   }
}

int countAliveNeighbors(const vector<vector<bool>>& grid, int x, int y) {
   int aliveNeighbors = 0;
   int M = grid.size();
   int N = grid[0].size();
   for (int i = -1; i <= 1; ++i) {
       for (int j = -1; j <= 1; ++j) {
           if (i == 0 && j == 0) continue; // Skip the cell itself
           int newX = (x + i + M) % M; // Wrap around for periodic boundary
           int newY = (y + j + N) % N;
           if (grid[newX][newY]) {
               ++aliveNeighbors;
           }
       }
   }
   return aliveNeighbors;
}


void printGrid(const vector<vector<bool>>& grid) {
   int M = grid.size();
   int N = grid[0].size();
   // Imprimir a linha superior da borda
   cout << "+"; // Canto superior esquerdo
   for (int j = 0; j < N; ++j) {
       cout << "-"; // Linha superior da borda
   }
   cout << "+" << endl; // Canto superior direito


   for (int i = 0; i < M; ++i) {
       cout << "|"; // Início da linha da borda
       for (int j = 0; j < N; ++j) {
           cout << (grid[i][j] ? 'O' : ' '); // Célula viva ou morta
       }
       cout << "|" << endl; // Fim da linha da borda
   }


   // Imprimir a linha inferior da borda
   cout << "+"; // Canto inferior esquerdo
   for (int j = 0; j < N; ++j) {
       cout << "-"; // Linha inferior da borda
   }
   cout << "+" << endl; // Canto inferior direito
}




void nextGeneration(vector<vector<bool>>& grid, const vector<int>& Ssurvive, const vector<int>& Sbirth) {
  
   int M = grid.size();
   int N = grid[0].size();
   vector<vector<bool>> newGrid(M, vector<bool>(N, false));
   for (int i = 0; i < M; ++i) {
       for (int j = 0; j < N; ++j) {
           int neighbors = countAliveNeighbors(grid, i, j);
           if (grid[i][j] && find(Ssurvive.begin(), Ssurvive.end(), neighbors) != Ssurvive.end()) {
               newGrid[i][j] = true;
           } else if (!grid[i][j] && find(Sbirth.begin(), Sbirth.end(), neighbors) != Sbirth.end()) {             
               newGrid[i][j] = true;
           }
       }
   }
   grid = newGrid;
}


void timestamp() {
   char time_buffer[40];
   time_t now = time(nullptr);
   tm *tm = localtime(&now);
   strftime(time_buffer, sizeof(time_buffer), "%d %B %Y %I:%M:%S %p", tm);
   std::cout << time_buffer << std::endl;
}


int main() {
   timestamp();
   const int n = XX; //SUBSTITUA PELO TAMANHO DO SEU GRID
   const int n_generations = XX; // SUBSTITUA PELO NRO. DE GERACOES
   vector<vector<bool>> grid(n, vector<bool>(n, false));
   const vector<int> Ssurvive = {X, X, X}; //SUBSTITUA POR S_SURVIVE
   const vector<int> Sbirth = {XXX, XXX, XXX}; // SUBSTITUA POR S_BIRTH
   initializeGrid(grid);
   printGrid(grid);
   for (int generation = 1; generation <= n_generations; ++generation) {
   nextGeneration(grid, Ssurvive, Sbirth);
       if (generation % 25 == 0 || generation == n_generations) {
            printGrid(grid);
        }
   }


   return 0;
}
