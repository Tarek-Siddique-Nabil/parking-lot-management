/**
 * @file auth.h
 * @brief User authentication and authorization functions.
 *
 * This module provides user authentication and role-based functions for
 * the parking lot management system.
 */

#ifndef AUTH_H
#define AUTH_H

#include "common.h"

/**
 * @brief Authenticate a user with the provided credentials.
 *
 * @param[in] username The username to authenticate
 * @param[in] password The password to verify
 * @param[in] users Array of user records to search
 * @param[in] count Number of users in the array
 * @param[out] out_user Pointer to store authenticated user data
 *
 * @return true if authentication succeeds, false otherwise
 */
bool authenticate(const char *username, const char *password, const User *users, size_t count, User *out_user);

/**
 * @brief Get the string representation of a user role.
 *
 * @param[in] role The role enumeration value
 *
 * @return String name of the role (e.g., "admin", "attendant")
 */
const char *role_name(Role role);

#endif // AUTH_H
