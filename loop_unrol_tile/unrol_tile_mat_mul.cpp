#include<iostream>
#include <chrono> 
#include <omp.h>
using namespace std;
using namespace std::chrono;
const int p = 500 ;
const int q = 500 ;
const int r = 500 ;
double arr1[p][q],arr2[q][r],res[p][r];
#define MIN(x,y) (((x)>(y)) ? (y):(x))
int main()
{
    
    #pragma omp parallel for collapse(2)
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            arr1[i][j]=0.5;
            for(int k=0;k<r;k++)
            {
                arr2[j][k]=0.5;
                res[i][k]=0.0;
            }
        }
    }
 
    int B=30; //tile size
    int N=500;
    auto start = high_resolution_clock::now(); 
    #pragma omp parallel for collapse(1)
    for(int x=0;x<p;x=x+B)
    {
        for(int y=0;y<q;y=y+B)
        {
            for(int z=0;z<r;z=z+B)
            {
                for(int i=x;i<MIN(p,(x+B));i++)
                {
                    for(int j=y;j<MIN(q,(y+B));j++)
                    {
                        for(int k=z;k<MIN(r,(z+B));k++)
                        {
                            res[i][k]=res[i][k]+((arr1[i][j])*(arr2[j][k]));
                            
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
