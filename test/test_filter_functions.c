#include "test_filter_functions.h"
#include "../c_vector_ci/filter_functions.h"
#include "stdlib.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"

void test_is_even(){
    bool even = true;
    for(int i=0; i<10; i++){
        CU_ASSERT(is_even(i) == even);
        even = !even;
    }
}