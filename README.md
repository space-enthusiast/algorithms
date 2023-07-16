# 알고리즘 정리
- 알고리즘 공부한 것을 정리하는 저장소

# 알고리즘 Study Workflow
### 1, 알고리즘 이론공부
- 1, root 폴더에서 해당 알고리즘 이름으로 폴더생성
- 2, 해당 알고리즘 폴더로 이동 `theory.md` 파일에 알고리즘 이론 정리
### 2, 문제 풀어보기
- 1, 해당 알고리즘 관련 문제 선정
- 2, 일주일 분량으로 계획
- 3, 문제풀어서 해당 알고리즘 폴더에 `[question-provider][question-id].c`





# git 메세지 전략
- 이론 : `[theory] [theory-name] desscription`
- 문제푼것 표시: `[problem] [problem-provider] [problem-id] desscription`
- README 업데이트: `[README] description`

> theory-name ex: `[greedy]`, `[dp]`, `[sort]`, `[dfs]`, `[bfs]`
>
> problem-provider ex: `[boj]`, `[codeup]`, `[leetcode]`
>
> git message ex: `[theory] [greedy] 이론정리`, `[problem] [boj] [13305]`, `[problem] [boj] [13305] 알고리즘 보완`

<br>
<br>
<br>
<br>
<br>


#### 기타
- Clion 에디터를 쓰는 경우 CmakeLists.txt 파일수정 해야지 실행가능하다.
```cmake
cmake_minimum_required(VERSION 3.24)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithms [main-c-source-code-path])
```