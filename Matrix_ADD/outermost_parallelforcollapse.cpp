#include <iostream>
#include <vector>
#include <chrono> 
#include <omp.h>
using namespace std;
using namespace std::chrono; 
int main() {
    int l=700;
    int m=700;
    double arr1[l][m],arr2[l][m];
    int i;
    int j;

    for(i=0;i<l;i++)
        {
            for(j=0;j<m;j++)
            {
                arr1[i][j]=1;
                arr2[i][j]=3;
            }
        }
    
    auto start = high_resolution_clock::now();
    #pragma omp parallel for collapse(2)
      for(int i=0;i<l;i++)
      {   
          for(int j=0;j<m;j++)
              arr1[i][j]=arr1[i][j]+arr2[i][j];
      }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function for parallel: "
         << duration.count() << " microseconds" << endl; 

    cout << arr1[9][9];
    return 0;
}
