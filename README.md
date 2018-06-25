# 객체지향주소록 과제

양호진 2016940247

제출일자 2018/06/25

## 디렉토리 구조

- `/` 는 프로젝트의 루트 디렉토리입니다.
- `/include` 는 header 파일(*.h)이 모여있습니다.
- `/src` 는 소스 파일(*.cc)이 모여있습니다.
- `/build` 는 오브젝트 파일(*.o)이 모여있습니다.
- `/bin` 은 실행 가능 파일이 모여있습니다.

## 빌드하는 방법

셸(bash, cmd 등)을 열고 프로젝트 루트 디렉토리로 이동한 후 `make`를 실행합니다.

```
$ make
```

위 명령은 `/build` 에 오브젝트 파일과 `bin/AddressBook`(Windows의 경우 `bin\AddressBook.exe`)을 만들 것입니다.

Note: 빌드 파일들 지우기 위해선 매개변수로 `clean`을 넘겨줍니다.

```
$ make clean
```

## 대략적인 설계

구현이 귀찮은 부분은 STL를 활용했습니다.

활용한 STL는 다음과 같습니다.

- std::string
- std::vector

### class AddressBook

- header: `include/AddressBook.h`
- source: `src/AddressBook.cc`

`class AddressBook`은 프로그램의 UI를 담당합니다. 

내부적으로 `std::vector<User*> users`를 가지고 있으며, 이로 유저 목록을 관리합니다.

#### 상태

AddressBook은 `a`, `s`, `d`, `r`, `q`와 `i` 이렇게 6개의 상태를 가지고 있습니다.

각 상태는 사용자의 입력에 따라 변하며, 처음 5개를 제외한 모든 입력은 `i`로 간주합니다.

각 상태에 대응하는 이름은 다음과 같습니다.

- `a`: Add    새로운 `User`를 추가합니다.
- `s`: Search `User`를 검색합니다.
- `d`: Print  모든 `User`를 출력합니다.
- `r`: Remove `User`를 제거합니다.
- `q`: Quit   장비를 정지합니다.
- `i`: Idle   사용자 입력을 기다리는 상태입니다.

### class User

- header: `include/User.h`
- source: `src/User.cc`

`class User`은 유저 정보를 담고 있습니다.

이름과 전화번호를 가지고 있습니다.

## 설계 상세

코드의 주석을 참고해주세요.

## 예외처리

처리한 예외는 다음과 같습니다.

- 중복된 이름의 유저를 추가 할 경우
- 유저 검색시 일치하는 이름의 유저가 없을 경우
