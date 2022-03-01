#include "test_filter_functions.h"
#include "test_map_functions.h"
#include "test_las.h"
#include "test_point.h"
#include "test_stl.h"
#include "test_triangle.h"
#include "test_vector.h"
#include <stdio.h>
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"

int main()
{

    CU_pSuite filter_suite = NULL;
    CU_pSuite map_suite = NULL;
    //CU_pSuite las_suite = NULL;
    //CU_pSuite point_suite = NULL;
    //CU_pSuite stl_suite = NULL;
    //CU_pSuite triangle_suite = NULL;
    CU_pSuite vector_suite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    filter_suite = CU_add_suite("Filter suite", NULL, NULL);
    if (NULL == filter_suite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(filter_suite, "test of is_even", test_is_even)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add a suite to the registry */
    map_suite = CU_add_suite("Map suite", NULL, NULL);
    if (NULL == map_suite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(map_suite, "test of square", test_square)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add a suite to the registry */
    vector_suite = CU_add_suite("Vector suite", NULL, NULL);
    if (NULL == vector_suite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(vector_suite, "test of vector_init", test_vector_init)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_is_equal", test_vector_is_equal)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_free", test_vector_free)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_length", test_vector_length)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_push", test_vector_push)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_pop", test_vector_pop)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_set", test_vector_set)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_get", test_vector_get)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_remove", test_vector_remove)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_insert", test_vector_insert)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_empty", test_vector_empty)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_map", test_vector_map)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_filter", test_vector_filter)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic (console output) and Automated (xml output) interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    CU_automated_run_tests();

    // return CU_get_error();
    return CU_get_number_of_tests_failed();
}