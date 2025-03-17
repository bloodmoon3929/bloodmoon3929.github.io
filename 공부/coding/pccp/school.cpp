#include <bits/stdc++.h>

using namespace std;

vector<int> choose;
vector<int> used;
int sport;
int student;
int total=-1;

void back(int cnt, vector<vector<int>> &ability)
{
    if(cnt==sport)
    {
        int sum=0;
        for(int i=0;i<cnt;i++)
            sum+=ability[choose[i]][i];
        
        total=max(total, sum);
        return;
    }
    
    for(int i=0;i<student;i++)
    {
        if(!used[i])
        {
            used[i]=true;
            choose[cnt]=i;
            back(cnt+1, ability);
            used[i]=false;
        }
    }
}

int solution(vector<vector<int>> ability) 
{
    sport=ability[0].size();
    student=ability.size();
    
    choose.assign(sport, 0);
    used.assign(student, 0);
    
    back(0, ability);
    
    return total;
}