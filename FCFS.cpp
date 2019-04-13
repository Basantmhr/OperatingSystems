#include<iostream>
using namespace std;
int main() 
{ 
int n,tdistance=0; 
int DiskQueue[5000]; 
int cur_pos; 
cout<<"\n FCFS Disc-Scheduler\n"<<endl;
cout<<"Enter no. of requests pending for processing::";
cin>>n;
cout<<"\nEnter the cylinder no. for corresponding requests(IN FCFS ORDER)::"<<endl;
for(int i=0;i<n;++i) {
cin>>DiskQueue[i];
}
cout<<"Enter current position of disc arm::";
cin>>cur_pos;

}
