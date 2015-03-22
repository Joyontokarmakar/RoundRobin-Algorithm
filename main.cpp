 /**
 Made by Samvid
 **/
 #include <iostream>

using namespace std;

int main()
{
    int i,j,k,sum=0;
    int timeQuantum;
    int burstTime[50];
    int waitingTime[50];
    int turnAroundTime[50];
    int a[50];
    int n;
    cout << "Enter number of Process :\t" ;
    cin >> n;
    cout << "Enter time Quantum :\t";
    cin >> timeQuantum;
    cout <<"Enter brust Time:\n\n";
    for(i=0;i<n;i++)
    {
    cout << "Enter brust Time for :  " << (i+1) << "\t";
    cin >> burstTime[i];
    }

    for(i=0;i<n;i++)
        a[i]=burstTime[i];
    for(i=0;i<n;i++)
        waitingTime[i]=0;

    do
    {
      for(i=0;i<n;i++)
      {
        if(burstTime[i]>timeQuantum)
        {
          burstTime[i]-=timeQuantum;
          for(j=0;j<n;j++)
            {
             if((j!=i)&&(burstTime[j]!=0))
             waitingTime[j]+=timeQuantum;
            }
        }
        else
        {
          for(j=0;j<n;j++)
            {
             if((j!=i)&&(burstTime[j]!=0))
             waitingTime[j]+=burstTime[i];
            }
          burstTime[i]=0;
        }
      }
    sum=0;
    for(k=0;k<n;k++)
        sum=sum+burstTime[k];
}
while(sum!=0);

for(i=0;i<n;i++)
    {
            turnAroundTime[i]=waitingTime[i]+a[i];
    }

cout << "\nProcesses"<<"\t" <<"Burst Time" <<"\t" << "Waiting Time" <<"\t" <<"Turn Around Time" << "\n\n";

for(i=0;i<n;i++)
{
    cout << "process" << (i+1) <<"\t" <<a[i] <<"\t\t" << waitingTime[i] <<"\t\t" <<turnAroundTime[i] << "\n\n";
}

int sumesonWaitingTime=0;
for(i=0;i<n;i++)
{
    sumesonWaitingTime=sumesonWaitingTime+waitingTime[i];
}

float averageWaitingTime;
averageWaitingTime=sumesonWaitingTime/(float)n;

cout << "\n\nThe Total Waiting Time : \t" << sumesonWaitingTime;
cout << "\n\nThe Average Waiting Time : \t" << averageWaitingTime;

int sumesonTurnAroundTime=0;
for(i=0;i<n;i++)
{
    sumesonTurnAroundTime=sumesonTurnAroundTime+turnAroundTime[i];
}

float averageTurnAroundTime;
averageTurnAroundTime=sumesonTurnAroundTime/(float)n;

cout << "\n\nThe Total Turn Around Time : \t" << sumesonTurnAroundTime;
cout << "\n\nThe Average Turn Around Time : \t" << averageTurnAroundTime;




return 0;
}
