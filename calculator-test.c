/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "calculator-test.check" instead.
 */

#include <check.h>

#line 1 "calculator-test.check"
#include "calculator.h"

START_TEST(calc)
{
#line 4
 // adding the operation of addition and subtraction operation
	fail_unless((inputs("M","D",1) == 1500),"returned correct roman value"); 
	
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, calc);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
