#include <bits/stdc++.h> 

using namespace std;

int n,m; //n: 현재 처리중인 문장의 단어 수, m: 사전의 전체 단어 수
int R[100]; //입력된 문장의 각 단어들의 인덱스를 저장하는 배열

double T[501][501]; //전이 확률 행렬 (i번 단어 다음에 j번 단어가 올 확률)
double M[501][501]; //혼동 행렬 (실제 i번 단어가 j번 단어로 인식될 확률)

int choice[102][502]; //동적 프로그래밍에서 최적의 선택을 저장하는 배열
double cache[102][502]; //메모이제이션을 위한 캐시 배열

string corpus[501]; //원문에 출현할 수 있는 단어들을 저장하는 배열

//segment번째 위치에서 이전 단어가 previousMatch일 때의 최적 확률을 계산하는 함수
double recognize(int segment, int previousMatch)
{
    //문장의 끝에 도달하면 종료
    if(segment==n) 
        return 0;

    double& ret = cache[segment][previousMatch];
    //이미 계산된 값이 있으면 재사용
    if(ret!=1.0)
        return ret;
    //log(0)값으로 초기화
    ret = -1e200;

    int& choose = choice[segment][previousMatch];
    //현재 위치에서 가능한 모든 단어를 시도
    for(int thismatch = 0; thismatch < m; ++thismatch)
    {
        //현재 위치의 확률 계산: 전이확률 + 혼동확률 + 다음 위치의 최적확률
        double cand = T[previousMatch][thismatch] + M[thismatch][R[segment]] + recognize(segment+1, thismatch);

        //더 높은 확률을 찾으면 업데이트
        if(ret < cand)
        {
            ret = cand;
            choose = thismatch;
        }
    }
    return ret;
}

//최적의 경로를 재구성하는 함수
string reconstruct(int segment, int previousMatch)
{
    int choose = choice[segment][previousMatch];
    string ret = corpus[choose];
    //마지막 단어가 아니면 다음 단어를 재귀적으로 구성
    if(segment < n-1)
        ret = ret + " " + reconstruct(segment+1, choose);
    return ret;
}

int main()
{
    //fastio
    ios_base::sync_with_stdio(0); // 원래 cin과 scanf는 서로 연동 가능하기에 느리다. 이 연결을 끊어 빠른 입출력을 제공함
    cin.tie(0); // cin의 연동을 끊음
    
    int q;
    cin >> m >> q; //m은 단어의 수, q는 문장의 수
    
    for(int i = 0; i < m; ++i)
        cin >> corpus[i]; // 원문에 출현할 수 있는 m개의 단어 입력
    
    vector<double> B(m); // 문장의 첫 단어가될 확률 기록
    for(int i = 0; i < m; ++i)
        cin >> B[i];
    
    // 전이 확률 행렬 입력
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            cin >> T[i][j]; //i번 단어 다음이 j번일 확률 기록
    
    // 혼동 행렬 입력
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            cin >> M[i][j]; //i가 j로 잘못 기록될 확률 기록
    
    while(q--) //문장 횟수 만큼 반복
    {
        cin >> n; //변형된 문장의 단어의 갯수 입력

        //입력된 문장의 각 단어를 인덱스로 변환
        for(int i = 0; i < n; ++i)
        {
            string word;
            cin >> word;
            for(int j = 0; j < m; ++j)
                if(corpus[j] == word)
                    R[i] = j;
        }

        // 캐시 초기화
        for(int i = 0; i < 102; ++i)
            for(int j = 0; j < 502; ++j)
                cache[i][j] = 1.0;
        
        //가장 높은 확률을 가진 시작 단어 찾기
        double best = -1e200;
        int bestStart = 0;
        
        for(int i = 0; i < m; ++i) 
        {
            //시작 확률 + 혼동 확률 + 나머지 문장의 최적 확률
            double cand = log(B[i]) + log(M[i][R[0]]) + recognize(1, i);
            if(best < cand) 
            {
                best = cand;
                bestStart = i;
            }
        }

        //최적의 문장 출력
        cout << corpus[bestStart] << " " << reconstruct(1, bestStart) << "\n";
    }
    
    return 0;
}