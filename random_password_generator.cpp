#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generatePasswords(int length, int count) {
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char symbols[] = "!@#$%^&*()-_=+[]{};:,.<>?";

    srand(time(0));

    for(int n = 0; n < count; n++){
        char password[100];
        int pos = 0;

        password[pos++] = upper[rand() % 26];
        password[pos++] = lower[rand() % 26];
        password[pos++] = digits[rand() % 10];
        password[pos++] = symbols[rand() % 28];

        for(; pos < length; pos++){
            int type = rand() % 4;
            if(type == 0) password[pos] = upper[rand() % 26];
            else if(type == 1) password[pos] = lower[rand() % 26];
            else if(type == 2) password[pos] = digits[rand() % 10];
            else password[pos] = symbols[rand() % 28];
        }

        for(int i = 0; i < length; i++){
            int j = rand() % length;
            char temp = password[i];
            password[i] = password[j];
            password[j] = temp;
        }

        password[length] = '\0';
        cout << "Password " << (n+1) << ": " << password << endl;
    }
}

int main() {
    int choice = 0;

    while(true) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "   Strong Password Generator   " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1. Generate Password(s)" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            int length, count;
            cout << "Enter password length (>=4): ";
            cin >> length;
            if(length < 4){
                cout << "Length must be at least 4." << endl;
                continue;
            }
            cout << "How many passwords you want to generate? ";
            cin >> count;

            cout << "\nGenerated Passwords:\n";
            generatePasswords(length, count);
            cout << "\n";
        }
        else if(choice == 2) {
            cout << "Exiting... Bye-Bye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
