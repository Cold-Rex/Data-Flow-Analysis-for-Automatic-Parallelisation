#include<stdio.h>
double arr1[5120][5120],arr2[5120][5120],res[5120][5120];
#define MIN(x,y) (((x)>(y)) ? (y):(x))
int main()
{
    int proc=5;
    //printf("enter number of processor:");
    //scanf("%d",&proc);
    int b=(5120/proc);
    for(int p=0;p<proc;p++)
    {
        for(int i=b*p;i<MIN(5120,(b*(p+1)));i++)
        {
            for(int j=0;j<5120;j++)
            {
                arr1[i][j]=i+j+0.5;
                arr2[i][j]=i+j+0.5;
                res[i][j]=0;
            }
        }
    }
    int B=1000;
    for(int x=0;x<5120;x=x+B)
    {
        printf("came");
        for(int y=0;y<5120;y=y+B)
        {
            for(int z=0;z<5120;z=z+B)
            {
                for(int i=x;i<MIN((5120),(x+B));i++)
                {
                    for(int j=y;j<MIN((5120),(y+B));j++)
                    {
                        for(int k=z;k<MIN((5120),(z+B));k++)
                        {
                            res[i][j]=res[i][j]+((arr1[i][k])*(arr2[k][j]));
                            
                        }
                    }
                }
            }
        }
    }
    printf("came");

    return 0;
}