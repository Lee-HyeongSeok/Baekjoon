## DFS(Depth First Search)

***

<br>

### :pushpin: 그래프란?

- 노드(N, Node)와 노드를 연결하는 간선(E, Edge)을 하나로 모아놓은 **비선형 자료구조**

- 연결되어 있는 객체 간의 관계를 표현할 수 있는 자료 구조

- **종류**

  - **무방향 그래프**
    - 간선을 통해 양방향으로 갈 수 있다.
    - 정점 A, B를 연결하는 간선은 (A, B) 로 표현
    - (A, B)와 (B, A)는 동일하다.
  - **방향 그래프**
    - 간선에 방향성이 존재하는 그래프
    - 정점 A에서 B로만 갈 수 있는 간선은 <A, B>로 표현
    - <A, B>는 <B, A>와 다름
  - **가중치 그래프**
    - 두 정점을 이동할 때 발생하는 비용을 표시한 그래프
  - **완전 그래프**
    - 모든 정점이 간선으로 연결되어 있는 그래프

  ![Untitled Diagram drawio](https://user-images.githubusercontent.com/55940552/148229610-1de3f57f-5e8b-46f1-9f30-6bcff27d67f3.png) 

- **구현 방법**

  - **인접 행렬(Adjacency Materix)**

  ![1](https://user-images.githubusercontent.com/55940552/148229813-dd98cea3-ff90-40ef-900c-0f49fcc57144.PNG) 

  - 그래프의 노드를 **2차원 배열로** 생성한 형태

  - 자신과 인접한 노드에 1을 부여, 그렇지 않은 경우 0을 부여

    > **ex) materix\[1][2] = 1;**

  - 두 정점에 대한 연결된 정보를 확인할 때 O(1)의 시간 복잡도 발생

  - 모든 정점에 대해 간선의 정보를 부여할 때 O(n^2)의 시간 복잡도 발생(2차원 배열이므로)

  - 2차원 배열의 특성상 필요 이상의 공간이 낭비

  <br>

  - **인접 리스트(Adjacency List)**

  ![2](https://user-images.githubusercontent.com/55940552/148229816-75056d6f-0392-4831-b5e2-f9c75c454486.PNG) 

  - 그래프의 노드를 **리스트로** 표현한 것
  - 하나의 정점에 대한 리스트 배열을 만들어 관계를 설정
  - 두 정점에 대한 연결된 정보를 확인할 때 O(n)의 시간 복잡도 발생(하나의 정점에 리스트 배열을 순회하기 때문)
  - 필요한 만큼의 공간만 사용하기 때문에 메모리 낭비가 최소화된다.



<br>

### :pushpin: DFS란?

- 그래프를 순회하는 알고리즘
- 특정 노드에서 시작해 다음 분기로 넘어가기 전 해당 분기를 완벽하게 탐색하는 방법

![Untitled Diagram drawio (1)](https://user-images.githubusercontent.com/55940552/148235708-ecebfef7-7284-4ba3-b26e-d5aa5a5539a6.png) 



***

### :pushpin: 자료 출처

[1] [그래프 출처](https://coding-factory.tistory.com/610)

