// test_calculadora.c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "calculadora.h"

void test_suma(void) {
    CU_ASSERT(sumar(2, 2) == 4);
    CU_ASSERT(sumar(-1, 1) == 0);
    CU_ASSERT(sumar(0, 0) == 0);
}

void test_resta(void) {
    CU_ASSERT(restar(2, 2) == 0);
    CU_ASSERT(restar(-1, 1) == -2);
    CU_ASSERT(restar(0, 0) == 0);
}

int main() {
    // Inicializa el registro de pruebas
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Crea un suite de pruebas
    CU_pSuite suite = CU_add_suite("Suite de Suma", 0, 0);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Agrega el test al suite
    if (NULL == CU_add_test(suite, "Prueba de suma", test_suma)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Agrega el test al suite
    if (NULL == CU_add_test(suite, "Prueba de restar", test_restar)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Corre los tests en modo básico
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
