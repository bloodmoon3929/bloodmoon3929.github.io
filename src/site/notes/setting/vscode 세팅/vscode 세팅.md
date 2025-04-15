---
{"dg-publish":true,"permalink":"/setting/vscode 세팅/vscode 세팅/"}
---

https://blog.amylo.diskstation.me/algorithm/Starting_Algorithm_with_VSCode_C++/


# C++ 개발 환경 구축(window)

순서
1. MinGW 설치
2. MinGW 수동 설치 (필요시)
3. MinGW Path 설정
4. VSCode 설치
5. VSCode Extension 설치
6. VSCode C++ 빌드 및 디버깅 환경 설정
7. 이외 알고리즘 연습에 도움되는 vscode extension 설치

## MinGW 설치
### PC의 운영체제 확인
![assets/Gseed-image01.png](/img/user/assets/Gseed-image01.png)
윈도우 검색에 설정을 검색하면, 다음과 같은 화면이 나온다.
홈 아래의 시스템 항목을 누른다.

![assets/setting-vsc-image02.png](/img/user/assets/setting-vsc-image02.png)
그 후 화면을 가장 아래까지 내려 정보를 누른다.

![assets/setting-vsc-image03.png](/img/user/assets/setting-vsc-image03.png)
시스템 종류를 보면, 본인의 컴퓨터가 몇 bit 컴퓨터인지 알 수 있다.

#### MinGW 다운 방법
##### 1. 정식 다운로드
아래의 링크는 MinGW의 정식 다운로드 링크이다.
https://www.mingw-w64.org/ 

정식 사이트로 진행 하는 방법은 다음과 같다.

![assets/setting-vsc-image04.png](/img/user/assets/setting-vsc-image04.png)
링크를 통해 들어간 홈페이지에서 download 항목 접속

![assets/setting-vsc-image05.png](/img/user/assets/setting-vsc-image05.png)
스크롤을 내린후 source forge 항목에 접속

![assets/setting-vsc-image06.png](/img/user/assets/setting-vsc-image06.png)
원하는 버전 다운로드 (안 될 가능성 높음)

##### 2. 개발자 Github를 통한 다운로드
다음은 개발자의 github를 통하여 다운로드 받는 법이다.
![assets/setting-vsc-image07.png](/img/user/assets/setting-vsc-image07.png)
https://github.com/niXman/mingw-builds-binaries/releases

##### 3. 기타
위의 두 가지 방법은 점점 상태가 이상해지고 있다. 그렇기에 구할수만 있다면, 정상적으로 동작하는 기존의 코드를 사용하는 것이 좋다.

아래의 링크를 통하여 다운받아도 된다. (내가 사용하는 구버젼)
[https://drive.google.com/file/d/1YfZ_HOrSoDwHT4U1aDdRwI-3nf9cmM89/view?usp=sharing](https://drive.google.com/file/d/1YfZ_HOrSoDwHT4U1aDdRwI-3nf9cmM89/view?usp=sharing)

## MinGW Path 설정
![assets/setting-vsc-image08.png](/img/user/assets/setting-vsc-image08.png)
![assets/setting-vsc-image09.png](/img/user/assets/setting-vsc-image09.png)
위치에 파일을 옮기면 된다.

다음은 환경변수를 설정해야 한다.
![assets/setting-vsc-image10.png](/img/user/assets/setting-vsc-image10.png)
win+R을 누르고 sysdm.cpl을 친다.

![assets/setting-vsc-image11.png](/img/user/assets/setting-vsc-image11.png)
해당 항목이 뜨면, 고급 항목을 누른다.

![assets/setting-vsc-image12.png](/img/user/assets/setting-vsc-image12.png)
환경 변수를 누른다.

![assets/setting-vsc-image13.png](/img/user/assets/setting-vsc-image13.png)
시스템 변수에서 변수명이 Path인 항목을 찾아 누른다.

![assets/setting-vsc-image14.png](/img/user/assets/setting-vsc-image14.png)
새로 만들기를 누른 후 C:\mingw64\bin 을 추가한다.

위의 설정이 모두 끝난 후 깔렸는지 확인하는 방법은
cmd(명령 프롬포트)에 g++ --version을 입력한다.
![assets/setting-vsc-image15.png](/img/user/assets/setting-vsc-image15.png)
다음과 같은 화면이 나온다면, MinGW는 깔린 것이다.

## VSCode 설치
https://code.visualstudio.com/docs/?dv=win64user
위의 링크를 통해 vscode를 설치하자




## VSCode Extension 설치
설치가 끝나면 다음과 같은 화면을 볼 수 있을 것이다.
![assets/setting-vsc-image16.png](/img/user/assets/setting-vsc-image16.png)

### 1. C/C++
![assets/setting-vsc-image17.png](/img/user/assets/setting-vsc-image17.png)
C++로 진행할 것이므로 C/C++, C/C++ Extension Pack을 설치한다.

### 2. Korean Language Pack for Visual Studio Code
![assets/setting-vsc-image18.png](/img/user/assets/setting-vsc-image18.png)
Korean Language Pack for Visual Studio Code는 한국어로 바꿔주는 확장인데, 설치하고 싶다면 설치하면 된다.

## VSCode C++ 빌드 및 디버깅 환경 설정

![assets/setting-vsc-image19.png](/img/user/assets/setting-vsc-image19.png)
좌측 첫 아이콘을 눌려 폴더를 만들거나 연다.

![assets/setting-vsc-image20.png](/img/user/assets/setting-vsc-image20.png)
1이 가르키는 아이콘을 눌려 파일을 생성하고 적당한 이름.cpp 파일을 생성한다.

![assets/setting-vsc-image21.png](/img/user/assets/setting-vsc-image21.png)
f1을 누르면 위의 검색창이 열리는데, C/C++:Edit Configurations (UI)를 누른다.

![assets/setting-vsc-image22.png](/img/user/assets/setting-vsc-image22.png)
다음의 화면이 뜰 텐데 딱 두 개만 변경한다.

컴파일 경로를 C드라이브에 넣은
C:/mingw64/bin/g++.exe로 수정한다.

InteliSense 모드도
windows-gcc-x64로 수정한다.

다시 처음으로 돌아와
![assets/setting-vsc-image23.png](/img/user/assets/setting-vsc-image23.png)
오른쪽 위의 톱니바퀴를 누른뒤 C/C++: g++.exe 활성 파일 빌드 및 디버그을 누른다.

그 다음 task.json의 program과 args의 인자를 다음과 같이 바꾼다.

| ![assets/setting-vsc-image24.png](/img/user/assets/setting-vsc-image24.png) | ![assets/setting-vsc-image25.png](/img/user/assets/setting-vsc-image25.png) |
| ---------------- | ---------------- |
| ![assets/setting-vsc-image26.png](/img/user/assets/setting-vsc-image26.png) | ![assets/setting-vsc-image27.png](/img/user/assets/setting-vsc-image27.png) |
설정이 완료되었다면, F5를 누를시 컴파일이 진행된다.

만일 오류 발생시 다음의 설명을 참고하자.

호환성 항목을 들어가고,
![assets/setting-vsc-image28.png](/img/user/assets/setting-vsc-image28.png)

모든 사용자에 대한 설정 변경 항목을 누르고
![assets/setting-vsc-image29.png](/img/user/assets/setting-vsc-image29.png)

호환모드가 본인의 OS와 같은지 확인하라
![assets/setting-vsc-image30.png](/img/user/assets/setting-vsc-image30.png)
만일 되지 않는다면, MinGW를 다시 깔아야 한다.

## 이외 알고리즘 연습에 도움되는 vscode extension 설치

Competitive Programming Helper (cph)
boj