#include "libsam.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



// Helper function to print test results
void print_result(const char *test, const char *expected, const char *result) {
    if (strcmp(expected, result) == 0) {
        printf("[PASS] %s\n", test);
    } else {
        printf("[FAIL] %s\n", test);
        printf("Expected: %s\n", expected);
        printf("Got: %s\n", result);
    }
}

// Test functions
void test_strlen() {
    const char *test_str = "Hello, World!";
    size_t expected_len = strlen(test_str);
    size_t result_len = ft_strlen(test_str);
    printf("[TEST] strlen\n");
    printf("Expected length: %zu\n", expected_len);
    printf("Result length: %zu\n", result_len);
    printf((expected_len == result_len) ? "[PASS]\n\n" : "[FAIL]\n\n");
}

void test_strcpy() {
    const char *src = "Hello, World!";
    char dest[50];
    char ft_dest[50];
    
    strcpy(dest, src);
    ft_strcpy(ft_dest, src);

    printf("[TEST] strcpy\n");
    print_result("strcpy", dest, ft_dest);
    printf("\n");
}

void test_strcmp() {
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, World!";
    const char *str3 = "Hello, world!";
    
    int expected_cmp1 = strcmp(str1, str2);
    int result_cmp1 = ft_strcmp(str1, str2);
    
    int expected_cmp2 = strcmp(str1, str3);
    int result_cmp2 = ft_strcmp(str1, str3);
    
    printf("[TEST] strcmp\n");
    printf("Expected strcmp(str1, str2): %d\n", expected_cmp1);
    printf("Result strcmp(str1, str2): %d\n", result_cmp1);
    printf((expected_cmp1 == result_cmp1) ? "[PASS]\n\n" : "[FAIL]\n\n");
    
    printf("Expected strcmp(str1, str3): %d\n", expected_cmp2);
    printf("Result strcmp(str1, str3): %d\n", result_cmp2);
    printf((expected_cmp2 == result_cmp2) ? "[PASS]\n\n" : "[FAIL]\n\n");
}

void test_strdup() {
    const char *src = "Hello, World!";
    
    char *expected_dup = strdup(src);
    char *result_dup = ft_strdup(src);
    
    printf("[TEST] strdup\n");
    print_result("strdup", expected_dup, result_dup);
	printf("addr of original strdup : %p\n", expected_dup);
	printf("addr of ft_strdup       : %p\n", result_dup);
    
    free(expected_dup);
    free(result_dup);
    printf("\n");
}

int main() {
    test_strlen();	// good
    test_strcpy();	// fucked
    test_strcmp();	// fucked
    test_strdup();	// ultra fucked 
    return 0;
}