#include <bits/stdc++.h>

using namespace std;

string solution(string input_string) 
{
    string answer = "";
    vector<int> first(26, -1);
    vector<bool> continuous(26, true);
    vector<int> count(26, 0);
    

    for(int i = 0; i < input_string.length(); i++) 
    {
        int idx = input_string[i] - 'a';
        count[idx]++;
        
        if(first[idx] == -1)
            first[idx] = i;
    }
    
    for(int i = 1; i < input_string.length(); i++) 
    {
        int curr_idx = input_string[i] - 'a';
        int prev_idx = input_string[i-1] - 'a';
        
        if(curr_idx != prev_idx) 
            if(first[curr_idx] != i && first[curr_idx] != -1) 
                continuous[curr_idx] = false;
    }
    
    set<char> lonely_chars;
    for(int i = 0; i < 26; i++) 
        if(count[i] >= 2 && !continuous[i]) 
            lonely_chars.insert('a' + i);

    for(char c : lonely_chars) 
        answer += c;
    
    return answer.empty() ? "N" : answer;
}