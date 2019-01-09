#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulTriplets function below.
int beautifulTriplets(int d, vector<int> arr) {
    int i=0,x=1,y,z,c=0;
    for(i=1;i<arr.size()-1;++i)
    {
        if(arr[i]!=arr[i+1])
        {
            y=count(arr.begin(),arr.begin()+i,arr[i]-d);
            if(y>0)
            {
                z=count(arr.begin()+i+1,arr.end(),arr[i]+d);
                if(z>0)
                    c+=x*y*z;
            }
            x=0;y=0;z=0;
        }
            ++x;
    }
 
    return c;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    cout<<beautifulTriplets(d, arr);



    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
