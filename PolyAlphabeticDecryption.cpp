#include<bits/stdc++.h>

using namespace std;

string decryptionVigenere(string cipherText, string keyword);


int main(){
    string cipherText, keyword, newKeyword, plainText;
    cout << "Enter Cipher Text(capital letter): ";
    getline(cin, cipherText);
    cout << "Enter keyword: ";
    getline(cin,keyword);
    int len = keyword.size();
    if(len < cipherText.size()){
        newKeyword = keyword;
        int i=0;
        while(len < cipherText.size()){
            newKeyword.push_back(keyword[i]);
            i++;
            len++;
            if(i==keyword.size()){
                i=0;
            }
        }
        cout << newKeyword << endl;
        plainText = decryptionVigenere(cipherText, newKeyword);
    }else{
        plainText = decryptionVigenere(cipherText, keyword);
    }
    cout << "Plain Text: " << plainText << endl;
    return 0;
}

string decryptionVigenere(string input, string keyword){
    string plainText = "";
    for(int i=0; i<input.size(); i++){
        int temp = ((input[i]- 'A') - (keyword[i] - 'A'));
        if(temp < 0){
            temp+=26;
        }
        char c = temp + 'A';
        plainText+=c;
    }
    return plainText;
}

