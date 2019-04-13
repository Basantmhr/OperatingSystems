#include<iostream>
using namespace std;
int waiting_time (int q[][3], int n);
int Cal_minArrivalandBurst (int arr[][3], int n);
void show (int R[][3], int CT[], int WT[], int TAT[], int N);
int Cal_minBurst (int arr[][3], int n);
int
main ()
{
  int n;
  cout << "Enter the number of processes to be processed:\n";
  cin >> n;
  int p[n][3];
  for (int i = 0; i < n; ++i)
    p[i][0] = i + 1;
  for (int i = 0; i < n; ++i)
    {
      cout << "Enter Burst time and Arrival time for process" << i + 1;
      cin >> p[i][1] >> p[i][2];
      if (p[i][2] == 0)
	{
	  cout << "Arrival Time can't be Zero! Enter it again!!!\n\n";
	  --i;
	  n = n - 1;
	}
    }
  cout << "\n\n";
  int t = waiting_time (p, n);
  cout << "Total time taken by processor for computation is:" << t << endl <<
    endl;
}

int
waiting_time (int q[][3], int n)
{
  int arr[10][3];
  for (int i = 0; i < n; ++i)
    {
      arr[i][0] = q[i][0];
      arr[i][1] = q[i][1];
      arr[i][2] = q[i][2];
    }
  int wt[50] = { 0 }, tat[50] ={0}, i = 0, j = 0, k = 0, t = 0, shortest = 0, tot = 0, ct[50] ={0}, min;
  shortest = Cal_minArrivalandBurst (arr, n);
  min = arr[shortest][2];
  int max = arr[0][2];
  for (int i = 0; i < n; ++i)
    {
      tot = tot + arr[i][1];
      if (max < arr[i][2])
	max = arr[i][2];
    }
  t = min;
  for (i = min; i < (tot + min); ++i)
    {
      --arr[shortest][1];
      ++t;
      if (arr[shortest][1] == 0)
	{
	  ct[shortest] = t;
	  arr[shortest][1] = arr[shortest][2] = 32767;
	  if (t >= max)
	    shortest = Cal_minBurst (arr, n);
	  else
	    shortest = Cal_minArrivalandBurst (arr, n);
	  t = t + 2;
	}
      if (t <= max)
	{
	  j = 0;
	  for (int k = 0; k < n; ++k)
	    {
	      if (arr[k][2] <= t)
		{
		  if (arr[shortest][1] > arr[k][1])
		    shortest = k;
		}
	    }
	}
    }
  for (i = 0; i < n; ++i)
    {
      tat[i] = ct[i] - q[i][2];
      wt[i] = tat[i] - q[i][1];
    }
  show (q, ct, wt, tat, n);
  return t;
}

int Cal_minBurst (int arr[][3], int n)
{
  int sh = 0;
  for (int i = 0; i < n; ++i)
    {
      if (arr[sh][1] > arr[i][1])
	sh = i;
    }
  return sh;
}

int Cal_minArrivalandBurst (int arr[][3], int n)
{
  int min = arr[0][2];
  int sh = 0;
  for (int i = 0; i < n; ++i)
    {
      if (arr[i][2] < min)
	{
	  min = arr[i][2];
	  sh = i;
	}
      if (min == arr[i][2])
	{
	  if (arr[i][1] < arr[sh][1])
	    sh = i;
	}
    }
  return sh;
}

void
show (int R[][3], int CT[], int WT[], int TAT[], int N)
{
  cout<<"Proc No. BT AT CT WT TAT\n";
  int _sumwt = 0, _sumtat = 0;
  for (int i = 0; i < N; ++i)
    {
      cout<<R[i][0]<<"         "<<R[i][1]<<"  "<<R[i][2]<<"  "<<CT[i]<<"  " <<WT[i]<<"  " <<TAT[i]<<endl;
      _sumwt = _sumwt + WT[i];
      _sumtat = _sumtat + TAT[i];
    }
  float avgwt = (float) _sumwt / N;
  float avgtat = (float) _sumtat / N;
  cout << "Average Waiting Time is::" << avgwt << endl;
  cout << "Average Turn Around Time is::" << avgtat << endl;
}
