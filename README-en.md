# algorithm study
- repository for studying algorithms

# algorithm Study Workflow
### 1, theory study
- 1, create a folder at the root directory with the algorithm name
- 2, moved to the created folder and create a `theory.md` and organize the theory there
### 2, solve problems
- 1, choose problems to practice certain algorithms
- 2, choose for one week study
- 3, solve a problem and save it as the following format inside the problem related algorithms folder `[question-provider][question-id].c`





# git message sementic
- theory : `[theory] [theory-name] desscription`
- solved problems: `[problem] [problem-provider] [problem-id] desscription`
- README update: `[README] description`
- tempalte related work: `[TEMPLATE] description`

> theory-name ex: `[greedy]`, `[dp]`, `[sort]`, `[dfs]`, `[bfs]`
>
> problem-provider ex: `[boj]`, `[codeup]`, `[leetcode]`
>
> git message ex: `[theory] [greedy] theory organize`, `[problem] [boj] [13305]`, `[problem] [boj] [13305] optimization`

<br>
<br>
<br>
<br>
<br>


#### etc
- If you are using a Cmake build system to build the cpp file for the algorithms change the [main-c-source-code-path] to the path to your cpp file (the code you want to run must be inside the repositories root directory or inside any of the folders inside the root directory)
```cmake
cmake_minimum_required(VERSION 3.24)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithms [main-c-source-code-path])
```