#include<iostream>

using namespace std;

int main()
{
    cout << "All permutations of a string" << endl;

    string s;
    cout <<"Please enter the string-";
    cin >> s;
    cout <<"\n Input String is - " << s << endl;
    int ct=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                if(i!=j && j !=k && i!=k)
                {
                    cout << s[i]<<s[j]<<s[k] << endl;;
                    ct++;
                }
   cout << "Total permutations = " << ct << endl;




    return 0;
}
