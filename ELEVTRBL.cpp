/*PREM KAGRANI*/
/*MNNIT ALLAHABAD*/
/*Used simple bfs to find the number of key presses required*/
#include<bits/stdc++.h>
using namespace std;
bool visited[1000002];
int press[1000002];
int f,s,g,u,d;
void bfs()
{
	queue<int> q;
	q.push(s);
	press[s]=0;
	visited[s]=true;
	while(!q.empty())
	{
		int val=q.front();
		q.pop();
		if(visited[g])
			return;
		if(val+u<=f && !visited[val+u])
		{
			q.push(val+u);
			press[val+u]=press[val]+1;
			visited[val+u]=true;
		}
		if(val-d>0 && !visited[val-d])
		{
			q.push(val-d);
			press[val-d]=press[val]+1;
			visited[val-d]=true;
		}
	}
}
int main() {
	memset(press,0,sizeof(press));
	memset(visited,false,sizeof(visited));
	cin>>f>>s>>g>>u>>d;
	bfs();
	if(visited[g])
		cout<<press[g];
	else
		cout<<"use the stairs";
	return 0;
}