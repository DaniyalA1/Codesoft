#include <iostream>
#include <string>
#define MaxTasks 100

using namespace std;

struct ToDoTask {
    string taskDescription;
    bool isCompleted;

    ToDoTask() {}
    ToDoTask(string description) {
        this->taskDescription = description;
        this->isCompleted = false;
    }
};

class TaskManager {
private:
    ToDoTask taskList[MaxTasks];
    int totalTasks;

public:
    TaskManager() {
        this->totalTasks = 0;
    }

    // Function to add a task to the list
    void addNewTask(string description) {
        if (totalTasks < MaxTasks) {
            taskList[totalTasks] = ToDoTask(description);
            totalTasks++;
            cout << "Task added: " << description << endl;
        } else {
            cout << "Task list is full. Cannot add more tasks." << endl;
        }
    }

    // Function to view the list of tasks
    void showTasks() {
        if (totalTasks == 0) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (int i = 0; i < totalTasks; i++) {
                cout << i + 1 << ". " << taskList[i].taskDescription << " - " << (taskList[i].isCompleted ? "Completed" : "Pending") << endl;
            }
            cout << endl;
        }
    }

    // Function to mark a task as completed
    void markTaskDone(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= totalTasks) {
            taskList[taskNumber - 1].isCompleted = true;
            cout << "Task marked as completed: " << taskList[taskNumber - 1].taskDescription << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    // Function to remove a task from the list
    void removeSpecificTask(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= totalTasks) {
            cout << "Task removed: " << taskList[taskNumber - 1].taskDescription << endl;
            for (int i = taskNumber - 1; i < totalTasks - 1; i++) {
                taskList[i] = taskList[i + 1];
            }
            totalTasks--;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main(int argc, char** argv) {
    TaskManager taskManager;
    int userChoice;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        if (userChoice == 1) {
            string taskDescription;
            cout << "Enter the task description: ";
            cin >> taskDescription;
            taskManager.addNewTask(taskDescription);
        } else if (userChoice == 2) {
            taskManager.showTasks();
        } else if (userChoice == 3) {
            int taskNumber;
            cout << "Enter the task number to mark as completed: ";
            cin >> taskNumber;
            taskManager.markTaskDone(taskNumber);
        } else if (userChoice == 4) {
            int taskNumber;
            cout << "Enter the task number to remove: ";
            cin >> taskNumber;
            taskManager.removeSpecificTask(taskNumber);
        } else if (userChoice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
