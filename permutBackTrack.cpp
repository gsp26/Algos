#include<iostream>
#include<string>
#include<vector>
using namespace std;

static int count = 0;
static vector<string> results;
void swap(string &s,int a,int b)
{
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

void permute(string s,int l , int r)
{
    //results.push_back(s.substr(l,r-l+1));
    if(l==r)
    {
        cout << s << endl;
        count++;
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

int main()
{
    cout << "permutation string" << endl;
    string s;
    cout << "enter the strin- ";
    cin >> s;
    permute(s,0,s.length()-1);
    cout << "Total count - " << count << endl;
    //cout << " Now all combinations of the string- picking min 1 to all strings" << endl;
    //for(int i=0;i<results.size();++i)
     //   cout << results[i] << endl;
    //cout << "size of all results - " << results.size() << endl;


    return 0;
}
