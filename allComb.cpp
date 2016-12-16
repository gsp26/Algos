#include<iostream>
#include<string>
#include<vector>

using namespace std;
void swap(vector<char> &s,int a,int b)
{
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

void permute(vector<char> s,int l , int r)
{
    //results.push_back(s.substr(l,r-l+1));
    if(l==r)
    {
        cout << string(s.begin(),s.end()) << endl;
        //count++;
    }
    else
    {
        for(int i=l;i<=r;++i)
        {
            swap(s,l,i);
            permute(s,l+1,r);
            swap(s,l,i);
        }
    }
}

void combUtil(string s,int n,int r,int index, vector<char> data,int i)
{
    //current combination is ready
    if(index == r)
    {
        for(int i=0;i<r;i++)
           cout << data[i];
        cout << "\n";
        //permute(data,0,r);
        return;
    }
    //when no more elements are there to put in data[];
    if(i>=n)
        return;

    //current is included put next at next location

    data[index] = s[i];
    combUtil(s,n,r,index+1,data,i+1);

    //current is excluded replace it with next ( note that i+1 is passed but index is not changed.)
    combUtil(s,n,r,index,data,i+1);
}

void printComb(string s,int n,int r)
{
    vector<char> data(r);
   // string data;
    combUtil(s,n,r,0,data,0);
}

int main()
{
    cout << "DUDE printing all the combinations >>> "<< endl;
    string s;
    cin >> s;
    for(int i=1;i<=s.length();i++)
       printComb(s,s.length(),i);
    //printComb(s,s.length(),2);

    return 0;
}


