//C program for round robin scheduling :

#include<stdio.h>
#include<conio.h>
int main()
{
          int i,j,n,time,remain,flag=0,ts;
          int sum_wait=0,sum_turnaround=0,at[10],bt[10],rt[10],start[10],wt[i],end[i],tt[i];
          printf("Enter no of Processes : ");
          scanf("%d",&n);
          remain=n;
          for(i=0;i<n;i++)
         {
                     printf("Enter arrival time and burst time for Process P%d :",i+1);
                     scanf("%d",&at[i]);
                     scanf("%d",&bt[i]);
                     rt[i]=bt[i];
                     start[i]=0;
          }
          printf("Enter time slice");
          scanf("%d",&ts);
          printf("\nProcess\t|\tRunning time\n");
          for(time=0,i=0;remain!=0;)
          {
                     if(start[i]==0&&i!=0)
                     start[i]=time;
                     if(rt[i]<=ts && rt[i]>0)
                     {
                               printf("p[%d]\t|\t%d-%d\n",i+1,time,time+rt[i]);
                               time+=rt[i];
                               rt[i]=0;
                               flag=1;
                     }
                     else if(rt[i]>0)
                     {
                                printf("p[%d]\t|\t%d-%d\n",i+1,time,time+ts);
                                rt[i]-=ts;
                                time+=ts;
                     }
                     if(rt[i]==0 && flag==1)
                     {
                                remain--;
                                end[i]=time;
                                wt[i]=time-at[i]-bt[i];
                                tt[i]=time-at[i];
                                sum_wait+=wt[i];
                                sum_turnaround+=tt[i];
                                flag=0;
                     }
                     if(i==n-1)
                     i=0;
                     else if(at[i+1]<=time)
                     i++;
                     else
                     i=0;
            }
            printf("\n\nProcess\t|Arrival time\t|Execution time\t|Start time\t|End time\t|
                         waiting time\t|Turnaround time\n\n");
            for(i=0;i<n;i++)
            printf("p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",i+1,at[i],bt[i],start[i],
                        end[i],wt[i],tt[i]);
            printf("\nAvg sum_wait = %f\n",sum_wait*1.0/n);
            printf("Avg sum_turnaround = %f",sum_turnaround*1.0/n);
            return 0;
}


