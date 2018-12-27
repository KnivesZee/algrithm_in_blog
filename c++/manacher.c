#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int getMaxcpsLength(string str);
string handleString(string str);

int main(int argc, char* argv[]) {
    for( int i = 1; i < argc; i++){
        string str = argv[i];
        cout << getMaxcpsLength(str) << endl;
    }
    string str = "112211";
    cout << "test str 112211" << endl;
    cout << getMaxcpsLength(str) << endl;
    return 0;
}

string handleString(string str){
    string resStr(str.length() * 2 + 1,' ');
    for(int i = 0, index = 0; i < resStr.length(); i++)
        resStr[i] = i % 2 == 0 ? '#' : str[index++];
    return resStr;
}

int getMaxcpsLength(string str){
    string handledStr = handleString(str);
    int pArr[handledStr.length()];
    int C = -1;
    int R = -1;
    int theMax = -1;
    for(int i = 0; i < handledStr.length(); i++){
        pArr[i] = R > i ? min(pArr[2 * C - i], R - i) : 1;
        while( i + pArr[i] < handledStr.length() && i - pArr[i] > -1){
            if(handledStr[i + pArr[i]] == handledStr[i - pArr[i]])
                pArr[i]++;
            else
                break;
        }
        if( i + pArr[i] > R){
            R = i + pArr[i];
            C = i;
        }
        theMax = max(theMax, pArr[i]);
    }
    return theMax / 2;
}
