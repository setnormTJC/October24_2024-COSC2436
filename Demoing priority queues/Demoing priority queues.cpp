// Demoing priority queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue> 

using std::cout; 
using std::string; 


struct PrinterJob
{
	string filename; 
	int pageCount; 


	PrinterJob(string filename, int pageCount)
		:filename(filename), pageCount(pageCount)
	{
		//"empty"
	}

	bool operator < (const PrinterJob& otherPrintJob) const 
	{
		return this->pageCount > otherPrintJob.pageCount; 

	}
};

int main()
{

	srand(time(0)); //time() returns the number of seconds since Jan 1, 1970 ("the epoch") 

	PrinterJob firstJob{ "birds", 11 }; 
	PrinterJob secondJob{ "silt", 1 };
	PrinterJob thirdJob{ "dictionary", 4 };

	std::priority_queue<PrinterJob> pq;

	pq.push(firstJob); 
	pq.push(secondJob); 
	pq.push(thirdJob); 

	pq.push(PrinterJob{ "some document", 432 }); //this will "jump the queue"! (PRE-EMPTION)


	//for()
	while (!pq.empty())
	{
		//Dijkstra's algo (in the future, for graph traversal) 
		cout << pq.top().filename << "- with this many pages: " << pq.top().pageCount; 
		cout << "\n";
		pq.pop(); 


	}

}
