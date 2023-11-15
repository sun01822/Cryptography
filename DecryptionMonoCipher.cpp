#include<bits/stdc++.h>
using namespace std;

int main(){
    string value = "zaybxcwdveuftgshriqjpkolnm";
    string input, plainText = "";
    cout << "Enter cipher text: ";
    cin >> input;

    for(int i=0; i<input.size(); i++){
        for(int j=0; j<value.size(); j++){
            if(input[i]==value[j]){
                char c = j + 97;
                plainText+=c;
            }
        }
    }
    cout << "Cipher Text: " << plainText << endl;
    return 0;
}
