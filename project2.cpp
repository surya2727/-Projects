#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

class Task {
public:
    string description;
    string category;
    bool completed;
    string dueDate;
    string priority;
    bool reminder;
    string reminderTime;

    Task(const string& description, const string& category, const string& priority, const string& dueDate)
        : description(description), category(category), completed(false),
          dueDate(dueDate), priority(priority), reminder(false), reminderTime("") {}
};

vector<Task> tasks;
vector<string> categories = {"Work", "Personal", "Study", "Shopping", "Other"};

void displayTasks() {
    if (tasks.empty()) {
        cout << "No tasks available. Please add some tasks first.\n";
        return;
    }

    cout << "\nTasks:\n"
         << "   " << "Task" << " | " << "Category" << " | " << "Priority" << " | " << "DueDate" << " | " << "Status" << " | " << "Reminder" << "\n";

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". "
             << tasks[i].description << " | "
             << tasks[i].category << " | "
             << tasks[i].priority << " | "
             << tasks[i].dueDate << " | "
             << (tasks[i].completed ? "Completed" : "Pending") << " | "
             << (tasks[i].reminder ? tasks[i].reminderTime : "No") << "\n";
    }
}

void markTaskAsCompleted() {
    int taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void deleteTask() {
    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void setReminder() {
    int taskNumber;
    cout << "Enter task number to set a reminder: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        cout << "Enter the reminder time (HH:MM): ";
        cin >> tasks[taskNumber - 1].reminderTime;
        tasks[taskNumber - 1].reminder = true;
        cout << "Reminder set.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void filterTaskByCategory() {
    string categoryToFilter;
    cout << "Enter the category to filter: ";
    cin >> categoryToFilter;

    cout << "\nTasks in the " << categoryToFilter << " category:\n";
    cout << "   " << "Task" << " | " << "Category" << " | " << "Priority" << " | " << "DueDate" << " | " << "Status" << " | " << "Reminder" << "\n";

    bool foundTasks = false;
    for (const auto& task : tasks) {
        if (task.category == categoryToFilter) {
            foundTasks = true;
            cout << "- " << task.description << " | "
                 << task.category << " | "
                 << task.priority << " | "
                 << task.dueDate << " | "
                 << (task.completed ? "Completed" : "Pending") << " | "
                 << (task.reminder ? task.reminderTime : "No") << "\n";
        }
    }

    if (!foundTasks) {
        cout << "No tasks found in the " << categoryToFilter << " category.\n";
    }
}

void addTask() {
    string description, category, priority;

    cout << "Enter the description: ";
    cin.ignore();
    getline(cin, description);

    auto now = time(nullptr);
    tm* current = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", current);
    string dueDate(buffer);

    cout << "Choose a category:\n";
    for (size_t i = 0; i < categories.size(); ++i) {
        cout << i + 1 << ". " << categories[i] << "\n";
    }

    int categoryChoice;
    cin >> categoryChoice;
    if (categoryChoice > 0 && categoryChoice <= categories.size()) {
        category = categories[categoryChoice - 1];
    } else {
        cout << "Invalid choice, defaulting to 'Other'\n";
        category = "Other";
    }

    cout << "Enter priority (HIGH/LOW/MEDIUM): ";
    cin >> priority;

    Task task(description, category, priority, dueDate);
    tasks.push_back(task);
    cout << "Task added successfully.\n";
}

void displayMenu() {
    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Delete Task\n"
             << "5. Set Reminder\n"
             << "6. Filter Task By Category\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                setReminder();
                break;
            case 6:
                filterTaskByCategory();
                break;
            case 7:
                cout << "Goodbye! Please do the tasks on time.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 7);
}

int main() {
    displayMenu();
    return 0;
}
