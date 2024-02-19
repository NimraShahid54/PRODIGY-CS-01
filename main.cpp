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
        a = s[i] + key; 
        // Check if the character is within the lowercase or uppercase alphabet range
        if ((a < 'z' && s[i] <= 'z') || (a < 'Z' && s[i] <= 'Z'))
        {
            output += a; 
        } else {
            a -= 26; 
            output += a; 
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
        a = s[i] - key; 
        
        // Check if the character is within the lowercase or uppercase alphabet range 
        
        if ((a >= 'a' && s[i] >= 'a') || (a >= 'A' && s[i] >= 'A')) {
            output += a; 
        }
        else
        {
            a += 26; 
            output += a; 
        }
    }
    return output; 
}

int main()
{
    string input, input_user; // Variables to store user input
    int key; // Variable to store the encryption/decryption key

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

    return 0;
}
