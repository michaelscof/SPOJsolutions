#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+3;
int parent[MAX],nodes,edges;
pair<int,pair<int,int> > arr[MAX];
void initialize()
{
    for(int i= 0;i<MAX;i++)
        parent[i]=i;
}
int root(int x)
{
    while(parent[x]!=x)
    {
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}
void union1(int x,int y)
{
    int p=root(x);
    int q=root(y);
    parent[p]=parent[q];
}
int kruskal(pair<int,pair<int, int> > arr[])
{
    int x, y;
    int cost,mcost=0;
    for(int i=0;i<edges;i++)
    {
        x=arr[i].second.first;
        y=arr[i].second.second;
        cost=arr[i].first;
        if(root(x)!=root(y))
        {
            mcost+=cost;
            union1(x, y);
        }
    }
    return mcost;
}

int main()
{
    cin>>nodes>>edges;
    while(nodes!=0 && edges!=0)
    {
      int x,y;
      int weight,cost,mcost;
      initialize();
      int sum=0;
      for(int i=0;i<edges;i++)
      {
          cin>>x>>y>>weight;
          arr[i]=make_pair(weight,make_pair(x,y));
          sum+=weight;
      }
      sort(arr,arr+edges);
      mcost=kruskal(arr);
      cout<<sum-mcost<<endl;
      cin>>nodes>>edges;
    }
    return 0;
}
