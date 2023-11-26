#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


void timestamp();


int main() {
   std::vector<int> a;
   int n, target;
   srand(static_cast<unsigned>(time(nullptr)));


   timestamp();
   std::cout << "SEARCH - Serial version\n"
             << "An example program to search an array.\n";


   // Define o número de elementos no vetor
   n = 1000 + (rand() % 151);


   std::cout << "The number of data items is " << n << ".\n";


   // Preenche o vetor com valores aleatórios entre 0 e 1000
   a.resize(n);
   for (int& value : a) {
       value = rand() % 1001; // Números entre 0 e 1000
   }
   target = a[n / 2];
   std::cout << "The target value is " << target << ".\n";


   // Procura no vetor por ocorrências do valor alvo
   for (int i = 0; i < n; ++i) {
       if (a[i] == target) {
           std::cout << "Found target at index " << i << ". Value: " << a[i] << "\n";
       }
   }


   std::cout << "SEARCH - Normal end of execution.\n";
   timestamp();


   return 0;
}


void timestamp() {
   char time_buffer[40];
   time_t now = time(nullptr);
   tm *tm = localtime(&now);
   strftime(time_buffer, sizeof(time_buffer), "%d %B %Y %I:%M:%S %p", tm);
   std::cout << time_buffer << std::endl;
}

