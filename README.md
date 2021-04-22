# Data-Flow-Analysis-for-Automatic-Parallelisation
It is for a project for the final year

We are using google collab so here are the specs of the system we are working in =>


### Initial Step is to read about all the method used.

Links

### Then some example of series and parallel codes.


## Next We Do Matrix Addition And Matrix Multiplication
We do the outermost loop parallelise, with collapse clause using openmp in google collab
https://colab.research.google.com/drive/1JIuJ6m9qxYmO2bAAV1-KsYdSHRmsQWRJ?usp=sharing

For it to get the approximate time we write :-

```
!pip install ipython-autotime
%load_ext autotime
```

Then we write :-

```
%%file filename.cpp
```

before the code given in the repositories(Matrix_ADD and Matrix_MUL) and then run this script in google colab: -

```
%%script bash
g++ file_name.cpp -std=c++11
./a.out
```

It run the program and autotime gives the time taken to run it.


## Loop unrolling and Tiling

Run the code given in loop_unrol_tile the same as mentioned in above step.

Change the different tile size and maximum size to see the time difference.
