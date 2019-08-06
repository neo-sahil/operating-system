//C program for LRU page replacement :



#include<stdio.h>
#include<conio.h>
void print(int frameno,int frame[])
{
            int j;
            for(j=0;j<frameno;j++)
            printf("%d\t",frame[j]);
            printf("\n");
}         
int main()
{
            int i,j,k,n,page[50],frameno,frame[10],move=0,flag,count=0,count1,repindex,
                        check[50]={0};
            float rate;
clrscr();
            printf("Enter the number of pages\n");
            scanf("%d",&n);
            printf("Enter the page reference numbers\n");
            for(i=0;i<n;i++)
            scanf("%d",&page[i]);
            printf("Enter the number of frames\n");
            scanf("%d",&frameno);
            for(i=0;i<frameno;i++)
            frame[i]=-1;
            printf("Page reference string\tFrames\n");
            for(i=0;i<n;i++)
            {
                        printf("%d\t\t\t",page[i]);
                        flag=0;
                        for(j=0;j<frameno;j++)
                        {
                                    if(page[i]==frame[j])
                                    {
                                                flag=1;
                                                printf("No replacement\n");
                                                break;
                                    }
                        }
                        if(flag==0&&count<frameno)
                        {
                                    frame[move]=page[i];
                                    move=(move+1)%frameno;
                                    count++;
                                    print(frameno,frame);
                        }
                        else if(flag==0)
                        {
                                    count1=0;
                                    for(j=i-1;j>=0;j--)
                                    {
                                                for(k=0;k<frameno;k++)
                                                {
                                                            if(page[j]==frame[k]&&check[page[j]]==0)
                                                            {
                                                                        check[page[j]]=1;
                                                                        count1++;
                                                                        repindex=k;
                                                                        k=frameno;
                                                            }
                                                }
                                                if(count1==frameno)
                                                break;
                                    }
                                    frame[repindex]=page[i];
                                    count++;
                                    print(frameno,frame);
                        }
                        for(j=0;j<50;j++)
                        check[j]=0;

            }
            rate=(float)count/(float)n;
            printf("Number of page faults is %d\n",count);
            printf("Fault rate is %f\n",rate);
            return 0;
}
 