#include<bits/stdc++.h>

using namespace std;

string encryptionVigenere(string plainText, int arr[], int len);

int main(){
    string plainText, keyword;
    cout << "Enter Plain Text(capital letter): ";
    getline(cin, plainText);
    cout << "Enter keyword: ";
    getline(cin,keyword);
    int len = keyword.size();
    int arr[len];
    for(int i=0; i<len; i++){
        arr[i] = keyword[i] - 'A';
    }
    string cipherText = encryptionVigenere(plainText, arr, len);

    cout << "Cipher Text: " << cipherText << endl;
    return 0;
}

string encryptionVigenere(string input, int arr[], int len){
    string cipherText = "";
    int sizeInput = input.size();
    int counter = 0;
    int i = 0;
    while(sizeInput){
        int temp = (input[i] - 'A' + arr[i]) % 26;
        char c = temp + 'A';
        cipherText+=c;
        counter++;
        if(counter==len){
            counter=0;
        }
        i++;
        sizeInput--;
    }
    return cipherText;
}
