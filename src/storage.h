/**
 * @file storage.h
 * @brief Data persistence and file I/O functions.
 *
 * This module handles loading and saving parking lot data to CSV files,
 * including users, parking slots, vehicle records, and audit logs.
 */

#ifndef STORAGE_H
#define STORAGE_H

#include "common.h"

/** @brief Path to users data file */
#define USERS_CSV "data/users.csv"
/** @brief Path to parking slots data file */
#define SLOTS_CSV "data/slots.csv"
/** @brief Path to vehicle records data file */
#define VEHICLES_CSV "data/vehicles.csv"
/** @brief Path to audit logs data file */
#define LOGS_CSV "data/logs.csv"

/** @brief Maximum number of user accounts */
#define MAX_USERS 128
/** @brief Maximum number of parking slots */
#define MAX_SLOTS 512
/** @brief Maximum number of vehicle records */
#define MAX_VEHICLES 1024
/** @brief Maximum number of audit log entries */
#define MAX_LOGS 2048

/**
 * @brief Load user accounts from CSV file.
 *
 * @param[in] path Path to the CSV file
 * @param[out] out Array to store loaded users
 * @param[in] max_count Maximum number of users to load
 * @param[out] out_count Actual number of users loaded
 *
 * @return true if load succeeds, false on file or parse error
 */
bool load_users(const char *path, User *out, size_t max_count, size_t *out_count);

/**
 * @brief Save user accounts to CSV file.
 *
 * @param[in] path Path to the CSV file
 * @param[in] arr Array of users to save
 * @param[in] count Number of users to save
 *
 * @return true if save succeeds, false on write error
 */
bool save_users(const char *path, const User *arr, size_t count);

/**
 * @brief Load parking slots from CSV file.
 *
 * @param[in] path Path to the CSV file
 * @param[out] out Array to store loaded slots
 * @param[in] max_count Maximum number of slots to load
 * @param[out] out_count Actual number of slots loaded
 *
 * @return true if load succeeds, false on file or parse error
 */
bool load_slots(const char *path, Slot *out, size_t max_count, size_t *out_count);

/**
 * @brief Save parking slots to CSV file.
 *
 * @param[in] path Path to the CSV file
 * @param[in] arr Array of slots to save
 * @param[in] count Number of slots to save
 *
 * @return true if save succeeds, false on write error
 */
bool save_slots(const char *path, const Slot *arr, size_t count);

/**
 * @brief Load vehicle records from CSV file.
 *
 * @param[in] path Path to the CSV file
 * @param[out] out Array to store loaded vehicle records
 * @param[in] max_count Maximum number of records to load
 * @param[out] out_count Actual number of records loaded
 *
 * @return true if load succeeds, false on file or parse error
 */
bool load_vehicles(const char *path, VehicleRecord *out, size_t max_count, size_t *out_count);

/**
 * @brief Save vehicle records to CSV file.
 *
 * @param[in] path Path to the CSV file
 * @param[in] arr Array of vehicle records to save
 * @param[in] count Number of records to save
 *
 * @return true if save succeeds, false on write error
 */
bool save_vehicles(const char *path, const VehicleRecord *arr, size_t count);

/**
 * @brief Load audit log entries from CSV file.
 *
 * @param[in] path Path to the CSV file
 * @param[out] out Array to store loaded log entries
 * @param[in] max_count Maximum number of entries to load
 * @param[out] out_count Actual number of entries loaded
 *
 * @return true if load succeeds, false on file or parse error
 */
bool load_logs(const char *path, LogEntry *out, size_t max_count, size_t *out_count);

/**
 * @brief Append a single log entry to the log file.
 *
 * @param[in] path Path to the CSV file
 * @param[in] entry Log entry to append
 *
 * @return true if append succeeds, false on write error
 */
bool append_log(const char *path, const LogEntry *entry);

#endif // STORAGE_H
