/** 
 * @brief It tests space module
 * @file space_test.c
 * @author Profesores Pprog and Eric Morales
 * @version 2.0 
 * @date 16-01-2015
 * @updated 19-01-2016
 * @copyright GNU Public License
 */

#undef __STRICT_ANSI__

#include <stdio.h> 
#include <stdlib.h> 
#include <wchar.h>
#include "../include/space.h"
#include "../include/space_test.h"
#include "../include/test.h"

#define MAX_TESTS 65

/*
 * Main function for SPACE unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 */

int main(int argc, char** argv) {
    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Space:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }

    if (all || test ==  1) test1_space_create();
    if (all || test ==  2) test2_space_create();
    if (all || test ==  3) test1_space_set_name();
    if (all || test ==  4) test2_space_set_name();
    if (all || test ==  5) test3_space_set_name();
    if (all || test ==  6) test1_space_set_direction();
    if (all || test ==  7) test2_space_set_direction();
    if (all || test ==  8) test3_space_set_direction();
    if (all || test ==  9) test4_space_set_direction();
    if (all || test == 10) test5_space_set_direction();
    if (all || test == 11) test6_space_set_direction();
    if (all || test == 12) test7_space_set_direction();
    if (all || test == 13) test1_space_set_graphic_description();
    if (all || test == 14) test2_space_set_graphic_description();
    if (all || test == 15) test3_space_set_graphic_description();
    if (all || test == 16) test1_space_set_basic_description();
    if (all || test == 17) test2_space_set_basic_description();
    if (all || test == 18) test3_space_set_basic_description();
    if (all || test == 19) test1_space_set_check_description();
    if (all || test == 20) test2_space_set_check_description();
    if (all || test == 21) test3_space_set_check_description();
    if (all || test == 22) test1_space_get_name();
    if (all || test == 23) test2_space_get_name();
    if (all || test == 24) test1_space_get_direction();
    if (all || test == 25) test2_space_get_direction();
    if (all || test == 26) test3_space_get_direction();
    if (all || test == 27) test4_space_get_direction();
    if (all || test == 28) test5_space_get_direction();
    if (all || test == 29) test6_space_get_direction();
    if (all || test == 30) test1_space_get_id();
    if (all || test == 31) test2_space_get_id();
    if (all || test == 32) test1_space_get_graphic_description();
    if (all || test == 33) test2_space_get_graphic_description();
    if (all || test == 34) test1_space_get_basic_description();
    if (all || test == 35) test2_space_get_basic_description();
    if (all || test == 36) test1_space_get_check_description();
    if (all || test == 37) test2_space_get_check_description();
    if (all || test == 38) test1_space_get_object_id();
    if (all || test == 39) test2_space_get_object_id();
    if (all || test == 40) test1_space_get_objects_number();
    if (all || test == 41) test2_space_get_objects_number();
    if (all || test == 42) test3_space_get_objects_number();
    if (all || test == 43) test4_space_get_objects_number();
    if (all || test == 44) test1_space_add_object();
    if (all || test == 45) test2_space_add_object();
    if (all || test == 46) test1_space_is_empty();
    if (all || test == 47) test2_space_is_empty();
    if (all || test == 48) test3_space_is_empty();
    if (all || test == 49) test1_space_is_full();
    if (all || test == 50) test2_space_is_full();
    if (all || test == 51) test3_space_is_full();
    if (all || test == 52) test4_space_is_full();
    if (all || test == 53) test1_space_check_object();
    if (all || test == 54) test2_space_check_object();
    if (all || test == 55) test3_space_check_object();
    if (all || test == 56) test1_space_add_tags();
    if (all || test == 57) test2_space_add_tags();
    if (all || test == 58) test1_space_check_tag();
    if (all || test == 59) test2_space_check_tag();
    if (all || test == 60) test1_space_remove_tags();
    if (all || test == 61) test2_space_remove_tags();
    if (all || test == 62) test1_space_get_tags();
    if (all || test == 63) test2_space_get_tags();
    if (all || test == 64) test1_space_get_tags_number();
    if (all || test == 65) test2_space_get_tags_number();

    PRINT_PASSED_PERCENTAGE;

    return 0;
}

void test1_space_create() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space != NULL);
    space_destroy(space);
}

void test2_space_create() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_get_id(space) == 1);
    space_destroy(space);
}

void test1_space_set_name() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_name(space, L"test") == OK);
    space_destroy(space);
}

void test2_space_set_name() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_name(space, L"test") == ERROR);
}

void test3_space_set_name() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_name(space, NULL) == ERROR);
    space_destroy(space);
}

void test1_space_set_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_direction(space, NORTH, LINK_BASE_ID+1) == OK);
    space_destroy(space);
}

void test2_space_set_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_direction(space, WEST, LINK_BASE_ID+1) == OK);
    space_destroy(space);
}

void test3_space_set_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_direction(space, SOUTH, LINK_BASE_ID+1) == OK);
    space_destroy(space);
}

void test4_space_set_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_direction(space, EAST, LINK_BASE_ID+1) == OK);
    space_destroy(space);
}

void test5_space_set_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_direction(space, NO_DIR, LINK_BASE_ID+1) == ERROR);
    space_destroy(space);
}

void test6_space_set_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_direction(space, NORTH, NO_ID) == ERROR);
    space_destroy(space);
}

void test7_space_set_direction() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_set_direction(space, NORTH, LINK_BASE_ID+1) == ERROR);
}

void test1_space_set_graphic_description() {
    Space *space = NULL;
    wchar_t desc[MAX_GDESC_R][MAX_GDESC_C];
    int i;
    space = space_create(SPACE_BASE_ID+1);
    for (i = 0; i < MAX_GDESC_R; i++) {
        wcscpy(desc[i], L"desc");
    }
    PRINT_TEST_RESULT(space_set_graphic_description(space, desc) == OK);
    space_destroy(space);
}

void test2_space_set_graphic_description() {
    Space *space = NULL;
    wchar_t desc[MAX_GDESC_R][MAX_GDESC_C];
    int i;
    for (i = 0; i < MAX_GDESC_R; i++) {
        wcscpy(desc[i], L"desc");
    }
    PRINT_TEST_RESULT(space_set_graphic_description(space, desc) == ERROR);
}

void test3_space_set_graphic_description() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_graphic_description(space, NULL) == ERROR);
    space_destroy(space);
}

void test1_space_set_basic_description() {
    Space *space = NULL;
    wchar_t basic_description[MAX_TDESC_R][MAX_TDESC_C];
    int i;
    space = space_create(SPACE_BASE_ID+1);
    for (i = 0; i < MAX_TDESC_R; i++) {
        wcscpy(basic_description[i], L"Basic description");
    }
    PRINT_TEST_RESULT(space_set_basic_description(space, basic_description) == OK);
    space_destroy(space);
}

void test2_space_set_basic_description() {
    Space *space = NULL;
    wchar_t basic_description[MAX_TDESC_R][MAX_TDESC_C];
    int i;
    for (i = 0; i < MAX_TDESC_R; i++) {
        wcscpy(basic_description[i], L"Basic description");
    }
    PRINT_TEST_RESULT(space_set_basic_description(space, basic_description) == ERROR);
}

void test3_space_set_basic_description() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_basic_description(space, NULL) == ERROR);
    space_destroy(space);
}

void test1_space_set_check_description() {
    Space *space = NULL;
    wchar_t check_description[MAX_TDESC_R][MAX_TDESC_C];
    int i;
    space = space_create(SPACE_BASE_ID+1);
    for (i = 0; i < MAX_TDESC_R; i++) {
        wcscpy(check_description[i], L"Check description");
    }
    PRINT_TEST_RESULT(space_set_check_description(space, check_description) == OK);
    space_destroy(space);
}

void test2_space_set_check_description() {
    Space *space = NULL;
    wchar_t check_description[MAX_TDESC_R][MAX_TDESC_C];
    int i;
    for (i = 0; i < MAX_TDESC_R; i++) {
        wcscpy(check_description[i], L"Check description");
    }
    PRINT_TEST_RESULT(space_set_check_description(space, check_description) == ERROR);
}

void test3_space_set_check_description() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_set_check_description(space, NULL) == ERROR);
    space_destroy(space);
}

void test1_space_get_name() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_set_name(space, L"test");
    PRINT_TEST_RESULT(wcscmp(space_get_name(space), L"test") == 0);
    space_destroy(space);
}

void test2_space_get_name() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_name(space) == NULL);
}

void test1_space_get_id() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_get_id(space) == SPACE_BASE_ID+1);
    space_destroy(space);
}

void test2_space_get_id() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_id(space) == NO_ID);
}

void test1_space_get_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_set_direction(space, NORTH, LINK_BASE_ID+1);
    PRINT_TEST_RESULT(space_get_direction(space, NORTH) == LINK_BASE_ID+1);
    space_destroy(space);
}

void test2_space_get_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_set_direction(space, WEST, LINK_BASE_ID+1);
    PRINT_TEST_RESULT(space_get_direction(space, WEST) == LINK_BASE_ID+1);
    space_destroy(space);
}

void test3_space_get_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_set_direction(space, SOUTH, LINK_BASE_ID+1);
    PRINT_TEST_RESULT(space_get_direction(space, SOUTH) == LINK_BASE_ID+1);
    space_destroy(space);
}

void test4_space_get_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_set_direction(space, EAST, LINK_BASE_ID+1);
    PRINT_TEST_RESULT(space_get_direction(space, EAST) == LINK_BASE_ID+1);
    space_destroy(space);
}

void test5_space_get_direction() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_get_direction(space, NO_DIR) == NO_ID);
}

void test6_space_get_direction() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_direction(space, NORTH) == NO_ID);
}

void test1_space_get_graphic_description() {
    Space *space = NULL;
    wchar_t desc[MAX_GDESC_R][MAX_GDESC_C];
    wchar_t **descEnd;
    int i;
    int result = 0;
    space = space_create(SPACE_BASE_ID+1);
    for (i = 0; i < MAX_GDESC_R; i++) {
        wcscpy(desc[i], L"desc");
    }
    space_set_graphic_description(space, desc);
    descEnd = space_get_graphic_description(space);
    for (i = 0; i < MAX_GDESC_R; i++) {
        if (wcscmp(descEnd[i], L"desc") != 0) {
            result = 1;
        }
    }
    PRINT_TEST_RESULT(result == 0);
    space_destroy(space);
}

void test2_space_get_graphic_description() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_graphic_description(space) == NULL);
}

void test1_space_get_basic_description() {
    Space *space = NULL;
    wchar_t basic_description[MAX_TDESC_R][MAX_TDESC_C];
    wchar_t **basic_description_end;
    int i;
    int result = 0;
    space = space_create(SPACE_BASE_ID+1);
    for (i = 0; i < MAX_TDESC_R; i++) {
        wcscpy(basic_description[i], L"Basic description");
    }
    space_set_basic_description(space, basic_description);
    basic_description_end = space_get_basic_description(space);
    for (i = 0; i < MAX_TDESC_R; i++) {
        if (wcscmp(basic_description_end[i], L"Basic description") != 0) {
            result = 1;
        }
    }
    PRINT_TEST_RESULT(result == 0);
    space_destroy(space);
}

void test2_space_get_basic_description() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_basic_description(space) == NULL);
}

void test1_space_get_check_description() {
    Space *space = NULL;
    wchar_t check_description[MAX_TDESC_R][MAX_TDESC_C];
    wchar_t **check_description_end;
    int i;
    int result = 0;
    space = space_create(SPACE_BASE_ID+1);
    for (i = 0; i < MAX_TDESC_R; i++) {
        wcscpy(check_description[i], L"Check description");
    }
    space_set_check_description(space, check_description);
    check_description_end = space_get_check_description(space);
    for (i = 0; i < MAX_TDESC_R; i++) {
        if (wcscmp(check_description_end[i], L"Check description") != 0) {
            result = 1;
        }
    }
    PRINT_TEST_RESULT(result == 0);
    space_destroy(space);
}

void test2_space_get_check_description() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_check_description(space) == NULL);
}

void test1_space_get_object_id() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_add_object(space, OBJECT_BASE_ID+1);
    PRINT_TEST_RESULT(space_get_object_id(space, 0) == OBJECT_BASE_ID+1);
    space_destroy(space);
}

void test2_space_get_object_id() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_object_id(space, 0) == NO_ID);
}

void test1_space_get_objects_number() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_add_object(space, OBJECT_BASE_ID+1);
    PRINT_TEST_RESULT(space_get_objects_number(space) == 1);
    space_destroy(space);
}

void test2_space_get_objects_number() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_get_objects_number(space) == 0);
    space_destroy(space);
}

void test3_space_get_objects_number() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_objects_number(space) == 0);
}

void test4_space_get_objects_number() {
    Space *space = NULL;
    int i;
    space = space_create(SPACE_BASE_ID+1);
    for (i = 0; i <= MAX_OBJECTS+1; i++) {
        space_add_object(space, OBJECT_BASE_ID+1 + i);
    }
    PRINT_TEST_RESULT(space_get_objects_number(space) == SET_MAX_IDS);
    space_destroy(space);
}

void test1_space_add_object() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_add_object(space, TRUE) == OK);
    space_destroy(space);
}

void test2_space_add_object() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_add_object(space, TRUE) == ERROR);
}

void test1_space_is_empty() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_is_empty(space) == TRUE);
    space_destroy(space);
}

void test2_space_is_empty() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_is_empty(space) == TRUE);
}

void test3_space_is_empty() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_add_object(space, OBJECT_BASE_ID+1);
    PRINT_TEST_RESULT(space_is_empty(space) == FALSE);
    space_destroy(space);
}

void test1_space_is_full() {
    Space *space = NULL;
    int i;
    space = space_create(SPACE_BASE_ID+1);
    for (i = 0; i <= MAX_OBJECTS+1; i++) {
        space_add_object(space, OBJECT_BASE_ID+1 + i);
    }
    PRINT_TEST_RESULT(space_is_full(space) == TRUE);
    space_destroy(space);
}

void test2_space_is_full() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_is_full(space) == FALSE);
    space_destroy(space);
}

void test3_space_is_full() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_is_full(space) == TRUE);
}

void test4_space_is_full() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_add_object(space, OBJECT_BASE_ID+1);
    PRINT_TEST_RESULT(space_is_full(space) == FALSE);
    space_destroy(space);
}

void test1_space_check_object() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_add_object(space, OBJECT_BASE_ID+1);
    PRINT_TEST_RESULT(space_check_object(space, OBJECT_BASE_ID+1) == TRUE);
    space_destroy(space);
}

void test2_space_check_object() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_check_object(space, OBJECT_BASE_ID+1) == FALSE);
    space_destroy(space);
}

void test3_space_check_object() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_check_object(space, OBJECT_BASE_ID+1) == FALSE);
}

void test1_space_add_tags() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_add_tags(space, 2, ILLUMINATED, FINAL_ROOM) == OK);
    space_destroy(space);
}

void test2_space_add_tags() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_add_tags(space, 2, ILLUMINATED, FINAL_ROOM) == ERROR);
}

void test1_space_check_tag() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_add_tags(space, 2, ILLUMINATED, FINAL_ROOM);
    PRINT_TEST_RESULT(space_check_tag(space, ILLUMINATED));
    space_destroy(space);
}

void test2_space_check_tag() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    PRINT_TEST_RESULT(space_check_tag(space, ILLUMINATED) == FALSE);
    space_destroy(space);
}

void test1_space_remove_tags() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_add_tags(space, 2, ILLUMINATED, FINAL_ROOM);
    PRINT_TEST_RESULT(space_remove_tags(space, 2, ILLUMINATED, FINAL_ROOM) == OK);
    space_destroy(space);
}

void test2_space_remove_tags() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_remove_tags(space, 2, ILLUMINATED, FINAL_ROOM) == ERROR);
}

void test1_space_get_tags() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_add_tags(space, 2, ILLUMINATED, FINAL_ROOM);
    PRINT_TEST_RESULT(space_get_tags(space) != NULL);
    space_destroy(space);
}

void test2_space_get_tags() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_tags(space) == NULL);
}

void test1_space_get_tags_number() {
    Space *space = NULL;
    space = space_create(SPACE_BASE_ID+1);
    space_add_tags(space, 2, ILLUMINATED, FINAL_ROOM);
    PRINT_TEST_RESULT(space_get_tags_number(space) == 2);    
    space_destroy(space);
}

void test2_space_get_tags_number() {
    Space *space = NULL;
    PRINT_TEST_RESULT(space_get_tags_number(space) == 0);
}