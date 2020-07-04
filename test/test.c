#include <assert.h>
#include <stdio.h>

#include "vector.h"

int main() {
	int i;
	size_t j;

	printf("TESTING SETUP ...\n");
	Vector vector = VECTOR_INITIALIZER;
	assert(!vector_is_initialized(&vector));
	vector_setup(&vector, 0, sizeof(int));
	assert(vector_is_initialized(&vector));

	printf("TESTING INSERT ...\n");

	for (i = 0; i < 1000; ++i) {
		assert(vector_insert(&vector, 0, &i) == VECTOR_SUCCESS);
		assert(VECTOR_GET_AS(int, &vector, 0) == i);
		assert(vector.size == (size_t)(i + 1));
	}

	int x = 5;
	vector_push_back(&vector, &x);
	vector_insert(&vector, vector.size, &x);

	printf("TESTING ASSIGNMENT ...\n");

	for (j = 0; j < vector.size; ++j) {
		int value = 666;
		(void)value;
		assert(vector_assign(&vector, j, &value) == VECTOR_SUCCESS);
	}

	printf("TESTING ITERATION ...\n");

	Iterator iterator = vector_begin(&vector);
	(void)iterator;
	assert(iterator_index(&vector, &iterator) == 0);

	iterator = vector_iterator(&vector, 1);
	assert(iterator_index(&vector, &iterator) == 1);

	VECTOR_FOR_EACH(&vector, iterator) {
		assert(ITERATOR_GET_AS(int, &iterator) == 666);
	}

	printf("TESTING REMOVAL ...\n");

	iterator = vector_begin(&vector);
	assert(iterator_erase(&vector, &iterator) == VECTOR_SUCCESS);

	size_t expected_size = vector.size;
	(void)expected_size;
	while (!vector_is_empty(&vector)) {
		assert(vector_erase(&vector, 0) == VECTOR_SUCCESS);
		assert(vector.size == --expected_size);
	}

	printf("TESTING RESIZE ...\n");
	assert(vector_resize(&vector, 100) == VECTOR_SUCCESS);
	assert(vector.size == 100);
	assert(vector.capacity > 100);

	printf("TESTING RESERVE ...\n");
	assert(vector_reserve(&vector, 200) == VECTOR_SUCCESS);
	assert(vector.size == 100);
	assert(vector.capacity == 200);

	printf("TESTING CLEAR ...\n");
	assert(vector_clear(&vector) == VECTOR_SUCCESS);

	assert(vector.size == 0);
	assert(vector_is_empty(&vector));
	assert(vector.capacity == VECTOR_MINIMUM_CAPACITY);

	vector_destroy(&vector);

	printf("\033[92mALL TEST PASSED\033[0m\n");
}
