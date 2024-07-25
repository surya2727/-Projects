#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class User {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    User() = default;

    User(const string& firstName, const string& lastName, int age, const string& gender)
        : firstName(firstName), lastName(lastName), age(age), gender(gender) {}
};

map<string, User> userMap;
map<string, set<string>> friendsMap;

void addUser(const string& userName, const User& user) {
    if (userMap.find(userName) == userMap.end()) {
        userMap[userName] = user;
        cout << "User added successfully.\n";
    } else {
        cout << "Username already taken.\n";
    }
}

void makeFriends(const string& userName1, const string& userName2) {
    if (userMap.find(userName1) != userMap.end() && userMap.find(userName2) != userMap.end()) {
        friendsMap[userName1].insert(userName2);
        friendsMap[userName2].insert(userName1);
        cout << "Friendship established.\n";
    } else {
        cout << "One or both usernames do not exist.\n";
    }
}

void displayAllUsers() {
    for (const auto& [userName, user] : userMap) {
        cout << "Username: " << userName << ", Name: " << user.firstName << " " << user.lastName << "\n";
    }
}

void displayAllFriendships() {
    for (const auto& [userName, friends] : friendsMap) {
        cout << userName << " is friends with: ";
        for (const auto& friendName : friends) {
            cout << friendName << " ";
        }
        cout << "\n";
    }
}

int main() {
    while (true) {
        cout << "1. Add User\n2. Make Friends\n3. Display All Users\n4. Display All Friendships\n5. Exit\n";
        int choice;
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
                User newUser(firstName, lastName, age, gender);
                addUser(userName, newUser);
                break;
            }
            case 2: {
                string userName1, userName2;
                cout << "Enter First Username: ";
                cin >> userName1;
                cout << "Enter Second Username: ";
                cin >> userName2;
                makeFriends(userName1, userName2);
                break;
            }
            case 3:
                displayAllUsers();
                break;
            case 4:
                displayAllFriendships();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
