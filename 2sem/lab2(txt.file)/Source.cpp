#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"


size_t sizeOfFile(FILE* fp ) {

	fseek(fp, 0L, SEEK_END);
	size_t file_size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	
	return file_size;
}

word** frequencyOfEachWord(word** w, int* size, char* fileName) {
	FILE* f;
	while ((f = fopen(fileName, "r+")) == NULL) {
		printf("The file can not be open. Try again.\n");
		exit(1);
	}
	char s[100];
	int g = 0;

	while (fscanf(f, "%s", s) == 1) {
		g = 0;
		for (int i = 0;i < *size;i++) {
			if (strcmp(s, (*w)[i].name) == 0) {
				(*w)[i].number++;
				g = 1;
				break;
			}
		}
		if (g == 0) {
			*size = *size + 1;
			(*w) = realloc((*w), (*size) * sizeof(word));
			strcpy((*w)[*size - 1].name, s);
			(*w)[*size - 1].number = 1;
			(*w)[*size - 1].size = strlen(s);
		}
	}

	for (int i = 0;i < *size;i++)
		printf("%s \t           %d \t         %d\t\n", (*w)[i].name, (*w)[i].number, (*w)[i].size);

	if (fclose(f) != 0)
		printf("Error! File cannot be close");
	return w;
}

void sort(word* w, int size) {
	struct word m;
	int max;
	for (int i = 0;i < size - 1; i++) {
		max = i;
		for (int j = i + 1;j < size;j++) {
			if (w[j].number > w[max].number)
				max = j;
			if (w[j].number == w[max].number && w[j].size > w[max].size)
				max = j;
		}
		m = w[max];
		w[max] = w[i];
		w[i] = m;
	}
}
/*
char* findLongestWord(word* w, int size) {
	int lengthWord = 0;
	int a = 0;
	char lw[20];
	for (int i = 0;i < size;i++) {
		if (strlen(w[i].name) > lengthWord && w[i].number >= a) {
			strcpy(lw, w[i].name);
			a = w[i].number;
			lengthWord = strlen(w[i].name);
		}
	}
	return lw;
}

char* findShortestWord(word* w, int size) {
	int shortWord = w[0].size;
	int a = w[0].number;
	char sw[20];
	for (int i = 0;i < size;i++) {
		if (strlen(w[i].name) < shortWord && w[i].number < a) {
			strcpy(sw, w[i].name);
			a = w[i].number;
		}
	}
	return sw;
}*/

char* findMostCommonLongWord(word* w, int size) {
	int lengthWord = 0;
	int a = 0;
	char lw[20];
	for (int i = 0;i < size;i++) {
		if (w[i].number>a) {
			strcpy(lw, w[i].name);
			a = w[i].number;
			//lengthWord = strlen(w[i].name);
		}
	}

	return lw;

}

char* findLessCommonShortWord(word* w, int size) {
	int shortWord = w[0].size;
	int a = w[0].number;
	char sw[20];
	for (int i = 0;i < size;i++) {
		if (w[i].number<a) {
			strcpy(sw, w[i].name);
			a = w[i].number;
		}
	}
	return sw;

}

void replace_word(char* source_str, char* old_word, char* new_word) {
	char* occurence = strstr(source_str, old_word);
	while (occurence != NULL) {
		strncpy(occurence, new_word, strlen(new_word));
		occurence += strlen(new_word);
		char* rest_str = occurence + strlen(old_word);
		memmove(occurence, rest_str, strlen(rest_str) + 1);
		occurence = strstr(source_str, old_word);
	}
}

void replace_words_in_file(FILE* file, char* word1, char* word2) {
	char buffer[1000];
	char* start;

	while (fgets(buffer, 1000, file) != NULL) {
		start = strstr(buffer, word1);
		while (start != NULL) {
			strncpy(start, word2, strlen(word2));
			start = strstr(start + strlen(word2), word1);
		}
		fputs(buffer, file);
	}
}


void findAndReplaceInFile(word* w, int size,char* filename)
{

	FILE* ifp, * ofp;

	char ch, read[100];

	while ((ifp = fopen(filename, "r")) == NULL || (ofp = fopen("compressFile.txt", "w")) == NULL) {
		printf("The file can not be open. Try again.\n");
		exit(1);
	}



	puts("THE CONTENTS OF THE FILE ARE SHOWN BELOW :\n");


	// displaying file contents

	while (1) {

		ch = fgetc(ifp);

		if (ch == EOF) {

			break;

		}

		printf("%c", ch);

	}

	
	//char* A = findMostCommonLongWord(w, size);
	//char* B = findLessCommonShortWord(w, size);


	char buffer[1000];
	size_t nread;

	while (nread = fread(buffer,sizeof(char),sizeof(buffer),ifp)) {
		fwrite(buffer,sizeof(char),nread, ofp);
	}
		

	printf("\n\n\n\n\n\n");
	while (1) {

		ch = fgetc(ofp);

		if (ch == EOF) {

			break;

		}

		printf("%c", ch);

	}
	/*char lw = w[0].name;
	char sw = w[size - 1].name;
	size_t s = sizeOfFile(ifp);
	size_t ns = s;
	for (int i = 0;i < size/2;i++) {
		for (int j = size - 1;j = size/2; j--) {
			if ((w[i].size * w[i].number + w[j].size * w[j].number) > (w[i].size * w[j].number + w[j].size * w[i].number)) {
				while (fscanf(ifp, "%s", read) != EOF) {
					if (strcmp(read, w[i].name) == 0)
						fprintf(ofp, "%s", w[j].name);

					if (strcmp(read, w[j].name) == 0)
						fprintf(ofp, "%s", w[i].name);

					else
						fprintf(ofp, "%s ", read);
				}
			}
		}
	}
	/*int changed = 1;
	while (changed) {
		changed = 0;
		for (int i = 0;i < size;i++)
		{
			for (int j = size - 1;j = size; j--)
			{
				if ((w[i].size * w[i].number + w[j].size * w[j].number) > (w[i].size * w[j].number + w[j].size * w[i].number))
				{
					char* temp = words[i];
					words[i] = words[i + 1];
					words[i + 1] = temp;
					int temp_length = word_lengths[i];
					word_lengths[i] = word_lengths[i + 1];
					word_lengths[i + 1] = temp_length;
					file_size = new_file_size;
					changed = 1;
				}

			}
		}

		if (fscanf(ifp, "%s", &read) == 1) {
			for (int i = 0;i < size;i++) {
				for (int j = size - 1;j = size; j--) {

					if ((w[i].size * w[i].number + w[j].size * w[j].number) <= (w[i].size * w[j].number + w[j].size * w[i].number)) {

						if (strcmp(read, w[i].name) == 0)
							strcpy(read, w[j].name);

						if (strcmp(read, w[j].name) == 0)
							strcpy(read, w[i].name);
					}

					fprintf(ofp, "%s ", read);
				}
			}
		}

	}*/
	/*int file_size_before = sizeOfFile(ifp);
	int file_size_after = file_size_before;
	while (file_size_after > 0 && file_size_after < file_size_before) {
		char* A = findMostCommonLongWord(w,size);
		char* B = findLessCommonShortWord(w,size);
		printf("Replacing \"%s\" with \"%s\"\n", A, B);
		

	}*/
	int k, q = 0;
	
	for (int i = 0, j = size;i < size/2;i++, j--) {
		
		if ((w[i].size * w[i].number + w[j].size * w[j].number) <= (w[i].size * w[j].number + w[j].size * w[i].number)){
			k = w[i].number;
			w[i].number = w[j].number;
			w[j].number = k;
			
			replace_words_in_file(ofp, w[i].name, w[j].name);
			printf("111111111");
			/*while (!feof(ifp)) {
				printf("1111111111");
				fscanf(ifp, "%s", read);
				printf("1111111111");
				q = 0;
				if (strcmp(read, w[i].name) == 0) {
					strcpy(read, w[j].name);
					q = 1;
				}
				printf("1111111111");
				if (strcmp(read, w[j].name) == 0 && q == 0)
					strcpy(read, w[i].name);
				fprintf(ofp, "%s ", read);
			}*/
		}
	}

	

		printf("\n\n\n\n\n\n");
		while (1) {

			ch = fgetc(ofp);

			if (ch == EOF) {

				break;

			}

			printf("%c", ch);

		}
		

		
	if (fclose(ifp) != 0 || fclose(ofp) != 0)
		printf("Error! File cannot be close");
}








void compress(char* fileName) {

	word* w = malloc(sizeof(word));
	int size = 0;
	frequencyOfEachWord(&w, &size, fileName);
	sort(w, size);
	printf("\n\n\n\n\n\n\n\n");
	for (int i = 0;i < size;i++)
		printf("%s \t           %d \t         %d\t\n", w[i].name, w[i].number, w[i].size);
	findAndReplaceInFile(w, size,fileName);
	//s(fileName);




	

}

void decompress(char* filename) {


}