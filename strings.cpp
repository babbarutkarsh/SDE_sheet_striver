// Strings 10.30-12.00
// roman to integer
// atoi
// longest common prefix

// rabin karp algo done
// kmp 
// minimum chars to make string pallindromic dp
// count and say
// compare version numbers

#include<iostream>
using namespace std;
// rabin karp
#define d 256
// count and say
string helper(string s) {
        // count and say
        string out;
        // string s=to_string(n);
        cout<<s.size()<<endl;
        for(int i=0;i<s.size();i++){
            int temp=1;
            if(i+1<s.size())
                while(s[i]==s[i+1]){temp++;i++;}
            out=out+to_string(temp)+s[i];
        }
        return out;
    }
    // compare version numbers 
    int compareVersion(string version1, string version2) {
        // compare each block 
        int i=0;
        int j=0;
        while(i<version1.size() or j<version2.size()){
            long long temp1=0;
            long long temp2=0;
            if(version1.size()==0)temp1=0;
            if(version2.size()==0)temp2=0;
            while(i<version1.size() and version1[i]!='.'){
                temp1=temp1*10+version1[i]-'0';
                i++;
            }
            while(j<version2.size() and version2[j]!='.'){
                temp2=temp2*10+version2[j]-'0';
                j++;
            }
            if(temp1>temp2)return 1;
            else if(temp1<temp2)return -1;
            i++;j++;
        }
        return 0;
    }
    string countAndSay(int n){
        if(n==1)
            return "1";
        return helper(countAndSay(n-1));
    }
void RabinKarp(string text, string pattern){
// given a pattern find all occurences of it in the text
// rabin karp matches the hash value of pattern with substring 
// if two strings are equal their hash value is also equal

// pattern length=m, text is n, create a window of size m and hash window compare 
// with hash value of pattern
// hash function should provide hash in O(1)

// hash(txt[s+1...s+m])=d(hash(txt[s...s+m-1])-txt[s]*h)+txt[s+m] mod q
// d = number of characters in the alphabet
// q = prime number
// h=d^(m-1)

int M=strlen(pattern);
int N=strlen(text);
int i,j;
int p=0;// hash value of pattern
int t=0;// hash value for substring of text
int h=1;

for(int i=0;i<M-1;i++)h=(h*d)%q;

for(int i=0;i<M;i++){
    p=(d*p+pattern[i])%q;
    t=(d*t+pattern[i])%q;
}



}

// roman to integer
int romanToInt(string s) {
    int ans=0;
    unordered_map <char,int> mp{
    {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]<mp[s[i+1]])
            ans=ans-mp[s[i]];
        else 
            ans=ans+mp[s[i]];
    }
    return ans;
}
int myAtoi(string s) {
    // remove leading whitespaces
    long long int out=0;
    int negFlag=1;
    int i=0;
    while(s[i]==' ')i++;

    // check for - or +
    if(s[i]=='-'){
        negFlag=-1;
        i++;
    }
    else if(s[i]=='+'){
        i++;
    }
    // read in till the non-digit char is reached or end is reached
    for(;i<s.size();i++){
        if(!isdigit(s[i]))break;
        // convert to digits
        out=(out*10)+(s[i]-48);
        if(out*negFlag>INT_MAX)return INT_MAX;
        if(out*negFlag<INT_MIN)return INT_MIN;
    }
    return out*negFlag;
}
int main(){
    string s="apple string apple";
    char* s[]="This is a pointer string"
}

// revise all major string functions and their usecases