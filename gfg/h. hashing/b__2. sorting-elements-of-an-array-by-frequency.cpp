#include <bits/stdc++.h>
using namespace std;

//Q. https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0
unordered_map<int, int> mp;

bool comp(int x, int y) {
    if(mp[x] == mp[y]) return x<y;
    return mp[x] > mp[y];
}

vector<int> sortByFrequency(vector<int> vec, int n) {
    mp.clear();
    for(int i=0; i<n; i++) {
        mp[vec[i]]++;
    }
    sort(vec.begin(), vec.end(), comp);
    return vec;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<int> vec(n);
	    for(int i=0; i<n; i++) cin >> vec[i];
	    vector<int> ans = sortByFrequency(vec, n);
	    for(int i=0; i<n; i++) cout << ans[i] << " ";
	    cout << endl;
	}
	return 0;
}