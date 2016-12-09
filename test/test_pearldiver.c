#include "../src/Hash.h"
#include "../src/PearlDiver.h"
//#include "random_trits.h"

#ifdef __APPLE__
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#else
#include "BCUnit/BCUnit.h"
#include "BCUnit/Basic.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void runtests();
void getRandomTrits (long *RandomTrits, int length);
int init_suite(void) {return 0;}
int clean_suite(void) {return 0;}

/************** Test case functions ****************/


void test_pearl_diver_destroy(void)
{
	PearlDiver pearl_diver;

	pearl_diver = malloc(sizeof(struct _PearlDiver));
	
	CU_ASSERT(sizeof(struct _PearlDiver) > 8);

	free(pearl_diver);
}

void test_pearl_diver_search(void)
{
	//PearlDiver pearl_diver;

	//fprintf(stderr, "\n _PearlDiver size:%d\n", sizeof(struct _PearlDiver));
	/*
	pearl_diver = malloc(sizeof(struct _PearlDiver));
	if (pearl_diver == NULL) {
		CU_ASSERT(false);
		return;
	}
	*/
	int nonce_size = 1;
	long trits[TRANSACTION_LENGTH];// = { trit_1 };
	getRandomTrits(trits, TRANSACTION_LENGTH);

	//clock_t start = clock(), diff;
	search(trits, TRANSACTION_LENGTH, nonce_size, 32);
	//diff = clock() - start;
	
	//CU_ASSERT(out);
	
	//free(pearl_diver);
}

void test_pearl_diver_threads(void)
{
	PearlDiver pearl_diver;

	pearl_diver = malloc(sizeof(struct _PearlDiver));
	if (pearl_diver == NULL) {
		CU_ASSERT(false);
		return;
	}
	
	long trits[TRANSACTION_LENGTH];// = { trit_1 };
	long expect[TRANSACTION_LENGTH];// = { trit_output_1 };
	//getRandomTrits(trits, TRANSACTION_LENGTH);

	clock_t start = clock(), diff;
	search(trits, TRANSACTION_LENGTH, 18, 8);
	diff = clock() - start;

	CU_ASSERT(memcmp(trits, expect, TRANSACTION_LENGTH * sizeof(long)));
	CU_ASSERT(diff > 50000000);

	free(pearl_diver);
}


int main (int argc, char** argv) {

	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */ 
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */ 
	pSuite = CU_add_suite("Suite_1", NULL, NULL);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* add the tests to the suite */ 
	if ( //(NULL == CU_add_test(pSuite, "PearlDiver Create Test", test_pearl_diver_create)) ||
		(NULL == CU_add_test(pSuite, "PearlDiver Destroy Test", test_pearl_diver_destroy)) ||
		(NULL == CU_add_test(pSuite, "PearlDiver Search Test", test_pearl_diver_search))// ||
		//(NULL == CU_add_test(pSuite, "PearlDiver Thread Test", test_pearl_diver_threads))
	   ) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */ 
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}

void getRandomTrits (long *RandomTrits, int length) {
	int i = 0;
	srand(time(NULL));
	while (i < length) {
		RandomTrits[i] = rand() % 3 - 1;
		i++;
	}

}
