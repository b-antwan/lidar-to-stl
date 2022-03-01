#include "test_map_functions.h"
#include "../c_vector_ci/map_functions.h"
#include "stdlib.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"

void test_square(){
    for(int i=0; i<10; i++){
        CU_ASSERT(square(i) == i*i);
    }
}