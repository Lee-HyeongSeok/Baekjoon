## ​ 메모장

***

<br> 

### :pushpin: 함수(Function) & 메소드(Method) 차이점

- **[함수]** : 특정 작업을 수행하는 코드 조각, 독립된 기능을 수행하는 단위

- **[메소드 = 클래스 함수]** : 클래스, 구조체, 열거형에 포함된 함수

  > **클래스 외부, 내부에 위치하는 차이**

<br> 

### :pushpin: 오버로딩(Overloading) & 오버라이딩(Overriding) 차이

- **오버로딩** : 메서드의 이름은 같지만, 매개변수의 데이터 타입과 개수가 다른 것
- **오버라이딩** : 상위 클래스가 가진 메서드를 하위 클래스가 재정의해서 사용

- **오버로딩 예시**

  ```c++
  class OverloadingClass{
      public : 
      void push(int x, int y){ }
      void push(string x, string y){ }
      void push(int x, int y, int z){ }
  }
  ```

- **오버라이딩 예시**

  ```c++
  class SuperClass{
      public :
      void push(int x, int y){ }
  }
  // 다형성 : 서로 다른 객체들 사이에서 같은 함수를 사용했을 때 다르게 동작하는 것
  class SubClass : SuperClass{
      public : 
      void push(int x, int y){ cout<<"SuperClass의 push() 메서드를 오버라이딩"; }
  }
  ```

<br> 

### :pushpin: 추상 클래스(Abstract Class) & 인터페이스(Interface) 

- **공통점**
  - 자신을 new를 통해 생성할 수 없으며, 상속받은 자식 클래스만이 객체를 생성 가능하다.
  - 하나의 클래스이며 자식 클래스에서 모든 메서드를 구현해야 한다.
  - 인스턴스화가 불가능하다.
- **차이점**
  - **추상 클래스(확장 관계)**
    - 부모 클래스가 가진 공통적인 기능들을 여러 클래스에서 사용할 경우에 사용
    - 다중 상속 불가, 하나의 클래스에 하나의 부모만 상속 가능(extends)
  - **인터페이스(포함 관계)**
    - 클래스와 별도로 구현 객체가 같은 동작을 한다는 것을 보장하기 위해 사용
    - 각 클래스가 서로 다른 부모 클래스를 상속하지만, 같은 기능이 필요한 경우에 사용
    - 다중 상속 가능, 하나의 클래스에 여러 인터페이스 상속 가능(implements)
    - 필요에 따라 결합