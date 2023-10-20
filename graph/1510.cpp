// thuat toan chieu rong
#include<bits/stdc++.h>
using namespace std;
// 5 9
//

// danh sach ke

int n, m;
vector<int> adj[1001];
bool visited[1001]; 

// luu danh sac ke cua dinh i 

void inp(){

	cin>> n >> m;
	for (int i =0; i < m; i++){
	
	int x, y; cin >> x >> y;
	adj[x].push_back(y);
	adj[y].push_back(x);
}
memset(visited, false, sizeof(visited));
 

}

void bfs(int u){
	cout << u << " ";
	// Buoc khoi tao 
	queue<int> q; 
	q.push(u); 
	visited[u] = true;
	// Buoc lap
	while(!q.empty()){
		int v = q.front();// lay dinh o dau hang
		q.pop();
		cout<< v << " ";
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true; 
			} 
		} 
	} 
	 

} 


int main(){
	inp();
	bfs(1); 
	return 0; 
}