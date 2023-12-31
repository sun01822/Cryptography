#include<bits/stdc++.h>

using namespace std;

string encryptionVigenere(string plainText, string keyword);

int main(){
    string plainText, keyword, newKeyword, cipherText;
    cout << "Enter Plain Text(capital letter): ";
    getline(cin, plainText);
    cout << "Enter keyword: ";
    getline(cin,keyword);
    int len = keyword.size();
    if(len < plainText.size()){
        newKeyword = keyword;
        int i=0;
        while(len < plainText.size()){
            newKeyword.push_back(keyword[i]);
            i++;
            len++;
            if(i==keyword.size()){
                i=0;
            }
        }
        cout << newKeyword << endl;
        cipherText = encryptionVigenere(plainText, newKeyword);
    }
    else{
        cipherText = encryptionVigenere(plainText, keyword);
    }

    cout << "Cipher Text: " << cipherText << endl;
    return 0;
}

string encryptionVigenere(string input, string keyword){
    string cipherText = "";
    for(int i=0; i<input.size(); i++){
        int temp = ((input[i]-'A') + (keyword[i] - 'A')) % 26;
        char c = temp + 'A';
        cipherText+=c;
    }
    return cipherText;
}
