#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_length(string key);
int check_alpha(char c[26]);
int check_repetition(char b[26]);
string encrypt(char keyl[26], string pt);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Key not Entered!\n");
        return 1;
    }
    else if (argc == 2 && check_length(argv[1]) == 26)
    {
        int alpha = check_alpha(argv[1]);
        if (alpha == 26)
        {
            int rep = check_repetition(argv[1]);
            if (rep == 0)
            {
                string plain_text = get_string("plaintext:  ");
                string ciphertext = encrypt(argv[1], plain_text);
                printf("ciphertext: %s\n", ciphertext);
                return 0;
            }
            else
            {
                printf("Key cannot contain repeated chars.\n");
                return 1;
            }
        }
        else
        {
            printf("Key cannot contain non-alphabetical characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Key must conatain 26 characters.\n");
        return 1;
    }
}

int check_length(string key)
{
    int length = strlen(key);
    return length;
}

int check_alpha(char c[26])
{
    int yn = 0;
    for (int i = 0; i < 26; i++)
    {
        char keyl = c[i];
        int check = isalpha(keyl);
        if (check == 0)
        {
            yn = yn + 0;
        }
        else
        {
            yn++;
        }
    }
    return yn;
}

int check_repetition(char b[26])
{
    int a = 0;
    for (int i = 0; i < 26; i++)
    {
        char c = toupper(b[i]);
        for (int j = 0; j < 26; j++)
        {
            char d = toupper(b[j]);
            if (c == d)
            {
                a++;
            }
        }
    }
    if (a > 26)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string encrypt(char keyl[26], string pt)
{
    char keyl_cap[26];
    for (int i = 0; i < 26; i++)
    {
        if (keyl[i] >= 97)
        {
            keyl_cap[i] = keyl[i] - 32;
        }
        else
        {
            keyl_cap[i] = keyl[i];
        }
    }
    for (int i = 0, j = strlen(pt); i < j; i++)
    {
        if (pt[i] >= 65 && pt[i] <= 90)
        {
            pt[i] = toupper(keyl[pt[i] - 65]);
        }
        else if (pt[i] >= 97 && pt[i] <= 122)
        {
            pt[i] = tolower(keyl[pt[i] - 97]);
        }
        else
        {
            pt[i] = pt[i];
        }
    }
    return pt;
}
