/*
	* Program Name : Array Linked-List Management List

	* Author : jihoonkimtech (github)
	* Version : 0.0.1
	* Release Date : 2020.02.02
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int element;

typedef struct {
	int list[MAXSIZE];
	int length;
}ArrayListType;


void error(char* msg) {
	fprintf(stderr, "ERROR : %s\n", msg);
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
	if(pos > 100 || pos < 0)
		error("Out of Array size!");

	if ( (!is_full(_list)) && ( (pos >= 0) && (pos <= _list->length) ) ) { 
		int i;
		for (i = (_list->length - 1); i >= pos; i--) {
			_list->list[i+1] = _list->list[i];
		}
		_list->list[pos] = item;
		_list->length++;
	}
}


element del(ArrayListType* _list, int pos) {

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
		error("No more elements to delete!");
	}
}

void menu(int* input){
	while(1){
		int _input;
		printf("MENU LIST\n");
		printf("1. ADD ELEMENT\n");
		printf("2. DELETE ELEMENT\n");
		printf("3. PRINT ELEMENT\n");
		printf("4. EXIT\n\n");
		printf("COMMAND : ");
		scanf("%d", _input);
		
		if(_input < 0 || _input > 3){
			error("Invalid command entered\n\n");
		} else{
			*input = _input;
			printf("\n\n");
			break;
		}
		
	}
	
}

int main() {
	int useCmd, pos;
	element elem;
	ArrayListType list;
	init(&list); 
	
	while(1){
		menu(&useCmd);
		
		if(useCmd == 1){
			printf("POSITION : ");
			scanf("%d", pos);
			printf("\n");
			printf("ELEMENT : ");
			scanf("%d", elem);
			printf("\n");
			add(&list, pos, elem);
		} else if(useCmd == 2) {
			printf("POSITION : ");
				scanf("%d", pos);
				printf("\n");
				del(&list, pos);
		} else if(useCmd == 3) {
			display(&list);
		} else if(useCmd == 4) {
			exit(1);
		}
	}
	

}


