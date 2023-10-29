#include <iostream>
using namespace std;

string encryption(string input, int key);

int main(){
    string input;
    int key;
    cout << "Enter a sentence as Plain Text(all small letters): ";
    getline(cin, input);
    cout << "Enter Key: ";
    cin >> key;

    // Encryption
    string cipher_text = encryption(input, key);
    cout << "\nCipher Text: " << cipher_text << endl;

    return 0;
}


// Encryption Function
string encryption(string input, int key){
    string ans = "";
    for(int i=0; i<input.size(); i++){
        int val = input[i] - 97 + key;
        if(val > 25)
            val%=26;
        char c = val + 97;
        ans+=c;
    }
    return ans;
}
