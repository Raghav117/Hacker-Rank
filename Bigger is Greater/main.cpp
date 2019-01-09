#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string s) {
    int i,l=s.length(),c=-1;
    for(i=0;i<l-1;++i)
        if(int(s[i])<int(s[i+1]))
            c=i;
    
    if(c<0)
        return "no answer";

    int j=int(s[c]);
    int k=int(s[c+1]);
    int m=c+1;
    
    for(i=c+2;i<l;++i)
        if(k>int(s[i]) && int(s[i])>j)
        {
            k=int(s[i]);
            m=i;
        }

    s[m]=s[c];
    s[c]=char(k);

    sort(s.begin()+c+1,s.end());
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}
