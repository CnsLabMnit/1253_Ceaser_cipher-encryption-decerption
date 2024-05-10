#include <iostream>
#include <limits>

using namespace std;

// Define macros for Unix-like systems
#define PAUSE "read -p 'Press Enter to continue...' var"
#define CLR "clear"

/********************************************************************************************
    Caesar Encryption Function C = E(k, p) = (p + k) mod 26
********************************************************************************************/
string encryption_CaesarCipher(int k, string &plain_text)
{
    string output;
    for(char ch: plain_text)
    {
        // Uppercase char
        if(isupper(ch)) {
            output += char((int(ch) - 65 + k) % 26 + 65);
        }
        // Lowercase char
        else if(islower(ch)) {
            output += char((int(ch) - 97 + k) % 26 + 97);
        }
        else
            output += ch;
    }

    return output;
}

/********************************************************************************************
    Caesar Decryption Function p = D(k, C) = (C - k) mod 26
********************************************************************************************/
string decryption_CaesarCipher(int k, string &cipher_text)
{
    string output;
    int normalised, r;
    for(char ch: cipher_text)
    {
        // Uppercase char
        if(isupper(ch)) {
             normalised = (int(ch) - 65 - k);
             r = normalised % 26 >= 0 ? normalised % 26  : 26 + normalised % 26 ;
            output += char(r + 65);
        }
        // Lowercase char
        else if(islower(ch)) {
            normalised = (int(ch) - 97 - k);
            r = normalised % 26 >= 0 ? normalised % 26  : 26 + normalised % 26 ;
            output += char(r + 97);
        }
        else
            output += ch;
    }

    return output;
}

int main()
{
    char choice;
    string ip_plain_txt, op_plain_txt;  // Plain text to encrypt
    string op_cipher_txt, ip_cipher_txt; // Cipher text
    int shift_val; // Shift value for Caesar cipher

    do{
        char ch;

        cout << endl << endl << endl;
        system(PAUSE);
        system(CLR);

        cout << "\n\n -------- CAESER CIPHER MENU--------";

        cout << "\n e. Encryption";
        cout << "\n d. Decryption";

        cout << "\n\n n. Exit - Bye \n\n --Choice : ";
        cin >> ch;
        cout << "\n <-------->";

        switch(ch){
            // Encryption
            case 'e':
                cout << "\n Enter Plain Text String : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, ip_plain_txt);

                cout << "\n Enter Shift Value \'k\' (1-25) : ";
                cin >> shift_val;

                op_cipher_txt = encryption_CaesarCipher(shift_val, ip_plain_txt);

                cout << "\n ENCRYPTION DONE :"
                     << "\n :::::=> Plain Text (input) : " << ip_plain_txt
                     << "\n :::::=> Shift Value (input) : " << shift_val
                     << "\n :::::=> Cipher Text (output) : " << op_cipher_txt;

                break;
            // Decryption
            case 'd':
                cout << "\n Enter Cipher Text String : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, ip_cipher_txt);

                cout << "\n Enter Shift Value \'k\' (1-25) : ";
                cin >> shift_val;

                op_plain_txt = decryption_CaesarCipher(shift_val, ip_cipher_txt);

                cout << "\n DECRYPTION DONE :"
                    << "\n :::::=> Cipher Text (input) : " << ip_cipher_txt
                    << "\n :::::=> Shift Value (input) : " << shift_val
                    << "\n :::::=> Plain Text (output) : " << op_plain_txt;

                break;

            case 'n': cout << "\n Bye \n"; break;
            default: cout << "\n--Invalid Choice. Enter Again \n";
        }

        choice=ch;
    } while(choice != 'n');

    cin.get();
    cin.get();
    return 0;
}
