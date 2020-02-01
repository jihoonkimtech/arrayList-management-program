/*
	리스트(list), 선형리스트(linear list)
		순서를 가진 항목들의 모임

	집합
		항목간의 순서의 개념이 없음

	리스트는 집합과는 다르다.


    리스트의 연산
		새로운 항목을 리스트의 끝, 처음, 중간에 추가한다.
		기존의 항목을 리스트의 임의의 위치에서 삭제한다.
		모든 항목을 삭제한다.
		기존의 항목을 대치한다.
		리스트가 특정한 항목을 가지고 있는지를 살핀다.
		리스트의 특정위치 항목을 반환한다.
		리스트 안의 항목 개수를 센다.
		리스트가 비었는지, 꽉 찼는지를 체크한다.
		리스트 안의 모든 항목을 표시한다.

		객체: n개의 element형으로 구성된 순서있는 모임
		? add_last(list, item) ::= 맨끝에 요소를 추가한다.
		? add_first(list, item) ::= 맨끝에 요소를 추가한다.
		? add(list, pos, item) ::= pos 위치에 요소를 추가한다.
		? delete(list, pos) ::= pos 위치의 요소를 제거한다.
		? clear(list) ::= 리스트의 모든 요소를 제거한다.
		? replace(list, pos, item) ::= pos 위치의 요소를 item로 바꾼다.
		? is_in_list(list, item) ::= item이 리스트안에 있는지를 검사한다.
		? get_entry(list, pos) ::= pos 위치의 요소를 반환한다.
		? get_length(list) ::= 리스트의 길이를 구한다.
		? is_empty(list) ::= 리스트가 비었는지를 검사한다.
		? is_full(list) ::= 리스트가 꽉찼는지를 검사한다.
		? display(list) ::= 리스트의 모든 요소를 표시한다.


	리스트 ADT
		추상데이터(ADT) 단계로 리스트가 무엇이냐 하는 것에 집중하는 것이다.(What)
		실제로 자료구조는 추상데이타 타입을 특정한 프로그래밍 언어로 구현한 것을 의미한다.(how)


	리스트 구현 방법
		(1) 배열을 이용하는 방법
		  - 구현 간단하다.
		  - 삽입, 삭제 시 오버헤드
		  - 항목의 개수 제한

		(2) 연결리스트를 이용하는 방법
		  - 구현 복잡하다
		  - 삽입, 삭제가 효율적
		  - 크기가 제한되지 않음



	배열리스트 
	삽입
		리스트1->리스트3...	->		리스트1->NULL->리스트3... -> 리스트1->리스트2->리스트3...
			리스트2					 리스트2↗     ->
	삭제
		리스트1->리스트2->리스트3...	->		리스트1->NULL->리스트3... -> 리스트1->리스트3...
												 리스트2↙						       <-
*/
	



#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int element;

typedef struct {
	int list[MAXSIZE];
	int length;
}ArrayListType;

//오류 처리
void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1); //main 프로그램을 종료.
}

//리스트 초기화.
void init(ArrayListType* _list) {
	_list->length = 0;
}

//리스트가 비어있는지 확인.
int is_empty(ArrayListType* _list) {
	return _list->length == 0; //리스트의 길이가 == 0(비어있는 상태)이라면 true 반환.
}

//리스트가 가득 차있는지 확인.
int is_full(ArrayListType* _list) {
	return _list->length == MAXSIZE; //리스트의 길이가 == MAXSIZE(최대 사이즈와 같다면)이라면 true 반환.
}

//리스트 출력
void display(ArrayListType* _list) {
	int i;
	for (i = 0; i < _list->length; i++) {
		printf("%d, ", _list->list[i]);
	}
	printf("\n");
}

//리스트에 요소 추가. 추가할 위치와 요소 필요.
void add(ArrayListType* _list, int pos, element item) { //삽입.
	if ( (!is_full(_list)) && ( (pos >= 0) && (pos <= _list->length) ) ) { //꽉 차있는 상태도 아니도 입력한 값이 정상 범위 내라면.(최소-최대)
		int i;
		/*인덱스는 0부터 시작하므로 1을 제거	/	 0,1,2,3 이지만 크기는 4이다.*/
		for (i = (_list->length - 1); i >= pos; i--) {
			/* 
				맨 뒤의 요소부터 입력한 요소까지 한칸식 뒤로 옮긴다.
				
						↓(pos=2)				↓(pos=2)
				[0] [1] [3]		->		[0] [1] [3] [3] 
											    i->i+1
			*/
			_list->list[i+1] = _list->list[i];
		}
		/* 
						 ↓(pos=3)				    ↓(item=2)
			[0] [1] [3] [3] 		->		[0] [1] [2] [3] 
		 length = 3 ↑				         length = 4 ↑
		*/
		_list->list[pos] = item;
		_list->length++;
	}
}

//리스트에 요소 삭제. 삭제할 요소의 위치 필요.
element delete(ArrayListType* _list, int pos) {

	if ((!is_empty(_list)) && ((pos >= 0) && (pos <= _list->length))) { //다 비어있는 상태도 아니도 입력한 값이 정상 범위 내라면.(최소-최대)
		int i;
		element item = _list->list[pos];

		/*인덱스는 0부터 시작하므로 1을 제거	/	 0,1,2,3 이지만 크기는 4이다.*/
		for (i = pos; i <= (_list->length - 1); i++) {
			/*
				맨 뒤의 요소부터 입력한 요소까지 한칸식 앞으로 옮긴다.

							 ↓(pos=3)						↓(pos=3)
				[0] [1] [2] [2] [3]		->		[0] [1] [2] [3] [3]
															i <- i+
			*/
			_list->list[i] = _list->list[i + 1];
		}
		/*
					 ↓(pos=2)				        ↓(item=2)
			[0] [1] [3] [3] 		->		[0] [1] [2] [3]
		         length = 5 ↑				 length = 4 ↑
		*/
		_list->length--;
		return item;
	}
	else {
		error("잘못된 인덱스입니다.");
	}
}

int main() {
	ArrayListType list1;
	ArrayListType *dynamicList; //ArrayListType을 가르키는 포인터로 생성해 동적(배열처럼) 생성.

	//배열 리스트 정적 생성
	//생성한 구조체를 가르키는 포인터(주소(&))을 함수의 매개 변수로 전달한다.
	init(&list1); //주소 0으로 초기화
	add(&list1, 0, 10); //0번 위치에 10 삽입
	add(&list1, 0, 13); //자동으로 다음 위치에 13 삽입
	add(&list1, 0, 15); //자동으로 다음 위치에 15 삽입
	display(&list1);
	printf("%d 요소를 삭제했습니다.\n",delete(&list1, 1));
	display(&list1);

	//printf('\n');

	//배열 리스트 동적 생성
	//포인터 구조체에 404만큼의 메모리를 할당하여 구조체 타입에 맞게 캐스팅 후 주소를 부여한다.
	//동적 할당 룰, 구조체* 이름 = (구조체*)malloc(sizeof(구조체));
	dynamicList = (ArrayListType*)malloc(sizeof(ArrayListType)); //-> (int length)4 + (int list[MAXSIZE(100)] ) 400 -> 404 바이트
																//만큼의 메모리를 할당.
	//한번 malloc의 결과를 찍어볼 것.
	init(dynamicList);
	add(dynamicList, 0, 10); //0번 위치에 10 삽입
	add(dynamicList, 0, 13); //자동으로 다음 위치에 13 삽입
	add(dynamicList, 0, 15); //자동으로 다음 위치에 15 삽입
	display(dynamicList);
	free(dynamicList); //사용 후 메모리 해제
	//init(&list2); 
}
