#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Header.h"
/*int cmp(movie* film, int i, int j, int fs, int ss) {
	switch (fs) {
	case 1: {
		switch (ss) {
		case 2:return(film[i].name == film[j].name) ? (film[i].day > film[j].day) : (strcmp(film[i].name, film[j].name)>0);
			break;
		case 3:return(film[i].name == film[j].name) ? ((film[i].tm.hour == film[j].tm.hour) ? (film[i].tm.minutes > film[j].tm.minutes) : (film[i].tm.hour > film[j].tm.hour)) : (strcmp(film[i].name, film[j].name)>0);
			break;
		case 4:return(film[i].name == film[j].name) ? (film[i].rating > film[j].rating) : (strcmp(film[i].name, film[j].name)>0);
			break;
		case 5:return(film[i].name == film[j].name) ? (film[i].cost > film[j].cost) : (strcmp(film[i].name, film[j].name)>0);
			break;
		}
		break;
	}
	case 2: {
		switch (ss) {
		case 1:return(film[i].day == film[j].day) ? (strcmp(film[i].name, film[j].name)>0) : (film[i].day > film[j].day);
			break;
		case 3:return(film[i].day == film[j].day) ? ((film[i].tm.hour == film[j].tm.hour) ? (film[i].tm.minutes > film[j].tm.minutes) : (film[i].tm.hour > film[j].tm.hour)) : (film[i].day > film[j].day);
			break;
		case 4:return(film[i].day == film[j].day) ? (film[i].rating > film[j].rating) : (film[i].day > film[j].day);
			break;
		case 5:return(film[i].day == film[j].day) ? (film[i].cost > film[j].cost) : (film[i].day > film[j].day);
			break;
		}
		break;
	}
	case 3: {
		switch (ss) {
		case 1:return(film[i].tm.hour == film[j].tm.hour && film[i].tm.minutes == film[j].tm.minutes) ? (strcmp(film[i].name, film[j].name)>0) : ((film[i].tm.hour == film[j].tm.hour) ? (film[i].tm.minutes > film[j].tm.minutes) : (film[i].tm.hour > film[j].tm.hour));
		case 2:return(film[i].tm.hour == film[j].tm.hour && film[i].tm.minutes == film[j].tm.minutes) ? (film[i].day > film[j].day) : ((film[i].tm.hour == film[j].tm.hour) ? (film[i].tm.minutes > film[j].tm.minutes) : (film[i].tm.hour > film[j].tm.hour));
		case 4:return(film[i].tm.hour == film[j].tm.hour && film[i].tm.minutes == film[j].tm.minutes) ? (film[i].rating > film[j].rating) : ((film[i].tm.hour == film[j].tm.hour) ? (film[i].tm.minutes > film[j].tm.minutes) : (film[i].tm.hour > film[j].tm.hour));
		case 5:;return(film[i].tm.hour == film[j].tm.hour && film[i].tm.minutes == film[j].tm.minutes) ? (film[i].cost > film[j].cost) : ((film[i].tm.hour == film[j].tm.hour) ? (film[i].tm.minutes > film[j].tm.minutes) : (film[i].tm.hour > film[j].tm.hour));
		}
	}
		break;
	case 4: {
		switch (ss) {
		case 1:return(film[i].rating == film[j].rating) ? (strcmp(film[i].name, film[j].name)>0) : (film[i].rating > film[j].rating);
			break;
		case 2:return(film[i].rating == film[j].rating) ? (film[i].day > film[j].day) : (film[i].rating > film[j].rating);
			break;
		case 3:return(film[i].rating == film[j].rating) ? ((film[i].tm.hour == film[j].tm.hour) ? (film[i].tm.minutes > film[j].tm.minutes) : (film[i].tm.hour > film[j].tm.hour)) : (film[i].rating > film[j].rating);
			break;
		case 5:return(film[i].rating == film[j].rating) ? (film[i].cost > film[j].cost) : (film[i].rating > film[j].rating);
			break;
		}
		break;
	}
	case 5: {
		switch (ss) {
		case 1:return(film[i].cost == film[j].cost) ? (strcmp(film[i].name, film[j].name)>0) : (film[i].cost > film[j].cost);
			break;
		case 2:return(film[i].cost == film[j].cost) ? (film[i].day > film[j].day) : (film[i].cost > film[j].cost);
			break;
		case 3:return(film[i].cost == film[j].cost) ? ((film[i].tm.hour == film[j].tm.hour) ? (film[i].tm.minutes > film[j].tm.minutes) : (film[i].tm.hour > film[j].tm.hour)) : (film[i].cost > film[j].cost);
			break;
		case 4:return(film[i].cost == film[j].cost) ? (film[i].rating > film[j].rating) : (film[i].cost > film[j].cost);
			break;
		}
	}
	break;
	}
}*/

struct time {
	int hour;
	int minutes;
};
enum data {
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};
typedef struct movie {
	char name[100];
	enum data day;
	struct time tm;
	float rating;
	int cost;
}movie;


int main(void) {
	movie* film = NULL;
	int size = sizeOfStruct();
	film = (movie*)calloc(size ,sizeof(movie));
	
	filling(&film, size);
	

	int p, k;
	do {
		printf("What you wanna do?\n1-print struct\n2-delete some element\n3-sorting");
		while (scanf_s("%d", &p) != 1 || p < 1 || p>3 || getchar() != '\n') {
			printf("Input error.Try again.\n");
			rewind(stdin);
		}
		
		switch (p) {
		case 1:
			printStruct(&film, size);
			break;
		case 2:
			delet(&film, &size);
			break;
		case 3:sorting(&film, size);
		}

		printf("Do you want to stop?1-yes,2-no");
		while (scanf_s("%d", &k) != 1 || k < 1 || k>2 || getchar() != '\n') {
			printf("Input error.Try again.\n");
			rewind(stdin);
		}
	} while (k != 1);

	freeStruct(&film, size);
	return 0;
}

