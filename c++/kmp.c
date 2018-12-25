#include<iostream>
#include<string>
using namespace std;

int* getNext(string str2);
int getIndexOf(string str1, string str2);

int main(){
    string str1 = "1234567fdsa";
    string str2 = "fdsa";
    int i = getIndexOf(str1, str2);
    cout << i << endl;
    return 0;
}

int getIndexOf(string str1, string str2){
    if( str1.length() < str2.length() )
        return -1;
    int* next = getNext(str2);
    int i = 0;
    int j = 0;
    while( i < str1.length() && j < str2.length() ) {
        if( str1[i] == str2[j] ) {
            i++;
            j++;
        }
        else if(next[j] == -1)
            i++;
        else
            j = next[j];
    }
    return j == str2.length() ? i - j : -1;
}

int* getNext(string str2){
    int lenOfStr2 = str2.length();
    if( lenOfStr2 == 1){
        int* next= new int[1];
        next[1] = -1;
        return next;
    }
   int* next = new int[lenOfStr2];
   next[0] = -1;
   next[1] = 0;
   int i = 2;
   int cn = 0;
   while( i < lenOfStr2 ){
       if( str2[i - 1] == str2[cn] )
           next[i++] = next[i-1] + 1;
       else{
           if( cn == -1 )
               next[i++] = 0;
           else
               cn = next[cn];
       }
   }
   return next;
}
