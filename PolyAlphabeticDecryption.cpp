#include<bits/stdc++.h>

using namespace std;

string decryptionVigenere(string cipherText, int arr[], int len);


int main(){
    string cipherText, keyword;
    cout << "Enter Cipher Text(capital letter): ";
    getline(cin, cipherText);
    cout << "Enter keyword: ";
    getline(cin,keyword);
    int len = keyword.size();
    int arr[len];
    for(int i=0; i<len; i++){
        arr[i] = keyword[i] - 'A';
    }
    string plainText = decryptionVigenere(cipherText, arr, len);

    cout << "Plain Text: " << plainText << endl;
    return 0;
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

