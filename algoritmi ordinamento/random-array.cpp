#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;


void swap(int &a, int &b)
{
  int temp=a;
  a=b;
  b=temp;
}

void initRandomArray(vector<int>& arr, int size)
{
  // srand(time(NULL)); questo pezzo di codice randomizza il mischiamento degli elementi
  for (int i = 0; i < size; ++i)
  {
    arr[i] = i + 1;
  }

  int random_index;
  for (int i = 0; i < size; ++i)
  {
    random_index = rand() % size;
    swap(arr[i], arr[random_index]);
  }
} 



// int main()
// {
//   initInputFile();
//   return 0;
// }