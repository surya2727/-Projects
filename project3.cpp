#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class Person {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    Person() = default;

    Person(const string& firstName, const string& lastName, int age, const string& gender)
        : firstName(firstName), lastName(lastName), age(age), gender(gender) {}
};

map<string, Person> userDirectory;
map<string, set<string>> friendships;

void addPerson(const string& userName, const Person& person) {
    if (userDirectory.find(userName) == userDirectory.end()) {
        userDirectory[userName] = person;
        cout << "User added successfully.\n";
    } else {
        cout << "Username already exists.\n";
    }
}

void establishFriendship(const string& userName1, const string& userName2) {
    if (userDirectory.find(userName1) != userDirectory.end() && userDirectory.find(userName2) != userDirectory.end()) {
        friendships[userName1].insert(userName2);
        friendships[userName2].insert(userName1);
        cout << "Friendship established.\n";
    } else {
        cout << "One or both usernames do not exist.\n";
    }
}

void listAllUsers() {
    if (userDirectory.empty()) {
        cout << "No users available.\n";
        return;
    }

    cout << "\nUsers List:\n";
    for (const auto& [userName, person] : userDirectory) {
        cout << "Username: " << userName << ", Name: " << person.firstName << " " << person.lastName << ", Age: " << person.age << ", Gender: " << person.gender << "\n";
    }
}

void listAllFriendships() {
    if (friendships.empty()) {
        cout << "No friendships available.\n";
        return;
    }

    cout << "\nFriendships List:\n";
    for (const auto& [userName, friends] : friendships) {
        cout << userName << " is friends with: ";
        for (const auto& friendName : friends) {
            cout << friendName << " ";
        }
        cout << "\n";
    }
}

void showMenu() {
    int choice;
    while (true) {
        cout << "\nMenu:\n"
             << "1. Add User\n"
             << "2. Make Friends\n"
             << "3. Display All Users\n"
             << "4. Display All Friendships\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string userName, firstName, lastName, gender;
                int age;
                cout << "Enter Username: ";
                cin >> userName;
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Gender: ";
                cin >> gender;
                Person newPerson(firstName, lastName, age, gender);
                addPerson(userName, newPerson);
                break;
            }
            case 2: {
                string userName1, userName2;
                cout << "Enter First Username: ";
                cin >> userName1;
                cout << "Enter Second Username: ";
                cin >> userName2;
                establishFriendship(userName1, userName2);
                break;
            }
            case 3:
                listAllUsers();
                break;
            case 4:
                listAllFriendships();
                break;
            case 5:
                cout << "Exiting. Have a great day!\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    showMenu();
    return 0;
}

