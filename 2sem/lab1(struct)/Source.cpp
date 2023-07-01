#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
struct movie {
	char* name;
	enum data day;
	struct time tm;
	float rating;
	int cost;
};
int sizeOfStruct() {
	unsigned size;
	printf("Enter size. \n");
	while (scanf_s("%d", &size) != 1 || getchar() != '\n') {
		printf("Input error.Try again.\n");
		rewind(stdin);
	}
	return size;
}
void printStruct(struct movie** film, int size) {
	/*for (int i = 0;i < size;i++) {
		printf("Name: %s \t Day:%d  \t Time: %d : %d \t Rating: %.1f \t Cost: %d\n",  (*film)[i].name, (*film)[i].day, (*film)[i].tm.hour, (*film)[i].tm.minutes, (*film)[i].rating, (*film)[i].cost);
	}*/
	for (int i = 0;i < size;i++) {
		printf("Name: %s \t", (*film)[i].name);
		switch ((*film)[i].day) {
		case 1: printf("Monday   \t");
			break;
		case 2: printf("Tuesday  \t");
			break;
		case 3:  printf("Wednesday\t");
			break;
		case 4:  printf("Thursday \t");
			break;
		case 5:  printf("Friday   \t");
			break;
		case 6: printf("Saturday \t");
			break;
		case 7:  printf("Sunday   \t");
			break;
		}
		printf("Time: %d : %d \t Rating: %.1f \t Cost: %d\n", (*film)[i].tm.hour, (*film)[i].tm.minutes, (*film)[i].rating, (*film)[i].cost);

	}
}
void freeStruct(struct movie** film, int size) {
	for (int i = 0;i < size;i++)
		free((*film)[i].name);
	free((*film));
}
void delet(struct movie** film, int* size) {
	int n;
	printf("Which element do you want to delete?");
	while (scanf_s("%d", &n) != 1 || n < 0 || n>*size || getchar() != '\n') {
		printf("Input error.Try again.\n");
		rewind(stdin);
	}

	for (int i = n - 1;i < *size-1;i++) {
		strcpy((*film)[i].name, (*film)[i + 1].name);
		(*film)[i].day = (*film)[i + 1].day;
		(*film)[i].tm.hour = (*film)[i + 1].tm.hour;
		(*film)[i].tm.minutes = (*film)[i + 1].tm.minutes;
		(*film)[i].rating = (*film)[i + 1].rating;
		(*film)[i].cost = (*film)[i + 1].cost;
	};
	(*film) = (struct movie*)realloc((*film), (*size - 1) * sizeof(struct movie));
	*size = *size - 1;
}
void filling(struct movie** film, int size) {
	int k = 0, j = 0;
	for (int i = 0;i < size;i++) {

		//printf("Enter the name of the movie.\n");
		//fflush(stdin);
		//gets((*film)[i].name);
		int n = 32;
	   (*film)[i].name = (char*)calloc(n, sizeof(char));
		char ch;
		int pos = 0, a = 0;
		printf("Enter the name of the movie.\n");
		while (a != 1) {
			ch = getchar();
			if (ch == '\n') {
				(*film)[i].name[pos] = '\0';
				(*film)[i].name = (char*)realloc((*film)[i].name, (pos+1) * sizeof(char));
				a = 1;
			}
			else {
				(*film)[i].name[pos] = ch;
				pos++;
				if (pos >= n) {
					n *= 2;
					(*film)[i].name = (char*)realloc((*film)[i].name, n * sizeof(char));
				}
			}
		}
		//printf("\n%s\n", (*film)[i].name);
		
		printf("Enter day of the film. \n");
		while (scanf_s("%d", &(*film)[i].day) != 1 || (*film)[i].day < 0 || (*film)[i].day>7 || getchar() != '\n') {
			printf("Input error.Try again.\n");
			rewind(stdin);
		}


		printf("Enter start time of the movie. \n");
		scanf_s("%d %d", &(*film)[i].tm.hour, &(*film)[i].tm.minutes);
		while ((*film)[i].tm.hour < 0 || (*film)[i].tm.hour >= 24 || (*film)[i].tm.minutes < 0 || (*film)[i].tm.minutes >= 60 || getchar() != '\n') {
			printf("Input error.Try again.\n");
			rewind(stdin);
			scanf_s("%d %d", &(*film)[i].tm.hour, &(*film)[i].tm.minutes);
		}

		printf("Enter rating of the film. \n");
		while (scanf_s("%f", &(*film)[i].rating) != 1 || (*film)[i].rating < 0 || (*film)[i].rating > 5 || getchar() != '\n') {
			printf("Input error.Try again.\n");
			rewind(stdin);
		}

		printf("Enter the ticket price. \n");
		while (scanf_s("%d", &(*film)[i].cost) != 1 || (*film)[i].cost < 0 || getchar() != '\n') {
			printf("Input error.Try again.\n");
			rewind(stdin);
		}
		printf("\n");
	}
}
int c(struct movie** film, int i, int j, int fs) {
	switch (fs) {
	case 1: return (strcmp((*film)[i].name, (*film)[j].name) > 0);
		break;
	case 2:return ((*film)[i].day > (*film)[j].day);
		break;
	case 3: return(((*film)[i].tm.hour == (*film)[j].tm.hour) ? ((*film)[i].tm.minutes > (*film)[j].tm.minutes) : ((*film)[i].tm.hour > (*film)[j].tm.hour));
		break;
	case 4:return ((*film)[i].rating > (*film)[j].rating);
		break;
	case 5:return  ((*film)[i].cost > (*film)[j].cost);
		break;
	}
}
int c2(struct movie** film, int i,int j, int fs) {
	switch (fs) {
	case 1: return (strcmp((*film)[i].name, (*film)[j].name) == 0);
		break;
	case 2: return((*film)[i].day == (*film)[j].day);
		break;
	case 3: return((*film)[i].tm.hour == (*film)[j].tm.hour && (*film)[i].tm.minutes == (*film)[j].tm.minutes);
		break;
	case 4: return((*film)[i].rating == (*film)[j].rating);
		break;
	case 5: return((*film)[i].cost == (*film)[j].cost);
		break;
	}
}
void sorting(struct movie** film, int size) {
	int fs, ss;
	printf("By which parameter do you want to sort first?\n1-name\n2-day\n3-time\n4-rating\n5-cost");
	while (scanf_s("%d", &fs) != 1 || fs < 1 || fs>5 || getchar() != '\n') {
		printf("Input error.Try again.\n");
		rewind(stdin);
	}
	printf("By which parameter do you want to sort then?\n1-name\n2-day\n3-time\n4-rating\n5-cost");
	while (scanf_s("%d", &ss) != 1 || ss < 1 || ss>5 || ss == fs || getchar() != '\n') {
		printf("Input error.Try again.\n");
		rewind(stdin);
	}
	struct movie m;
	int min;
	for (int i = 0;i < size - 1; i++) {
		min = i;
		for (int j = i + 1;j < size;j++) {
			if (c(film, min, j, fs))
				min = j;
		}
		m = (*film)[min];
		(*film)[min] = (*film)[i];
		(*film)[i] = m;
	}

	/*for (int i = 0;i < size - 1; i++) {
		min = i;
		for (int j = i + 1;j < size;j++){
			if (c2(film, min,j, fs) && c(film, min, j, ss)) {
				min = j;
			}
			m = (*film)[min];
			(*film)[min] = (*film)[i];
			(*film)[i] = m;
		}
	}*/

	for (int i = 0;i < size - 1;i++) {
		if (c2(film, i, i + 1, fs) && c(film, i, i + 1, ss)) {
			m = (*film)[i+1];
			(*film)[i+1] = (*film)[i];
			(*film)[i] = m;
		}
	}

}