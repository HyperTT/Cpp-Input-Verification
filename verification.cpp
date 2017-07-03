#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool ssn_validation(string test)
{
    bool ssn_valid_length = true;
    bool ssn_valid_hyphens = true;
    bool ssn_valid_characters = true;
    if (test.length() != 11)
    {
        cout << "Problem: You must type exactly 11 characters.\n";
        ssn_valid_length = false;
        return ssn_valid_length;

    }
    if (test[3] != '-' || test[6] != '-')//xxx-xx-xxxx
    {                                    //012345678910
        cout << "Problem: The dashes are missing or are in the wrong spot\n";
        ssn_valid_hyphens = false;
        return ssn_valid_hyphens;
    }
    for (int counter = 0; counter < test.length();counter++)
    {
        if (isalpha(test[counter]))
        {
            cout << "Problem: Only digits are allowed in a SSN\n";
            ssn_valid_characters = false;
            return ssn_valid_characters;
        }
    }
    return ssn_valid_length && ssn_valid_hyphens && ssn_valid_characters;
}

int main ()
{
    string ssn;
    cout << "Enter your SSN in this format: XXX-XX-XXXX\n";
    cin >> ssn;
    if (!ssn_validation(ssn))
    {
        return 0;
    }
    cout << "That is valid.\n";
    return 0;
}
