#include<bits/stdc++.h>
using namespace std;

int main(){
    string value ="zaybxcwdveuftgshriqjpkolnm";
    string input, cipherText = "";
    cout << "Enter a Sentence is lowercase: ";
    cin >> input;

    for(int i=0; i<input.size(); i++){
        int temp = input[i] - 97;
        cipherText+=value[temp];
    }
    cout << "Cipher Text: " << cipherText << endl;
    return 0;
}
