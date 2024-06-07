#include "libsam.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>



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


void test_write() {
    const char *test_str = "Hello, ft_write!\n";
    ssize_t expected_res = write(STDOUT_FILENO, test_str, strlen(test_str));
    ssize_t result_res = ft_write(STDOUT_FILENO, test_str, strlen(test_str));
    
    printf("[TEST] write\n");
    printf("Expected write result: %zd\n", expected_res);
    printf("Result write result: %zd\n", result_res);
    printf((expected_res == result_res) ? "[PASS]\n\n" : "[FAIL]\n\n");

	expected_res = write(STDOUT_FILENO, NULL, strlen(test_str));
    result_res = ft_write(STDOUT_FILENO, NULL, strlen(test_str));
    
    printf("[TEST] write\n");
    printf("Expected write result: %zd\n", expected_res);
    printf("Result write result: %zd\n", result_res);
    printf((expected_res == result_res) ? "[PASS]\n\n" : "[FAIL]\n\n");
}

void test_read() {
    char expected_buf[100];
    char result_buf[100];
    int fd = open("testfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }
    
    ssize_t expected_res = read(fd, expected_buf, 99);
    expected_buf[expected_res] = '\0';
    
    lseek(fd, 0, SEEK_SET);  // Reset file descriptor to beginning for second read
    ssize_t result_res = ft_read(fd, result_buf, 99);
    result_buf[result_res] = '\0';
    
    close(fd);
    
    printf("[TEST] read\n");
    printf("Expected read result: %zd\n", expected_res);
    printf("Result read result: %zd\n", result_res);
    printf((expected_res == result_res && strcmp(expected_buf, result_buf) == 0) ? "[PASS]\n\n" : "[FAIL]\n\n");
}

int main() {
    test_strlen();	// good
    test_strcpy();	// fucked
    test_strcmp();	// fucked
    test_strdup();	// ultra fucked 
	test_write();
	test_read();
    return 0;
}