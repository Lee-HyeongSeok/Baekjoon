## 정규표현식(c++)

***

<br>

### :pushpin: 정규표현식(Regular Expression)

- 문자열을 처리하는 방법 중의 하나

- 특정한 조건의 문자를 검색, 치환하는 과정을 간편하게 처리할 수 있도록 하는 방법

  > **010-1234-1234 또는 010-123-1234를 처리할 수 있는 정규표현식 예시**
  >
  > **ex) ([01]{3})-([0-9]{3,4})-([0-9]{4})**

<br>

### :pushpin: 정규표현식의 표현식

![1](https://user-images.githubusercontent.com/55940552/145717579-3b571608-39a5-46bd-b84c-4ed166716e16.PNG) 

<br>

![2](https://user-images.githubusercontent.com/55940552/145717580-08052086-fa5f-4133-8c17-d676207bb80d.PNG)

<br>

![3](https://user-images.githubusercontent.com/55940552/145717581-79900cc2-0c5a-4aa2-b786-d2445690a2c9.PNG) 

> 사진 출처 : [hamait 블로그 <- 링크](https://hamait.tistory.com/342)



<br> 

### :pushpin: 정규표현식의 syntax_option-type

> **c++ 11부터 std::regex 추가, 이전에는 boost::regex 또는 tr1::regex를 사용했음**
>
> 출처 : [torbjorn 블로그 <- 링크](https://torbjorn.tistory.com/273)

- regex 객체를 생성하면서 syntax option을 부여하는 것을 말함
- 정규식 문법 규칙 또는 검색 옵션을 선택하는 Flag
- **정규식 문법 규칙 종류**
  - ECMAScript : flag를 설정하지 않고 regex("\d") 식으로 사용했을 때 기본값으로 사용됨
  - basic : POSIX 기본 BRE로 컴파일 됨
  - extended : POSIX 확장 ERE로 컴파일 됨
  - awk : 패턴 탐색, 처리를 위한 명령어(유틸리티)
  - grep(GNU 기본 BRE)
  - egrep(GNU 확장 ERE)
  - _Gmask
- **정규식 검색 옵션**
  - icase : 알파벳 대소문자를 구분하지 않음
  - nosubs : 캡처 그룹을 사용하지 않음
  - optimize : 문자열 매칭 시간이 빨라질 수 있도록 최적화(ex. NFA를 DFA로 전환)
  - collate : [a-b] 처럼 문자열 범위를 사용할 때 로케일을 고려

<br>

### :pushpin: 주의점

- {3,4} : 최소 3회 이상 4회 이하로 반복됨을 알리는 표현식은 {3, 4}와 같이 띄어쓰면 오류
  - **표현식 그대로 사용할 것**