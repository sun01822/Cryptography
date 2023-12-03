// Encryption
#include<bits/stdc++.h>
using namespace std;

// A B C D E F G H I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
// 0 1 2 3 4 5 6 7 8  9 10 11 12 13 14 15 16 17 18 19 20 21 21 23 24 25

bool used[26];
vector<vector<int>> v(5, vector<int>(5, -1));

string decryption(string);

int main()
{
    string key;
    used[9] = true;
    cout << "Enter a key(capital letter): ";
    getline(cin, key);
//    cout << "Key is: " << key << endl;
    for(int i=0; i<key.size(); i++){
        if(key[i]=='J'){
            key[i] = 'I';
        }
    }
    cout << "Key is: " << key << endl;
    int rotation = 0;
    bool flag = false;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5;)
        {
            if(rotation==key.size())
            {
                flag = true;
                break;
            }
            int temp = key[rotation] - 'A';
            if(used[temp]!=true)
            {
                v[i][j] = temp;
                used[temp] = true;
                j++;
            }
            rotation++;
        }
        if(flag)
            break;
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(v[i][j]==-1)
            {
                for(int k=0; k<26; k++)
                {
                    if(!used[k])
                    {
                        v[i][j] = k;
                        used[k] = true;
                        break;
                    }
                }
            }
        }
    }

    cout << "Key Matrix: " << endl;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            char c = v[i][j] + 'A';
            cout << c << ' ';
            //cout << v[i][j] << ' ';
        }
        cout << endl;
    }



    string cipherText;
    cout << "Enter Cipher Text(capital letter): ";
    getline(cin, cipherText);
    vector<string> store;
    for(int i=0; i<cipherText.size(); )
    {
        string temp = "";
        temp+=cipherText[i];
        temp+=cipherText[i+1];
        i+=2;
        store.push_back(temp);
    }

    string plainText = "";
    for(auto i:store)
    {
        cout << i << endl;
        plainText+=decryption(i);
    }
    cout << "Cipher Text: " << plainText << endl;

    return 0;
}

string decryption(string s)
{
    string plain = "";
    int char1 = s[0] - 'A';
    int char2 = s[1] - 'A';
    int row1 = -1;
    int row2 = -1;
    int column1 = -1;
    int column2  = -1;
    bool flag = false;
    bool find1 = false;
    bool find2 = false;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(v[i][j] == char1)
            {
                row1 = i;
                column1 = j;
                find1 = true;
            }
            else if(v[i][j] == char2)
            {
                row2 = i;
                column2 = j;
                find2 = true;
            }
            if(find1 && find2)
            {
                flag = true;
            }
        }
        if(flag)
        {
            break;
        }
    }

//    cout << "Row1: " << row1 << " Column1: " << column1 << endl;
//    cout << "Row2: " << row2 << " Column2: " << column2 << endl;
//    cout << endl;

    if(row1 == row2)
    {
        int row = row1;
        column1--;
        column2--;
        if(column1 < 0)
        {
            column1 = 4;
        }
        if(column2 < 0)
        {
            column2 = 4;
        }
        char c1 = v[row][column1] + 'A';
        char c2 = v[row][column2] + 'A';
        plain+=c1;
        plain+=c2;
    }

    else if(column1 == column2)
    {
        int column = column1;
        row1--;
        row2--;
        if(row1 < 0)
        {
            row1 = 4;
        }
        if(row2 < 0)
        {
            row2 = 4;
        }
        char c1 = v[row1][column] + 'A';
        char c2 = v[row2][column] + 'A';
        plain+=c1;
        plain+=c2;
    }

    else
    {
        char c1 = v[row1][column2] + 'A';
        char c2 = v[row2][column1] + 'A';
        plain+=c1;
        plain+=c2;
    }

    return plain;
}

