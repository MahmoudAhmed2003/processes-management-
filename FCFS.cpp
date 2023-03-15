#include <iostream>
#include <iomanip>
using namespace std;
void main()
{
	struct process
	{
		int id, at, bt, wt ,per;
	};// Struct Definition
	process* arr;
	int num;
	cout << " Enter number of Processes \n";
	cin >> num;
	arr = new process[num];//Dynamic Array of Struct 
	cout << " \tArrival time \t Burst time\t perudety " << endl;
	for (int i = 0; i < num; i++)//Enter Arrival time & Burst time 
	{
		arr[i].id = i + 1;
		cout << "P" << i + 1 << "\t";
		cin >> arr[i].at >> arr[i].bt>> arr[i].per;
	}
	//Sorting Process in ascending order according to its arrival time using Bubble Sort;
	process temp;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i].per > arr[j].per)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	// Calculating Waiting Time for each Process
	arr[0].wt = 0;
	int tot = 0;
	for (int i = 1; i < num; i++)
	{
		tot += arr[i - 1].bt;
		arr[i].wt = tot - arr[i].at;
	}
	cout << "---------------------------------------------------------------------\n";
	cout << "The Sequence of Processes Will be & The Waiting Time for each process \n";
	cout << "\t Arrival time \t Burst time \t Waiting time \n";
	for (int i = 0; i < num; i++)
	{
		cout << "P" << arr[i].id << "\t \t" << arr[i].at << " \t \t" << arr[i].bt << "\t \t" << arr[i].wt << endl;
	}
	cout << "---------------------------------------------------------------------\n";
	cout << "Gantt Chart \n ";// Drawing Gantt chart
	for (int i = 0; i < num; i++)
	{
		cout << setw(arr[i].bt) << "P" << arr[i].id << "\t";
	}
	cout << endl << "0";
	tot = 0;
	for (int i = 0; i < num; i++)
	{
		tot += arr[i].bt;       
		cout << setfill('-') << setw(arr[i].bt * 2) << tot;
	}
	//Calculating the Average Waiting Time
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += arr[i].wt;
	}
	cout << "\n \n Average Waiting time = " << sum << " / " << num << " = " << (float)sum / num << endl; delete[] arr;

}
