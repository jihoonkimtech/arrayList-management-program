#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int element;

typedef struct {
	int list[MAXSIZE];
	int length;
}ArrayListType;


void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1); 
}


void init(ArrayListType* _list) {
	_list->length = 0;
}


int is_empty(ArrayListType* _list) {
	return _list->length == 0; 
}


int is_full(ArrayListType* _list) {
	return _list->length == MAXSIZE; 
}


void display(ArrayListType* _list) {
	int i;
	for (i = 0; i < _list->length; i++) {
		printf("%d, ", _list->list[i]);
	}
	printf("\n");
}


void add(ArrayListType* _list, int pos, element item) { 
	if ( (!is_full(_list)) && ( (pos >= 0) && (pos <= _list->length) ) ) { 
		int i;
		for (i = (_list->length - 1); i >= pos; i--) {
			_list->list[i+1] = _list->list[i];
		}
		_list->list[pos] = item;
		_list->length++;
	}
}


element delete(ArrayListType* _list, int pos) {

	if ((!is_empty(_list)) && ((pos >= 0) && (pos <= _list->length))) {
		int i;
		element item = _list->list[pos];

		for (i = pos; i <= (_list->length - 1); i++) {
			_list->list[i] = _list->list[i + 1];
		}
		_list->length--;
		return item;
	}
	else {
		error("잘못된 인덱스입니다.");
	}
}

int main() {
	ArrayListType list1;
	init(&list1); 
	add(&list1, 0, 10);

	printf("ARRAY LINKED LIST\nMANAGEMENT PROGRAM");

	display(&list1);
	printf("%d 요소를 삭제했습니다.\n",delete(&list1, 1));
	display(&list1);

}
