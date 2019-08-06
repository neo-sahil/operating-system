//C program for FCFS scheduling :

#include<stdio.h>
#include<conio.h>
int main()
{
          int process[10],arrival[10],exec[10],start[10],end[10],wait[10],turnaround[10];
          int n,i,j,temp,totalwait=0,totalturn=0;
          float avgwait,avgturn;
clrscr();
          printf("Enter the number of processes\n");
          scanf("%d",&n);
          printf("Enter the process name,arrival time and execution time of each process\n");
          for(i=0;i<n;i++)
          scanf("%d%d%d",&process[i],&arrival[i],&exec[i]);
          for(i=0;i<n-1;i++)
         {
                  for(j=i+1;j<n;j++)
                 {
                          if(arrival[i]>arrival[j])
                          {
                                     temp=arrival[i];
                                     arrival[i]=arrival[j];
                                     arrival[j]=temp;
                                     temp=process[i];
                                     process[i]=process[j];
                                     process[j]=temp;
                                     temp=exec[i];
                                     exec[i]=exec[j];
                                     exec[j]=temp;
                           }
                  }
          }
          printf("Process name\tArrival time\tExecution time\n");
          for(i=0;i<n;i++)
          printf("%d\t\t%d\t\t%d\n",process[i],arrival[i],exec[i]);
          start[0]=arrival[0];
          end[0]=arrival[0]+exec[0];
          wait[0]=0;
          turnaround[0]=exec[0];
          totalturn+=turnaround[0];
          for(i=1;i<n;i++)
         {
                   if(arrival[i]<=end[i-1])
                   start[i]=end[i-1];
                   else
                   start[i]=arrival[i];
                   wait[i]=start[i]-arrival[i];
                   totalwait+=wait[i];
                   end[i]=start[i]+exec[i];
                   turnaround[i]=exec[i]+wait[i];
                   totalturn+=turnaround[i];
          }
          avgwait=(float)totalwait/(float)n;
          avgturn=(float)totalturn/(float)n;
          printf("Process name\tArrival time\tExecution time\tStart time\tEnd time\tWaiting                                            time\tTurnaround time\n");
          for(i=0;i<n;i++)
          printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[i],arrival[i],exec[i],start[i],
                       end[i],wait[i],turnaround[i]);
          printf("Total waiting time is %d\n",totalwait);
          printf("Average waiting time is %f\n",avgwait);
          printf("Total turnaround time is %d\n",totalturn);
          printf("Average turnaround time is %f\n",avgturn);
          return 0;

}
