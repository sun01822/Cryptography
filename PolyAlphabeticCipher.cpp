#include<bits/stdc++.h>

using namespace std;

string encryptionVigenere(string plainText, int arr[], int len);
string decryptionVigenere(string cipherText, int arr[], int len);



int main(){
    string input, keyword;
    cout << "Enter Plain Text(capital letter): ";
    getline(cin, input);
    cout << "Enter keyword: ";
    getline(cin,keyword);
    int len = keyword.size();
    int arr[len];
    for(int i=0; i<len; i++){
        arr[i] = keyword[i] - 'A';
    }
    string cipherText = encryptionVigenere(input, arr, len);
    string plainText = decryptionVigenere(cipherText, arr, len);

    cout << "Cipher Text: " << cipherText << endl;
    cout << "Plain Text: " << plainText << endl;
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

string decryptionVigenere(string cipherText, int arr[],int len){
    string plainText = "";
    int sizeInput = cipherText.size();
    int counter = 0;
    int i = 0;
    while(sizeInput){
        int temp = (cipherText[i] - 'A' - arr[i]);
        if(temp < 0){
            temp += 26;
        }
        char c = temp + 'A';
        plainText += c;
        counter++;
        if(counter==len){
            counter = 0;
        }
        i++;
        sizeInput--;
    }
    return plainText;
}
