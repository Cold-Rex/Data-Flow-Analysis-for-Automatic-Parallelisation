#include <iostream>
#include <vector>
#include <chrono> 
#include <omp.h>
using namespace std;
using namespace std::chrono; 
int main() {
    int n;
    cin>>n;
    vector <int> A(n,2),B(n,3);
    auto start = high_resolution_clock::now(); 
    #pragma omp parallel for
        for(int i=1;i<n;i++)
            A[i]=B[i]+B[i-1];
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function for parallel: "
         << duration.count() << " microseconds" << endl; 
    start = high_resolution_clock::now();     
    for(int i=1;i<n;i++)
            A[i]=B[i]+B[i-1];
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function for series: "
         << duration.count() << " microseconds" << endl; 
    return 0;
}

