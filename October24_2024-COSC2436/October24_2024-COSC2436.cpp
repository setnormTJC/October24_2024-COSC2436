// October24_2024-COSC2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

#include<random> 

#include<chrono> 

#include<thread>

using std::cout; 
using std::string;


using std::queue;

using std::ostream; 


std::mt19937 engine(time(0));

struct Customer
{
	string name; 
	int numberOfItems; 

	Customer(string name)
		:name(name)
	{

		std::uniform_int_distribution<int> randomDistribution{ 2, 10 }; 

		numberOfItems = randomDistribution(engine); 

		
		//numberOfItems = (rand() % 10) + 2; 
	}

	friend ostream& operator << (ostream& os, Customer customerObject);

};

ostream& operator << (ostream& os, Customer customerObject)
{
	os << customerObject.name << "-" << customerObject.numberOfItems << "\n";
	return os;
}


/*DO NOT pass the args by reference - queues will be PREMATURELY emptied!*/
void printTheTwoQueues(std::queue<Customer> firstLane, queue<Customer> secondLane)
{
	cout << "First lane contents: \n";
	while (!firstLane.empty())
	{
		cout << "\t" << firstLane.front() << "\n";
		firstLane.pop();  //the pop operation for queues is called "dequeue" (not Dairy Queen) (deque)

	}

	cout << "Second lane contents: \n";
	while (!secondLane.empty())
	{
		cout << "\t" << secondLane.front() << "\n";
		secondLane.pop(); 
	}
}

int main()
{

	std::vector<Customer> allOfTheCustomersInStore =
	{
		Customer{"Alice"},
		Customer{"Bob"},

		Customer{"Carol"},
		Customer{"Darth"},
		
		Customer{"Eve"},
		Customer{"Frank"},

		Customer{"Gus"}
	}; 

	srand(time(0));
	std::random_shuffle(allOfTheCustomersInStore.begin(), allOfTheCustomersInStore.end());

	//queues are called "FIFO" -> first in, first out
	//DSA course

	//Let's make a grocery store simulator!

	//std::priority_queue

	queue<Customer>firstLane; 
	queue<Customer>secondLane;

	int totalNumberOfCustomers = allOfTheCustomersInStore.size(); 

	for (int i = 0; i < totalNumberOfCustomers / 2; ++i)
	{
		firstLane.push(allOfTheCustomersInStore.at(i)); //push for a queue is also called "enqueue" (in kyoo)

		//secondLane.push(allOfTheCustomersInStore.at(i + 1)); 
	}

	for (int i = totalNumberOfCustomers / 2; i < totalNumberOfCustomers; ++i)
	{
		secondLane.push(allOfTheCustomersInStore.at(i)); 
	}

	printTheTwoQueues(firstLane, secondLane); 

	//begin the "scanning" - HOORAY (money for the grocery store) 

	firstLane.front().numberOfItems--; 
	cout << "\n\n\nAfter " << firstLane.front().name << " scanned a single item...\n";
	printTheTwoQueues(firstLane, secondLane);


	while (firstLane.empty() == false && secondLane.empty() == false)
	{
		//scan items and dequeue (pop) customers 
		
		firstLane.front().numberOfItems--; 
		secondLane.front().numberOfItems--;

		if (firstLane.front().numberOfItems == 0)
		{
			cout << firstLane.front().name << " has finished scanning his/her items\n";
			firstLane.pop(); 
		}

		if (secondLane.front().numberOfItems == 0)
		{
			cout << firstLane.front().name << " has finished scanning his/her items\n";
			secondLane.pop(); 
		}

		std::this_thread::sleep_for(std::chrono::seconds{ 3 });
		
		system("CLS"); 
		printTheTwoQueues(firstLane, secondLane);
		//cout << "...\n";

	}
}
