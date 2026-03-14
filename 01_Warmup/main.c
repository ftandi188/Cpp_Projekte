/*
 * Copyright (C) 2025 by Michael Farmbauer
 *
 */
#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef int value_t;  // type used for values

struct list {
    size_t len; // Number of values in list
    value_t values[]; // Array of values with "len" entries
};

/**
 * @brief Allocate memory for a list
 * @param len   Number of values in list
 * @return      Pointer to a struct list with the len initialized
 */
struct list *listAllocate(size_t len)
{
    struct list *list = malloc(sizeof(size_t) + len * sizeof(value_t));
    list->len = len;

    return list;
}
/**
 * @brief Check if two lists are of equal length and contain the same values
 * @param a 	A list
 * @param b 	A list
 */
bool listEqual(struct list *a, struct list *b)
{
    if (a->len != b->len) {
	return false;
    }

    for(size_t i = 0; i < a->len; i++) {
	if (a->values[i] != b->values[i]) {
	    return false;
	}
    }
    return true;
}

/**
 * @brief Print len and values of a list for debugging purpose
 *
 * @param l 	A list
 */
void listPrint(struct list * l)
{
    printf("len = %ld; values = ", l->len);
    for (size_t i = 0; i < l->len; i++) {
        printf("%d%s", l->values[i], (i+1 < l->len)?";":"\n");
    }
}

/*
 * -- %< --------- Place your solution here --------------------
 */

/*
 * global data
 */

// if your solution requires global data, you can place them here

/**
 * @brief This function it can help initalizing global data
 */
void setup()
{

    // this is the perfect place to initialize any global variable you placed above

}

/**
 * @brief          get all unique digit permutations of a list of numbers
 *
 * @param numbers  A list of numbers.
 * @return         A list of numbers, which are unique digit permutations of above list
 */
struct list * getUniqPermutations(struct list *numbers)
{

    // add your code here


    // FIXME return your solution
    //
    // This returns the solution for first example
    struct list * result = listAllocate(numbers->len);
    result->len = 1; // overwrite len with the number of values in your result
    result->values[0] = 456;
    return result;
}

/*
 * -- %< -------------------------------------------------------
 */

#define EXAMPLES "examples.txt"
#define MAXLENGTH 2500
#define NUMLINES 3

struct test {
    struct list * result;
    struct list * numbers;
};

struct test * readTest(char line[NUMLINES][MAXLENGTH])
{
    if (line[0][0] != 'C' || line[1][0] != 'R') {
	return NULL;
    }

    struct test *test = malloc(sizeof(struct test));

    char *tok = NULL;
    size_t size = 0;

    // read numbers line
    tok = strtok(&line[0][2], " "); // read size
    size = atoi(tok);
    test->numbers = listAllocate(size);
    tok = strtok(NULL, ";"); // read first number token before iterating the list
    for (size_t i = 0; i < size && tok; i++ ) {
	test->numbers->values[i] = atoi(tok);
	tok = strtok(NULL, ";");
    }

    // read result
    tok = strtok(&line[1][2], " "); // read size
    size = atoi(tok);
    test->result = listAllocate(size);
    tok = strtok(NULL, ";"); // read first number token before iterating the list
    for (size_t i = 0; i < size && tok; i++ ) {
	test->result->values[i] = atoi(tok);
	tok = strtok(NULL, ";");
    }

    return test;
}

void deleteTest(struct test *test)
{
    if (test) {
	free(test->result);
	free(test->numbers);
	free(test);
    }
}

value_t comp(const void *a, const void *b)
{
    return (*(value_t *)a - *(value_t *)b);
}

int main()
{
    FILE *f = fopen(EXAMPLES, "r");
    if (f == NULL) perror ("Error opening file");

    setup();

    char multilinebuffer[NUMLINES][MAXLENGTH];

    int testnr = 1;
    int linenr = 0;
    while(fgets(multilinebuffer[linenr], MAXLENGTH, f) != NULL) {
	if (strlen(multilinebuffer[linenr]) < 2) {
	    continue;
	}

	if (linenr < 1) {
	    linenr++;
	} else {
	    linenr = 0;
	    struct test *test = readTest(multilinebuffer);

	    if (test == NULL) perror ("Error parsing example");

	    printf("Test %d ... ", testnr);
	    struct list * result = getUniqPermutations(test->numbers);

	    // Sort the result
	    qsort(result->values, result->len, sizeof(result->values[0]), comp);
	    qsort(test->result->values, test->result->len, sizeof(test->result->values[0]), comp);

	    if (!listEqual(test->result, result)) {
		printf("FAILED expected result:\n");
		listPrint(test->result);
		printf("your result:\n");
		listPrint(result);

		abort(); // stop execution. Remove this line to keep going
	    } else {
		printf("PASSED with result:\n");
		listPrint(result);
	    }
	    deleteTest(test);
	    testnr++;
	}
    }

    return 0;
}
