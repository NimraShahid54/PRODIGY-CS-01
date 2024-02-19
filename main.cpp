#include <iostream>
#include <string>
using namespace std;

string output; // Global variable to store the result
char a; // Temporary variable for character manipulation
// Function to perform encryption using Caesar cipher
string encryption(string s, int key)
{
    output = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i])) { // Check if it's an alphabetic character
            // Preserve case while encrypting
            if (isupper(s[i]))
                output += ((s[i] - 'A' + key) % 26) + 'A';
            else
                output += ((s[i] - 'a' + key) % 26) + 'a';
        }
        else {
            output += s[i]; // Non-alphabetic characters remain unchanged
        }
    }
    return output;
}

// Function to perform decryption using Caesar cipher
string decryption(string s, int key)
{
    output = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i])) { // Check if it's an alphabetic character
            // Preserve case while decrypting
            if (isupper(s[i]))
                output += ((s[i] - 'A' - key + 26) % 26) + 'A';
            else
                output += ((s[i] - 'a' - key + 26) % 26) + 'a';
        }
        else {
            output += s[i]; // Non-alphabetic characters remain unchanged
        }
    }
    return output;
}


int main()
{
    string input, input_user; // Variables to store user input
    int key; // Variable to store the encryption/decryption key
    char choice; // Variable to store user's choice to continue or not

    do {
        // Prompt the user to choose encryption or decryption
        cout << "Press 'E' for encryption and 'D' for decryption" << endl;
        cin >> input_user;

        cout << "Enter text: " << endl;
        cin >> input;

        cout << "Enter key: " << endl;
        cin >> key;

        // Switch statement to perform encryption or decryption based on user input
        switch (input_user[0])
        {
        case 'E':
        case 'e':
            cout << "Encrypted text: " << endl << encryption(input, key) << endl;
            break;
        case 'D':
        case 'd':
            cout << "Decrypted text: " << endl << decryption(input, key) << endl;
            break;
        default:
            cout << "Invalid input" << endl;
        }

        cout << "Do you want to encrypt or decrypt again? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
