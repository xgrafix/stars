// Something to write about in c++ file

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cstdlib>

const int X_SIZE = 10;
const int Y_SIZE = 5;

int main()
{
  char **arr = NULL;
  char **ptr = NULL; // Adding a temporary place for traversing.

  arr = new char*[X_SIZE];

  for(int x = 0; x < X_SIZE; x++)
  {
    arr[x] = new char[Y_SIZE];
  }

  // Assign a temporary arr to the pointer ptr.
  ptr = arr;

  for(int x = 0; x < X_SIZE; ++x)
  {
    for(int y = 0; y < Y_SIZE; ++y)
    {
      if(((x + y) % 2) == 0)
      {
        *(*(ptr + x) + y) = '*';
      }
      else
      {
        *(*(ptr + x) + y) = '.';
      }
    }
  }

  while(true) {
    for(int x = 0; x < rand() % X_SIZE; ++x)
    {
      std::chrono::milliseconds duration( 50 );
      for(int y = 0; y < rand() % Y_SIZE; ++y)
      {
        std::this_thread::sleep_for(duration);
        std::cout << std::right << std::setw(rand() % X_SIZE*10)
                  << *(*(ptr + x) + y) << " ";
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
