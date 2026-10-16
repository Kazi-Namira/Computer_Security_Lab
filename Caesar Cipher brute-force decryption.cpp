#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string decryptCaesar(string ciphertext, int key)
{
    string plaintext = "";

    for (char ch : ciphertext)
    {
        if (isupper(ch))
        {
            char decrypted = (ch - 'A' - key + 26) % 26 + 'A';
            plaintext += decrypted;
        }
        else if (islower(ch))
        {
            char decrypted = (ch - 'a' - key + 26) % 26 + 'a';
            plaintext += decrypted;
        }
        else
        {
            plaintext += ch;
        }
    }

    return plaintext;
}

int main()
{
    string ciphertext;
    cout << "Enter the ciphertext: ";
    getline(cin, ciphertext);
    cout << "\n--- Caesar Cipher Brute-Force Decryption ---\n";

    for (int key = 1; key <= 25; key++)
    {
        cout << "Key " << key << ": "
             << decryptCaesar(ciphertext, key) << endl;
    }

    return 0;
}

// input: WKLV LV D WHVW PHVVDJH
