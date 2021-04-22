#include <iostream>
#include <vector>
#include <chrono> 
#include <omp.h>
using namespace std;
using namespace std::chrono; 
int main() {
    int l=500;
    int m=500;
    int n=500;
    double arr1[l][m],arr2[m][n],ans[l][n];
    int i;
    int j;
    int k;

    for(i=0;i<l;i++)
        {
            for(j=0;j<m;j++)
            {
                arr1[i][j]=1;
                for(k=0;k<n;k++)
                {
                    arr2[j][k]=2;
                    ans[i][k]=0;
                }
            }
        }

    auto start = high_resolution_clock::now();
    #pragma omp parallel
    #pragma omp for
    {
      for(int i=0;i<l;i++)
      {   
          for(int k=0;k<n;k++)
          {
              for(int j=0;j<m;j++)
                ans[i][k]+=(arr1[i][j]*arr2[j][k]);
          }
      }
    }  

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function for parallel: "
         << duration.count() << " microseconds" << endl;
    /*
    for(i=0;i<l;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<< ans[i][j];
            }
            cout << "\n";
        }

        */
    //cout << ans[9][9];
    return 0;
}
