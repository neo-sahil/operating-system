//C program for worst fit memory management :



#include<stdio.h>
#include<conio.h>
int main()
{
            int i,j,flag=0,blockno,blocksize[10],processno,processsize[10],lstsize,lstindex;
            printf("Enter the number of free blocks\n");
            scanf("%d",&blockno);
            printf("Enter the size of free blocks\n");
            for(i=0;i<blockno;i++)
            scanf("%d",&blocksize[i]);
            printf("Enter the number of processes\n");
            scanf("%d",&processno);
            printf("Enter the size of processes\n");
            for(i=0;i<processno;i++)
            scanf("%d",&processsize[i]);
            for(i=0;i<blockno;i++)
            printf("size of free block %d: %d\n",i+1,blocksize[i]);
            printf("\n\n");
            for(i=0;i<processno;i++)
            printf("size of process %d: %d\n",i+1,processsize[i]);
            printf("\n");
            printf("WORST FIT MEMORY ALLOCATION\n\n");
            printf("Processno\tAllocated block\tAllocated size\tFragment in that block\n");
            i=0;
            while(i<processno)
            {
                        flag=0;
                        for(j=0;j<blockno;j++)
                        {
                                    if(processsize[i]<=blocksize[j])
                                    {
                                                if(flag==0)
                                                {
                                                            lstsize=blocksize[j];
                                                            lstindex=j;
                                                            flag++;
                                                }
                                                else if(blocksize[j]>lstsize)
                                                {
                                                            lstsize=blocksize[j];
                                                            lstindex=j;
                                                }
                                    }
                        }
                        blocksize[lstindex]-=processsize[i];
                        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,lstindex+1,processsize[i],
                                    blocksize[lstindex]);
                        i++;
            }
            return 0;
}
