#include<iostream>
using namespace std;
bool isPalindrom(string s,int start,int end)
{
   if(start>=end)
   {
       return true;
   }
   else {
       return (s[start]==s[end] && isPalindrom(s,start+1,end-1));
   }
}
int main()
{
    string s;
    cin>>s;
    int e;
    cin>>e;
   if( isPalindrom(s,0,e-1))
   cout<<"is a palindrome";
   else
   {
       cout<<"not a palindrome";
   }
    return 0;
}
