/**
 * @file test_auth.c
 * @brief Unit tests for authentication module
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "auth.h"

int test_authenticate_valid_credentials() {
    User users[2] = {
        {"user1", "pass123", ROLE_ADMIN},
        {"user2", "pass456", ROLE_ATTENDANT}
    };
    
    User authenticated_user;
    bool result = authenticate("user1", "pass123", users, 2, &authenticated_user);
    
    assert(result == true);
    assert(strcmp(authenticated_user.username, "user1") == 0);
    assert(authenticated_user.role == ROLE_ADMIN);
    
    printf("✓ test_authenticate_valid_credentials passed\n");
    return 0;
}

int test_authenticate_invalid_password() {
    User users[2] = {
        {"user1", "pass123", ROLE_ADMIN},
        {"user2", "pass456", ROLE_ATTENDANT}
    };
    
    User authenticated_user;
    bool result = authenticate("user1", "wrongpass", users, 2, &authenticated_user);
    
    assert(result == false);
    
    printf("✓ test_authenticate_invalid_password passed\n");
    return 0;
}

int test_authenticate_user_not_found() {
    User users[2] = {
        {"user1", "pass123", ROLE_ADMIN},
        {"user2", "pass456", ROLE_ATTENDANT}
    };
    
    User authenticated_user;
    bool result = authenticate("nonexistent", "pass123", users, 2, &authenticated_user);
    
    assert(result == false);
    
    printf("✓ test_authenticate_user_not_found passed\n");
    return 0;
}

int test_authenticate_null_inputs() {
    User users[1] = {{"user1", "pass123", ROLE_ADMIN}};
    User authenticated_user;
    
    bool result1 = authenticate(NULL, "pass123", users, 1, &authenticated_user);
    assert(result1 == false);
    
    bool result2 = authenticate("user1", NULL, users, 1, &authenticated_user);
    assert(result2 == false);
    
    bool result3 = authenticate("user1", "pass123", NULL, 1, &authenticated_user);
    assert(result3 == false);
    
    printf("✓ test_authenticate_null_inputs passed\n");
    return 0;
}

int test_role_name_admin() {
    const char *name = role_name(ROLE_ADMIN);
    assert(strcmp(name, "Admin") == 0);
    
    printf("✓ test_role_name_admin passed\n");
    return 0;
}

int test_role_name_attendant() {
    const char *name = role_name(ROLE_ATTENDANT);
    assert(strcmp(name, "Attendant") == 0);
    
    printf("✓ test_role_name_attendant passed\n");
    return 0;
}

int main() {
    printf("Running authentication tests...\n\n");
    
    test_authenticate_valid_credentials();
    test_authenticate_invalid_password();
    test_authenticate_user_not_found();
    test_authenticate_null_inputs();
    test_role_name_admin();
    test_role_name_attendant();
    
    printf("\nAll authentication tests passed!\n");
    return 0;
}
