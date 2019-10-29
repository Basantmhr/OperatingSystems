#include<iostream>
using namespace std;
int main() 
{ 
int n,tdistance=0; 
int DiskQueue[]={86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130}; 
int cur_pos=143; 
cout<<"\n FCFS Disc-Scheduler\n"<<endl;
for(int j=0;j<9;++j) 
{ 
if((DiskQueue[j]-cur_pos)>0)
tdistance=tdistance +DiskQueue[j] - cur_pos; 
else 
tdistance= tdistance - DiskQueue[j] + cur_pos; 
cur_pos=DiskQueue[j]; 
} 
cout<<"Total distance moved by the arm is::"<<tdistance<<endl;
  cout<<"Project Complete";

}
