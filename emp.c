#include "employee.h"
#include <string.h>
#include "emp_util.h"
#include "file_mgr.h"
#include "common_utils.h"

int main(int argc, char *argv[])
{
    emp_detail test;

    
    strcpy(test.name, "TestEmployee_2");
//   test.age_gender = 114;
    format_age_gender(29, 0, &test);
    strcpy(test.emp_id ,"EMP_002");
//    strcpy(test.email, "TESTEMP_1@nagra.com");
    test.designation = INTERN;
    test.experience = 1;
    test.skillset = 255;
    test.salary = 100000;
    test.dep = IOT;

    generate_emp_email(&test);

    //read_emp_from_file("EMP_001", &test);

    print_emp(&test);

 //   save_emp_to_file(&test);

    return EXIT_SUCCESS;
}
