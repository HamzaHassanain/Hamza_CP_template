#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
struct segTree
{
    int size;
    vector<double> data;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        data.assign(2 * size, 0LL); // asigin it to the cloeset poewr of two
    }
    void set(int i, double value, int node, int beginSeg, int endSeg)
    {
        if (beginSeg == endSeg)
        {
            data[node] = value;
            return;
        }

        int mid = (beginSeg + endSeg) / 2;
        if (i <= mid)
            set(i, value, 2 * node, beginSeg, mid);
        else
            set(i, value, 2 * node + 1, mid + 1, endSeg);

        data[node] = (data[2 * node] + data[2 * node + 1]);
    }

    double sum(int left, int right, int node, int beginSeg, int endSeg)
    {
        if (beginSeg > right || left > endSeg)
            return 0;

        if (beginSeg >= left && endSeg <= right)
            return data[node];

        int mid = (beginSeg + endSeg) / 2;
        double sum1 = this->sum(left, right, 2 * node, beginSeg, mid);
        double sum2 = this->sum(left, right, 2 * node + 1, mid + 1, endSeg);

        return (sum1 + sum2);
    }
    double sum(int left, int right)
    {

        return sum(left, right, 1, 1, size);
    }
    void set(int i, double value)
    {
        set(i, value, 1, 1, size);
    }
};	
const int N =3e5+1;
segTree sgt;
vector<int> adj[N];
int timer = 0;

int flat[2*N];
int start[N];
int leave[N];

void flaten_tree(int u  =1,int p  = 0) {
	timer++;
	start[u] = timer;
	flat[timer] = u;
	
	for(int& v : adj[u]) {
		if(p == v) continue;
		flaten_tree(v,u);
	}
	timer++;
	leave[u] = timer;
	flat[timer] = u;
} 

int main() {
	
	ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	
	int n,q;
	cin >> n;
	sgt.init(2*n);

	for(int i  = 2;i<= n;i++) {
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	flaten_tree();
	for(int i  =1;i<=2*n;i++ ) sgt.set(i,0);
	
	vector<vector<int>> qs;
	cin >> q;
	for (int i = 0;i < q;i++) {
		int a,b,c;
		cin >> a >> b >> c;

		qs.push_back( {a ,b, c} );
	}
	cout << setprecision(9); 
    cout << fixed;
    
	for(auto arr : qs) {
		int type = arr[0];
		if(type ==2) {
			double subtree1 = sgt.sum ( start[arr[1]] , leave[arr[1]] ) / 2; 
			double subtree2 = sgt.sum ( start[arr[2]] , leave[arr[2]] ) / 2;
			double ans =  subtree1 - subtree2;
			if(ans <= 0) cout << pow(2,ans)<< "\n";
			else if(ans >= log2(1e9)) cout << int(1e9) << "\n";
			else cout << pow(2,ans)<< "\n";
		} else {
			sgt.set(start[arr[1]] , log2(arr[2]) ),sgt.set(leave[arr[1]] , log2(arr[2]));
		}
	}
	return 0;
}
