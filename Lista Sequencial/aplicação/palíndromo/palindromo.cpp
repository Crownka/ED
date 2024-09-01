#include <iostream>
using std::string;

bool isPalindrome(string word){
    int n = word.length();
    for(int i = 0; i < n / 2; i++){
        if(word[i] != word[n - 1 - i]){
            return false;
        }
    }
    return true;
}

int main(){
    string w;
    std::cin >> w;
    if(isPalindrome(w)){
        std::cout << "palindromo" << std::endl;
    }else{
        std::cout << "nao palindromo" << std::endl;
    }
}