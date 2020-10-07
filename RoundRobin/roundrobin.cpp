#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// code by abhinav verma
// LinkedIn: https://www.linkedin.com/in/abhinavverma2
int main(){
    ll n;
    cin>>n;
    ll arrival[n];
    ll burst[n];
    ll copyofburst[n];
    
    for(ll i=0; i<n; i++){
        cin>>arrival[i];
    }
    for(ll i=0; i<n; i++){
        cin>>burst[i];
        copyofburst[i]=burst[i];
    }
    ll quantum;
    cin>>quantum;
    queue<ll> ready;
    queue< pair<ll,ll> > running;
    ll j=0;
    // pushing all with same arrival
    while(arrival[j]==arrival[j+1]){
        ready.push(j+1);
        j++;
    }
    ready.push(j+1);
    ll sum=0;
    bool visited[n+1];
    for(ll i=0; i<n+1; i++){
        visited[i]=false;
    }
    while(ready.empty()==false){
        ll pnum=ready.front();
        visited[pnum]=true;
        ready.pop();
        
        ll mini=min(quantum,burst[pnum-1]);
        sum+=mini;
        pair<ll,ll> p;
        p.first=pnum;
        p.second=sum;
        running.push(p);
        burst[pnum-1]-=mini;
        for(ll i=0; i<n; i++){
            if(visited[i+1]==false){
                if(arrival[i]<=sum){
                    ready.push(i+1);
                    visited[i+1]=true;
                }
            }
        }
        if(burst[pnum-1]>0){
            ready.push(pnum);
        }
    }
    bool visit[n+1];
    for(ll i=0; i<n+1; i++){
        visit[i]=false;
    }
    ll completion[n+1];
    vector< pair<ll,ll> > rr;
    while(running.empty()==false){
        pair<ll,ll> p1=running.front();
        rr.push_back(p1);
        running.pop();
    }
    // calculating completion time for each process
    for(ll i=rr.size()-1; i>=0; i--){
        pair<ll,ll> p2=rr[i];
        ll processnum=p2.first;
        ll finaltime=p2.second;
        if(visit[processnum]==false){
            completion[processnum]=finaltime;
            visit[processnum]=true;
        }
    }
    ll turnaround[n+1];
    // calculating turnaround time
    for(ll i=1; i<=n; i++){
        turnaround[i]=completion[i]-arrival[i-1];
    }
    
    ll waitingtime[n+1];
    // calculating waiting time
    for(ll i=1; i<=n; i++){
        waitingtime[i]=turnaround[i]-copyofburst[i-1];
    }
    // calculating average waiting time
    double avgwait=0.0;
    ll sumwaiting=0;
    for(ll i=1; i<=n; i++){
        sumwaiting+=waitingtime[i];
    }
    avgwait=(double)sumwaiting/n;

    printf("%0.2f",avgwait);



}
