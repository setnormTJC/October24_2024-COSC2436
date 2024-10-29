// Demoing deques (double-ended queues).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<deque>
#include <vector>

using std::string; 
using std::cout; 

struct Task
{
	string taskName; 
	int priorityLevel; //higher means more important 
};

void printToDoList(std::deque<Task> taskList)
{
	while (!taskList.empty())
	{
		cout << taskList.front().taskName << "-" << taskList.front().priorityLevel << "\n";
		taskList.pop_front(); 
	}
}

int main()
{
	//deque -> pronounced as "deck" (not dee-queue)

	std::deque<Task> todoList; 
	//dq.pop

	Task firstTask{ "wash clothes", 1 }; //the second arg. is an integer-based priority level (higher = more important)  
	Task secondTask{ "make oatmeal", 1 }; 
	Task thirdTask{ "forget about chores and stream entertainment things", 2 }; 
	Task fourthTask{ "put out the FIRE in the kitchen", 3 };

	todoList.push_front(firstTask); 

	std::vector<Task> unprioritizedTaskList = { secondTask, thirdTask, fourthTask };

	while (unprioritizedTaskList.empty() != true)
	{
		Task currentTask = unprioritizedTaskList.back();

		//insert currentTask into FRONT of deque if higher than front task's priority: 
		if (currentTask.priorityLevel > todoList.front().priorityLevel)
		{
			todoList.push_front(currentTask); 
		}

		//insert currentTask into BACK of deque if LOWER than front task's priority: 
		//NOTE: this is quite the imperfect priority queue -> see std::priority_queue for better approach
		else 
		{
			todoList.push_back(currentTask); 
		}

		cout << "The UPDATED list (DEQUE) is: \n";
		printToDoList(todoList);

		system("pause"); 

		unprioritizedTaskList.pop_back(); 
	}



}
