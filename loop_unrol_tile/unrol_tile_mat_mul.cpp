#include<iostream>
#include <chrono> 
#include <omp.h>
using namespace std;
using namespace std::chrono;
double arr1[500][500],arr2[500][500],res[500][500];
#define MIN(x,y) (((x)>(y)) ? (y):(x))
int main()
{
    
    #pragma omp parallel for collapse(2)
    for(int i=0;i<500;i++)
    {
        for(int j=0;j<500;j++)
        {
            arr1[i][j]=0.5;
            arr2[i][j]=0.5;
            res[i][j]=0.0;
        }
    }
    int B=50; //tile size
    int N=500;
    auto start = high_resolution_clock::now(); 
    #pragma omp parallel for collapse(1)
    for(int x=0;x<N;x=x+B)
    {
        for(int y=0;y<N;y=y+B)
        {
            for(int z=0;z<N;z=z+B)
            {
                for(int i=x;i<MIN(N,(x+B));i++)
                {
                    for(int j=y;j<MIN(N,(y+B));j++)
                    {
                        for(int k=z;k<MIN(N,(z+B));k++)
                        {
                            res[i][j]=res[i][j]+((arr1[i][k])*(arr2[k][j]));
                            
                        }
                    }
                }
            }
        }
    }
  cout<<res[499][499]<<"\n";
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function for parallel: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
